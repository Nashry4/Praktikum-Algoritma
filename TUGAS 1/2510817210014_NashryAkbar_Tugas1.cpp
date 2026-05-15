#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct TNode
{
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[3];
string dataBaru, dataHapus;

void init();
int isEmpty();
int hitungNode();

void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main()
{
    init();

    do
    {
        cout << "Single Linked List Circular (SLLC)" << endl;
        cout << "====================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Hapus Semua Elemen" << endl;
        cout << "7. Cari Data" << endl;
        cout << "8. Hapus Setiap Data Tertentu" << endl;
        cout << "9. Sisipkan Node/Data Baru Sebelum Data Tertentu" << endl;
        cout << "10. Sisipkan Node/Data Baru Setelah Data Tertentu" << endl;
        cout << "11. Quit" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        pil = atoi(pilihan);

        switch (pil)
        {
        case 1:
            tambahDepan();
            break;
        case 2:
            tambahBelakang();
            break;
        case 3:
            hapusDepan();
            break;
        case 4:
            hapusBelakang();
            break;
        case 5:
            tampilkan();
            break;
        case 6:
            reset();
            break;
        case 7:
            cariData();
            break;
        case 8:
            hapusData();
            break;
        case 9:
            sisipkanSebelum();
            break;
        case 10:
            sisipkanSetelah();
            break;
        default:
            cout << "\nTERIMA KASIH" << endl;
            cout << "Program was made by Nashry Akbar (2510817210014)." << endl;
        }

        cout << "\nPress any key to continue!" << endl;
        getch();
        system("cls");

    } while (pil < 11);
}

void init()
{
    head = NULL;
    tail = NULL;
}

int isEmpty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

int hitungNode()
{
    if (isEmpty() == 1)
        return 0;

    int count = 0;
    TNode *bantu = head;
    do
    {
        count++;
        bantu = bantu->next;
    } while (bantu != head);

    return count;
}

void tambahDepan()
{
    cout << "Masukkan data: ";
    cin.ignore();

    string baris;
    getline(cin, baris);

    stringstream ss(baris);
    string token;

    string tokens[255];
    int jumlah = 0;

    while (ss >> token)
    {
        tokens[jumlah++] = token;
    }

    if (jumlah == 0)
    {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    for (int i = jumlah - 1; i >= 0; i--)
    {
        TNode *baru = new TNode;
        baru->data = tokens[i];
        baru->next = baru;

        if (isEmpty() == 1)
        {
            head = baru;
            tail = baru;
        }
        else
        {
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }

    cout << "Data \"";
    for (int i = 0; i < jumlah; i++)
    {
        cout << tokens[i];
        if (i < jumlah - 1)
            cout << " ";
    }
    cout << "\" berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakang()
{
    cout << "Masukkan data : ";
    TNode *baru;
    baru = new TNode;
    cin >> dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if (isEmpty() == 1)
    {
        head = baru;
        tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian belakang." << endl;
}

void hapusDepan()
{
    if (isEmpty() == 1)
    {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    int N;
    cout << "Hapus node ke-N dari depan. Masukkan N : ";
    cin >> N;

    int total = hitungNode();

    if (N > total)
    {
        cout << "N melebihi jumlah node (" << total << "). Node yang dihapus adalah tail." << endl;
        N = total;
    }

    for (int i = 0; i < N; i++)
    {
        TNode *hapus = head;
        dataHapus = hapus->data;

        if (head == tail)
        {

            init();
        }
        else
        {
            head = head->next;
            tail->next = head;
        }

        cout << "Node ke-" << (i + 1) << " dari depan : \"" << dataHapus << "\" berhasil dihapus." << endl;
        delete hapus;
    }
}

void hapusBelakang()
{
    if (isEmpty() == 1)
    {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    int N;
    cout << "Hapus node ke-N dari belakang. Masukkan N : ";
    cin >> N;

    int total = hitungNode();

    if (N > total)
    {
        cout << "N melebihi jumlah node (" << total << "). Node yang dihapus adalah head." << endl;
        N = total;
    }

    for (int i = 0; i < N; i++)
    {
        TNode *hapus = tail;
        dataHapus = hapus->data;

        if (head == tail)
        {

            init();
        }
        else
        {

            TNode *newTail = head;
            while (newTail->next != tail)
            {
                newTail = newTail->next;
            }
            tail = newTail;
            tail->next = head;
        }

        cout << "Node ke-" << (i + 1) << " dari belakang : \"" << dataHapus << "\" berhasil dihapus." << endl;
        delete hapus;
    }
}

void tampilkan()
{
    if (isEmpty() == 0)
    {
        TNode *bantu;
        bantu = head;

        cout << "Linked List : ";
        do
        {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        } while (bantu != head);
        cout << endl;
    }
    else
        cout << "Tidak terdapat data pada Linked List." << endl;
}

void reset()
{
    if (isEmpty() == 1)
    {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    int nodeKe = 1;

    while (isEmpty() == 0)
    {
        TNode *hapus = head;
        string isiNode = hapus->data;

        if (head == tail)
        {

            init();
        }
        else
        {
            head = head->next;
            tail->next = head;
        }

        cout << "Menghapus node ke-" << nodeKe << " : \"" << isiNode << "\"" << endl;
        delete hapus;
        nodeKe++;
    }

    cout << "Seluruh elemen pada Linked List telah dibersihkan." << endl;
}

void cariData()
{
    if (isEmpty() == 0)
    {
        string cari;
        cout << "Masukkan data yang ingin dicari : ";
        cin >> cari;

        TNode *bantu, *bantuTampilkan;
        bool apaDitemukan = false;

        bantu = head;

        do
        {
            if (cari == bantu->data)
            {
                cout << "Setiap data yang berada di dalam tanda kurung siku ([...]) "
                     << "merupakan data yang anda cari." << endl;
                cout << "Linked List : ";
                bantuTampilkan = head;

                do
                {
                    if (cari == bantuTampilkan->data)
                        cout << "[" << bantuTampilkan->data << "] ";
                    else
                        cout << bantuTampilkan->data << ' ';
                    bantuTampilkan = bantuTampilkan->next;
                } while (bantuTampilkan != head);

                apaDitemukan = true;
                cout << endl;
                break;
            }
            bantu = bantu->next;
        } while (bantu != head);

        if (apaDitemukan == false)
            cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    }
    else
        cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusData()
{
    if (isEmpty() == 0)
    {
        string cari;
        cout << "Masukkan data yang ingin dihapus : ";
        cin >> cari;

        TNode *bantu, *sebelum, *hapus[255], *bantu2;
        int hitung = 0;
        bool apaDitemukan = false;

        bantu = head;

        do
        {
            bantu2 = bantu;
            if (cari == bantu->data)
            {
                hapus[hitung++] = bantu;
                apaDitemukan = true;
                if (bantu != head && bantu != tail)
                {
                    sebelum->next = bantu->next;
                    bantu2 = sebelum;
                }
            }
            sebelum = bantu2;
            bantu = bantu->next;
        } while (bantu != head);

        if (apaDitemukan == true)
        {
            for (int i = 0; i < hitung; i++)
            {
                if (hapus[i] == head)
                    hapusDepan();
                else if (hapus[i] == tail)
                    hapusBelakang();
                else
                    delete hapus[i];
            }
            cout << "Setiap data \"" << cari << "\" yang terdapat pada Linked List telah dihapus." << endl;
        }
        else
            cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    }
    else
        cout << "Tidak terdapat data pada Linked List." << endl;
}

void sisipkanSebelum()
{
    if (isEmpty() == 0)
    {
        TNode *bantu, *sebelum;
        string nextData;
        bool apaAda = false;

        bantu = head;
        sebelum = tail;

        cout << "Sisipkan data baru sebelum data : ";
        cin >> nextData;

        do
        {
            if (nextData == bantu->data)
            {
                apaAda = true;
                break;
            }
            else
            {
                sebelum = bantu;
                bantu = bantu->next;
            }
        } while (bantu != head);

        if (apaAda == true)
        {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;

            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu;
            sebelum->next = baru;

            if (bantu == head)
                head = baru;

            cout << "Data \"" << dataBaru << "\" berhasil disisipkan sebelum data \"" << nextData << "\"." << endl;
        }
        else
            cout << "Tidak terdapat data \"" << nextData << "\" pada Linked List." << endl;
    }
    else
        cout << "Tidak terdapat data pada Linked List." << endl;
}

void sisipkanSetelah()
{
    if (isEmpty() == 0)
    {
        TNode *bantu;
        string prevData;
        bool apaAda = false;

        bantu = head;

        cout << "Sisipkan data baru setelah data : ";
        cin >> prevData;

        do
        {
            if (prevData == bantu->data)
            {
                apaAda = true;
                break;
            }
            else
                bantu = bantu->next;
        } while (bantu != head);

        if (apaAda == true)
        {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;

            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu->next;
            bantu->next = baru;

            if (bantu == tail)
                tail = baru;

            cout << "Data \"" << dataBaru << "\" berhasil disisipkan setelah data \"" << prevData << "\"." << endl;
        }
        else
            cout << "Tidak terdapat data \"" << prevData << "\" pada Linked List." << endl;
    }
    else
        cout << "Tidak terdapat data pada Linked List." << endl;
}