#ifndef NODAVLHEADER_H_INCLUDED
#define NODAVLHEADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>


using namespace std;

class nod_avl : public nod
{
private:
    int echilibru;
    nod_avl *stanga;
    nod_avl *dreapta;
public:
    nod_avl();
    nod_avl(int);
    nod_avl(int, int);
    nod_avl(int,int,nod_avl *,nod_avl*);
    int get_echilibru();
    virtual ~nod_avl();
    friend class arboreAVL;
    friend class ABC;
    friend class arbore;
    nod_avl(const nod_avl &);
    friend ostream & operator<<(ostream &,nod_avl &);
    friend istream & operator>>(istream &,nod_avl &);
    friend ostream & operator<<(ostream &,nod_avl *&);
    friend istream & operator>>(istream &,nod_avl *&);
    nod_avl & operator =(const nod_avl&);
    virtual int get_info();
    virtual void set_info(int);
    virtual nod_avl * get_st();
    virtual nod_avl * get_dr();
    virtual void set_st(nod_avl *);
    virtual void set_dr(nod_avl *);
    void calc_echilibru_nod(nod_avl *);
    int inaltime_nod(nod_avl *);

};

#endif // NODAVLHEADER_H_INCLUDED
