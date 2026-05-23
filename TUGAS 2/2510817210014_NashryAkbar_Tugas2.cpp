#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

typedef struct TNode
{
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[3];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main()
{
menu:
    cout << "Double Linked List Non Circular (DLLNC)" << endl;
    cout << "========================================" << endl;
    cout << "Pilihkan pilih program DLLNC yang ingin dijalankan!" << endl;
    cout << "1. DLLNC dengan Head" << endl;
    cout << "2. DLLNC dengan Head dan Tail" << endl;
    cout << "3. Quit" << endl;
    cout << "Pilihan : ";
    cin >> menu;
    system("cls");

    if (menu == 1)
    {
        initH();
        do
        {
            cout << "Double Linked List Non Circular (DLLNC) (Head)" << endl;
            cout << "===============================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Hapus Berdasarkan Target" << endl;
            cout << "7. Reset" << endl;
            cout << "8. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch (pil)
            {
            case 1:
                tambahDepanH();
                break;
            case 2:
                tambahBelakangH();
                break;
            case 3:
                tampilkanH();
                break;
            case 4:
                hapusDepanH();
                break;
            case 5:
                hapusBelakangH();
                break;
            case 6:
                hapusTargetH();
                break;
            case 7:
                clearH();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout << "\nPress any key to continue" << endl;
            getch();
            system("cls");

        } while (pil < 8);
    }
    else if (menu == 2)
    {
        initHT();
        do
        {
            cout << "Double Linked List Non Circular (DLLNC) (Head dan Tail)" << endl;
            cout << "========================================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Hapus Berdasarkan Target" << endl;
            cout << "7. Reset" << endl;
            cout << "8. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch (pil)
            {
            case 1:
                tambahDepanHT();
                break;
            case 2:
                tambahBelakangHT();
                break;
            case 3:
                tampilkanHT();
                break;
            case 4:
                hapusDepanHT();
                break;
            case 5:
                hapusBelakangHT();
                break;
            case 6:
                hapusTargetHT();
                break;
            case 7:
                clearHT();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout << "\nPress any key to continue" << endl;
            getch();
            system("cls");

        } while (pil < 8);
    }
    else
    {
        cout << "\nTERIMA KASIH" << endl;
        cout << "Program was made by Nashry Akbar (2510817210014)." << endl;
    }
}

void initH()
{
    head = NULL;
}

void initHT()
{
    head = NULL;
    tail = NULL;
}

int isEmptyH()
{
    return (head == NULL) ? 1 : 0;
}

int isEmptyHT()
{
    return (tail == NULL) ? 1 : 0;
}

int hitungNodeH()
{
    int count = 0;
    TNode *bantu = head;
    while (bantu != NULL)
    {
        count++;
        bantu = bantu->next;
    }
    return count;
}

int hitungNodeHT()
{
    int count = 0;
    TNode *bantu = head;
    while (bantu != NULL)
    {
        count++;
        bantu = bantu->next;
    }
    return count;
}

void sisipSatuDepanH(string nilai)
{
    TNode *baru = new TNode;
    baru->data = nilai;
    baru->next = NULL;
    baru->prev = NULL;

    if (isEmptyH() == 1)
    {
        head = baru;
    }
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
}

void sisipSatuBelakangH(string nilai)
{
    TNode *baru = new TNode;
    baru->data = nilai;
    baru->next = NULL;
    baru->prev = NULL;

    if (isEmptyH() == 1)
    {
        head = baru;
    }
    else
    {
        TNode *bantu = head;
        while (bantu->next != NULL)
            bantu = bantu->next;
        bantu->next = baru;
        baru->prev = bantu;
    }
}

void sisipSatuDepanHT(string nilai)
{
    TNode *baru = new TNode;
    baru->data = nilai;
    baru->next = NULL;
    baru->prev = NULL;

    if (isEmptyHT() == 1)
    {
        head = baru;
        tail = baru;
    }
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
}

void sisipSatuBelakangHT(string nilai)
{
    TNode *baru = new TNode;
    baru->data = nilai;
    baru->next = NULL;
    baru->prev = NULL;

    if (isEmptyHT() == 1)
    {
        head = baru;
        tail = baru;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void tambahDepanH()
{
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();

    string baris;
    getline(cin, baris);

    stringstream ss(baris);
    string token;
    string tokens[255];
    int jumlah = 0;

    while (ss >> token)
        tokens[jumlah++] = token;

    if (jumlah == 0)
    {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    TNode *headLama = head;

    for (int i = jumlah - 1; i >= 0; i--)
        sisipSatuDepanH(tokens[i]);

    (void)headLama;

    cout << "Data \"";
    for (int i = 0; i < jumlah; i++)
    {
        cout << tokens[i];
        if (i < jumlah - 1)
            cout << " ";
    }
    cout << "\" berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakangH()
{
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();

    string baris;
    getline(cin, baris);

    stringstream ss(baris);
    string token;
    string tokens[255];
    int jumlah = 0;

    while (ss >> token)
        tokens[jumlah++] = token;

    if (jumlah == 0)
    {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    for (int i = 0; i < jumlah; i++)
        sisipSatuBelakangH(tokens[i]);

    cout << "Data \"";
    for (int i = 0; i < jumlah; i++)
    {
        cout << tokens[i];
        if (i < jumlah - 1)
            cout << " ";
    }
    cout << "\" berhasil dimasukkan di bagian belakang." << endl;
}

void tambahDepanHT()
{
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();

    string baris;
    getline(cin, baris);

    stringstream ss(baris);
    string token;
    string tokens[255];
    int jumlah = 0;

    while (ss >> token)
        tokens[jumlah++] = token;

    if (jumlah == 0)
    {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    for (int i = jumlah - 1; i >= 0; i--)
        sisipSatuDepanHT(tokens[i]);

    cout << "Data \"";
    for (int i = 0; i < jumlah; i++)
    {
        cout << tokens[i];
        if (i < jumlah - 1)
            cout << " ";
    }
    cout << "\" berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakangHT()
{
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();

    string baris;
    getline(cin, baris);

    stringstream ss(baris);
    string token;
    string tokens[255];
    int jumlah = 0;

    while (ss >> token)
        tokens[jumlah++] = token;

    if (jumlah == 0)
    {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    for (int i = 0; i < jumlah; i++)
        sisipSatuBelakangHT(tokens[i]);

    cout << "Data \"";
    for (int i = 0; i < jumlah; i++)
    {
        cout << tokens[i];
        if (i < jumlah - 1)
            cout << " ";
    }
    cout << "\" berhasil dimasukkan di bagian belakang." << endl;
}

void hapusDepanH()
{
    if (isEmptyH() == 0)
    {
        TNode *hapus = head;
        string data = hapus->data;

        if (head->next != NULL)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
        {
            initH();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus." << endl;
    }
    else
        cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusDepanHT()
{
    if (isEmptyHT() == 0)
    {
        TNode *hapus = head;
        string data = hapus->data;

        if (head->next != NULL)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
        {
            initHT();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus." << endl;
    }
    else
        cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusBelakangH()
{
    if (isEmptyH() == 1)
    {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    int N;
    cout << "Hapus node ke-N dari belakang. Masukkan N : ";
    cin >> N;

    int total = hitungNodeH();

    if (N > total)
    {
        int Nasli = N;
        N = N % total;
        if (N == 0)
            N = total;
        cout << "N=" << Nasli << " melebihi jumlah node (" << total
             << "). Menggunakan sistem mundur, N menjadi " << N << "." << endl;
    }

    TNode *target = head;

    while (target->next != NULL)
        target = target->next;

    for (int i = 1; i < N; i++)
        target = target->prev;

    string data = target->data;

    if (target->prev != NULL)
        target->prev->next = target->next;
    else
        head = target->next;

    if (target->next != NULL)
        target->next->prev = target->prev;

    delete target;
    cout << "Node ke-" << N << " dari belakang (\"" << data << "\") berhasil dihapus." << endl;
}

void hapusBelakangHT()
{
    if (isEmptyHT() == 1)
    {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    int N;
    cout << "Hapus node ke-N dari belakang. Masukkan N : ";
    cin >> N;

    int total = hitungNodeHT();

    if (N > total)
    {
        int Nasli = N;
        N = N % total;
        if (N == 0)
            N = total;
        cout << "N=" << Nasli << " melebihi jumlah node (" << total
             << "). Menggunakan sistem mundur, N menjadi " << N << "." << endl;
    }

    TNode *target = tail;
    for (int i = 1; i < N; i++)
        target = target->prev;

    string data = target->data;

    if (target->prev != NULL)
        target->prev->next = target->next;
    else
        head = target->next;

    if (target->next != NULL)
        target->next->prev = target->prev;
    else
        tail = target->prev;

    delete target;
    cout << "Node ke-" << N << " dari belakang (\"" << data << "\") berhasil dihapus." << endl;
}

void hapusTargetH()
{
    if (isEmptyH() == 1)
    {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    string target;
    cout << "Masukkan data yang ingin dihapus : ";
    cin >> target;

    TNode *bantu = head;
    int jumlahHapus = 0;

    while (bantu != NULL)
    {
        TNode *selanjutnya = bantu->next;

        if (bantu->data == target)
        {

            if (bantu->prev != NULL)
                bantu->prev->next = bantu->next;
            else
                head = bantu->next;

            if (bantu->next != NULL)
                bantu->next->prev = bantu->prev;

            delete bantu;
            jumlahHapus++;
        }

        bantu = selanjutnya;
    }

    if (jumlahHapus > 0)
        cout << "Sebanyak " << jumlahHapus << " node dengan data \""
             << target << "\" berhasil dihapus." << endl;
    else
        cout << "Data \"" << target << "\" tidak ditemukan pada Linked List." << endl;
}

void hapusTargetHT()
{
    if (isEmptyHT() == 1)
    {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    string target;
    cout << "Masukkan data yang ingin dihapus : ";
    cin >> target;

    TNode *bantu = head;
    int jumlahHapus = 0;

    while (bantu != NULL)
    {
        TNode *selanjutnya = bantu->next;

        if (bantu->data == target)
        {
            if (bantu->prev != NULL)
                bantu->prev->next = bantu->next;
            else
                head = bantu->next;

            if (bantu->next != NULL)
                bantu->next->prev = bantu->prev;
            else
                tail = bantu->prev;

            delete bantu;
            jumlahHapus++;
        }

        bantu = selanjutnya;
    }

    if (jumlahHapus > 0)
        cout << "Sebanyak " << jumlahHapus << " node dengan data \""
             << target << "\" berhasil dihapus." << endl;
    else
        cout << "Data \"" << target << "\" tidak ditemukan pada Linked List." << endl;
}

void tampilkanH()
{
    if (isEmptyH() == 0)
    {
        TNode *bantu = head;
        cout << "Linked List : ";
        while (bantu != NULL)
        {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
        cout << "Tidak terdapat data pada Linked List." << endl;
}

void tampilkanHT()
{
    if (isEmptyHT() == 0)
    {
        TNode *bantu = head;
        cout << "Linked List : ";
        while (bantu != NULL)
        {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
        cout << "Tidak terdapat data pada Linked List." << endl;
}

void clearH()
{
    if (isEmptyH() == 1)
    {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    TNode *tailManual = head;
    while (tailManual->next != NULL)
        tailManual = tailManual->next;

    int urutan = 1;
    bool giliranDepan = true;

    while (head != NULL)
    {
        if (head == tailManual)
        {
            cout << "Urutan ke-" << urutan << " : \"" << head->data
                 << "\" (node terakhir)" << endl;
            delete head;
            head = NULL;
            tailManual = NULL;
        }
        else if (giliranDepan)
        {
            TNode *hapus = head;
            cout << "Urutan ke-" << urutan << " : \"" << hapus->data
                 << "\" (dari depan)" << endl;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            delete hapus;
        }
        else
        {

            TNode *hapus = tailManual;
            cout << "Urutan ke-" << urutan << " : \"" << hapus->data
                 << "\" (dari belakang)" << endl;
            tailManual = tailManual->prev;
            if (tailManual != NULL)
                tailManual->next = NULL;
            delete hapus;
        }

        giliranDepan = !giliranDepan;
        urutan++;
    }

    initH();
    cout << "Seluruh data pada Linked List telah dibersihkan." << endl;
}

void clearHT()
{
    if (isEmptyHT() == 1)
    {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    int urutan = 1;
    bool giliranDepan = true;

    while (head != NULL)
    {
        if (head == tail)
        {

            cout << "Urutan ke-" << urutan << " : \"" << head->data
                 << "\" (node terakhir)" << endl;
            delete head;
            head = NULL;
            tail = NULL;
        }
        else if (giliranDepan)
        {

            TNode *hapus = head;
            cout << "Urutan ke-" << urutan << " : \"" << hapus->data
                 << "\" (dari depan)" << endl;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            delete hapus;
        }
        else
        {

            TNode *hapus = tail;
            cout << "Urutan ke-" << urutan << " : \"" << hapus->data
                 << "\" (dari belakang)" << endl;
            tail = tail->prev;
            if (tail != NULL)
                tail->next = NULL;
            delete hapus;
        }

        giliranDepan = !giliranDepan;
        urutan++;
    }

    initHT();
    cout << "Seluruh data pada Linked List telah dibersihkan." << endl;
}