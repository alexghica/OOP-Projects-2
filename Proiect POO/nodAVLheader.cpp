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
nod_avl :: nod_avl()
{
    echilibru=0;
    info=0;
    stanga=NULL;
    dreapta=NULL;
}
nod_avl :: nod_avl(int i) : nod(i,NULL,NULL) //pt transmitere in clasa de baza. asta e absolut useless si in plus
{
    echilibru=i;
    stanga=NULL;
    dreapta=NULL;
}

nod_avl :: nod_avl(int i,int j){                //pt transmitere in clasa de baza
        stanga=NULL;
        dreapta=NULL;
        info=i;
        echilibru=j;
}

nod_avl :: nod_avl(int i,int j, nod_avl *st,nod_avl *dr)
{
    echilibru=j;
    info=i;
    stanga=st;
    dreapta=dr;
}

nod_avl ::~nod_avl()
{
    stanga=NULL;
    dreapta=NULL;
    info=0;
    echilibru=0;
}

nod_avl :: nod_avl(const nod_avl & n)
{
    stanga=n.stanga;
    dreapta=n.dreapta;
    info=n.info;
    echilibru=n.echilibru;
}

ostream & operator <<(ostream & out,nod_avl &n)  //pt nod normal
{
    out<<"Info= "<<n.info<<endl;
    out<<"Echilibru= "<<n.echilibru<<endl;
    return out;
}

ostream & operator <<(ostream & out,nod_avl *&n)   //pt pointer
{
    out<<"Info= "<<n->info<<endl;
    out<<"Echilibru= "<<n->echilibru<<endl;
    return out;
}

istream & operator >>(istream & in, nod_avl &n)
{
    cout<<"Introduceti info: ";
    in>>n.info;
    cout<<"Introduceti echilibru: ";
    in>>n.echilibru;
    return in;
}

istream & operator >>(istream & in, nod_avl *&n)
{
    cout<<"Introduceti info: ";
    in>>n->info;
    cout<<"Introduceti echilibru: ";
    in>>n->echilibru;
    return in;
}

nod_avl & nod_avl :: operator =(const nod_avl &n)
{
    if(this==&n)
        return *this;
    else{
    delete stanga;
    delete dreapta;
    stanga= new nod_avl;
    dreapta = new nod_avl;
    info=n.info;
    echilibru=n.echilibru;
    stanga=n.stanga;
    dreapta=n.dreapta;
    return *this;
    }
}

int nod_avl :: get_info()     //pt functii virtuale
{
    return info;
}

void nod_avl :: set_info(int x)     //pt functii virtuale
{
    info=x;
}

void nod_avl :: set_st(nod_avl *n)
{
    this->stanga=n;
}

void nod_avl :: set_dr(nod_avl *n)
{
    this->dreapta=n;
}

int nod_avl :: get_echilibru()
{
    return echilibru;
}

nod_avl * nod_avl :: get_st()
{
    return stanga;
}

nod_avl * nod_avl :: get_dr()
{
    return dreapta;
}


void  nod_avl :: calc_echilibru_nod(nod_avl *rad)
{
    if(rad==NULL)
        return;
    rad->echilibru=inaltime_nod(rad->stanga)-inaltime_nod(rad->dreapta);
}

int nod_avl :: inaltime_nod(nod_avl * n)
{
    if(n==NULL)
        return 0;
    else
    {
        int lh = inaltime_nod(n->stanga);
        int dh = inaltime_nod(n->dreapta);
        if(lh > dh)
            return (lh +1);
        else
            return (dh +1);
    }
}
