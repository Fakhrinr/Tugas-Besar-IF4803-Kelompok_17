// Toko.h
#ifndef TOKO_H_INCLUDED
#define TOKO_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

typedef string infotype;

// Forward declarations
struct elmProduk;
typedef elmProduk *addressC;

struct elmToko{
    infotype namaToko;
    infotype alamatToko;
    elmToko* nextT;
    addressC firstC;
};

typedef elmToko *addressP;

struct ListParent{
    addressP first;
};

void createListToko(ListParent &L);
addressP createElmToko(infotype nama, infotype alamat);
void insertFirstToko(ListParent &L, addressP P);
void insertLastToko(ListParent &L, addressP P);
void insertAfterToko(ListParent &L, addressP P, infotype prec);
void deleteFirstToko(ListParent &L);
void deleteLastToko(ListParent &L);
void deleteAfterToko(ListParent &L, infotype prev);
addressP searchToko(ListParent L, infotype namaToko);
void showAllToko(ListParent L);
int hitungTotalProduk(addressP P);
int hitungJumlahToko(ListParent L);

#endif // TOKO_H_INCLUDED
