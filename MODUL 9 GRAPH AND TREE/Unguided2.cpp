```C++
#include <iostream>
using namespace std;

struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root;

void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "\nNode " << data << " BERHASIL MENJADI ROOT." << endl;
    }
    else
    {
        cout << "\nPOHON TELAH DIBUAT" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBUAT TREE TERLEBIH DAHULU !" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " CHILD KIRI SUDAH TERSEDIA !" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " BERHASIL DITAMBAH DI CHILD KIRI " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBUAT CHILD TERLEBIH DAHULU !" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " CHILD KANAN SUDAH TERSEDIA !" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " BERHASIL DITAMBAH DI CHILD KANAN " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBUAT TREE TERLEBIH DAHULU !" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNODE YANG INGIN DIGANTI TIDAK ADA !!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " BERHASIL DIUBAH MENJADI " << data << endl;
        }
    }
}

void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBUAT TREE TERLEBIH DAHULU !" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode TIDAK ADA !" << endl;
        else
        {
            cout << "\nDATA NODE : " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBUAT TREE TERLEBIH DAHULU !" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNODE TIDAK ADA !" << endl;
        else
        {
            cout << "\nDATA NODE : " << node->data << endl;
            cout << "ROOT : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

void showChild(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBUAT TREE TERLEBIH DAHULU !" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNODE TIDAK ADA !" << endl;
        }
        else
        {
            cout << "\nNODE " << node->data << " Child: " << endl;
            if (node->left)
                cout << "Child Kiri : " << node->left->data << endl;
            else
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            if (node->right)
                cout << "Child Kanan : " << node->right->data << endl;
            else
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
        }
    }
}

void preOrder(Pohon *node)
{
    if (node != NULL)
    {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void showDescendants(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBUAT TREE TERLEBIH DAHULU !" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNODE TIDAK ADA !" << endl;
        }
        else
        {
            cout << "\nDescendants of node " << node->data << " : ";
            preOrder(node);
            cout << endl;
        }
    }
}

void inOrder(Pohon *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << " " << node->data << ", ";
        inOrder(node->right);
    }
}

void postOrder(Pohon *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data << ", ";
    }
}

void deleteTree(Pohon *node)
{
    if (node != NULL)
    {
        if (node != root)
        {
            if (node->parent->left == node)
                node->parent->left = NULL;
            else if (node->parent->right == node)
                node->parent->right = NULL;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        if (node == root)
        {
            delete root;
            root = NULL;
        }
        else
        {
            delete node;
        }
    }
}

void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBUAT TREE TERLEBIH DAHULU !" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNODE SUBTREE " << node->data << " BERHASIL DIHAPUS." << endl;
    }
}

void clear()
{
    if (isEmpty())
    {
        cout << "\nBUAT TREE TERLEBIH DAHULU !!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\nPOHON BERHASIL DIHAPUS" << endl;
    }
}

int size(Pohon *node)
{
    if (!node)
    {
        return 0;
    }
    else
    {
        return 1 + size(node->left) + size(node->right);
    }
}

int height(Pohon *node)
{
    if (!node)
    {
        return 0;
    }
    else
    {
        int heightKiri = height(node->left);
        int heightKanan = height(node->right);
        if (heightKiri >= heightKanan)
        {
            return heightKiri + 1;
        }
        else
        {
            return heightKanan + 1;
        }
    }
}

void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

int main()
{
    int choice;
    char _189, parentData, direction;
    Pohon *parentNode, *tempNode;

    do
    {
        cout << "\n===---- HALLOO ----===\n";
        cout << "1. BUAT NODE ROOT\n";
        cout << "2. TAMBAH NODE DI KIRI\n";
        cout << "3. TAMBAH NODE DI KANAN\n";
        cout << "4. UPDATE NODE\n";
        cout << "5. RETRIVE NODE\n";
        cout << "6. FIND NODE\n";
        cout << "7. SHOW CHILD\n";
        cout << "8. SHOW DESCENDANTS\n";
        cout << "9. PRE ORDER TRAVERSAL\n";
        cout << "10. IN ORDER TRAVERSAL\n";
        cout << "11. POST ORDER TRAVERSAL\n";
        cout << "12. SHOW CHARACTERISTIC\n";
        cout << "13. CLEAR TREE\n";
        cout << "14. EXIT\n";
        cout << "CHOSEE MENU : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan data root: ";
            cin >> _189;
            buatNode(_189);
            break;
        case 2:
            cout << "Masukkan data parent: ";
            cin >> parentData;
            cout << "Masukkan data node kiri: ";
            cin >> _189;
            parentNode = root;
            while (parentNode && parentNode->data != parentData)
            {
                if (parentNode->left && parentNode->left->data == parentData)
                    parentNode = parentNode->left;
                else if (parentNode->right && parentNode->right->data == parentData)
                    parentNode = parentNode->right;
                else if (parentNode->left)
                    parentNode = parentNode->left;
                else if (parentNode->right)
                    parentNode = parentNode->right;
                else
                    parentNode = NULL;
            }
            if (parentNode)
            {
                insertLeft(_189, parentNode);
            }
            else
            {
                cout << "Parent tidak ditemukan!" << endl;
            }
            break;
        case 3:
            cout << "Masukkan data parent: ";
            cin >> parentData;
            cout << "Masukkan data node kanan: ";
            cin >> _189;
            parentNode = root;
            while (parentNode && parentNode->data != parentData)
            {
                if (parentNode->left && parentNode->left->data == parentData)
                    parentNode = parentNode->left;
                else if (parentNode->right && parentNode->right->data == parentData)
                    parentNode = parentNode->right;
                else if (parentNode->left)
                    parentNode = parentNode->left;
                else if (parentNode->right)
                    parentNode = parentNode->right;
                else
                    parentNode = NULL;
            }
            if (parentNode)
            {
                insertRight(_189, parentNode);
            }
            else
            {
                cout << "Parent tidak ditemukan!" << endl;
            }
            break;
        case 4:
            cout << "Masukkan data node yang ingin diupdate: ";
            cin >> parentData;
            cout << "Masukkan data baru: ";
            cin >> _189;
            tempNode = root;
            while (tempNode && tempNode->data != parentData)
            {
                if (tempNode->left && tempNode->left->data == parentData)
                    tempNode = tempNode->left;
                else if (tempNode->right && tempNode->right->data == parentData)
                    tempNode = tempNode->right;
                else if (tempNode->left)
                    tempNode = tempNode->left;
                else if (tempNode->right)
                    tempNode = tempNode->right;
                else
                    tempNode = NULL;
            }
            if (tempNode)
            {
                update(_189, tempNode);
            }
            else
            {
                cout << "Node tidak ditemukan!" << endl;
            }
            break;
        case 5:
            cout << "Masukkan data node yang ingin diretrieve: ";
            cin >> _189;
            tempNode = root;
            while (tempNode && tempNode->data != _189)
            {
                if (tempNode->left && tempNode->left->data == _189)
                    tempNode = tempNode->left;
                else if (tempNode->right && tempNode->right->data == _189)
                    tempNode = tempNode->right;
                else if (tempNode->left)
                    tempNode = tempNode->left;
                else if (tempNode->right)
                    tempNode = tempNode->right;
                else
                    tempNode = NULL;
            }
            if (tempNode)
            {
                retrieve(tempNode);
            }
            else
            {
                cout << "Node tidak ditemukan!" << endl;
            }
            break;
        case 6:
            cout << "Masukkan data node yang ingin dicari: ";
            cin >> _189;
            tempNode = root;
            while (tempNode && tempNode->data != _189)
            {
                if (tempNode->left && tempNode->left->data == _189)
                    tempNode = tempNode->left;
                else if (tempNode->right && tempNode->right->data == _189)
                    tempNode = tempNode->right;
                else if (tempNode->left)
                    tempNode = tempNode->left;
                else if (tempNode->right)
                    tempNode = tempNode->right;
                else
                    tempNode = NULL;
            }
            if (tempNode)
            {
                find(tempNode);
            }
            else
            {
                cout << "Node tidak ditemukan!" << endl;
            }
            break;
        case 7:
            cout << "Masukkan data node yang ingin ditampilkan child-nya: ";
            cin >> _189;
            tempNode = root;
            while (tempNode && tempNode->data != _189)
            {
                if (tempNode->left && tempNode->left->data == _189)
                    tempNode = tempNode->left;
                else if (tempNode->right && tempNode->right->data == _189)
                    tempNode = tempNode->right;
                else if (tempNode->left)
                    tempNode = tempNode->left;
                else if (tempNode->right)
                    tempNode = tempNode->right;
                else
                    tempNode = NULL;
            }
            if (tempNode)
            {
                showChild(tempNode);
            }
            else
            {
                cout << "Node tidak ditemukan!" << endl;
            }
            break;
        case 8:
            cout << "Masukkan data node yang ingin ditampilkan descendant-nya: ";
            cin >> _189;
            tempNode = root;
            while (tempNode && tempNode->data != _189)
            {
                if (tempNode->left && tempNode->left->data == _189)
                    tempNode = tempNode->left;
                else if (tempNode->right && tempNode->right->data == _189)
                    tempNode = tempNode->right;
                else if (tempNode->left)
                    tempNode = tempNode->left;
                else if (tempNode->right)
                    tempNode = tempNode->right;
                else
                    tempNode = NULL;
            }
            if (tempNode)
            {
                showDescendants(tempNode);
            }
            else
            {
                cout << "Node tidak ditemukan!" << endl;
            }
            break;
        case 9:
            cout << "\nPreOrder :" << endl;
            preOrder(root);
            cout << "\n"
                 << endl;
            break;
        case 10:
            cout << "InOrder :" << endl;
            inOrder(root);
            cout << "\n"
                 << endl;
            break;
        case 11:
            cout << "PostOrder :" << endl;
            postOrder(root);
            cout << "\n"
                 << endl;
            break;
        case 12:
            characteristic();
            break;
        case 13:
            clear();
            break;
        case 14:
            cout << "TERIMAKSIH !!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid !" << endl;
        }
    } while (choice != 14);

    return 0;
}
```
