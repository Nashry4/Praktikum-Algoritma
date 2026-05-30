#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

int randomNum(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

void sequentialSearch()
{
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;

    randomize();

    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++)
    {
        data[i] = randomNum(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\ndone.\n");

    for (int i = 0; i < 100; i++)
    {
        if (data[i] == cari)
        {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1)
    {
        printf("Data ada, sebanyak %d\n", counter);
        printf("pada indeks ke-%d", save);
    }
    else
    {
        printf("Data tidak ada!\n");
    }
}

void binarySearch()
{
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukkan jumlah data? ";
    cin >> n;

    int angka[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Angka ke- [" << i << "] : ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "\n==========================================================\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++)
    {
        cout << angka[i] << " ";
    }

    cout << "\n==========================================================\n";
    cout << "Masukkan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;

    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;

        if (key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if (key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true)
        cout << "Angka ditemukan! ";
    else
        cout << "Angka tidak ditemukan!";
}

void jelaskanPerbedaan()
{
    cout << "\n==========================================================\n";
    cout << "  PERBEDAAN SEQUENTIAL SEARCHING DAN BINARY SEARCHING\n";
    cout << "==========================================================\n";

    cout << "\n[1] SEQUENTIAL SEARCHING\n";
    cout << "----------------------------------------------------------\n";
    cout << "Definisi  : Mencari data dengan menelusuri elemen array\n";
    cout << "            satu per satu dari awal hingga akhir.\n";
    cout << "Syarat    : Data TIDAK perlu terurut.\n";
    cout << "\nKelebihan :\n";
    cout << "  + Dapat digunakan pada data yang tidak terurut.\n";
    cout << "  + Implementasi sangat sederhana.\n";
    cout << "  + Dapat menemukan SEMUA kemunculan data yang dicari.\n";
    cout << "\nKekurangan :\n";
    cout << "  - Lambat pada data berjumlah besar.\n";

    cout << "\n[2] BINARY SEARCHING\n";
    cout << "----------------------------------------------------------\n";
    cout << "Definisi  : Mencari data dengan membagi array menjadi dua,\n";
    cout << "            membandingkan target dengan elemen tengah,\n";
    cout << "            lalu membuang setengah yang tidak relevan.\n";
    cout << "Syarat    : Data harus terurut terlebih dahulu.\n";
    cout << "\nKelebihan :\n";
    cout << "  + Sangat cepat pada data berjumlah besar.\n";
    cout << "\nKekurangan :\n";
    cout << "  - Data harus diurutkan terlebih dahulu.\n";
    cout << "  - Tidak efisien jika data sering berubah.\n";
}

int main()
{
    int pilih;

    do
    {
        cout << "\nPilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching?" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            sequentialSearch();
            break;
        case 2:
            binarySearch();
            break;
        case 3:
            jelaskanPerbedaan();
            break;
        case 4:
            cout << "\nTERIMA KASIH" << endl;
            cout << "Program was made by Nashry Akbar (2510817210014)." << endl;
            break;
        default:
            cout << "Pilihan tidak valid! Masukkan angka 1-4." << endl;
        }

        if (pilih != 4)
        {
            cout << "\nPress any key to continue...";
            cin.ignore();
            cin.get();
            clrscr();
        }

    } while (pilih != 4);

    return 0;
}