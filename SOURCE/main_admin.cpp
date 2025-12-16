// main_admin.cpp
#include "Toko.h"
#include "Produk.h"
#include <iostream>
using namespace std;

// Deklarasi Fungsi
void mainAdmin(ListParent &L);
void mainToko(ListParent &L);
void mainProduk(ListParent &L);
void dataDummyParent(ListParent &L);  

void mainToko(ListParent &L) {
    int pilihan = -99;
    while (pilihan != 0) {
        cout << "\n========== MENU TOKO ==========" << endl;
        cout << "--- Insert Toko ---" << endl;
        cout << "1. Insert First Toko" << endl;
        cout << "2. Insert Last Toko" << endl;
        cout << "3. Insert After Toko" << endl;
        cout << "--- Delete Toko ---" << endl;
        cout << "4. Delete First Toko" << endl;
        cout << "5. Delete Last Toko" << endl;
        cout << "6. Delete After Toko" << endl;
        cout << "--- Search & Show Toko ---" << endl;
        cout << "7. Search Toko" << endl;
        cout << "8. Show All Toko" << endl;
        cout << "--- Hitung Toko & Produk ---" << endl;
        cout << "9. Hitung Total Produk di Toko" << endl;
        cout << "10. Hitung Jumlah Toko" << endl;
        cout << "0. Kembali ke Menu Admin" << endl;
        cout << "=================================" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            infotype nama, alamat;
            cout << "Masukkan Nama Toko: ";
            cin >> nama;
            cout << "Masukkan Alamat Toko: ";
            cin >> alamat;
            addressP P = createElmToko(nama, alamat);
            insertFirstToko(L, P);
            cout << "Toko berhasil ditambahkan!" << endl;

        } else if (pilihan == 2) {
            infotype nama, alamat;
            cout << "Masukkan Nama Toko: ";
            cin >> nama;
            cout << "Masukkan Alamat Toko: ";
            cin >> alamat;
            addressP P = createElmToko(nama, alamat);
            insertLastToko(L, P);
            cout << "Toko berhasil ditambahkan!" << endl;

        } else if (pilihan == 3) {
            infotype nama, alamat, prec;
            cout << "Masukkan nama toko sebelumnya: ";
            cin >> prec;
            cout << "Masukkan Nama Toko: ";
            cin >> nama;
            cout << "Masukkan Alamat Toko: ";
            cin >> alamat;

            addressP P = createElmToko(nama, alamat);
            insertAfterToko(L, P, prec);
            cout << "Toko berhasil ditambahkan!" << endl;

        } else if (pilihan == 4) {
            deleteFirstToko(L);
            cout << "Toko pertama berhasil dihapus!" << endl;

        } else if (pilihan == 5) {
            deleteLastToko(L);
            cout << "Toko terakhir berhasil dihapus!" << endl;

        } else if (pilihan == 6) {
            infotype prev;
            cout << "Masukkan nama toko sebelumnya: ";
            cin >> prev;
            deleteAfterToko(L, prev);
            cout << "Toko berhasil dihapus!" << endl;

        } else if (pilihan == 7) {
            infotype namaToko;
            cout << "Masukkan Nama Toko yang dicari: ";
            cin >> namaToko;
            addressP hasil = searchToko(L, namaToko);
            if (hasil != nullptr) {
                cout << "Toko ditemukan: " << hasil->namaToko << ", Alamat: " << hasil->alamatToko << endl;
            } else {
                cout << "Toko tidak ditemukan." << endl;
            }

        } else if (pilihan == 8) {
            showAllToko(L);

        } else if (pilihan == 9) {
            infotype nama;
            cout << "Masukkan Nama Toko: ";
            cin >> nama;
            addressP p = searchToko(L, nama);
            if (p != nullptr) {
                int total = hitungTotalProduk(p);
                cout << "Total Produk di Toko " << p->namaToko << ": " << total << endl;
            } else {
                cout << "Toko tidak ditemukan." << endl;
            }
        } else if (pilihan == 10) {
            int jumlah = hitungJumlahToko(L);
            cout << "Jumlah Toko: " << jumlah << endl;
        } else if (pilihan == 0) {
            cout << "Kembali ke Menu Admin" << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    }
}

void mainProduk(ListParent &L) {
    int pilihan = -99;
    while (pilihan != 0) {
        cout << "\n========== MENU PRODUK ==========" << endl;
        cout << "1. Cari Toko Terlebih Dahulu" << endl;
        cout << "2. Kembali ke Menu Admin" << endl;
        cout << "==================================" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            infotype namaToko;
            cout << "Masukkan Nama Toko: ";
            cin >> namaToko;

            addressP toko = searchToko(L, namaToko);
            if (toko == nullptr) {
                cout << "Toko tidak ditemukan!" << endl;
            } else {
                cout << "\n=== Menu Produk untuk Toko " << toko->namaToko << " ===" << endl;
                // Tambahkan menu produk di sini sesuai kebutuhan
                showAllProduk(toko);
            }
        }else if (pilihan == 2) {
            cout << "Kembali ke Menu Admin" << endl;
            break;
        }else{
            cout << "Pilihan tidak valid!" << endl;
        }
    }
}

void mainAdmin(ListParent &L) {
    int pilihan = -99;
    while (pilihan != 0) {
        cout << "\n========== MENU ADMIN ==========" << endl;
        cout << "1. Kelola Toko" << endl;
        cout << "2. Kelola Produk" << endl;
        cout << "0. Keluar" << endl;
        cout << "================================" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                mainToko(L);
                break;
            case 2:
                mainProduk(L);
                break;
            case 0:
                cout << "Terima kasih" << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
    }
}


void dataDummyParent(ListParent &L) {

    // DUMMY TOKO (PARENT)
    addressP toko1 = createElmToko("Alfamart", "Jl_Merdeka");
    addressP toko2 = createElmToko("Indomaret", "Jl_Sudirman");
    addressP toko3 = createElmToko("Superindo", "Jl_AsiaAfrika");

    insertLastToko(L, toko1);
    insertLastToko(L, toko2);
    insertLastToko(L, toko3);

    // DUMMY PRODUK ALFAMART
    insertLastProduk(toko1,createElmProduk("Aqua", "Danone", "Minuman", 50, 5000));
    insertLastProduk(toko1,createElmProduk("Indomie", "Indofood", "Makanan", 100, 3000));
    insertLastProduk(toko1,createElmProduk("TehBotol", "Sosro", "Minuman", 30, 6000));

    // DUMMY PRODUK INDOMARET

    insertLastProduk(toko2,createElmProduk("Beras", "Wilmar", "Sembako", 20, 60000));
    insertLastProduk(toko2,createElmProduk("Gula", "Gulaku", "Sembako", 15, 14000));
    insertLastProduk(toko2,createElmProduk("Minyak", "Bimoli", "Sembako", 25, 18000));

    // DUMMY PRODUK SUPERINDO
    insertLastProduk(toko3,createElmProduk("Susu", "UltraJaya", "Minuman", 10, 7000));
    insertLastProduk(toko3,createElmProduk("Roti", "SariRoti", "Makanan", 40, 12000));
}
