#ifndef NODHEADER_H_INCLUDED
#define NODHEADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class nod
{
protected:
    int info;
    nod *st;
    nod *dr;
public:
    nod();
    nod(int);
    nod(int,nod*,nod*);
    virtual ~nod();
    friend class arboreAVL;
    friend class arbore;
    friend class ABC;
    int get_info();
    void set_info(int);
    nod(const nod& );
    friend ostream & operator<<(ostream &,nod &);
    friend istream & operator>>(istream &,nod &);
    friend istream & operator>>(istream &,nod *&);
    friend ostream & operator<<(ostream &,nod *&);
    nod & operator =(const nod &);
    void set_st(nod *);
    void set_dr(nod *);
    nod * get_st();
    nod * get_dr();

    int calculECH(nod*);
    int inaltime(nod *);
};

#endif // NODHEADER_H_INCLUDED
