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
void insertToko(ListParent &L, addressP P);
void deleteToko(ListParent &L, string namaToko);
addressP searchToko(ListParent L, string namaToko);
void showAllToko(ListParent L);
int hitungTotalKategoriProduk(addressP P, string kategori);
int hitungJumlahToko(ListParent L);
#endif // TOKO_H_INCLUDED