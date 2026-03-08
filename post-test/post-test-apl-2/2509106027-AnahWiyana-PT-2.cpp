#include <iostream>
using namespace std;

struct User {
    string nama;
    string nim;
};

struct Album {
    string nama_pembeli;
    string nama_album;
    string nama_grup;
    string nama_agensi;
    int jumlah;
};

int main() {
    User user = {"Anah", "027"};

    string nama, password;
    int kesempatan = 3;

    cout << "=========================================" << endl;
    cout << "      Sistem Pemesanan Album K-pop       " << endl;
    cout << "=========================================" << endl;

    while (kesempatan > 0) {
        cout << "================ LOGIN ================" << endl;
        cout << "Masukkan Nama     : ";
        cin >> nama;
        cout << "Masukkan Password : ";
        cin >> password;

        if (nama == user.nama && password == user.nim) {
            cout << "Login Berhasil!" << endl;
            break;
        } else {
            kesempatan--;
            cout << "Login Gagal! Sisa kesempatan: " << kesempatan << endl;
        }
    }

    if (kesempatan == 0) {
        cout << "Percobaan Login sudah mencapai batas maksimum. Program berhenti." << endl;
        return 0;
    }
    Album data [100];
    int jumlahdata = 0;
    int pilihan;
    do {
         cout << "========================================" << endl;
         cout << "              MENU UTAMA                " << endl;
         cout << "========================================" << endl;
         cout << "1. Lakukan Pemesanan. " << endl;
         cout << "2. Lihat Data Pesanan. " << endl;
         cout << "3. Ubah Data Pemesanan. " << endl;
         cout << "4. Hapus Pesanan. " << endl;
         cout << "5. Keluar." << endl;
         cout << "Pilih Menu :" ;
         cin >> pilihan;
         cin.ignore();

        switch (pilihan){

            case 1:{
                cout << "Nama Pembeli : ";
                getline(cin, data[jumlahdata].nama_pembeli);
                cout << "Nama Album   : ";
                getline(cin, data[jumlahdata].nama_album);
                cout << "Nama Grup    : ";
                getline(cin, data[jumlahdata].nama_grup);
                cout << "Nama Agensi  : ";
                getline(cin, data[jumlahdata].nama_agensi);
                cout << "Jumlah Yang Ingin Dipesan : ";
                while(!(cin >> data[jumlahdata].jumlah)){
                    cout << "Input harus angka! Masukkan lagi: ";
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
                
                cin.ignore();
                jumlahdata++;
                cout << "Pemesanan Berhasil!" << endl;
                break;
            }

            case 2:
            cout << "===============================================================" << endl;
            cout << "                     DATA PESANAN ALBUM KPOP                   " << endl;
            cout << "===============================================================" << endl;
            cout << "No | Pembeli | Album | Grup | Agensi | Jumlah" << endl;
            cout << "---------------------------------------------------------------" << endl;

            for(int i = 0; i < jumlahdata; i++){
                cout << i + 1 << " | "
                     << data[i].nama_pembeli << " | "
                     << data[i].nama_album << " | "
                     << data[i].nama_grup << " | "
                     << data[i].nama_agensi << " | "
                     << data[i].jumlah << endl;
            }

            cout << "===============================================================" << endl;
            break;

            case 3:{
            int ubah;
            cout << "Masukan Nomor Data Yang Ingin Anda Ubah  :" ;
            cin >> ubah;
            cin.ignore();
           
            if(ubah < 1 || ubah > jumlahdata){
                cout << "Nomor data tidak valid!" << endl;
                break;
            }

            cout << " Nama Pembeli Baru  :" ;
            getline(cin , data[ubah - 1].nama_pembeli);
            cout << " Nama Album Baru  :"  ;
            getline(cin , data[ubah - 1].nama_album);
            cout << " Nama Grup Baru  :" ;
            getline(cin , data[ubah - 1].nama_grup) ;
            cout << " Nama Agensi Baru  :" ;
            getline(cin , data[ubah - 1].nama_agensi) ;
            cout << " Jumlah Pesanan Yang Baru  :" ;
            cin >> data[ubah - 1].jumlah ;
            cin.ignore();
            
            cout << "Data Berhasil Di Ubah" << endl;
            break;
        }

            case 4:{
            int hapus;
            cout << "Masukan Nomor Data Yang Ingin Dihapus  :";
            cin >> hapus;
            if(hapus < 1 || hapus > jumlahdata){
                cout << "Nomor data tidak valid!" << endl;
                break; 
            }

            for(int i = hapus - 1; i < jumlahdata - 1; i++){
                data[i] = data[ i + 1];
            }

            jumlahdata--;
            cout << "Data Berhasil Di Hapus!" << endl;
            break;
        }

            case 5:
            cout << "Program selesai." << endl;
            break;

        default:
            cout << "Pilihan tidak tersedia!" << endl;     
        }
    } while (pilihan != 5);
}