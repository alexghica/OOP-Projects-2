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

int ABC :: get_nr_noduri()
{
    return nr_noduri;
}

ABC :: ABC()
{
    rad=NULL;
    nr_noduri=0;
}

ABC :: ABC(int i,nod *n): arbore(i),rad(n) {}    //transmiterea in clasa baza

ABC :: ~ABC()
{
    delete rad;
    rad=NULL;
}

nod * ABC :: get_rad()
{
    return rad;
}

ABC :: ABC(const ABC &a)
{
    nr_noduri=a.nr_noduri;
    rad=a.rad;
}

ostream & operator<<(ostream & out,ABC &a)
{
    out<<"Numarul de noduri este: ";
    out<<a.nr_noduri<<endl;
         if(a.rad!=NULL)
    {
        out<<a.rad->get_info()<<" ";
        a.rsd(a.rad->get_st());
        a.rsd(a.rad->get_dr());
    }
    return out;
}

istream & operator>>(istream &in,ABC &a)
{
    int val,i;
    cout<<"Introduceti numarul de noduri: ";
    in>>a.nr_noduri;
    for(i=0;i<a.nr_noduri;i++)
    {
        cout<<"Introduceti valoarea nodului: ";
        in>>val;
        a.inserare(a.rad,val);
    }
    return in;
}

void ABC :: copiere(ABC & arbnou, nod * radveche)
{
    inserare(arbnou.rad, radveche->info);
    copiere(arbnou,radveche->st);
    copiere(arbnou,radveche->dr);
}

void ABC :: stergere(nod *& rad)
{
    if(rad!=NULL)
    {
        stergere(rad->st);
        stergere(rad->dr);
        delete rad;
        rad=NULL;
    }
}

void ABC :: inserare (nod *& rad, int x)
{
        if(rad==NULL)
    {
        rad = new nod;
        rad->info=x;
        rad->st=NULL;
        rad->dr=NULL;
    }
    else
    {
        if(x<rad->info)
            inserare(rad->st,x);
        if(x>rad->info)
            inserare(rad->dr,x);
    }
}

ABC & ABC :: operator=(const ABC & a)
{
    if(this==&a)
        return *this;
    else
    {
        stergere(this->rad);
        copiere((*this),a.rad);
        return *this;
    }
}

void ABC :: rsd(nod *rad)
{
     if(rad!=NULL)
    {
        cout<<rad->info<<" ";
        rsd(rad->st);
        rsd(rad->dr);
    }
}

void ABC :: srd(nod *rad)
{
        if(rad!=NULL)
    {

        srd(rad->st);
        cout<<rad->info<<" ";
        srd(rad->dr);
    }
}
