#include "Toko.h"
#include <iostream>
using namespace std;

void createListToko(ListParent &L);
addressP createElmToko(infotype nama, infotype alamat);
void insertToko(ListParent &L, addressP P);
void deleteToko(ListParent &L, string namaToko);
addressP searchToko(ListParent L, string namaToko);
void showAllToko(ListParent L);
int hitungTotalKategoriProduk(addressP P, string kategori);
int hitungJumlahToko(ListParent L);