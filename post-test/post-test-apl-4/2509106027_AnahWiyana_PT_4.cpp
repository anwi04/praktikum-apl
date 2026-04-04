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

bool login(User user);
void tambahPesanan(Album *data, int *jumlahdata);
void lihatPesanan(Album data[], int jumlahdata);
void lihatPesanan(Album data[], int jumlahdata, string grup);
void ubahPesanan(Album data[], int jumlahdata);
void hapusPesanan(Album *data, int *jumlahdata);
int totalPesanan(Album data[], int n);

int main(){

    User user = {"Anah","027"};

    cout << "=========================================" << endl;
    cout << "      Sistem Pemesanan Album K-pop       " << endl;
    cout << "=========================================" << endl;

    if(!login(user)){
        return 0;
    }

    Album data[100];
    int jumlahdata = 0;
    int pilihan;

    do{
        cout << "\n========================================" << endl;
        cout << "              MENU UTAMA                " << endl;
        cout << "========================================" << endl;
        cout << "1. Lakukan Pemesanan" << endl;
        cout << "2. Lihat Data Pesanan" << endl;
        cout << "3. Ubah Data Pesanan" << endl;
        cout << "4. Hapus Pesanan" << endl;
        cout << "5. Lihat Total Pesanan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;
        cin.ignore();

        switch(pilihan){

        case 1:
            tambahPesanan(data, &jumlahdata);
            break;

        case 2:
            lihatPesanan(data, jumlahdata);
            break;

        case 3:
            ubahPesanan(data, jumlahdata);
            break;

        case 4:
            hapusPesanan(data, &jumlahdata);
            break;

        case 5:
            cout << "Total seluruh pesanan album : "
                 << totalPesanan(data, jumlahdata) << endl;
            break;

        case 6:
            cout << "Program selesai." << endl;
            break;

        default:
            cout << "Pilihan tidak tersedia!" << endl;
        }

    }while(pilihan != 6);
}

bool login(User user){

    string nama, password;
    int kesempatan = 3;

    while (kesempatan > 0){
        cout << "\n=============== LOGIN ===============" << endl;
        cout << "Masukkan Nama     : ";
        cin >> nama;
        cout << "Masukkan Password : ";
        cin >> password;

        if(nama == user.nama && password == user.nim){
            cout << "Login Berhasil!" << endl;
            return true;
        }else{
            kesempatan--;
            cout << "Login gagal! Sisa kesempatan: "
                 << kesempatan << endl;
        }
    }

    cout << "Percobaan login melebihi batas!" << endl;
    return false;
}

void tambahPesanan(Album *data, int *jumlahdata){

    cout << "Nama Pembeli : ";
    getline(cin, data[*jumlahdata].nama_pembeli);

    cout << "Nama Album   : ";
    getline(cin, data[*jumlahdata].nama_album);

    cout << "Nama Grup    : ";
    getline(cin, data[*jumlahdata].nama_grup);

    cout << "Nama Agensi  : ";
    getline(cin, data[*jumlahdata].nama_agensi);

    cout << "Jumlah Pesanan : ";
    cin >> data[*jumlahdata].jumlah;
    cin.ignore();

    (*jumlahdata)++;

    cout << "Pemesanan berhasil!" << endl;
}

void lihatPesanan(Album data[], int jumlahdata){

    cout << "\n===================================================" << endl;
    cout << "                DATA PESANAN ALBUM                 " << endl;
    cout << "===================================================" << endl;

    for(int i=0;i<jumlahdata;i++){
        cout << i+1 << " | "
             << data[i].nama_pembeli << " | "
             << data[i].nama_album << " | "
             << data[i].nama_grup << " | "
             << data[i].nama_agensi << " | "
             << data[i].jumlah << endl;
    }
}

void lihatPesanan(Album data[], int jumlahdata, string grup){

    cout << "\nPesanan dari grup: " << grup << endl;

    for(int i=0;i<jumlahdata;i++){
        if(data[i].nama_grup == grup){
            cout << data[i].nama_pembeli << " | "
                 << data[i].nama_album << " | "
                 << data[i].jumlah << endl;
        }
    }
}

void ubahPesanan(Album data[], int jumlahdata){

    int ubah;

    cout << "Masukkan nomor data yang ingin diubah: ";
    cin >> ubah;
    cin.ignore();

    if(ubah < 1 || ubah > jumlahdata){
        cout << "Nomor data tidak valid!" << endl;
        return;
    }

    cout << "Nama Pembeli Baru : ";
    getline(cin, data[ubah-1].nama_pembeli);

    cout << "Nama Album Baru : ";
    getline(cin, data[ubah-1].nama_album);

    cout << "Nama Grup Baru : ";
    getline(cin, data[ubah-1].nama_grup);

    cout << "Nama Agensi Baru : ";
    getline(cin, data[ubah-1].nama_agensi);

    cout << "Jumlah Baru : ";
    cin >> data[ubah-1].jumlah;
    cin.ignore();

    cout << "Data berhasil diubah!" << endl;
}

void hapusPesanan(Album *data, int *jumlahdata){

    int hapus;

    cout << "Masukkan nomor data yang ingin dihapus: ";
    cin >> hapus;

    if(hapus < 1 || hapus > *jumlahdata){
        cout << "Nomor data tidak valid!" << endl;
        return;
    }

    for(int i=hapus-1;i< (*jumlahdata)-1;i++){
        data[i] = data[i+1];
    }

    (*jumlahdata)--;

    cout << "Data berhasil dihapus!" << endl;
}

int totalPesanan(Album data[], int n){

    if(n == 0)
        return 0;
    else
        return data[n-1].jumlah + totalPesanan(data, n-1);
}