#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

void tampilkanGaris()
{
    cout << " +----------------------------------+" << endl;
}

void tampilkanMenu()
{
    cout << "\n";
    tampilkanGaris();
    cout << " |           S O R T I N G          |" << endl;
    tampilkanGaris();
    cout << " |  1. Insertion Sort  (Nama)       |" << endl;
    cout << " |  2. Merge Sort      (Nama)       |" << endl;
    cout << " |  3. Shell Sort      (Nama)       |" << endl;
    cout << " |  4. Quick Sort      (NIM)        |" << endl;
    cout << " |  5. Bubble Sort     (NIM)        |" << endl;
    cout << " |  6. Selection Sort  (NIM)        |" << endl;
    cout << " |  7. Exit                         |" << endl;
    tampilkanGaris();
    cout << " Masukkan Pilihan : ";
}

void namaKeArray(const string &nama, char arr[], int &n)
{
    n = 0;
    for (int i = 0; i < (int)nama.size(); i++)
    {
        if (nama[i] != ' ')
        {
            arr[n++] = nama[i];
        }
    }
}

void nimKeArray(const string &nim, int arr[], int &n)
{
    n = 0;
    for (int i = 0; i < (int)nim.size(); i++)
    {
        if (nim[i] >= '0' && nim[i] <= '9')
        {
            arr[n++] = nim[i] - '0';
        }
    }
}

void tampilkanChar(char arr[], int n, const string &label)
{
    cout << label;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void tampilkanInt(int arr[], int n, const string &label)
{
    cout << label;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void insertionSort(char arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        char kunci = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > kunci)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = kunci;
    }
}

void merge(char arr[], int kiri, int tengah, int kanan)
{
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    char L[MAX], R[MAX];

    for (int i = 0; i < n1; i++)
        L[i] = arr[kiri + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(char arr[], int kiri, int kanan)
{
    if (kiri < kanan)
    {
        int tengah = kiri + (kanan - kiri) / 2;
        mergeSort(arr, kiri, tengah);
        mergeSort(arr, tengah + 1, kanan);
        merge(arr, kiri, tengah, kanan);
    }
}

void shellSort(char arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            char temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int partisi(int arr[], int rendah, int tinggi)
{
    int pivot = arr[tinggi];
    int i = rendah - 1;
    for (int j = rendah; j < tinggi; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[tinggi]);
    return i + 1;
}

void quickSort(int arr[], int rendah, int tinggi)
{
    if (rendah < tinggi)
    {
        int pi = partisi(arr, rendah, tinggi);
        quickSort(arr, rendah, pi - 1);
        quickSort(arr, pi + 1, tinggi);
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool adaTukar = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                adaTukar = true;
            }
        }
        if (!adaTukar)
            break;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idxMin = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[idxMin])
                idxMin = j;
        if (idxMin != i)
            swap(arr[i], arr[idxMin]);
    }
}

void handleNamaSort(int pilihan)
{
    string nama;
    char arrUrut[MAX];
    int n;

    cout << " Masukkan Nama : ";
    cin.ignore();
    getline(cin, nama);

    if (nama.empty())
    {
        cout << "\n [!] Nama tidak boleh kosong!\n";
        return;
    }

    namaKeArray(nama, arrUrut, n);

    switch (pilihan)
    {
    case 1:
        insertionSort(arrUrut, n);
        break;
    case 2:
        mergeSort(arrUrut, 0, n - 1);
        break;
    case 3:
        shellSort(arrUrut, n);
        break;
    }

    cout << "\n ==================================" << endl;
    cout << " Nama Input  : " << nama << endl;
    tampilkanChar(arrUrut, n, " Hasil Urut  : ");
    cout << " ==================================" << endl;
}

void handleNIMSort(int pilihan)
{
    string nim;
    int arrUrut[MAX];
    int n;

    cout << " Masukkan NIM  : ";
    cin.ignore();
    getline(cin, nim);

    if (nim.empty())
    {
        cout << "\n [!] NIM tidak boleh kosong!\n";
        return;
    }
    for (int i = 0; i < (int)nim.size(); i++)
    {
        if (nim[i] < '0' || nim[i] > '9')
        {
            cout << "\n [!] NIM hanya boleh berisi angka!\n";
            return;
        }
    }

    nimKeArray(nim, arrUrut, n);

    switch (pilihan)
    {
    case 4:
        quickSort(arrUrut, 0, n - 1);
        break;
    case 5:
        bubbleSort(arrUrut, n);
        break;
    case 6:
        selectionSort(arrUrut, n);
        break;
    }

    cout << "\n ==================================" << endl;
    cout << " NIM Input   : " << nim << endl;
    tampilkanInt(arrUrut, n, " Hasil Urut  : ");
    cout << " ==================================" << endl;
}

int main()
{
    int pilihan;

    do
    {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        case 2:
        case 3:
            handleNamaSort(pilihan);
            break;
        case 4:
        case 5:
        case 6:
            handleNIMSort(pilihan);
            break;
        case 7:
            cout << "\n Program selesai. Terima kasih!\n"
                 << endl;
            break;
        default:
            cout << "\n [!] Pilihan tidak valid. Masukkan angka 1-7.\n";
        }

    } while (pilihan != 7);

    return 0;
}