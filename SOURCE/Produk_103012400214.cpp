// Produk_103012400214.cpp
#include "Toko.h"
#include "Produk.h"
#include <iostream>
using namespace std;

addressC createElmProduk(infotype nama, infotype pemasok, infotype kategori, int stok, int harga) {
    addressC C = new elmProduk;
    C->namaProduk = nama;
    C->pemasok = pemasok;
    C->kategori = kategori;
    C->stok = stok;
    C->harga = harga;
    C->next = nullptr;
    C->prev = nullptr;

    return C;
}

void deleteFirstProduk(addressP &P) {
    if (P->firstC == nullptr) {
        cout << "Tidak ada produk yang bisa dihapus" << endl;
    } else {
        addressC temp = P->firstC;
        P->firstC = temp->next;
        if (P->firstC != nullptr) {
            P->firstC->prev = nullptr;
        }
        delete temp;
        cout << "Produk pertama berhasil dihapus!" << endl;
    }
}

void deleteLastProduk(addressP &P) {
    if (P->firstC == nullptr) {
        cout << "Tidak ada produk yang bisa dihapus" << endl;
    } else if (P->firstC->next == nullptr) {
        deleteFirstProduk(P);
    } else {
        addressC temp = P->firstC;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
        cout << "Produk terakhir berhasil dihapus!" << endl;
    }
}

void deleteAfterProduk(addressP &P, infotype namaProduk) {
    if (P->firstC == nullptr) {
        cout << "Tidak ada produk yang bisa dihapus" << endl;
        return;
    }

    addressC temp = P->firstC;
    while (temp != nullptr && temp->namaProduk != namaProduk) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Produk " << namaProduk << " tidak ditemukan" << endl;
    } else if (temp->next == nullptr) {
        cout << "Tidak ada produk setelah " << namaProduk << endl;
    } else {
        addressC toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next != nullptr) {
            toDelete->next->prev = temp;
        }
        delete toDelete;
        cout << "Produk berhasil dihapus!" << endl;
    }
}

void searchProdukLowStock(addressP P, int Batasan) {
    addressC produk = P->firstC;
    cout << "Produk dengan stok kurang dari " << Batasan << " di toko " << P->namaToko << ":" << endl;

    bool found = false;
    while (produk != nullptr) {
        if (produk->stok < Batasan) {
            cout << "- " << produk->namaProduk << ", Stok: " << produk->stok << endl;
            found = true;
        }
        produk = produk->next;
    }

    if (!found) {
        cout << "Tidak ada produk dengan stok rendah" << endl;
    }
}

int hitungProdukLowStock(addressP P, int Batasan) {
    int jumlah = 0;
    addressC produk = P->firstC;

    while (produk != nullptr) {
        if (produk->stok < Batasan) {
            jumlah++;
        }
        produk = produk->next;
    }

    return jumlah;
}

void showProdukInfo(addressP P, infotype kategori) {
    addressC produk = P->firstC;
    cout << "\nProduk dengan kategori " << kategori << " di toko " << P->namaToko << ":" << endl;

    bool found = false;
    while (produk != nullptr) {
        if (produk->kategori == kategori) {
            cout << "- Nama Produk: " << produk->namaProduk << endl;
            cout << "  Kategori: " << produk->kategori << endl;
            cout << "  Pemasok: " << produk->pemasok << endl;
            cout << "  Stok: " << produk->stok << endl;
            cout << "  Harga: Rp " << produk->harga << endl;
            cout << "  -------------------------" << endl;
            found = true;
        }
        produk = produk->next;
    }

    if (!found) {
        cout << "Tidak ada produk dengan kategori " << kategori << endl;
    }
}
