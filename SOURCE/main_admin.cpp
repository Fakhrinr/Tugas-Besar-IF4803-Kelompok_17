#include "Toko.h"
#include "Produk.h"

#include <iostream>
using namespace std;

//Deklarasi Fungsi
void mainAdmin(ListParent &L);
void mainToko(ListParent &L);
void mainProduk(ListParent &L);


void mainAdmin(ListParent &L){
    int pilihan = -99;
    while (pilihan != 0){
        cout << "========== MENU ADMIN ========== \n";
        cout << "1. Toko (Parent) \n";
        cout << "2. Produk (Child) \n";
        cout << "0. Keluar \n";
        cout << "================================= \n";
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        switch(pilihan){
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

    void mainToko(ListParent &L){
        int pilihan = -99;
        while (pilihan != 0){
            cout << " ========= MENU TOKO ========== \n";
            cout << "---Insert Toko--- \n";
            cout << "1. Insert First Toko \n";
            cout << "2. Insert Last Toko \n";
            cout << "3. Insert After Toko \n";
            cout << "--- Delete Toko--- \n";
            cout << "4. Delete First Toko \n";
            cout << "5. Delete Last Toko \n";
            cout << "6. Delete After Toko \n";
            cout << " --- Search & Show Toko--- \n";
            cout << "7. Search Toko \n";
            cout << "8. Show All Toko \n";
            cout << "--- Hitung Toko & Produk --- \n";
            cout << "9. Hitung Total Produk di Toko \n";
            cout << "10. Hitung Jumlah Toko \n";
            cout << "0. Kembali ke Menu Admin \n";
            cout << "================================= \n";
            cout << "Masukkan Pilihan: ";
            cin >> pilihan;

            if (pilihan == 1){
                infotype nama, alamat; //deklarasi variabel
                cout << "Masukkan Nama Toko: ";
                cin >> nama;
                cout << "Masukkan Alamat Toko: ";
                cin >> alamat;
                addressP P = createElmToko(nama, alamat);
                insertFirstToko(L, P);

            }else if (pilihan == 2){
                infotype nama, alamat; //deklarasi variabel
                cout << "Masukkan Nama Toko: ";
                cin >> nama;
                cout << "Masukkan Alamat Toko: ";
                cin >> alamat;
                addressP P = createElmToko(nama, alamat);
                insertLastToko(L, P);
            }else if(pilihan == 3){
                infotype nama,alamat,prec; //deklarasi variabel
                cout << "Masukkan setelah toko (nama toko): ";
                cin >> prec;
                cout << "Masukkan Nama Toko: ";
                cin >> nama;
                cout << "Masukkan Alamat Toko: ";
                cin >> alamat;

                addressP P = createElmToko(nama, alamat);
                insertAfterToko(L, P, prec);
            }else if (pilihan == 4){
                deleteFirstToko(L);

            }else if (pilihan == 5){
                deleteLastToko(L);

            }else if (pilihan == 6){
                infotype prev;
                cout << "Masukkan setelah toko (nama toko): ";
                cin >> prev;
                deleteAfterToko(L, prev);

            }else if (pilihan == 7){
                infotype namaToko;
                cout << "Masukkan Nama Toko yang dicari: ";
                cin >> namaToko;
                addressP hasil;
                hasil = searchToko(L, namaToko);
                if (hasil != nullptr){
                    cout << "Toko ditemukan: " << hasil->namaToko << ", Alamat: " << hasil->alamatToko << endl;
                }else{
                    cout << "Toko tidak ditemukan." << endl;
                }

            }else if (pilihan == 8){
                showAllToko(L);

            }else if (pilihan == 9){
                infotype nama; //mencari nama toko
                cout << "Masukkan Nama Toko: ";
                cin >> nama;
                addressP p ;
                p = searchToko(L, nama);
                if (p != nullptr){
                    int total;
                    total = hitungTotalProduk(p);
                    cout << "Total Produk di Toko " << p->namaToko << ": " << total << endl;
                }else{
                    cout << "Toko tidak ditemukan." << endl;
                }
            }else if (pilihan == 10){
                int jumlah;
                jumlah = hitungJumlahToko(L);
                cout << "Jumlah Toko: " << jumlah << endl;
            }else if (pilihan == 0){
                cout << "Kembali ke Menu Admin" << endl;
            }else{
                cout << "Pilihan tidak valid!" << endl;
            }
        }
    }
}