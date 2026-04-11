#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct Stack
{
    int Atas;
    int Data[MAX];
};

Stack Tumpuk;

int Kosong()
{
    if (Tumpuk.Atas == -1)
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
    if (Tumpuk.Atas == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(int Data)
{
    if (Kosong() == 1)
    {
        Tumpuk.Atas++;
        Tumpuk.Data[Tumpuk.Atas] = Data;
        cout << "Data " << Tumpuk.Data[Tumpuk.Atas] << " dimasukkan ke dalam Stack." << endl;
    }
    else if (Penuh() == 0)
    {
        Tumpuk.Atas++;
        Tumpuk.Data[Tumpuk.Atas] = Data;
        cout << "Data " << Tumpuk.Data[Tumpuk.Atas] << " dimasukkan ke dalam Stack." << endl;
    }
    else
    {
        cout << "Stack telah Penuh!!!" << endl;
    }
}

void Pop()
{
    if (Kosong() == 0)
    {
        cout << "Data " << Tumpuk.Data[Tumpuk.Atas] << " diambil dari Stack." << endl;
        Tumpuk.Atas--;
    }
    else
    {
        cout << "Stack Kosong!!!" << endl;
    }
}

void Cetak_Stack()
{
    if (Kosong() == 0)
    {
        for (int i = Tumpuk.Atas; i >= 0; i--)
        {
            cout << "\nTumpukan Ke " << i << " = " << Tumpuk.Data[i];
        }
        cout << endl;
    }
    else
    {
        cout << "Stack Kosong!!!" << endl;
    }
}

void Bersihkan_Stack()
{
    Tumpuk.Atas = -1;
    cout << "Stack telah dibersikan!!!" << endl;
}

void Inisialisasi()
{
    Tumpuk.Atas = -1;
}

int main()
{
    Inisialisasi();
    int Pilihan, Data;
    do
    {
        cout << "\nSTACK" << endl;
        cout << "==============" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. CETAK STACK" << endl;
        cout << "4. BERSIHKAN STACK" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : ";
        cin >> Pilihan;
        switch (Pilihan)
        {
        case 1:
            cout << "Masukkan Nilai: ";
            cin >> Data;
            Push(Data);
            break;

        case 2:
            Pop();
            break;

        case 3:
            Cetak_Stack();
            break;

        case 4:
            Bersihkan_Stack();
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