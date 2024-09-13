#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Daftar pakaian dengan harga
    vector<vector<string>> list_pakaian = {{"kaos", "50000"}, {"kemeja", "100000"}, {"celana", "120000"}};

    // Menampilkan barang yang ada di toko
    cout << "Barang yang ada di toko:\n";
    for (int i = 0; i < list_pakaian.size(); i++) {
        cout << i + 1 << ". " << list_pakaian[i][0] << " harga Rp " << list_pakaian[i][1] << endl;
    }

    // Matriks untuk menyimpan pembelian
    vector<vector<int>> pembelian;

    // Perulangan untuk pembelian
    while (true) {
        string beli;
        cout << "Apakah Anda ingin membeli pakaian? (ya/tidak): ";
        cin >> beli;

        if (beli == "tidak") {
            break;
        } else if (beli == "ya") {
            int pilihan, jumlah;
            cout << "Masukkan nomor pakaian yang ingin dibeli (1, 2, 3): ";
            cin >> pilihan;

            if (pilihan < 1 || pilihan > list_pakaian.size()) {
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                continue;
            }

            cout << "Masukkan jumlah " << list_pakaian[pilihan - 1][0] << " yang ingin dibeli: ";
            cin >> jumlah;

            // Menyimpan pembelian
            pembelian.push_back({pilihan - 1, stoi(list_pakaian[pilihan - 1][1]), jumlah});
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }

    // Menghitung total biaya
    int total_biaya = 0;
    for (auto &item : pembelian) {
        total_biaya += item[1] * item[2];
    }

    // Memberikan diskon jika berlaku
    double diskon = 0;
    if (total_biaya >= 1000000) {
        diskon = total_biaya * 0.25;
    } else if (total_biaya >= 500000) {
        diskon = total_biaya * 0.10;
    }

    double total_akhir = total_biaya - diskon;

    // Menampilkan ringkasan pembelian
    cout << "\nRingkasan Pembelian:\n";
    for (auto &item : pembelian) {
        cout << item[2] << " x " << list_pakaian[item[0]][0] << " - Rp " << item[1] 
             << " masing-masing, total: Rp " << item[1] * item[2] << endl;
    }

    cout << "\nTotal biaya: Rp " << total_biaya << endl;
    cout << "Diskon: Rp " << diskon << endl;
    cout << "Total yang harus dibayar: Rp " << total_akhir << endl;

    return 0;
}


