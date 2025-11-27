#include <iostream>
using namespace std;

typedef string infotype;
typedef struct elmProduk *addressC;
typedef elmToko *addressP;

typedef struct elmToko{
    infotype namaToko;
    infotype alamatToko;
    addressC firstC;
    addressP nextT;
};
typedef struct ListParent{
    addressP first;
};