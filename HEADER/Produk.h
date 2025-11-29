#include <iostream>
using namespace std;

typedef struct elmToko *addressP;
typedef struct produk *addressC;
typedef string infotype;
struct produk{
    infotype namaProduk;
    infotype kategori;
    infotype pemasok;
    int stok;
    int harga;
    addressC nextC;
    addressC prevC;
    addressP nextCP;
};

typedef struct ListChild{
    addressC first;
};

void createListProduk(ListChild &L);
addressC createElmProduk(infotype nama,infotype pemasok, infotype kategori, int stok, int harga);
void insertProduk(ListChild &L, addressC P);
void deleteProduk(ListChild &L, infotype kodeProduk);
addressC searchProduk(ListChild L, infotype kodeProduk);
void searchProdukLowStock(ListChild L, int Batasan);
int hitungProdukKategori(ListChild L, infotype kategori);
int hitungProdukLowStock(ListChild L, int Batasan);    
void showAllProduk(ListChild L);
void showProdukInfo(addressC P);
