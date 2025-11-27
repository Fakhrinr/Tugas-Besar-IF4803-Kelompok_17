#include <iostream>
using namespace std;

typedef struct elmToko *addressP;
typedef struct produk *addressC;

struct produk{
    string namaProduk;
    string kodeProduk;
    string kategori;
    string pemasok;
    int stok;
    int harga;
    addressC nextC;
    addressP nextCP;
};

typedef struct ListChild{
    addressC first;
};