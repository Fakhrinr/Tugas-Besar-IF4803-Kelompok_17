// main_user.cpp
#include "Toko.h"
#include "Produk.h"
#include <iostream>
using namespace std;

void mainUser(ListParent &L) {
    int pilihan = -1;

    while (pilihan != 0) {
        cout << "\n=== MENU PRODUK ===" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Lihat Semua Toko" << endl;
        cout << "3. Lihat Produk di Toko" << endl;
        cout << "4. Cari Produk Berdasarkan Kategori" << endl;
        cout << "5. Cari Produk" << endl;
        cout << "6. Hitung Total Produk di Toko" << endl;
        cout << "7. Hitung Produk Berdasarkan Kategori" << endl;
        cout << "8. Cek Produk Stok Rendah" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        string nama, alamat, pemasok, kategori, namaToko, namaProduk;

         if (pilihan == 1) {
            cout << "\n--- Tambah Produk ---" << endl;
            cout <<"Nama Toko: ";
            cin >> namaToko;

            addressP toko = searchToko(L, namaToko);
            if (toko == nullptr) {
                cout << "Toko tidak ditemukan!" << endl;
            } else {
                int stok, harga;

                cout << "Nama Produk: ";
                cin >> nama;
                cout << "Pemasok: ";
                cin >> pemasok;
                cout << "Kategori: ";
                cin >> kategori;
                cout << "Stok: ";
                cin >> stok;
                cout << "Harga: ";
                cin >> harga;

                addressC produkBaru = createElmProduk(nama, pemasok, kategori, stok, harga);
                insertLastProduk(toko, produkBaru);
                cout << "Produk berhasil ditambahkan!" << endl;
            }

        } else if (pilihan == 2) {
            cout << "\n";
            showAllToko(L);

        } else if (pilihan == 3) {
            cout << "\n--- Lihat Produk di Toko ---" << endl;
            cout << "Nama Toko: ";
            cin >> namaToko;

            addressP toko = searchToko(L, namaToko);
            if (toko == nullptr) {
                cout << "Toko tidak ditemukan!" << endl;
            } else {
                showAllProduk(toko);
            }

        } else if (pilihan == 4) {
            cout << "\n--- Cari Produk Berdasarkan Kategori ---" << endl;
            cout << "Nama Toko: ";
            cin >> namaToko;
            cout << "Kategori: ";
            cin >> kategori;

            addressP toko = searchToko(L, namaToko);
            if (toko == nullptr) {
                cout << "Toko tidak ditemukan!" << endl;
            } else {
                // PERBAIKAN DI SINI: tambahkan parameter kategori
                showProdukInfo(toko, kategori);
            }

        } else if (pilihan == 5) {
            cout << "\n--- Cari Produk ---" << endl;
            cout << "Nama Toko: ";
            cin >> namaToko;
            cout << "Nama Produk: ";
            cin >> namaProduk;

            addressP toko = searchToko(L, namaToko);
            if (toko == nullptr) {
                cout << "Toko tidak ditemukan!" << endl;
            } else {
                addressC produk = searchProduk(toko, namaProduk);
                if (produk == nullptr) {
                    cout << "Produk tidak ditemukan!" << endl;
                } else {
                    cout << "\nProduk ditemukan!" << endl;
                    cout << "Nama: " << produk->namaProduk << endl;
                    cout << "Kategori: " << produk->kategori << endl;
                    cout << "Pemasok: " << produk->pemasok << endl;
                    cout << "Stok: " << produk->stok << endl;
                    cout << "Harga: Rp " << produk->harga << endl;
                }
            }

        } else if (pilihan == 6) {
            cout << "\n--- Hitung Total Produk ---" << endl;
            cout << "Nama Toko: ";
            cin >> namaToko;

            addressP toko = searchToko(L, namaToko);
            if (toko == nullptr) {
                cout << "Toko tidak ditemukan!" << endl;
            } else {
                int total = hitungTotalProduk(toko);
                cout << "Total produk di toko " << namaToko << ": " << total << endl;
            }

        } else if (pilihan == 7) {
            cout << "\n--- Hitung Produk Berdasarkan Kategori ---" << endl;
            cout << "Nama Toko: ";
            cin >> namaToko;
            cout << "Kategori: ";
            cin >> kategori;

            addressP toko = searchToko(L, namaToko);
            if (toko == nullptr) {
                cout << "Toko tidak ditemukan!" << endl;
            } else {
                int jumlah = hitungProdukKategori(toko, kategori);
                cout << "Jumlah produk kategori " << kategori
                     << " di toko " << namaToko << ": " << jumlah << endl;
            }

        } else if (pilihan == 8) {
            cout << "\n--- Cek Produk Stok Rendah ---" << endl;
            cout << "Nama Toko: ";
            cin >> namaToko;

            addressP toko = searchToko(L, namaToko);
            if (toko == nullptr) {
                cout << "Toko tidak ditemukan!" << endl;
            } else {
                int batas;
                cout << "Masukkan batas stok minimum: ";
                cin >> batas;
                searchProdukLowStock(toko, batas);
            }

        } else if (pilihan == 0) {
            cout << "\nKeluar dari menu user..." << endl;

        } else {
            cout << "\nPilihan tidak valid!" << endl;
        }
    }
}
