/*
Nama    : Harta Rama
NPM     : 140810200027
Kelas   : A
*/

#include <iostream>
#include <string.h>
using namespace std;

void enkripsi(string teks, int kunci);
void dekripsi(string teks, int kunci);

int main() {
    string teks;
    int opsi, kunci;

    cout << "\nMasukkan Teks: ";
    getline (cin, teks);
    
    cout << "Masukan kunci: ";
    cin >> kunci;

    cout << "\n1. Enkripsi \n2. Dekripsi \nPilih opsi: ";
    cin >> opsi;

    if (opsi == 1) {
        enkripsi(teks, kunci);
    } else if (opsi == 2) {
        dekripsi(teks, kunci);
    }
}

void enkripsi(string teks, int kunci) {
    string hasil = "";
    for (int i=0; i < teks.length(); i++) {
        if (teks[i] == ' ') {
            hasil += ' ';
        } else if (isupper(teks[i])) {
            hasil += char(int(teks[i] + kunci - 65) % 26 + 65);
        } else {
            hasil += char(int(teks[i] + kunci - 97) % 26 + 97);
        }
    }
    cout << "\nHasil Enkripsi: " << hasil << endl;
}

void dekripsi(string teks, int kunci) {
    string hasil = "";
    for (int i=0; i < teks.length(); i++) {
        if (teks[i] == ' ') {
            hasil += ' ';
        } else if (isupper(teks[i])) {
            hasil += char(int(teks[i] + (26 - kunci) - 65) % 26 + 65);
        } else {
            hasil += char(int(teks[i] + (26 - kunci) - 97) % 26 + 97);
        }
    }
    cout << "\nHasil Dekripsi: " << hasil << endl;
}