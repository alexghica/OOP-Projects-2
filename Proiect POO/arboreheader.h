#ifndef ARBOREHEADER_H_INCLUDED
#define ARBOREHEADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class arbore      //clasa abstracta
{
protected:
    int nr_noduri;
public:
    arbore();
    arbore(int);
    virtual ~arbore();
    arbore(const arbore &);
    friend istream & operator>>(istream &,arbore &);
    friend ostream & operator<<(ostream &,arbore &);
    arbore & operator=(const arbore &);
    virtual int get_nr_noduri()=0;     //functia pura
};


#endif // ARBOREHEADER_H_INCLUDED
