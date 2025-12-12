// Toko_103012400214.cpp
#include "Toko.h"
#include "Produk.h"
#include <iostream>
using namespace std;

void createListToko(ListParent &L){
    L.first = nullptr;
}

void insertFirstToko(ListParent &L, addressP P){
    if (L.first == nullptr){
        L.first = P;
        P->nextT = nullptr;
    } else {
        P->nextT = L.first;
        L.first = P;
    }
}

void insertLastToko(ListParent &L, addressP P){
    if(L.first == nullptr){
        L.first = P;
        P->nextT = nullptr;
    } else {
        addressP Q = L.first;
        while(Q->nextT != nullptr){
            Q = Q->nextT;
        }
        Q->nextT = P;
        P->nextT = nullptr;
    }
}

void insertAfterToko(ListParent &L, addressP P, infotype prec){
    if (L.first == nullptr) {
        cout << "Tidak ada toko dalam list!" << endl;
        return;
    }

    addressP Q = searchToko(L, prec);

    if(Q == nullptr){
        cout << "Toko " << prec << " tidak ditemukan" << endl;
    } else {
        P->nextT = Q->nextT;
        Q->nextT = P;
        cout << "Toko berhasil ditambahkan setelah " << prec << endl;
    }
}

addressP searchToko(ListParent L, infotype namaToko){
    addressP cari = L.first;

    while(cari != nullptr){
        if(cari->namaToko == namaToko){
            return cari;
        }
        cari = cari->nextT;
    }
    return nullptr;
}

int hitungTotalProduk(addressP P){
    int total = 0;
    addressC Child = P->firstC;

    while(Child != nullptr){
        total++;
        Child = Child->next;
    }
    return total;
}
