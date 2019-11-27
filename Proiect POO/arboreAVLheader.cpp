#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "nodheader.h"
#include "nodAVLheader.h"
#include "arboreheader.h"
#include "ABCheader.h"
#include "arboreAVLheader.h"
using namespace std;

arboreAVL :: arboreAVL()
{
    nr_noduri=0;
    rad=NULL;
}

arboreAVL :: arboreAVL(int i,nod_avl *n):arbore(i),rad(n) {}               //transmiterea in clasa baza

arboreAVL :: ~arboreAVL()
{
    nr_noduri=0;
    delete rad;
}


ostream & operator<<(ostream & out,arboreAVL &a)
{
    out<<"Numarul de noduri este: ";
    out<<a.nr_noduri;
    while(a.rad!=NULL)
    {
        out<<a.rad->get_info()<<" ";
        out<<a.rad->get_echilibru()<<endl;
        a.afisarersd(a.rad->get_st());
        a.afisarersd(a.rad->get_dr());
    }
    return out;
}

istream & operator>>(istream &in,arboreAVL &a)
{
    int val,i;
    cout<<"Introduceti numarul de noduri: ";
    in>>a.nr_noduri;
    for(i=0; i<a.nr_noduri; i++)
    {
        cout<<"Introduceti valoarea nodului: "<<endl;
        in>>val;
        a.inserare(a.rad,val,0);
        a.PuneEchilibru(a.rad);
    }
    return in;
}

void arboreAVL :: set_rad(nod_avl * n)
{
    rad=n;
}

int arboreAVL :: max(int val1,int val2)
{
    return val1 < val2 ? val2 : val1;
}

int arboreAVL :: get_echilibru(nod_avl *n)
{
    return n->echilibru;
}

nod_avl * arboreAVL :: get_rad()
{
//    if(rad==NULL)
//    {
//        throw "Eroare- arborele este gol!";
//        cout<<endl;
//    }
    return rad;
}


int arboreAVL :: get_nr_noduri()
{
    return nr_noduri;
}

nod_avl * arboreAVL :: inserare(nod_avl *rad,int valoare, int echilibru)
{

    if(rad==NULL)
    {
        rad= new nod_avl(valoare,echilibru,NULL,NULL);
    }
    else if(rad->info<valoare)
        rad->dreapta = inserare(rad->dreapta,valoare,echilibru);
    else if(rad->info>valoare)
        rad->stanga= inserare(rad->stanga,valoare, echilibru);
    return rad;
}

void arboreAVL:: copiereArbore(arboreAVL & arbnou, nod_avl *radarbvechi)
{
    if(radarbvechi!=NULL)
    {
        arbnou.rad =arbnou.inserare(arbnou.rad,radarbvechi->info,radarbvechi->echilibru);
        copiereArbore( arbnou,radarbvechi->stanga);
        copiereArbore( arbnou,radarbvechi->dreapta);
    }
}

arboreAVL :: arboreAVL(const arboreAVL & a)
{
    this->rad =NULL;
    copiereArbore((*this),a.rad);
}

void arboreAVL :: stergere(nod_avl *& rad)
{
    if(rad!=NULL)
    {
        stergere(rad->stanga);
        stergere(rad->dreapta);
        delete rad;
        rad=NULL;
    }
}

arboreAVL & arboreAVL :: operator=(const arboreAVL & a)
{
    if(this==&a)
        return *this;
    else
    {
        stergere(this->rad);
        copiereArbore((*this),a.rad);
        return *this;
    }
}

void arboreAVL :: afisarersd(nod_avl *rad)
{
    if(rad==NULL)
        return;
    if(rad!=NULL)
    {
        cout<<rad->info<<" ";
        afisarersd(rad->stanga);
        afisarersd(rad->dreapta);
    }
}

void arboreAVL :: PuneEchilibru(nod_avl *rad)
{
    if(rad==NULL)
        return;
    if(rad!=NULL)
    {
        rad->calc_echilibru_nod(rad);
        rad->calc_echilibru_nod(rad->stanga);
        rad->calc_echilibru_nod(rad->dreapta);
    }
}

void arboreAVL :: AfisareEchilibru(nod_avl *rad)
{
    if(rad==NULL)
        return;
    if(rad!=NULL)
    {
        cout<<rad->get_echilibru()<<endl;
        AfisareEchilibru(rad->stanga);
        AfisareEchilibru(rad->dreapta);
    }
}

void arboreAVL :: rotatieSimplaDreapta(nod_avl * &pivot)
{
    nod_avl *FiuStanga = pivot->stanga;
    pivot->stanga = FiuStanga->dreapta;
    FiuStanga->dreapta = pivot;
    pivot->echilibru = 0;
    FiuStanga->echilibru = 0;
    pivot = FiuStanga;
}

void arboreAVL :: rotatieSimplaStanga(nod_avl * &pivot)
{
    nod_avl *FiuDreapta = pivot->dreapta;
    pivot->dreapta = FiuDreapta->stanga;
    FiuDreapta->stanga = pivot;
    pivot->echilibru = 0;
    FiuDreapta->echilibru = 0;
    pivot = FiuDreapta;
}

void arboreAVL::rotatieDublaDreapta(nod_avl * &pivot)
{
    nod_avl *fiuStanga, *fiuStanga_FiuDreapta;
    fiuStanga = pivot->stanga;
    fiuStanga_FiuDreapta = fiuStanga->dreapta;
//realizare rotatie 1 - simpla stanga
    fiuStanga->dreapta = fiuStanga_FiuDreapta->stanga;
    fiuStanga_FiuDreapta->stanga = fiuStanga;
//realizare rotatie 2 - simpla dreapta
    pivot->stanga = fiuStanga_FiuDreapta->dreapta;
    fiuStanga_FiuDreapta->dreapta = pivot;
//modificare grade de echilibru
    if(fiuStanga_FiuDreapta->echilibru == 1)
    {
        pivot->echilibru = 0;
        fiuStanga->echilibru = -1;
    }
    else if(fiuStanga_FiuDreapta->echilibru == 0)
    {
        pivot->echilibru = 0;
        fiuStanga->echilibru = 0;
    }
    else
    {
        pivot->echilibru = 1;
        fiuStanga->echilibru = 0;
    }

    fiuStanga_FiuDreapta->echilibru=0;
    pivot = fiuStanga_FiuDreapta;
}

void arboreAVL::rotatieDublaStanga(nod_avl * &pivot)
{
    nod_avl *fiuDreapta, *fiuDreapta_FiuStanga;
    fiuDreapta = pivot->dreapta;
    fiuDreapta_FiuStanga = fiuDreapta->stanga;
//realizare rotatie 1 - simpla stanga
    fiuDreapta->stanga = fiuDreapta_FiuStanga->dreapta;
    fiuDreapta_FiuStanga->dreapta = fiuDreapta;
//realizare rotatie 2 - simpla dreapta
    pivot->dreapta = fiuDreapta_FiuStanga->stanga;
    fiuDreapta_FiuStanga->stanga = pivot;  //de AICI
//modificare grade de echilibru
    if(fiuDreapta_FiuStanga->echilibru == 1)
    {
        pivot->echilibru = 0;
        fiuDreapta->echilibru = -1;
    }
    else if(fiuDreapta_FiuStanga->echilibru == 0)
    {
        pivot->echilibru = 0;
        fiuDreapta->echilibru = 0;
    }
    else
    {
        pivot->echilibru = 1;
        fiuDreapta->echilibru = 0;
    }

    fiuDreapta_FiuStanga->echilibru=0;
    pivot = fiuDreapta_FiuStanga;
}

void arboreAVL::RotatieSimplaDreaptaStergere(nod_avl * &pivot)
{
    nod_avl *FiuStanga = pivot->stanga;
    pivot->stanga = FiuStanga->dreapta;
    FiuStanga->dreapta = pivot;
    pivot->echilibru += 1;
    FiuStanga->echilibru  += 1;
    pivot = FiuStanga;
}
void arboreAVL::RotatieSimplaStangaStergere(nod_avl * &pivot)
{
    nod_avl *FiuDreapta = pivot->dreapta;
    pivot->dreapta = FiuDreapta->stanga;
    FiuDreapta->stanga = pivot;
    pivot->echilibru  -=1;
    FiuDreapta->echilibru -= 1;
    pivot = FiuDreapta;
}

void arboreAVL :: ReechilibrareSubarboreStang(nod_avl* &pivot, int
        &echilibruNou)
{
    nod_avl * FiuStanga = pivot->stanga;
    if(FiuStanga->echilibru == -1)
    {
        rotatieSimplaDreapta(pivot);
        echilibruNou = 0;
    }
    else if(FiuStanga->echilibru == 1)
    {
        rotatieDublaDreapta(pivot);
        echilibruNou = 0;
    }
    else
//situatie specifica operatiei de stergere
        if(FiuStanga->echilibru == 0)
        {
            RotatieSimplaDreaptaStergere(pivot);
            echilibruNou = 0;
        }
}

void arboreAVL :: ReechilibrareSubarboreDrept(nod_avl * &pivot, int
        &echilibruNou)
{
    nod_avl * FiuDreapta = pivot->dreapta;
    if(FiuDreapta->echilibru == 1)
    {
        rotatieSimplaStanga(pivot);
        echilibruNou = 0;
    }
    else if(FiuDreapta->echilibru == -1)
    {
        rotatieDublaStanga(pivot);
        echilibruNou = 0;
    }
    else
//situatie specifica operatiei de stergere
        if(FiuDreapta->echilibru == 0)
        {
            RotatieSimplaStangaStergere(pivot);
            echilibruNou = 0;
        }
}

void arboreAVL:: AVLInsert(nod_avl* &arbore,nod_avl * nodNou, int &
                           echilibruNou)
{
    int Reechilibrare;
    if(arbore == NULL)
    {
        arbore = nodNou;
        arbore->echilibru = 0;
        echilibruNou = 1;
    }
    else if(nodNou->info<arbore->info)
    {
        AVLInsert(arbore->stanga,nodNou,Reechilibrare);
        if(Reechilibrare)
        {
            if(arbore->echilibru == -1)

                ReechilibrareSubarboreStang(arbore,echilibruNou);
            else if(arbore->echilibru == 0)
            {
                arbore->echilibru = -1;
                echilibruNou = 1;
            }
            else
            {
                arbore->echilibru = 0;
                echilibruNou = 0;
            }
        }
        else
            echilibruNou = 0;
    }
    else
    {
        if(nodNou->info>arbore->info)
        {
            AVLInsert(arbore->dreapta, nodNou, Reechilibrare);
            if(Reechilibrare)
            {
                if(arbore->echilibru == -1)
                {
                    arbore->echilibru = 0;
                    echilibruNou = 0;
                }
                else if(arbore->echilibru == 0)
                {
                    arbore->echilibru = 1;
                    echilibruNou = 1;
                }
                else

                    ReechilibrareSubarboreDrept(arbore,echilibruNou);
            }
            else
                echilibruNou = 0;
        }
        else
            echilibruNou = 0;
    }
}
//CE AM FACUT CU DYNAMIC CAST SI N A MERS

/*

arboreAVL & arboreAVL :: operator=(const arboreAVL *& a)
{
 //   if(this==&a)
  //      return *this;
 //   else{
  //      stergere(this->rad);
  //      copiereArbore((*this),a->rad);
        return *this;
 //   }
}
arboreAVL :: arboreAVL(const arboreAVL & a)
{
    this->rad =NULL;
//    copiereArbore((*this),a.rad);
}

void arboreAVL:: copiereArbore(arboreAVL & arbnou, nod_avl *radarbvechi)
{
 if(radarbvechi!=NULL)
 {
    nod_avl * stanga=dynamic_cast <nod_avl*>(rad->st);
    nod_avl * dreapta=dynamic_cast <nod_avl*>(rad->dr);
 arbnou.rad =arbnou.inserare(arbnou.rad,radarbvechi->info,radarbvechi->echilibru);
 copiereArbore( arbnou,stanga);
 copiereArbore( arbnou,dreapta);
 }
}



void arboreAVL :: stergere(nod_avl *& rad)    //aici
{
    if(rad!=NULL)
    {
    nod_avl * stanga=dynamic_cast <nod_avl*>(rad->st);
    nod_avl * dreapta=dynamic_cast <nod_avl*>(rad->dr);
    stergere(stanga);
    stergere(dreapta);
    delete rad;
    rad=NULL;
    }
}


int arboreAVL :: inaltime(nod_avl * n)
{
        if(n==NULL)
        return 0;
    else {
        nod_avl * stanga= new nod_avl;
        nod_avl *dreapta =new nod_avl;
        stanga= dynamic_cast <nod_avl *>(n->st);
        dreapta= dynamic_cast <nod_avl *>(n->dr);
        int lh = inaltime(stanga);
        int dh = inaltime(dreapta);
        if(lh > dh)
            return (lh +1);
        else return (dh +1);
    }
}

int arboreAVL :: echilibru(nod *n)
{
        nod_avl * stanga= new nod_avl;
        nod_avl *dreapta =new nod_avl;
        stanga= dynamic_cast <nod_avl *>(n->st);
        dreapta= dynamic_cast <nod_avl *>(n->dr);
    return inaltime(dreapta)-inaltime(stanga);
}

void arboreAVL :: afiseaza_echilibru(nod * a)
{       nod_avl * stanga= new nod_avl;
        nod_avl *dreapta =new nod_avl;
        stanga= dynamic_cast <nod_avl *>(a->st);
        dreapta= dynamic_cast <nod_avl *>(a->dr);
    if(a==NULL)
        cout<<"Nod NULL "<<endl;
    else {
        cout<<a->calculECH(a)<<endl;
        afiseaza_echilibru(stanga);
        afiseaza_echilibru(dreapta);
    }
}

nod_avl * arboreAVL :: inserare(nod_avl *rad,int valoare, int echilibru)
{

    if(rad==NULL)
    {   cout<<"inauntru ";
        rad = new nod_avl(0,valoare,NULL,NULL);
 //       return rad;
    }
    cout<<"aici";
    if(rad->info<valoare)
    {nod_avl * dreapta=dynamic_cast <nod_avl*>(rad->dr);
             dreapta = inserare(dreapta,valoare,echilibru);}
    else if(rad->info>valoare)
             {nod_avl * stanga=dynamic_cast <nod_avl*>(rad->st);
             stanga = inserare(stanga,valoare, echilibru);}
    return rad;
}


void arboreAVL :: afisarersd(nod_avl *rad)
{
    if(rad==NULL)
        return;
    nod_avl * stanga=dynamic_cast <nod_avl*>(rad->st);
    nod_avl * dreapta=dynamic_cast <nod_avl*>(rad->dr);
    if(rad==NULL)
        return;
      cout<<rad->info<<" ";
      afisarersd(stanga);
      afisarersd(dreapta);

}
*/
