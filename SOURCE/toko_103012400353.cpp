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
};

void deleteFirstToko(ListParent &L) {
    if (L.first == nullptr){
        cout << "kosong";
    }else{
        addressP P = L.first;
        L.first = P->nextT;
        P->nextT = nullptr;
    };
};

void deleteLastToko(ListParent &L) {
    if (L.first == nullptr) {
        cout << "kosong";
    } else if (L.first->nextT == nullptr) {
        L.first = nullptr;
    } else {
        addressP P = L.first;
        while (P->nextT->nextT != nullptr) {
            P = P->nextT;
        }
        P->nextT = nullptr;
    }
};

void deleteAfterToko(ListParent &L, string prev) {
    if (L.first == nullptr) {
        cout << "kosong";
    } else {
        addressP P = L.first;
        
        while (P != nullptr && P->namaToko != prev) {
            P = P->nextT;
        }
        
        if (P == nullptr) {
            cout << "toko tidak ditemukan";
        } else if (P->nextT == nullptr) {
            cout << "Toko tidak ditemukan";
        } else {
            addressP toDelete = P->nextT;
            P->nextT = toDelete->nextT;
            toDelete->nextT = nullptr;
        }
    }
};


void showAllToko(ListParent L) {
    addressP Toko = L.first;
    
    if (Toko == nullptr) {
        cout << "Tidak ada toko yang terdaftar." << endl;
        return;
    }
    
    cout << "=== DAFTAR TOKO INDOAPRIL ===" << endl;
    cout << "=============================" << endl;
    
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
};

int hitungJumlahToko(ListParent L) {
    int jumlah = 0;
    addressP Toko = L.first;
    
    while (Toko != nullptr) {
        jumlah++;
        Toko = Toko->nextT;
    }
    
    return jumlah;
};
