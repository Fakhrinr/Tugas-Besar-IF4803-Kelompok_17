#ifndef TOKO_H_INCLUDED
#define TOKO_H_INCLUDED
#include <iostream>
using namespace std;

typedef string infotype;
typedef struct elmProduk *addressC;
typedef elmToko *addressP;

typedef struct elmToko{
    infotype namaToko;
    infotype alamatToko;
    addressP nextT;
    addressC firstC;
};
typedef struct ListParent{
    addressP first;
};

void createListToko(ListParent &L);
addressP createElmToko(infotype nama, infotype alamat);
void insertFirstToko(ListParent &L, addressP P);
void insertLastToko(ListParent &L, addressP P);
void insertAfterToko(ListParent &L, addressP P, infotype prec);
void deleteFirstToko(ListParent &L);
void deleteLastToko(ListParent &L);
void deleteAfterToko(ListParent &L, string prev);
addressP searchToko(ListParent L, string namaToko);
void showAllToko(ListParent L);
int hitungTotalProduk(addressP P);
int hitungJumlahToko(ListParent L);
#endif // TOKO_H_INCLUDED