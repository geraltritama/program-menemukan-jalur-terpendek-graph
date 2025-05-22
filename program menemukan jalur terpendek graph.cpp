#include <iostream>
using namespace std;

const int jumlahSimpul = 4;
int graph[jumlahSimpul][jumlahSimpul] = {
    {0, 4, 1, 3},
    {4, 0, 2, 1},
    {1, 2, 0, 5},
    {3, 1, 5, 0}
};

int ruteTerpendek[jumlahSimpul + 1];
int biayaMinimum = 9999;

void salinRute(int dari[], int panjang) {
    for (int i = 0; i < panjang; i++) {
        ruteTerpendek[i] = dari[i];
    }
    ruteTerpendek[panjang] = dari[0];
}

//rekursif
void cariRute(int posisi[], bool dikunjungi[], int level, int biayaSaatIni, int start) {
    if (level == jumlahSimpul) {
        biayaSaatIni += graph[posisi[level - 1]][start];
        if (biayaSaatIni < biayaMinimum) {
            biayaMinimum = biayaSaatIni;
            salinRute(posisi, jumlahSimpul);
        }
        return;
    }

    for (int i = 0; i < jumlahSimpul; i++) {
        if (!dikunjungi[i]) {
            dikunjungi[i] = true;
            posisi[level] = i;
            cariRute(posisi, dikunjungi, level + 1, biayaSaatIni + graph[posisi[level - 1]][i], start);
            dikunjungi[i] = false;
        }
    }
}

int main() {
    cout << "Cost List:\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    int titikAwal;
    do {
        cout << "\nMasukkan titik awal (1-" << jumlahSimpul << "): ";
        cin >> titikAwal;
        if (titikAwal < 1 || titikAwal > jumlahSimpul) {
        cout << "Titik tidak valid! Coba lagi." << endl;
        }
    } while (titikAwal < 1 || titikAwal > jumlahSimpul);


    titikAwal--;

    int posisi[jumlahSimpul];
    bool dikunjungi[jumlahSimpul];

    for (int i = 0; i < jumlahSimpul; i++) dikunjungi[i] = false;

    posisi[0] = titikAwal;
    dikunjungi[titikAwal] = true;

    cariRute(posisi, dikunjungi, 1, 0, titikAwal);

    cout << "\nJalur Terpendek:\n";
    for (int i = 0; i <= jumlahSimpul; i++) {
        cout << ruteTerpendek[i] + 1;
        if (i < jumlahSimpul) cout << " --> ";
    }
    cout << "\n\nMinimum Cost: " << biayaMinimum << endl;

    return 0;
}
