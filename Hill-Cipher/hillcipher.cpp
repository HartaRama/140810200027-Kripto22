/*
Nama    : Harta Rama
NPM     : 140810200027
Kelas   : A
*/

#include <iostream>
#include <math.h>
using namespace std;

void enkripsi();
void dekripsi();
void inversmatrix();
void carikunci();
float menkrip[3][1], mdekrip[3][1], mkunci[3][3], ikunci[3][3], angka[3][1], m[3][3];
float plain[3][3], cipher[3][3], n[3][3], iplain[3][3], hkunci[3][3], pangka[3][1], cangka[3][1], adjp[3][3];
float tcipher[3][3], tiplain[3][3];

int main() {
    string teks;
    int i, j , opsi, kunci;

    cout << "\n1. Enkripsi/Dekripsi \n2. Cari Kunci \nPilih opsi: ";
    cin >> opsi;

    if (opsi == 1) {
        enkripsi();
        dekripsi();
    } else if (opsi == 2) {
        carikunci();
    }
}

void enkripsi() {
    string teks;
    int i, j, k;

    cout << "\nMasukkan Teks (3 huruf): ";
    cin >> teks;
    for(i = 0; i < 3; i++) {
        angka[i][0] = teks[i] - 65;
    }

    cout << "Masukkan kunci (9 angka):\n";   
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cin >> mkunci[i][j];
            m[i][j] = mkunci[i][j];
        }
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 1; j++) {
            for(k = 0; k < 3; k++) {
                menkrip[i][j] = menkrip[i][j] + mkunci[i][k] * angka[k][j];
            }
        }
    }
    cout << "\nHasil Enkripsi: ";
    for(i = 0; i < 3; i++) {
        cout << (char)(fmod(menkrip[i][0], 26) + 65);
    }
}

void dekripsi() {
    int i, j, k;
    inversmatrix();
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 1; j++) {
            for(k = 0; k < 3; k++) {
                mdekrip[i][j] = mdekrip[i][j] + ikunci[i][k] * menkrip[k][j];
            }
        }
    }
    cout<<"\nHasil Dekripsi: ";
    for(i = 0; i < 3; i++) {
        cout<<(char)(fmod(mdekrip[i][0], 26) + 65);
    }
    cout<<"\n";
}

void inversmatrix() {
    int i, j, k;
    float p, q;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(i == j) {
                ikunci[i][j] = 1;
            } else {
                ikunci[i][j] = 0;
            }    
        }
    }
    for(k = 0; k < 3; k++) {
        for(i = 0; i < 3; i++) {
            p = m[i][k];
            q = m[k][k];
            for(j = 0; j < 3; j++) {
                if(i != k) {
                    m[i][j] = m[i][j] * q - p * m[k][j];
                    ikunci[i][j] = ikunci[i][j] * q - p * ikunci[k][j];
                }
            }
        }
    }
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            ikunci[i][j] = ikunci[i][j] / m[i][i];
        }
    }
}

void getCofactor(float A[3][3], float temp[3][3], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = A[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
int determinant(float A[3][3], int n) {
    int D = 0;
    if (n == 1)
        return A[0][0];
 
    float temp[3][3];
    int sign = 1;
    for (int f = 0; f < n; f++) {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return D;
}
 
void adjoint(float A[3][3], float adj[3][3]) {
    int sign = 1;
    float temp[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            getCofactor(A, temp, i, j, 3);
 
            sign = ((i + j) % 2 == 0) ? 1 : -1;
 
            adj[j][i] = (sign) * (determinant(temp, 3 - 1));
        }
    }
}

void carikunci() {    
    string pteks, cteks;
    int i, j, k, det;

    cout << "\nMasukkan plainteks (9 huruf): ";
    cin >> pteks;
    for(i = 0; i < 9; i++) {
        pangka[i][0] = pteks[i] - 65;
    }
    k = 0;   
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            plain[i][j] = pangka[k][0];
            n[i][j] = plain[i][j];
            k++;
        }
    }

    cout << "Masukkan cipherteks (9 huruf): ";
    cin >> cteks;
    for(i = 0; i < 9; i++) {
        cangka[i][0] = cteks[i] - 65;
    }     
    k = 0; 
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cipher[i][j] = cangka[k][0];
            k++;
        }
    }

    int idet;
    det = determinant(plain, 3);
    det = det % 26; 
    for(int x = -26; x < 26; x++){
        if((det * x) % 26 == 1) 
        idet = x; 
    }

    adjoint(plain, adjp);
    int temp[3][3];
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            temp[i][j] = adjp[i][j] * idet;
            if(temp[i][j] < 0) {
                iplain[i][j] = iplain[i][j] + temp[i][j] % 26;
                iplain[i][j] += 26;
            } else {
                iplain[i][j] = iplain[i][j] + temp[i][j] % 26;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tcipher[j][i] = cipher[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tiplain[j][i] = iplain[i][j];
        }
    }

    for(i=0;i<3;i++) {    
        for(j=0;j<3;j++) {    
            hkunci[i][j]=0;    
            for(k=0;k<3;k++) {    
                hkunci[i][j]+=tcipher[i][k]*tiplain[k][j];  
            }
        }    
    }  

    cout<<"\nKunci: ";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cout << fmod(hkunci[i][j], 26) << " ";
        }
        cout << endl;
    }
    cout << "\n\n";
}