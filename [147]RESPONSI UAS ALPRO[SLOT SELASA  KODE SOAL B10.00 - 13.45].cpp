#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float uts, uas;
    float nilaiAkhir;
    string status;
};

void hitungNilai(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n; i++) {
        mhs[i].nilaiAkhir = (mhs[i].uts + mhs[i].uas) / 2;
        mhs[i].status = (mhs[i].nilaiAkhir >= 75) ? "Lulus" : "Tidak Lulus";
    }
}

void tampilkanData(Mahasiswa mhs[], int n) {
    cout << left << setw(10) << "NIM"
         << setw(10) << "Nama"
         << setw(6) << "UTS"
         << setw(6) << "UAS"
         << setw(10) << "NA"
         << setw(15) << "Status" << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << mhs[i].nim
             << setw(10) << mhs[i].nama
             << setw(6) << mhs[i].uts
             << setw(6) << mhs[i].uas
             << setw(10) << mhs[i].nilaiAkhir
             << setw(15) << mhs[i].status << endl;
    }
}

void cariNama(Mahasiswa mhs[], int n, string key) {
    bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (mhs[i].nama == key) {
            cout << "Ditemukan: " << mhs[i].nama << " Nilai Akhir: " << mhs[i].nilaiAkhir << " Status: " << mhs[i].status << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) cout << "Nama tidak ditemukan." << endl;
}

void cariTerkecil(Mahasiswa mhs[], int n, float nilai) {
    bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (mhs[i].nilaiAkhir == nilai) {
            cout << "Mahasiswa dengan nilai " << nilai << " adalah " << mhs[i].nama << " (" << mhs[i].nim << ")" << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) cout << "Tidak ada mahasiswa dengan nilai " << nilai << endl;
}

void urutkan(Mahasiswa mhs[], int n, bool naik) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if ((naik && mhs[i].nilaiAkhir > mhs[j].nilaiAkhir) ||
                (!naik && mhs[i].nilaiAkhir < mhs[j].nilaiAkhir)) {
                swap(mhs[i], mhs[j]);
            }
        }
    }
}

void simpanNilaiAkhir(Mahasiswa mhs[], int n) {
    ofstream out("nilai_akhir.txt");
    for (int i = 0; i < n; i++) {
        out << mhs[i].nim << " " << mhs[i].nama << " " << mhs[i].nilaiAkhir << endl;
    }
    out.close();
}

void simpanStatus(Mahasiswa mhs[], int n) {
    ofstream out("status_lulus.txt");
    for (int i = 0; i < n; i++) {
        out << mhs[i].nim << " " << mhs[i].nama << " " << mhs[i].status << endl;
    }
    out.close();
}

int main() {
    ifstream file("data.txt");
    int n;
    file >> n;
    Mahasiswa mhs[n];
    for (int i = 0; i < n; i++) {
        file >> mhs[i].nim >> mhs[i].nama >> mhs[i].uts >> mhs[i].uas;
    }
    file.close();

    hitungNilai(mhs, n);

    int pilih;
    do {
        cout << "\nMENU PROGRAM:\n";
        cout << "1. Tampilkan data\n";
        cout << "2. Cari berdasarkan nama\n";
        cout << "3. Cari mahasiswa dengan nilai tertentu\n";
        cout << "4. Urutkan nilai dari besar ke kecil\n";
        cout << "5. Urutkan nilai dari kecil ke besar\n";
        cout << "6. Simpan nilai akhir ke file\n";
        cout << "7. Simpan status lulus ke file\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            tampilkanData(mhs, n);
        } else if (pilih == 2) {
            string nama;
            cout << "Masukkan nama yang dicari: ";
            cin >> nama;
            cariNama(mhs, n, nama);
        } else if (pilih == 3) {
            float nilai;
            cout << "Masukkan nilai yang dicari: ";
            cin >> nilai;
            cariTerkecil(mhs, n, nilai);
        } else if (pilih == 4) {
            urutkan(mhs, n, false);
            cout << "Data diurutkan dari besar ke kecil.\n";
        } else if (pilih == 5) {
            urutkan(mhs, n, true);
            cout << "Data diurutkan dari kecil ke besar.\n";
        } else if (pilih == 6) {
            simpanNilaiAkhir(mhs, n);
            cout << "Data nilai akhir disimpan ke nilai_akhir.txt\n";
        } else if (pilih == 7) {
            simpanStatus(mhs, n);
            cout << "Data status lulus disimpan ke status_lulus.txt\n";
        }
    } while (pilih != 0);

    return 0;
}
