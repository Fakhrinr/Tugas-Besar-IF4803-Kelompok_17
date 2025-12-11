#include "Toko.h"
#include "Produk.h"
#include <iostream>
using namespace std;

void mainUser(ListParent &L) {
    int pilihan = -1;
    
    while (pilihan != 0) {
        cout << "\n=== MENU USER ===" << endl;
        cout << "1. Insert Toko" << endl;
        cout << "2. Insert Produk" << endl;
        cout << "3. Show All Toko" << endl;
        cout << "4. Show All Produk" << endl;
        cout << "5. Show Produk by Kategori" << endl;
        cout << "6. Search Toko" << endl;
        cout << "7. Search Produk" << endl;
        cout << "8. Hitung Total Produk di Toko" << endl;
        cout << "9. Hitung Produk by Kategori" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        string nama, alamat, pemasok, kategori, namaToko, namaProduk;

        if (pilihan == 1) {
            cout << "\n--- Insert Toko ---" << endl;
            cout << "Nama Toko (tanpa spasi): ";
            cin >> nama;
            cout << "Alamat Toko (tanpa spasi): ";
            cin >> alamat;

            addressP tokoBaru = createElmToko(nama, alamat);
            insertLastToko(L, tokoBaru);
            cout << "Toko berhasil ditambahkan!" << endl;

        } else if (pilihan == 2) {
            cout << "\n--- Insert Produk ---" << endl;
            cout << "Nama Toko: ";
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

        } else if (pilihan == 3) {
            cout << "\n";
            showAllToko(L);

        } else if (pilihan == 4) {
            cout << "\n--- Show All Produk ---" << endl;
            cout << "Nama Toko: ";
            cin >> namaToko;

            addressP toko = searchToko(L, namaToko);
            if (toko == nullptr) {
                cout << "Toko tidak ditemukan!" << endl;
            } else {
                showAllProduk(toko);
            }

        } else if (pilihan == 5) {
            cout << "\n--- Show Produk by Kategori ---" << endl;
            cout << "Nama Toko: ";
            cin >> namaToko;
            cout << "Kategori: ";
            cin >> kategori;

            addressP toko = searchToko(L, namaToko);
            if (toko == nullptr) {
                cout << "Toko tidak ditemukan!" << endl;
            } else {
                showProdukInfo(toko);
            }

        } else if (pilihan == 6) {
            cout << "\n--- Search Toko ---" << endl;
            cout << "Nama Toko: ";
            cin >> namaToko;

            addressP toko = searchToko(L, namaToko);
            if (toko == nullptr) {
                cout << "Toko tidak ditemukan!" << endl;
            } else {
                cout << "\nToko ditemukan!" << endl;
                cout << "Nama: " << toko->namaToko << endl;
                cout << "Alamat: " << toko->alamatToko << endl;
            }

        } else if (pilihan == 7) {
            cout << "\n--- Search Produk ---" << endl;
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

        } else if (pilihan == 8) {
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

        } else if (pilihan == 9) {
            cout << "\n--- Hitung Produk by Kategori ---" << endl;
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

        } else if (pilihan == 0) {
            cout << "\nKeluar dari menu user..." << endl;

        } else {
            cout << "\nPilihan tidak valid!" << endl;
        }
    }
}
