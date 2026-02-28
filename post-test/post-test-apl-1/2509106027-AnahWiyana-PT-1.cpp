#include <iostream>
using namespace std;

int main() {
    string namaBenar = "Anah"; 
    string passwordBenar = "027"; 

    string nama, password;
    int kesempatan = 3;

    cout << "========================================" << endl;
    cout << "        PROGRAM KONVERSI PANJANG        " << endl;
    cout << "========================================" << endl;

    while (kesempatan > 0) {
        cout << "================ LOGIN ================" << endl;
        cout << "Masukkan Nama     : ";
        cin >> nama;
        cout << "Masukkan Password : ";
        cin >> password;

        if (nama == namaBenar && password == passwordBenar) {
            cout << "Login Berhasil!" << endl;
            break;
        } else {
            kesempatan--;
            cout << "Login Gagal! Sisa kesempatan: " << kesempatan << endl;
        }
    }

    if (kesempatan == 0) {
        cout << "Percobaan Login sudah mencpai batas maksimum. Program berhenti." << endl;
        return 0;
    }

    int pilihan;
    double meter, km, cm;

    do {
        cout << "========================================" << endl;
        cout << "              MENU UTAMA                " << endl;
        cout << "========================================" << endl;
        cout << "1. Konversi Meter ==> Kilometer dan Centimeter" << endl;
        cout << "2. Konversi Kilometer ==> Meter dan Centimeter" << endl;
        cout << "3. Konversi Centimeter ==> Meter dan Kilometer" << endl;
        cout << "4. Keluar" << endl;
        cout << "========================================" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai dalam satuan Meter: ";
                cin >> meter;
                km = meter / 1000;
                cm = meter * 100;
                cout << "Hasil Konversi:" << endl;
                cout << meter << " meter = " << km << " kilometer " << endl;
                cout << meter << " meter = " << cm << " centimeter " << endl;
                break;

            case 2:
                cout << "Masukkan nilai dalam satuan Kilometer: ";
                cin >> km;
                meter = km * 1000;
                cm = km * 100000;
                cout << "Hasil Konversi:" << endl;
                cout << km << " km = " << meter << " meter " << endl;
                cout << km << " km = " << cm << " centimeter " << endl;
                break;

            case 3:
                cout << "Masukkan nilai dalam satuan Centimeter: ";
                cin >> cm;
                meter = cm / 100;
                km = cm / 100000;
                cout << "Hasil Konversi:" << endl;
                cout << cm << " cm = " << meter << " meter " << endl;
                cout << cm << " cm = " << km << " kilometer " << endl;
                break;

            case 4:
                cout << "Terima kasih telah menggunakan program ini.";
                break;

            default:
                cout << "Pilihan tidak valid! Silakan pilih 1-4." << endl;
        }

    } while (pilihan != 4);

    return 0;
}