#ifndef ARBOREAVLHEADER_H_INCLUDED
#define ARBOREAVLHEADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class arboreAVL : public arbore
{
    nod_avl *rad;
public:
    arboreAVL();
    arboreAVL(int,nod_avl *);
    ~arboreAVL();
    arboreAVL(const arboreAVL &);
    virtual int get_nr_noduri();
    friend ostream & operator<<(ostream &,arboreAVL &);
    friend istream & operator>>(istream &,arboreAVL &);
    arboreAVL & operator =(const arboreAVL &);
    int max(int,int);
    void set_rad(nod_avl *);
    nod_avl * get_rad();
    int get_echilibru(nod_avl *);
    void PuneEchilibru(nod_avl *);
    void AfisareEchilibru(nod_avl *);

    nod_avl *inserare(nod_avl *,int,int);
    void copiereArbore(arboreAVL &, nod_avl *);
    void stergere(nod_avl *&);
    void afisarersd(nod_avl *);

    void rotatieSimplaDreapta(nod_avl *&);
    void rotatieSimplaStanga(nod_avl *&);
    void rotatieDublaDreapta(nod_avl *&);
    void rotatieDublaStanga(nod_avl *&);
    void RotatieSimplaDreaptaStergere(nod_avl *&);
    void RotatieSimplaStangaStergere(nod_avl *&);
    void ReechilibrareSubarboreStang(nod_avl *&, int &);
    void ReechilibrareSubarboreDrept(nod_avl *&, int &);
    void AVLInsert(nod_avl *&,nod_avl*,int &);

 /*   nod_avl * inserare(nod_avl *,int, int);
    void afisarersd(nod_avl *);
    void copiereArbore(arboreAVL &, nod_avl *);
    void stergere(nod_avl *&);
    int echilibru(nod *);
    int inaltime(nod_avl *);
    void afiseaza_echilibru(nod *);
*/

};


#endif // ARBOREAVLHEADER_H_INCLUDED
