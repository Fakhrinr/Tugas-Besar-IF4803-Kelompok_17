#include <iostream>
using namespace std;

typedef struct elmToko *addressP;
typedef struct produk *addressC;

struct produk{
    string namaProduk;
    string kodeProduk;
    string kategori;
    string pemasok;
    int stok;
    int harga;
    addressC nextC;
    addressP nextCP;
};

typedef struct ListChild{
    addressC first;
};

void createListProduk(ListChild &L);
addressC createElmProduk(string nama, string kode, string kategori, int stok, int harga);
void insertProduk(ListChild &L, addressC P);
void deleteProduk(ListChild &L, string kodeProduk);
addressC searchProduk(ListChild L, string kodeProduk);
void searchProdukLowStock(ListChild L, int Batasan);
int hitungProdukKategori(ListChild L, string kategori);
int hitungProdukLowStock(ListChild L, int Batasan);    
void showAllProduk(ListChild L);
void showProdukInfo(addressC P);
