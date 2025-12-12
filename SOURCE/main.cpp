#include <iostream>
#include "Toko.h"
#include "Produk.h"

using namespace std;

void mainAdmin(ListParent &L);
void mainUser(ListParent &L);

int main() {
    ListParent L;
    createListToko(L);

    int pilihan = -1;

    while (pilihan != 0) {
        cout << "\n========== SISTEM MANAJEMEN TOKO ==========" << endl;
        cout << "1. Login sebagai Admin" << endl;
        cout << "2. Login sebagai User" << endl;
        cout << "0. Keluar" << endl;
        cout << "==========================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                mainAdmin(L);
                break;
            case 2:
                mainUser(L);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan sistem!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}
