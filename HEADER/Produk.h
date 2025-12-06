#ifndef PRODUK_H_INCLUDED
#define PRODUK_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elmToko *addressP;
typedef struct elmProduk *addressC;
typedef string infotype;

struct elmProduk{
    infotype namaProduk;
    infotype kategori;
    infotype pemasok;
    int stok;
    int harga;

    addressC next;
    addressC prev;
};

addressC createElmProduk(infotype nama,infotype pemasok, infotype kategori, int stok, int harga);
void insertProduk(addressP &P, addressC C);
void deleteProduk(addressP &P, infotype namaProduk);
addressC searchProduk(addressP P, infotype namaProduk);
void searchProdukLowStock(addressP P, int Batasan);
int hitungProdukKategori(addressP P, infotype kategori);
int hitungProdukLowStock(addressP P, int Batasan);    
void showAllProduk(addressP P);
void showProdukInfo(addressP P);

#endif // PRODUK_H_INCLUDED