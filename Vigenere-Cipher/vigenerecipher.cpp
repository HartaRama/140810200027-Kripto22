/*
    Nama    : Harta Rama
    NPM     : 140810200027
    Kelas   : A
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
 
string extendKunci(string teks, string kunci);
string enkripsi(string teks, string kunciExtended);
string dekripsi(string cipher_text, string kunciExtended);

int main() {
    string teks;
    string kunci;

    cout << "\nMasukkan Teks\t: ";
    getline (cin, teks);
    
    cout << "Masukan kunci\t: ";
    getline (cin, kunci);
 
    string kunciExtended = extendKunci(teks, kunci);
    string cipherteks = enkripsi(teks, kunciExtended);
 
    cout << "\nCipherteks\t: " << cipherteks << endl;
    cout << "Plainteks\t: " << dekripsi(cipherteks, kunciExtended) << endl;
}

string extendKunci(string teks, string kunci) {
    int x = teks.size();
    for (int i = 0; ; i++) {
        if (x == i) {
            i = 0;
        }
        if (kunci.size() == teks.size()) {
            break;
        }
        kunci.push_back(kunci[i]);
    }
    return kunci;
}

string enkripsi(string teks, string kunciExtended) {
    string cipherteks;
    for (int i = 0; i < teks.size(); i++) {
        char x = (teks[i] + kunciExtended[i]) %26;
        x += 'A';
        cipherteks.push_back(x);
    }
    return cipherteks;
}
 
string dekripsi(string cipherteks, string kunciExtended) {
    string plainteks;
    for (int i = 0 ; i < cipherteks.size(); i++) {
        char x = (cipherteks[i] - kunciExtended[i] + 26) %26;
        x += 'A';
        plainteks.push_back(x);
    }
    return plainteks;
}