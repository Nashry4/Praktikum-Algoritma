#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
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
        Node *baru;
        baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;
        (*root)->kiri = NULL;
        (*root)->kanan = NULL;
        cout << "Data bertambah";
    }
    else if (databaru < (*root)->data)
        tambah(&(*root)->kiri, databaru);
    else if (databaru > (*root)->data)
        tambah(&(*root)->kanan, databaru);
    else if (databaru == (*root)->data)
        cout << "Data sudah ada";
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main()
{
    int pil, data;
    Node *pohon;
    pohon = NULL;

    do
    {
        system("cls");
        cout << "================================" << endl;
        cout << "   BINARY SEARCH TREE (BST)     " << endl;
        cout << "================================" << endl;
        cout << "1. Tambah" << endl;
        cout << "2. PreOrder" << endl;
        cout << "3. InOrder" << endl;
        cout << "4. PostOrder" << endl;
        cout << "5. Exit" << endl;
        cout << "================================" << endl;
        cout << "\nPilihan : ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            cout << "\nINPUT    : ";
            cout << "\n----------";
            cout << "\nData baru : ";
            cin >> data;
            tambah(&pohon, data);
            break;

        case 2:
            cout << "\nPreOrder" << endl;
            cout << "------------------------" << endl;
            if (pohon != NULL)
                preOrder(pohon);
            else
                cout << "Masih Kosong";
            break;

        case 3:
            cout << "\nInOrder" << endl;
            cout << "------------------------" << endl;
            if (pohon != NULL)
                inOrder(pohon);
            else
                cout << "Masih Kosong";
            break;

        case 4:
            cout << "\nPostOrder" << endl;
            cout << "------------------------" << endl;
            if (pohon != NULL)
                postOrder(pohon);
            else
                cout << "Masih Kosong";
            break;

        case 5:
            return 0;
        }

        _getch();

    } while (pil != 5);

    return EXIT_FAILURE;
}