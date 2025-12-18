// produk_103012400353.cpp
#include "Produk.h"
#include "Toko.h"
#include <iostream>
using namespace std;

void insertFirstProduk(addressP &P, addressC C) {
    if (P->firstC == nullptr) {
        P->firstC = C;
        C->prev = nullptr;
        C->next = nullptr;
    }else {
    addressC existing = searchProduk(P, C->namaProduk);

        if (existing != nullptr) {
            existing->stok += C->stok;
            cout << "Produk " << C->namaProduk << " sudah ada. Stok ditambahkan!" << endl;
            cout << "Stok sekarang: " << existing->stok << " unit" << endl;
            delete C;
    }else {
            C->next = P->firstC;
            C->prev = nullptr;
            P->firstC->prev = C;
            P->firstC = C;
        }
    }
}

void insertLastProduk(addressP &P, addressC C) {
if (P->firstC == nullptr) {
        P->firstC = C;
        C->prev = nullptr;
        C->next = nullptr;
    } else {
        addressC existing = searchProduk(P, C->namaProduk);

        if (existing != nullptr) {
            existing->stok += C->stok;
            cout << "" << endl;
            cout << "Produk " << C->namaProduk << " sudah ada. Stok ditambahkan!" << endl;
            cout << "Stok " << C->namaProduk << " sekarang: " << existing->stok << endl;

            delete C;
        } else {
            addressC last = P->firstC;
            while (last->next != nullptr) {
                last = last->next;
            }
            C->prev = last;
            C->next = nullptr;
            last->next = C;        }
    }
}

void insertAfterProduk(addressP &P, addressC C, infotype prev) {
    if (P->firstC == nullptr) {
        cout << "Tidak ada produk di toko ini!" << endl;
        return;
    }

    addressC prec = P->firstC;
    while (prec != nullptr && prec->namaProduk != prev) {
        prec = prec->next;
    }

    if (prec == nullptr) {
        cout << "Produk " << prev << " tidak ditemukan." << endl;
        return;
    }

    C->next = prec->next;
    C->prev = prec;

    if (prec->next != nullptr) {
        prec->next->prev = C;
    }

    prec->next = C;
}

addressC searchProduk(addressP P, infotype namaProduk) {
    addressC Produk = P->firstC;

    while (Produk != nullptr) {
        if (Produk->namaProduk == namaProduk) {
            return Produk;
        }
        Produk = Produk->next;
    }

    return nullptr;
}

int hitungProdukKategori(addressP P, infotype kategori) {
    int Jumlah = 0;
    addressC Produk = P->firstC;

    while (Produk != nullptr) {
        if (Produk->kategori == kategori) {
            Jumlah++;
        }
        Produk = Produk->next;
    }

    return Jumlah;
}

void showAllProduk(addressP P) {
    addressC Produk = P->firstC;

    if (Produk == nullptr) {
        cout << "Tidak ada produk di toko " << P->namaToko << endl;
        return;
    }

    cout << "\n=== Daftar Produk Toko " << P->namaToko << " ===" << endl;
    cout << "Alamat: " << P->alamatToko << endl;
    cout << "--------------------------------------" << endl;

    int Jumlah = 1;
    while (Produk != nullptr) {
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
