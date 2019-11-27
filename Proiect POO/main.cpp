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


int main()
{

    arboreAVL i;

    nod_avl *h=new nod_avl(1,0,NULL,NULL);
    nod_avl *l=NULL;
    try{
        l=i.get_rad();
    }
    catch(const char * eroare)
    {
        cout<<eroare<<endl;
    }
    i.inserare(h,1,0);
    i.inserare(h,2,0);
    i.inserare(h,3,0);
    i.inserare(h,5,0);
    i.inserare(h,7,0);
    h->calc_echilibru_nod(h);
    cout<<h->get_echilibru()<<endl;

    i.afisarersd(h);
    cout<<endl;
    i.PuneEchilibru(h);
  //  i.AfisareEchilibru(h);
    cout<<"De aici. "<<endl;
    arboreAVL o;
    cin>>o;
    nod_avl *y=o.get_rad();
    o.afisarersd(y);
    cout<<o;
    cout<<endl;

     ABC a;
     cin>>a;
     cout<<a;
    return 0;
}
