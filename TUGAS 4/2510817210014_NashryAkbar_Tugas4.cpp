#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int databaru)
{
    if (*root == NULL)
    {
        Node *baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        *root = baru;
    }
    else if (databaru < (*root)->data)
        tambah(&(*root)->kiri, databaru);
    else if (databaru > (*root)->data)
        tambah(&(*root)->kanan, databaru);
}

int hitungTinggi(Node *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int tinggiKiri = hitungTinggi(root->kiri, diameter);
    int tinggiKanan = hitungTinggi(root->kanan, diameter);

    int jarakMelaluiRoot = tinggiKiri + tinggiKanan;
    if (jarakMelaluiRoot > diameter)
        diameter = jarakMelaluiRoot;

    if (tinggiKiri > tinggiKanan)
        return tinggiKiri + 1;
    else
        return tinggiKanan + 1;
}

int main()
{
    int N;
    cin >> N;

    Node *pohon = NULL;

    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;
        tambah(&pohon, data);
    }

    int diameter = 0;
    hitungTinggi(pohon, diameter);

    cout << diameter << endl;

    return 0;
}