#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// Struktur data untuk menyimpan informasi pengiriman
struct Pengiriman {
    string namaPenerima;
    string alamatPenerima;
    string kotaPenerima;
    int beratPaket;
    int biayaKirim;
};

// Fungsi Binary Search untuk mencari pengiriman berdasarkan nama penerima
int binarySearch(vector<Pengiriman> &dataPengiriman, string namaPenerima) {
    int left = 0;
    int right = dataPengiriman.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Bandingkan nama penerima di tengah dengan nama penerima yang dicari
        if (dataPengiriman[mid].namaPenerima == namaPenerima) {
            return mid; 
        } else if (dataPengiriman[mid].namaPenerima < namaPenerima) {
            left = mid + 1; // Pencarian dilanjutkan di sebelah kanan
        } else {
            right = mid - 1; // Pencarian dilanjutkan di sebelah kiri
        }
    }

    return -1; // Pengiriman tidak ditemukan, mengembalikan -1
}

int main() {
    // Inisialisasi data pengiriman (diurutkan berdasarkan nama penerima)
    vector<Pengiriman> dataPengiriman = {
        {"Ahmad", "Jl. Sudirman No. 1", "Jakarta", 2, 10000},
        {"Budi", "Jl. Gatot Subroto No. 2", "Surabaya", 3, 15000},
        {"Candra", "Jl. Thamrin No. 3", "Bandung", 1, 5000},
        {"Dwi", "Jl. Diponegoro No. 4", "Yogyakarta", 4, 20000},
        {"Eka", "Jl. Merdeka No. 5", "Semarang", 2, 10000}
    };

    string namaPenerima;
    cout << "Masukkan nama penerima yang ingin dicari: ";
    cin >> namaPenerima;

    // Melakukan pencarian menggunakan binary search
    int index = binarySearch(dataPengiriman, namaPenerima);

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
