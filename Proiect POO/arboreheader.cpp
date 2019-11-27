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

arbore :: arbore()
{
    nr_noduri=0;
}

arbore :: arbore(int x)
{
    nr_noduri=x;
}

arbore :: ~arbore()   //nu stiu ce pot sa i fac pt destructor, asa ca fac asta
{
    nr_noduri=0;
}

arbore :: arbore(const arbore &a)
{
    nr_noduri=a.nr_noduri;
}

ostream & operator<<(ostream & out,arbore & n)
{
    out<<"Numarul de noduri este: "<<n.nr_noduri<<endl;
    return out;
}

istream & operator>>(istream & in,arbore & n)
{
    cout<<"Introduceti numarul de noduri: ";
    in>>n.nr_noduri;
    return in;
}

arbore & arbore :: operator=(const arbore &a)
{
    if(this==&a)
        return *this;
    else
    {
        nr_noduri=a.nr_noduri;
        return *this;
    }
}
