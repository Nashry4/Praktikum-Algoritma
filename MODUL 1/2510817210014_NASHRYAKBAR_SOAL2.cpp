#include <iostream>
#include <string>
using namespace std;

struct plat
{
    string nomor;
    string jenis;
    string nama;
    string alamat;
    string kota;
};

int main()
{
    plat mobil;
    mobil.nomor = "DA1234MK";
    mobil.jenis = "RUSH";
    mobil.nama = "Andika Hartanto";
    mobil.alamat = "Jl. Kayu Tangi 1";
    mobil.kota = "Banjarmasin";

    cout << "Plat Nomor Kendaraan : " << mobil.nomor << endl;
    cout << "Jenis Kendaraan      : " << mobil.jenis << endl;
    cout << "Nama Pemilik         : " << mobil.nama << endl;
    cout << "Alamat               : " << mobil.alamat << endl;
    cout << "Kota                 : " << mobil.kota << endl;
    return 0;
}