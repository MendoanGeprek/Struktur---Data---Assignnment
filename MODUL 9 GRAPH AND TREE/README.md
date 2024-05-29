# <h1 align="center"> Laporan Praktikum Modul 9 Graph and Tree</h1>
<p align="center"> Muhammad Djidzan. N. N <p>
<p align="center"> 2311102189 </p>

## Dasar Teori 

### 1. Graph
Graph adalah struktur data non-linear yang terdiri dari kumpulan node (vertex/simpul) yang dihubungkan oleh edge (sisi/busur). Graph dapat direpresentasikan dengan beberapa carayaitu Adjacency Matrix, Adjacency List, Adjacency List.

### 2. Tree
Struktur pohon (tree) merupakan struktur yang penting mengharuskan kita mengorganisasikan informasi berdasarkan struktur lojik. Struktur data tree juga memungkinkan untuk mengakses suatu elemen dengan khusus. Struktur tree banyak dipakai untuk menggambarkan data yang memiliki struktur seperti pohon atau ada disebut sebagai struktur yang hirarkis.Struktur tree digunakan banyak di berbagai area. Struktur organisasi banyak digunakan di suatu perusahaan menyerupai struktur pohon. Sebagai contoh, seorang direktur di perusahaan membawahi wakil direktur. yang terjadi saat ini adalah orang-orang yang dihadapkan dengan struktur seperti ini membangun model data dan komponen pengelolaan datanya secara sendiri. Setiap orang membangun model data pohonnya sendiri sekaligus komponen pengelolaan datanya.

## Guided

### Guided 1
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"};int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}};
void tampilGraph()
{
    for (int baris = 0; baris < 7; baris++)
    {
        cout << " " << setiosflags(ios::left) << setw(15)
             << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++)
        {
            if (busur[baris][kolom] != 0)
            {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom]

                     << ")";
            }
        }
        cout << endl;
    }
}
int main()
{
    tampilGraph();
    return 0;
}
```
### Ouput Progam
<img width="689" alt="guided1" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/d1cdcd96-88b8-407a-ae0f-8d799283239c">

### Deskripsi Progam
Program ini menggunakan sebuah array simpul yang berisi nama-nama kota, serta sebuah matriks 2D busur yang berisi jarak antar kota. Masing-masing elemen dalam matriks busur berisi jarak antar kota yang bersangkutan, dengan nilai 0 jika tidak ada jalan yang menghubungkan kota tersebut.
Fungsi tampilGraph digunakan untuk menampilkan grafik jaringan. Fungsi ini menggunakan perulangan untuk memproses setiap baris dan kolom dalam matriks busur. Untuk setiap elemen yang tidak bernilai 0, program akan mencetak nama kota yang bersangkutan dan jarak antar kota tersebut.
Pada bagian main, fungsi tampilGraph dipanggil untuk menampilkan grafik jaringan. Hasilnya adalah sebuah output yang menampilkan nama-nama kota dan jarak antar kota yang bersangkutan.


### Guided 2
```cpp
#include <iostream>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};

// pointer global
Pohon *root;

// Inisialisasi
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
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;

            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;

            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
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

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
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
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus."
             << endl;
    }
}

// Hapus Tree
void clear()
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
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
}

// Cek Height Level Tree
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
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
}

// Karakteristik Tree
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
    init();
    buatNode('A');

    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
        *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n"
         << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n"
         << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    characteristic();
    return 0;
}
```

### Ouput Progam
<img width="680" alt="duarr" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/b35a3c81-b358-4fe3-9a08-b9f9f481a095">
<img width="692" alt="mbeeeer" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/3aa75689-c91d-4f35-bce6-e730f74c56af">


### Deskripsi Progam
Program ini adalah implementasi dari pohon biner (binary tree) dalam bahasa C++. Program ini menyediakan berbagai operasi dasar untuk manipulasi pohon biner, seperti penambahan node, pembaruan data node, penghapusan node, dan penelusuran (traversal) pohon.Program ini dimulai dengan menginisialisasi pohon dan membuat node root. Kemudian, node-node lain ditambahkan sebagai anak kiri atau kanan dari node tertentu. Setelah itu, program melakukan beberapa operasi pembaruan dan pengambilan data, serta traversal pre-order, in-order, dan post-order. Akhirnya, program menghapus subtree dari node tertentu dan menampilkan karakteristik pohon sebelum dan setelah penghapusan subtree.

## Unguided

## Unguided 1
Buatlah program graph dengan menggunakan inputan user untuk menghitung
jarak dari sebuah kota ke kota lainnya.
(Output Program)
<img width="302" alt="ululul" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/c619ec50-e64c-4bba-8d5e-714c16f906f8">

### Code Progam
```c++
#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

struct Vertex
{
    string name;
    int distance;
};

vector<vector<int>> createGraph(vector<string> &vertices)
{
    int numVertices189;
    cout << "MASUKAN JUMLAH SIMPUL : ";
    cin >> numVertices189;

    vertices.resize(numVertices189);
    for (int i = 0; i < numVertices189; i++)
    {
        cout << "MASUKAN SIMPUL : " << i + 1 << ": ";
        cin >> vertices[i];
    }

    vector<vector<int>> adjacencyMatrix(numVertices189, vector<int>(numVertices189));
    for (int i = 0; i < numVertices189; i++)
    {
        for (int j = 0; j < numVertices189; j++)
        {
            if (i == j)
            {
                adjacencyMatrix[i][j] = 0;
            }
            else
            {
                cout << "MASUKAN BOBOT SIMPUL : " << vertices[i] << "-->" << vertices[j] << ": ";
                cin >> adjacencyMatrix[i][j];
            }
        }
    }

    return adjacencyMatrix;
}

int findDistance(const vector<vector<int>> &adjacencyMatrix, const vector<string> &vertices,
                 const string &startCity, const string &endCity)
{
    auto startIt = find(vertices.begin(), vertices.end(), startCity);
    auto endIt = find(vertices.begin(), vertices.end(), endCity);

    if (startIt == vertices.end() || endIt == vertices.end())
    {
        return -1;
    }

    int startIndex = distance(vertices.begin(), startIt);
    int endIndex = distance(vertices.begin(), endIt);

    vector<int> distances(vertices.size(), INT_MAX);
    distances[startIndex] = 0;

    set<int> unvisitedVertices;
    for (int i = 0; i < vertices.size(); i++)
    {
        unvisitedVertices.insert(i);
    }

    while (!unvisitedVertices.empty())
    {
        int currentVertex = *min_element(unvisitedVertices.begin(), unvisitedVertices.end(),
                                         [&](int i, int j)
                                         { return distances[i] < distances[j]; });
        unvisitedVertices.erase(currentVertex);

        for (int neighbor = 0; neighbor < vertices.size(); neighbor++)
        {
            if (adjacencyMatrix[currentVertex][neighbor] > 0 &&
                distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor] < distances[neighbor])
            {
                distances[neighbor] = distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor];
            }
        }
    }

    return distances[endIndex];
}

int main()
{

    vector<string> vertices;
    vector<vector<int>> adjacencyMatrix = createGraph(vertices);

    string startCity, endCity;
    cout << "MASUKAN NAMA KOTA AWAL : ";
    cin >> startCity;
    cout << "MASUKAN NAMA KOTA TUJUAN : ";
    cin >> endCity;

    int distance = findDistance(adjacencyMatrix, vertices, startCity, endCity);

    if (distance == -1)
    {
        cout << "TIDAK ADA JALUR DARI " << startCity << " ke " << endCity << "." << endl;
    }
    else
    {
        cout << "JARAK DARI " << startCity << " KE " << endCity << " ADALAH " << distance << " KILOMETER" << endl;
    }

    return 0;
}
```

### Ouput Progam
<img width="687" alt="ALALA" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/ec862442-7e30-48c9-acca-45b1f7425be1">

### Deskripsi Progam
Program ini dibuat untuk menghitung jarak terdekat antara dua kota dalam sebuah grafik yang diwakili oleh matriks adjacency. Grafik ini dibuat oleh pengguna, yang diminta untuk memasukkan jumlah simpul (kota) dan tepi antara mereka bersama dengan berat (jarak) mereka.Program ini akan mencetak jarak terdekat antara dua kota yang dimasukkan oleh pengguna. Jika tidak ada jalur antara dua kota, maka program ini akan mencetak pesan yang sesuai.

## Unguided 2
Modifikasi guided tree diatas dengan program menu menggunakan input data tree
dari user dan berikan fungsi tambahan untuk menampilkan node child dan
descendant dari node yang diinput kan!

### Code Progam
```c++
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
### Ouput Progam
<img width="690" alt="1" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/3a1d8490-61e2-48b7-8fff-ea7ecc1648b8">
<img width="685" alt="2" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/32f4f287-b7ce-4b04-99ad-84003d5617f6">
<img width="678" alt="3" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/3cc05fa8-7777-4a1f-b820-42a1569450b7">
<img width="679" alt="4" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/5b78cbf1-44b8-4cd3-a6f1-ac5e7121f22d">
<img width="678" alt="5" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/c4882059-3bc9-4c6b-b224-84d367b9f593">
<img width="687" alt="6" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/206643ac-3b1e-4a6f-b6eb-9113286e404a">
<img width="675" alt="7" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/7a5c5362-1ff8-48d6-9ad3-ca168992acc6">
<img width="667" alt="8" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/dad90523-6aeb-415f-84ac-5db6a75d19a1">
<img width="676" alt="9" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/9c586491-ee56-4652-b12b-cc38350a20ef">
<img width="679" alt="10" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/2d407719-4cbe-457c-8978-ba309a0932e8">
<img width="684" alt="11" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/48101c8f-48a9-4075-8ba1-90b0dc1cca8f">
<img width="681" alt="12" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/5b4bf373-663c-4225-b380-c0331cdb9820">
<img width="686" alt="13" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/62294e3a-594d-4b18-89e6-4b26c8dadc9b">
<img width="676" alt="14" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/4c6abc76-30e7-482c-9a61-a471e335cfaf">

### Deskripsi Progam
Program ini untuk mengelola sebuah pohon biner (binary tree). Program ini menyediakan berbagai fungsi untuk membuat, menambah, mengupdate, mencari, dan menghapus node dalam pohon, serta menampilkan berbagai informasi mengenai pohon tersebut. Setelah memilih opsi dari menu, pengguna akan diminta untuk memasukkan data yang relevan seperti data node, parent node, dll. Program kemudian akan menjalankan fungsi yang sesuai dan menampilkan hasil atau pesan kesalahan jika ada.

## Kesimpulan
Tree dan graph adalah struktur data fundamental yang digunakan untuk mewakili hubungan dan koneksi antara data. Tree adalah subset dari graph dengan karakteristik tertentu yang membuatnya sangat berguna untuk representasi hierarkis dan pengambilan keputusan. Graph, dengan fleksibilitasnya untuk mewakili hubungan kompleks antara data, sangat penting dalam berbagai aplikasi termasuk jaringan, optimisasi, dan analisis data besar. Pemahaman mendalam tentang teori tree dan graph sangat penting dalam pengembangan algoritma efisien dan solusi komputasi modern.

## Refrensi
[1] Sindar, A, STRUKTUR DATA DAN ALGORITMADENGAN C++. Cetakan Pertama. Serang:CV.AA.RIZKY, 2019

[2] Agustin, S. (2022). IMPLEMENTASI STRUKTUR DATA TREE PADA WEB BLOG SEBAGAI MEDIA PEMBEOLAJARAN.

