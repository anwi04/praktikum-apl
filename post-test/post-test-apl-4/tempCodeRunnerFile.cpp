void tambahPesanan(Album *data, int *jumlahdata){

    if(*jumlahdata >= 100){
        cout << "Data sudah penuh! Tidak bisa menambah pesanan lagi." << endl;
        return;
    }

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