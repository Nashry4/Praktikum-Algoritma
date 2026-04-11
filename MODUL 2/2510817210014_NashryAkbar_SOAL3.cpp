#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct Queue
{
    int Front, Rear, Size;
    char Q[MAX];
};

Queue Antrian;

int Kosong()
{
    if (Antrian.Front == Antrian.Rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Penuh()
{
    if ((Antrian.Rear + 1) % Antrian.Size == Antrian.Front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void INSERT(char huruf)
{
    if (Penuh() == 1)
    {
        cout << "Queue Penuh!!!" << endl;
    }
    else
    {
        Antrian.Q[Antrian.Rear] = huruf;
        cout << "Data: " << Antrian.Q[Antrian.Rear] << " masuk ke dalam Queue" << endl;
        Antrian.Rear = (Antrian.Rear + 1) % Antrian.Size;
    }
}

void DELETE()
{
    if (Kosong() == 1)
    {
        cout << "Queue kosong!!!" << endl;
    }
    else
    {
        cout << "Data yang dihapus: " << Antrian.Q[Antrian.Front] << endl;
        Antrian.Front = (Antrian.Front + 1) % Antrian.Size;
    }
}

void CETAKLAYAR()
{
    if (Kosong() == 1)
    {
        cout << "Queue kosong!!!" << endl;
    }
    else
    {
        int i = Antrian.Front;
        while (i != Antrian.Rear)
        {
            cout << "Queue ke-" << i << " = " << Antrian.Q[i] << endl;
            i = (i + 1) % Antrian.Size;
        }
    }
}

void RESET()
{
    Antrian.Front = 0;
    Antrian.Rear = 0;
    Antrian.Size = MAX;
    cout << "Queue telah di-reset" << endl;
}

void Inisialisasi()
{
    Antrian.Front = 0;
    Antrian.Rear = 0;
    Antrian.Size = MAX;
}

int main()
{
    Inisialisasi();
    int Pilihan;
    char huruf;
    do
    {
        cout << "\nQUEUE" << endl;
        cout << "==============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET QUEUE" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : ";
        cin >> Pilihan;
        switch (Pilihan)
        {
        case 1:
            cout << "Masukkan Nilai: ";
            cin >> huruf;
            INSERT(huruf);
            break;

        case 2:
            DELETE();
            break;

        case 3:
            CETAKLAYAR();
            break;

        case 4:
            RESET();
            break;

        default:
            cout << "TERIMA KASIH" << endl;
            break;
        }
        cout << "Press any key to continue";
        getch();
        system("cls");
    } while (Pilihan < 5);
    return 0;
}