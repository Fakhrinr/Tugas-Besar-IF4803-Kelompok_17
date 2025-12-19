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

        } else if (pilihan == 5) {
            deleteLastToko(L);

        } else if (pilihan == 6) {
            infotype prev;
            cout << "Masukkan nama toko sebelumnya: ";
            cin >> prev;
            deleteAfterToko(L, prev);


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
    addressP selectedToko = nullptr;
    while (pilihan != 0) {
        cout << "\n========== MENU PRODUK ==========" << endl;
        cout << "1. Kelola Produk" << endl;
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
                cout << "1. Tambah Produk" << endl;
                cout << "2. Lihat Produk di Toko" << endl;
                cout << "3. Cari Produk Berdasarkan Kategori" << endl;
                cout << "4. Cari Produk" << endl;
                cout << "5. Hitung Total Produk di Toko" << endl;
                cout << "6. Hitung Produk Berdasarkan Kategori" << endl;
                cout << "7. Cek Produk Stok Rendah" << endl;
                cout << "8. Hapus Produk" << endl;
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
                            cout << "\n--- Lihat Produk di Toko ---" << endl;
                            cout << "Nama Toko: ";
                            cin >> namaToko;

                            addressP toko = searchToko(L, namaToko);
                            if (toko == nullptr) {
                                cout << "Toko tidak ditemukan!" << endl;
                            } else {
                                showAllProduk(toko);
                            }

                        } else if (pilihan == 3) {
                            cout << "\n--- Cari Produk Berdasarkan Kategori ---" << endl;
                            cout << "Nama Toko: ";
                            cin >> namaToko;
                            cout << "Kategori: ";
                            cin >> kategori;

                            addressP toko = searchToko(L, namaToko);
                            if (toko == nullptr) {
                                cout << "Toko tidak ditemukan!" << endl;
                            } else {
                                showProdukInfo(toko, kategori);
                            }

                        } else if (pilihan == 4) {
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

                        } else if (pilihan == 5) {
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

                        } else if (pilihan == 6) {
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

                        } else if (pilihan == 7) {
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

                        } else if (pilihan == 8){
                            cout << "Pilih metode penghapusan:" << endl;
                            cout << "1. Hapus Produk Pertama" << endl;
                            cout << "2. Hapus Produk Terakhir" << endl;
                            cout << "3. Hapus Produk Setelah Nama Tertentu" << endl;
                            cout << "Pilihan: ";
                            int hapusPilihan;
                            cin >> hapusPilihan;

                            if (hapusPilihan == 1) {
                                deleteFirstProduk(toko);
                            } else if (hapusPilihan == 2) {
                                deleteLastProduk(toko);
                            } else if (hapusPilihan == 3) {
                                infotype namaProdukSebelum;
                                cout << "Masukkan nama produk sebelumnya: ";
                                cin >> namaProdukSebelum;
                                deleteAfterProduk(toko, namaProdukSebelum);
                            } else {
                                cout << "Pilihan tidak valid!" << endl;
                            }
                        } else if (pilihan == 0) {
                            cout << "\nKeluar dari menu user..." << endl;

                        } else {
                            cout << "\nPilihan tidak valid!" << endl;
                        }
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
