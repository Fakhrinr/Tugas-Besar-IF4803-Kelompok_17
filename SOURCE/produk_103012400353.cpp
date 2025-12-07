#include "Produk.h"
#include "Toko.h"
#include <iostream>
using namespace std;

void insertFirstProduk(addressP &P, addressC C) {
    if (P->firstC == NULL) {
        P->firstC = C;
        C->prev = NULL;
        C->next = NULL;
    } else {
        C->next = P->firstC;
        C->prev = NULL;
        P->firstC->prev = C;
        P->firstC = C;
    }
}

void insertLastProduk(addressP &P, addressC C) {
    if (P->firstC == NULL) {
        P->firstC = C;
        C->prev = NULL;
        C->next = NULL;
    } else {
        addressC last = P->firstC;
        while (last->next != NULL) {
            last = last->next;
        }
        C->prev = last;
        C->next = NULL;
        last->next = C;
    }
}

void insertAfterProduk(addressP &P, addressC C, infotype prev) {
    addressC prec = P->firstC;
    while (prec != NULL && prec->namaProduk != prev) {
        prec = prec->next;
    }
    
    if (prec == NULL) {
        cout << "Produk " << prev << " tidak ditemukan." << endl;
        return;
    }
    
    C->next = prec->next;
    C->prev = prec;
    
    if (prec->next != NULL) {
        prec->next->prev = C;
    }
    
    prec->next = C;
}

addressC searchProduk(addressP P, infotype namaProduk) {
    addressC Produk = P->firstC;
    
    while (Produk != NULL) {
        if (Produk->namaProduk == namaProduk) {
            return Produk;
        }
        Produk = Produk->next;
    }
    
    return NULL;
}

int hitungProdukKategori(addressP P, infotype kategori) {
    int Jumlah = 0;
    addressC Produk = P->firstC;
    
    while (Produk != NULL) {
        if (Produk->kategori == kategori) {
            Jumlah++;
        }
        Produk = Produk->next;
    }
    
    return Jumlah;
}

void showAllProduk(addressP P) {
    addressC Produk = P->firstC;
    
    if (Produk == NULL) {
        cout << "Tidak ada produk di toko " << P->namaToko << endl;
        return;
    }
    
    cout << "=== Daftar Produk Toko " << P->namaToko << " ===" << endl;
    cout << "Alamat: " << P->alamatToko << endl;
    cout << "--------------------------------------" << endl;
    
    int Jumlah = 1;
    while (Produk != NULL) {
        cout << Jumlah << ". " << Produk->namaProduk << endl;
        cout << "   Kategori: " << Produk->kategori << endl;
        cout << "   Pemasok: " << Produk->pemasok << endl;
        cout << "   Stok: " << Produk->stok << " unit" << endl;
        cout << "   Harga: Rp " << Produk->harga << endl;
        cout << "--------------------------------------" << endl;
        
        Produk = Produk->next;
        Jumlah++;
    }
}