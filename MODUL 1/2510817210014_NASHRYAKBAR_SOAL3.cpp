#include <iostream>
#include <string>
using namespace std;

struct InputData
{
    char huruf;
    string kata;
    int angka;
};

int main()
{
    InputData data;
    cout << "Masukkan Sebuah Huruf= ";
    cin >> data.huruf;

    cout << "Masukkan Sebuah Kata= ";
    cin >> data.kata;

    cout << "Masukkan Sebuah Angka= ";
    cin >> data.angka;

    cout << "Huruf Yang Anda Masukkan Adalah " << data.huruf << "" << endl;
    cout << "Kata Yang Anda Masukkan Adalah " << data.kata << "" << endl;
    cout << "Angka Yang Anda Masukkan Adalah " << data.angka << "" << endl;

    return 0;
}