#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int binarySearch(int arr[], int kiri, int kanan, int target)
{
    while (kiri <= kanan)
    {
        int tengah = kiri + (kanan - kiri) / 2;

        if (arr[tengah] == target)
            return tengah;
        else if (arr[tengah] < target)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    return -1;
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
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                adaTukar = true;
            }
        }
        if (!adaTukar)
            break;
    }
}

int main()
{
    int N, X;
    cin >> N >> X;

    srand(time(NULL));

    int arr[N];
    int sorted[N];

    cout << "Array : ";
    for (int i = 0; i < N; i++)
    {
        arr[i] = (rand() % 25) + 1;
        sorted[i] = arr[i];
        cout << arr[i];
        if (i < N - 1)
            cout << " ";
    }
    cout << endl;

    bubbleSort(sorted, N);

    int count = 0;

    for (int i = 0; i < N - 1; i++)
    {
        if (i > 0 && sorted[i] == sorted[i - 1])
            continue;

        int komplemen = X - sorted[i];

        if (komplemen < sorted[i])
            continue;

        if (komplemen == sorted[i])
        {
            if (i + 1 < N && sorted[i + 1] == sorted[i])
                count++;
            continue;
        }

        int idx = binarySearch(sorted, i + 1, N - 1, komplemen);

        if (idx != -1)
            count++;
    }

    cout << count << endl;

    return 0;
}