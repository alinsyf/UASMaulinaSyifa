#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Struktur data untuk menyimpan informasi pengiriman
struct Pengiriman {
    string namaPenerima;
    string alamatPenerima;
    string kotaPenerima;
    int beratPaket;
    int biayaKirim;
};

// Fungsi Linear Search untuk mencari pengiriman berdasarkan nama penerima
int linearSearch(const vector<Pengiriman> &dataPengiriman, const string &namaPenerima) {
    for (int i = 0; i < dataPengiriman.size(); i++) {
        if (dataPengiriman[i].namaPenerima == namaPenerima) {
            return i; // Pengiriman ditemukan, mengembalikan indeksnya
        }
    }
    return -1; // Pengiriman tidak ditemukan, mengembalikan -1
}

int main() {
    // Inisialisasi data pengiriman (belum terurut)
    vector<Pengiriman> dataPengiriman = {
        {"Dwi", "Jl. Diponegoro No. 4", "Yogyakarta", 4, 20000},
        {"Ahmad", "Jl. Sudirman No. 1", "Jakarta", 2, 10000},
        {"Candra", "Jl. Thamrin No. 3", "Bandung", 1, 5000},
        {"Budi", "Jl. Gatot Subroto No. 2", "Surabaya", 3, 15000},
        {"Eka", "Jl. Merdeka No. 5", "Semarang", 2, 10000}
    };

    string namaPenerima;
    cout << "Masukkan nama penerima yang ingin dicari: ";
    cin >> namaPenerima;

    // Melakukan pencarian menggunakan linear search
    int index = linearSearch(dataPengiriman, namaPenerima);

    // Menampilkan hasil pencarian
    if (index != -1) {
        cout << "Pengiriman ditemukan:\n";
        cout << "Nama Penerima: " << dataPengiriman[index].namaPenerima << endl;
        cout << "Alamat Penerima: " << dataPengiriman[index].alamatPenerima << endl;
        cout << "Kota Penerima: " << dataPengiriman[index].kotaPenerima << endl;
        cout << "Berat Paket: " << dataPengiriman[index].beratPaket << " kg" << endl;
        cout << "Biaya Kirim: Rp " << dataPengiriman[index].biayaKirim << endl;
    } else {
        cout << "Pengiriman dengan nama penerima '" << namaPenerima << "' tidak ditemukan." << endl;
    }

    return 0;
}
