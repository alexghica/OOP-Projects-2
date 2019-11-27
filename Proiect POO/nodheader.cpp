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

nod :: nod()
{
    info=0;
    st=NULL;
    dr=NULL;
}

nod::nod(int i)
{
    st=NULL;
    dr=NULL;
    info=i;
}

nod :: nod(int inf,nod *a, nod *b) : info(inf),st(a),dr(b) {}

nod :: nod(const nod &n)      // ar trb copiat tot arborele
{
    info = n.info;
    st=n.st;
    dr=n.dr;
}

nod :: ~nod()
{
    delete st;
    delete dr;
    st=NULL;
    dr=NULL;
    info=0;
}

ostream & operator <<(ostream &out,nod &n) //pt nod normal
{
    out<<"Nodul este egal cu: ";
    out<<n.info<<endl;
    return out;
}

ostream & operator <<(ostream &out,nod *&n)   //pt pointer
{
    out<<"Nodul este egal cu: ";
    out<<n->info<<endl;
    return out;
}

istream & operator >>(istream &in,nod &n)   //pt nod normal
{
    int inf;
    cout<<"Introduceti info:"<<endl;
    in>>inf;
    n.info=inf;
    return in;
}

istream & operator >>(istream &in,nod *&n)   //pt pointer
{
    int inf;
    cout<<"Introduceti info:"<<endl;
    in>>inf;
    n->info=inf;
    return in;
}

nod & nod :: operator = (const nod & n)
{
    if(this==&n)
        return *this;
    else
    {
        delete  st;
        delete  dr;
        st=new nod;
        dr=new nod;
        info = n.info;
        st=n.st;
        dr=n.dr;
        return *this;
    }
}

void nod :: set_st(nod *n)
{
    st=n;
}

void nod :: set_dr(nod *n)
{
    dr=n;
}

int nod :: get_info()
{
    return info;
}

void nod :: set_info(int x)
{
    info=x;
}

nod * nod :: get_st()
{
    return st;
}

nod * nod :: get_dr()
{
    return dr;
}

int nod :: calculECH(nod *n)
{
    return inaltime(n->dr)-inaltime(n->st);
}

int nod :: inaltime(nod * n)
{
    if(n==NULL)
        return 0;
    else
    {
        int lh = inaltime(n->st);
        int dh = inaltime(n->dr);
        if(lh > dh)
            return (lh +1);
        else
            return (dh +1);
    }
}

