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
    }else{
        P->nextT = L.first;
        L.first = P;
    }
}

void insertLastToko(ListParent &L, addressP P){
    addressP Q;
    if(L.first == nullptr){
        L.first = P;
    }else{
        Q = L.first;
        while(Q->nextT != nullptr){
            Q = Q->nextT;
        }
        Q->nextT = P;
    }
}

void insertAfterToko(ListParent &L, addressP P,addressP prec){//List sudah dipastikan tidak kosong
    if(prec != nullptr){
        P->nextT = prec->nextT;
        prec->nextT = P;
    }
}

addressP searchToko(ListParent L, string namaToko){
    addressP cari;
    cari = L.first;
    if(cari == nullptr){
        return nullptr;
    }else{
        while(cari != nullptr){
            if(cari->namaToko == namaToko){
                return cari;
            }
        }
    }
}

int hitungTotalProduk(addressP P){
    int total = 0;
    addressC Child;
    Child = P->firstC;

    while(Child != nullptr){
        total = total + 1;
        Child = Child->next;   
    }
    return total;
}

