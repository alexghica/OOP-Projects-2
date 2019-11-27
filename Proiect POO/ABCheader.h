#ifndef ABCHEADER_H_INCLUDED
#define ABCHEADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class ABC : public arbore
{
    nod *rad;
public:
    int get_nr_noduri();        //e pura in arbore
    ABC();
    ABC(int,nod *);
    virtual ~ABC();
    ABC(const ABC&);
    friend ostream & operator<<(ostream &,ABC &);
    friend istream & operator>>(istream &,ABC &);
    ABC & operator =(const ABC &);
    nod * get_rad();

    void inserare(nod *&,int );
    void copiere(ABC &, nod *);
    void stergere(nod *&);
    void rsd(nod *);
    void srd(nod *);

};

#endif // ABCHEADER_H_INCLUDED
