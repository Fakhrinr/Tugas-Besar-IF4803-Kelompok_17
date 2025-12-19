// toko_103012400353.cpp
#include "Produk.h"
#include "Toko.h"
#include <iostream>
using namespace std;

addressP createElmToko(infotype nama, infotype alamat) {
    addressP TokoBaru = new elmToko;
    TokoBaru->namaToko = nama;
    TokoBaru->alamatToko = alamat;
    TokoBaru->nextT = nullptr;
    TokoBaru->firstC = nullptr;

    return TokoBaru;
}

void deleteFirstToko(ListParent &L) {
    if (L.first == nullptr) {
        cout << "Tidak ada toko yang dapat dihapus!" << endl;
    } else {
        addressP P = L.first;
        L.first = P->nextT;

        addressC produk = P->firstC;
        while (produk != nullptr) {
            addressC temp = produk;
            produk = produk->next;
            delete temp;
        }

        delete P;
        cout << "Toko pertama berhasil dihapus!" << endl;
    }
}

void deleteLastToko(ListParent &L) {
    if (L.first == nullptr) {
        cout << "Tidak ada toko yang dapat dihapus!" << endl;
    } else if (L.first->nextT == nullptr) {
        deleteFirstToko(L);
    } else {
        addressP P = L.first;
        while (P->nextT->nextT != nullptr) {
            P = P->nextT;
        }

        addressP last = P->nextT;
        addressC produk = last->firstC;
        while (produk != nullptr) {
            addressC temp = produk;
            produk = produk->next;
            delete temp;
        }

        delete last;
        P->nextT = nullptr;
        cout << "Toko terakhir berhasil dihapus!" << endl;
    }
}

void deleteAfterToko(ListParent &L, infotype prev) {
    if (L.first == nullptr) {
        cout << "Tidak ada toko!" << endl;
        return;
    }

    addressP P = L.first;
    while (P != nullptr && P->namaToko != prev) {
        P = P->nextT;
    }

    if (P == nullptr || P->nextT == nullptr) {
        cout << "Toko " << prev << " tidak ditemukan atau tidak ada toko setelahnya!" << endl;
    } else {
        addressP toDelete = P->nextT;

        addressC produk = toDelete->firstC;
        while (produk != nullptr) {
            addressC temp = produk;
            produk = produk->next;
            delete temp;
        }

        P->nextT = toDelete->nextT;
        delete toDelete;
        cout << "Toko berhasil dihapus!" << endl;
    }
}

void showAllToko(ListParent L) {
    addressP Toko = L.first;

    if (Toko == nullptr) {
        cout << "Tidak ada toko yang terdaftar." << endl;
        return;
    }

    cout << "\n======= DAFTAR TOKO  =======" << endl;
    cout << "==============================" << endl;

    int Jumlah = 1;
    while (Toko != nullptr) {
        cout << Jumlah << ". Nama Toko: " << Toko->namaToko << endl;
        cout << "   Alamat: " << Toko->alamatToko << endl;

        int jumlahProduk = 0;
        addressC produk = Toko->firstC;
        while (produk != nullptr) {
            jumlahProduk++;
            produk = produk->next;
        }

        cout << "   Jumlah Produk: " << jumlahProduk << endl;
        cout << "------------------------------" << endl;

        Toko = Toko->nextT;
        Jumlah++;
    }
}

int hitungJumlahToko(ListParent L) {
    int jumlah = 0;
    addressP Toko = L.first;

    while (Toko != nullptr) {
        jumlah++;
        Toko = Toko->nextT;
    }

    return jumlah;
}
