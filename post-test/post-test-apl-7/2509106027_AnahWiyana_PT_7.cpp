#include <iostream>
using namespace std;
#include <stdexcept>

struct User {
    string nama;
    string nim;
};

struct Album {
    int id;
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
void bubbleSortGrup(Album data[], int n);
void selectionSortJumlah(Album data[], int n);
void insertionSortAlbum(Album data[], int n);
void cariByID(Album *data, int jumlahdata);
void binarySearchAlbum(Album *data, int jumlahdata);

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
        cout << "3. Lihat Pesanan Berdasarkan Grup" << endl;
        cout << "4. Ubah Data Pesanan" << endl;
        cout << "5. Hapus Pesanan" << endl;
        cout << "6. Lihat Total Pesanan" << endl;
        cout << "7. Urutkan Data Berdasarkan Nama" << endl;
        cout << "8. Urutkan Data Berdasarkan Jumlah" << endl;
        cout << "9. Urutkan Data Berdasarkan Judul" << endl;
        cout << "10. Cari berdasarkan ID" << endl;
        cout << "11. Cari berdasarkan Nama Album" << endl;
        cout << "12. Keluar" << endl;
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

        case 3:{
            string grup;
            cout << "Masukan Nama Grup: ";
            getline(cin, grup);
            lihatPesanan(data, jumlahdata, grup);
            break;
        }
        case 4:
            ubahPesanan(data, jumlahdata);
            break;
   
        case 5:
            hapusPesanan(data, &jumlahdata);
            break;

        case 6:
            cout << "Total seluruh pesanan album : "
                 << totalPesanan(data, jumlahdata) << endl;
            break;

        case 7:
            bubbleSortGrup(data, jumlahdata);
            break;

        case 8:
            selectionSortJumlah(data, jumlahdata);
            break;

        case 9:
            insertionSortAlbum(data, jumlahdata);
            break;

        case 10:
            cariByID(data,  jumlahdata);
            break;
        
        case 11:
            insertionSortAlbum(data, jumlahdata);
            binarySearchAlbum(data, jumlahdata);
            break;

        case 12:
            cout << "Program selesai." << endl;
            break;

        default:
            cout << "Pilihan tidak tersedia!" << endl;
        }

    }while(pilihan != 12);
}

bool login(User user){

    string nama, password;
    int kesempatan = 3;

    while (kesempatan > 0){
        try{
            cout << "\n=============== LOGIN ===============" << endl;
            cout << "Masukkan Nama     : ";
            cin >> nama;

            cout << "Masukkan Password : ";
            cin >> password;

            if(nama.empty() || password.empty()){
                throw runtime_error("Input tidak boleh kosong!");
            }

            if(nama == user.nama && password == user.nim){
                cout << "Login Berhasil!" << endl;
                return true;
            }else{
                throw runtime_error("Nama atau password salah!");
            }

        }catch(exception &e){
            kesempatan--;
            cout << "Error: " << e.what() << endl;
            cout << "Sisa kesempatan: " << kesempatan << endl;
        }
    }

    cout << "Percobaan login melebihi batas!" << endl;
    return false;
}

void tambahPesanan(Album *data, int *jumlahdata){

    try{
        if(*jumlahdata >= 100){
            throw runtime_error("Data penuh!");
        }

        data[*jumlahdata].id = *jumlahdata + 1;

        cout << "Nama Pembeli : ";
        getline(cin, data[*jumlahdata].nama_pembeli);

        if(data[*jumlahdata].nama_pembeli.empty()){
            throw runtime_error("Nama pembeli tidak boleh kosong!");
        }

        cout << "Nama Album   : ";
        getline(cin, data[*jumlahdata].nama_album);

        cout << "Nama Grup    : ";
        getline(cin, data[*jumlahdata].nama_grup);

        cout << "Nama Agensi  : ";
        getline(cin, data[*jumlahdata].nama_agensi);

        cout << "Jumlah Pesanan : ";
        cin >> data[*jumlahdata].jumlah;

        if(cin.fail()){
            throw runtime_error("Jumlah harus angka!");
        }

        cin.ignore();

        (*jumlahdata)++;

        cout << "Pemesanan berhasil!" << endl;

    }catch(exception &e){
        cout << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void lihatPesanan(Album data[], int jumlahdata){

    cout << "\n===================================================" << endl;
    cout << "                DATA PESANAN ALBUM                 " << endl;
    cout << "===================================================" << endl;

    for(int i=0;i<jumlahdata;i++){
        cout << i+1 << " | "
             << data[i].id << " | "
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

    try{
        int ubah;

        cout << "Masukkan nomor data yang ingin diubah: ";
        cin >> ubah;

        if(cin.fail()){
            throw runtime_error("Input harus angka!");
        }

        cin.ignore();

        if(ubah < 1 || ubah > jumlahdata){
            throw out_of_range("Nomor tidak valid!");
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

        cout << "Data berhasil diubah!" << endl;

    }catch(exception &e){
        cout << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void hapusPesanan(Album *data, int *jumlahdata){
    try{
        int hapus;

        cout << "Masukkan nomor data yang ingin dihapus: ";
        cin >> hapus;

        if(cin.fail()){
            throw runtime_error("Input harus angka!");
        }

        if(hapus < 1 || hapus > *jumlahdata){
            throw out_of_range("Nomor tidak valid!");
        }

        for(int i=hapus-1;i< (*jumlahdata)-1;i++){
            data[i] = data[i+1];
        }

        (*jumlahdata)--;

        cout << "Data berhasil dihapus!" << endl;

    }catch(exception &e){
        cout << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void bubbleSortGrup(Album data[], int n){

    if(n == 0){
        cout << "Data masih kosong!" << endl;
        return;
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(data[j].nama_grup > data[j+1].nama_grup){
                swap(data[j], data[j+1]);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan nama grup." << endl;

    lihatPesanan(data, n);
}

void selectionSortJumlah(Album data[], int n){

    if(n == 0){
        cout << "Data masih kosong!" << endl;
        return;
    }

    for(int i = 0; i < n-1; i++){
        int maxIdx = i;
        for(int j = i+1; j < n; j++){
            if(data[j].jumlah > data[maxIdx].jumlah){
                maxIdx = j;
            }
        }
        swap(data[i], data[maxIdx]);
    }
    cout << "Data berhasil diurutkan berdasarkan jumlah." << endl;

    lihatPesanan(data, n);
}

void insertionSortAlbum(Album data[], int n){

    if(n == 0){
        cout << "Data masih kosong!" << endl;
        return;
    }

    for(int i = 1; i < n; i++){
        Album key = data[i];
        int j = i - 1;

        while(j >= 0 && data[j].nama_album > key.nama_album){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
    cout << "Data berhasil diurutkan berdasarkan nama album." << endl;

    lihatPesanan(data, n);
}

void cariByID (Album *data, int jumlahdata){
    int cari;
    cout << "Masukan ID yang dicari: ";
    cin >> cari;

    bool ketemu = false;

    for(int i = 0; i < jumlahdata; i++){
        if(data[i].id == cari){
            cout << "Data ditemukan: " << endl;
            cout << data[i].nama_pembeli << " | "
                 << data[i].nama_album << " | "
                 << data[i].nama_grup << " | "
                 << data[i].jumlah << endl;
            ketemu = true;
            break;
        }
    }
    if(!ketemu){
        cout << "Data tidak ditemukan!" << endl;
    }

}

void binarySearchAlbum(Album *data, int jumlahdata){

    try{
        string cari;
        cout << "Masukan nama album yang di cari: ";
        getline(cin, cari);

        if(cari.empty()){
            throw runtime_error("Input tidak boleh kosong!");
        }

        int kiri = 0, kanan = jumlahdata - 1;
        bool ketemu = false;

        while(kiri <= kanan){
            int tengah = (kiri + kanan) / 2;

            if(data[tengah].nama_album == cari){
                cout << "Data ditemukan: " << endl;
                cout << data[tengah].nama_pembeli << " | "
                     << data[tengah].nama_grup << " | "
                     << data[tengah].jumlah << endl;
                ketemu = true;
                break;
            }
            else if(data[tengah].nama_album < cari){
                kiri = tengah + 1;
            }
            else{
                kanan = tengah - 1;
            }
        }

        if(!ketemu){
            throw runtime_error("Data tidak ditemukan!");
        }

    }catch(exception &e){
        cout << "Error: " << e.what() << endl;
    }
}

int totalPesanan(Album data[], int n){

    if(n == 0)
        return 0;
    else
        return data[n-1].jumlah + totalPesanan(data, n-1);
}