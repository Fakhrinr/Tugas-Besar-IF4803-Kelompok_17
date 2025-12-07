#include "Toko.h"
#include "Produk.h"
#include <iostream>
using namespace std;


addressC createElmProduk(infotype nama,infotype pemasok, infotype kategori, int stok, int harga){
    addressC C;
    C = new elmProduk;
    C->namaProduk = nama;
    C->pemasok = pemasok;
    C->kategori = kategori;
    C->stok = stok;
    C->harga = harga;
    C->next = nullptr;
    C->prev = nullptr;

    return C;
}

void deleteFirstProduk(addressP &P){
    addressC temp;
    temp = P->firstC;
    if(P->firstC == nullptr){
        cout << "Tidak ada yang bisa dihapus";
    }else if(temp ->next == nullptr){
        P->firstC = nullptr;
    }else{
        temp = P->firstC;
        P->firstC = P->firstC->next;
        P->firstC->prev = nullptr;
    }
}

void deleteLastProduk(addressP &P){
    addressC temp;
    if(P->firstC == nullptr){
        cout << "Tidak ada yang bisa dihapus";
    }else if(temp ->next == nullptr){
        P->firstC = nullptr;
    }else{
        temp = P->firstC;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        temp->prev = nullptr;
    }
}

//List tidak mungkin Kosong
void deleteAfterProduk(addressP &P, addressC namaProduk){
    addressC temp;
    temp = P->firstC;
    while(temp->next != namaProduk){
        temp = temp->next;
    }
    temp->next = namaProduk->next;
    namaProduk->next->prev = temp;
}

void searchProdukLowStock(addressP P, int Batasan){
    addressC produk;
    produk = P->firstC;
    cout << "Produk dengan stok kurang dari" << Batasan << " di toko"<< P->namaToko << endl;
    while(produk != nullptr){
        if(produk->stok < Batasan){
            cout << "Nama Produk: " << produk->namaProduk << ", Stok: " << produk->stok << endl;
        }
        produk = produk->next;
    }
}

int hitungProdukLowStock(addressP P, int Batasan){
    int jumlah = 0;
    addressC produk;
    produk = P->firstC;
    while(produk != nullptr){
        if(produk->stok < Batasan){
            jumlah = jumlah +1;
        }
        produk = produk->next;
    }
    return jumlah;
}

//menampilkan data produk berdasarkan kategori
void showProdukInfo(addressP P, infotype kategori){
    addressC produk;
    produk = P->firstC;
    cout << "Produk dengan kategori " << kategori << " di toko " << P->namaToko << endl;
    while(produk != nullptr){
        if(produk->kategori == kategori){
            cout << "Nama Produk:" << produk->namaProduk << ", Kategori: " << produk->kategori << ", Pemasok: " << produk->pemasok << ", Stok: " << produk->stok << ", Harga: " << produk->harga << endl;
        }
    }
    produk = produk->next;
}