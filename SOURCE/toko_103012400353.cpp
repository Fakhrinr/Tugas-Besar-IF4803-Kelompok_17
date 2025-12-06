#include "Produk.h"
#include "Toko.h"
#include <iostream>
using namespace std;

addressP createElmToko(infotype nama, infotype alamat) {
    addressP TokoBaru = new elmToko;
    TokoBaru->namaToko = nama;
    TokoBaru->alamatToko = alamat;
    TokoBaru->nextT = NULL;
    TokoBaru->firstC = NULL;

    return TokoBaru;
};

void deleteFirstToko(ListParent &L) {
    if (L.first == NULL){
        cout << "kosong";
    }else{
        addressP P = L.first;
        L.first = P->nextT;
        P->nextT = NULL;
    };
};

void deleteLastToko(ListParent &L) {
    if (L.first == NULL) {
        cout << "kosong";
    } else if (L.first->nextT == NULL) {
        L.first = NULL;
    } else {
        addressP P = L.first;
        while (P->nextT->nextT != NULL) {
            P = P->nextT;
        }
        P->nextT = NULL;
    }
};

void deleteAfterToko(ListParent &L, string prev) {
    if (L.first == NULL) {
        cout << "kosong";
    } else {
        addressP P = L.first;
        
        while (P != NULL && P->namaToko != prev) {
            P = P->nextT;
        }
        
        if (P == NULL) {
            cout << "toko tidak ditemukan";
        } else if (P->nextT == NULL) {
            cout << "Toko tidak ditemukan";
        } else {
            addressP toDelete = P->nextT;
            P->nextT = toDelete->nextT;
            toDelete->nextT = NULL;
        }
    }
};


void showAllToko(ListParent L) {
    addressP Toko = L.first;
    
    if (Toko == NULL) {
        cout << "Tidak ada toko yang terdaftar." << endl;
        return;
    }
    
    cout << "=== DAFTAR TOKO INDOAPRIL ===" << endl;
    cout << "=============================" << endl;
    
    int Jumlah = 1;
    while (Toko != NULL) {
        cout << Jumlah << ". Nama Toko: " << Toko->namaToko << endl;
        cout << "   Alamat: " << Toko->alamatToko << endl;
        
        int jumlahProduk = 0;
        addressC produk = Toko->firstC;
        while (produk != NULL) {
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
    
    while (Toko != NULL) {
        jumlah++;
        Toko = Toko->nextT;
    }
    
    return jumlah;
};
