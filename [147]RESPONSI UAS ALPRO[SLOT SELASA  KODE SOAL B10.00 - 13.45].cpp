#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 100;

struct Mahasiswa {
    string nim;
    string nama;
    float uts, uas, nilaiAkhir;
    string status;
};

Mahasiswa data[MAX];
int jumlahData = 0;

void bacaFile(const string& int data[] ,int namaFile {
    ifstream file();
    namaFile;
    while (file>> data[jumlahData].nim >> data[jumlahData].nama >>
           data[jumlahData].uts >> data[jumlahData].uas) {
        data[jumlahData].nilaiAkhir = (data[jumlahData].uts + data[jumlahData].uas) / 2;
        data[jumlahData].status = (data[jumlahData].nilaiAkhir >= 75) ? "Lulus" : "Tidak Lulus";
        jumlahData++;
    }
    file.close();
}

void tampilkanData() {
    cout << "Data Mahasiswa:\n";
    for (int i = 0; i < jumlahData; i++) {
        cout << setw(10) << data[i].nim << setw(15) << data[i].nama
             << setw(6) << data[i].uts << setw(6) << data[i].uas
             << setw(8) << data[i].nilaiAkhir << "  " << data[i].status << endl;
    }
}


void cariNama(const string& namaCari) {
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].nama == namaCari) {
            cout << "Ditemukan: " << data[i].nama << " - Nilai Akhir: " << data[i].nilaiAkhir << endl;
            return;
        }
    }
    cout << "Nama tidak ditemukan.\n";
}

void cariTerkecil(float batas) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].nilaiAkhir < batas) {
            cout << data[i].nama << " (" << data[i].nilaiAkhir << ")\n";
            ditemukan = true;
        }
    }
    if (!ditemukan) cout << "Tidak ada nilai yang lebih kecil dari " << batas << endl;
}


void urutkan(bool ) {
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = i + 1; j < jumlahData; j++) {
            bool kondisi  ? (data[i].nilaiAkhir < data[j].nilaiAkhir)
                                      : (data[i].nilaiAkhir > data[j].nilaiAkhir);
            if (kondisi) swap(data[i], data[j]);
        }
    }
}


void simpanNilai(const string& namaFile) {
    ofstream file(namaFile);
    for (int i = 0; i < jumlahData; i++) {
        file << data[i].nim << " " << data[i].nama << " "
             << data[i].nilaiAkhir << endl;
    }
    file.close();
}


void simpanStatus(const string& namaFile) {
    ofstream file(namaFile);
    for (int i = 0; i < jumlahData; i++) {
        file << data[i].nim << " " << data[i].nama << " "
             << data[i].status << endl;
    }
    file.close();
}

int main() {
    bacaFile("data_mahasiswa.txt");

    tampilkanData();
    cout << "\nMencari nilai berdasarkan nama:\n";
    cariNama("Andi");

    cout << "\nMahasiswa dengan nilai akhir < 75:\n";
    cariTerkecil(75);

    cout << "\nMengurutkan dari besar ke kecil:\n";
    urutkan(true);
    tampilkanData();

    cout << "\nMengurutkan dari kecil ke besar:\n";
    urutkan(false);
    tampilkanData();

    simpanNilai("nilai_akhir.txt");
    simpanStatus("status_kelulusan.txt");

    return 0;

}
