# <h1 align="center">Laporan Praktikum Modul 3 Linked List Circular dan Non Circular </h1>
<p align="center">Muhammad Djidzan N N</p>
<p align="center">2311102189</p>
<p align="center">IF 11 E</p>

## Dasar Teori
Linked list adalah sekumpulan elemen bertipe sama yang mempunyai keterurutan tertentu, yang setiap elemennya terdiri dari dua bagian. Linked list menggunakan satu variabel pointer untuk menyimpan banyak data. Tipe data pointer bersifat dinamis, di mana variabel akan dialokasikan hanya saat dibutuhkan dan dapat direlokasikan kembali setelah tidak dibutuhkan[1].

Biasanya di dalam suatu linked list, terdapat istilah head dan tail.

Head adalah elemen yang berada pada posisi pertama dalam suatu linked list[2].
Tail adalah elemen yang berada pada posisi terakhir dalam suatu linked list[2].
1. Single Linked List:
Tempat yang disediakan pada satu area memori tertentu untuk menyimpan data dikenal dengan sebutan node atau simpul. Setiap node memiliki pointer yang menunjuk ke simpul berikutnya sehingga terbentuk satu untaian, dengan demikian hanya diperlukan sebuah variabel pointer. Susunan berupa untaian semacam ini disebut single linked list (NULL memiliki nilai khusus yang artinya tidak menunjuk ke mana-mana. Biasanya, linked list pada titik akhirnya akan menunjuk ke NULL)[1].

Pembuatansingle linked listdapat dilakukan menggunakan dua jenis metode, yaitu:

LIFO (last in first out), aplikasinya: stack (tumpukan)
adalah suatu metode pembuatan linked list, dimana data yang masuk paling akhir adalah data yang keluar paling awal[1].

FIFO (first in first out), aplikasinya: queue (antrean)
adalah suatu metode pembuatan linked list, di mana data yang masuk paling awal adalah data yang keluar paling awal juga[1].

2. Double Linked List
Salah satu kelemahan single linked list adalah pointer (penunjuk) hanya dapat bergerak satu arah, yaitu maju/mundur atau kanan/kiri sehingga pencarian data pada single linked list hanya dapat bergerak dalam satu arah. Untuk mengatasi kelemahan ini, kita bisa menggunakan metode double linked list. Linked list ini dikenal dengan nama linked list berpointer ganda atau double linked list[1].

3. Circular Linked List
Circular Linked List merupakan suatu linked list dimana tail (node terakhir) menunjukan ke head (node pertama). jadi tidak ada pointer yang menunjukan NULL[1]. Ada 2 jenis circular linked list:

Circular Single Linked List
Circular Double Linked List

## GUIDED

## Guided 1

### Source Progam
```c++
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;
Node *tail;

// inialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// pengecekan
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// tambah depan
void insertDepan(int nilai)
{
    // buat node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty())
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// tambah belakang
void insertBelakang(int nilai)
{
    // buat node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty())
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// hitung jumlah list
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;

    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

// tambah tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan di tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;

        // tranversing
        bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// hapus depan
void hapusDepan()
{
    Node *hapus;

    if (!isEmpty())
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List Kosong!" << endl;
    }
}

// hapus belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;

    if (!isEmpty())
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;

            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List Kosong!" << endl;
    }
}

// hapsu tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;

    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan di tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;

        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }

            if (nomor == posisi)
            {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

// ubah depan
void ubahDepan(int data)
{
    if (!isEmpty())
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// ubah tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;

    if (!isEmpty())
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan di tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;

            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }

            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong" << endl;
    }
}

// ubah belakang
void ubahBelakang(int data)
{
    if (!isEmpty())
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong" << endl;
    }
}

// hapus list
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;

    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// tampilkan list
void tampil()
{
    Node *bantu;
    bantu = head;

    if (!isEmpty())
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }

        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();

    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    
    return 0;
}
```
### Ouput Progam
<img width="690" alt="chih" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/6f89cef2-34c3-4ac9-a941-9388cd00a60c">

### Deskripsi Progam
Program ini mengimplementasikan struktur data Single Linked List (SLL) menggunakan bahasa C++. Linked list adalah struktur data linier yang terdiri dari serangkaian elemen yang dinamakan node. Setiap node memiliki dua komponen: data dan pointer ke node berikutnya. Dalam program ini, berbagai operasi dasar pada linked list disediakan, seperti penambahan node di depan, belakang, atau tengah, penghapusan node dari berbagai posisi, dan pengubahan data node. Program ini memberikan gambaran dasar tentang bagaimana menggunakan linked list untuk menyimpan dan memanipulasi data dalam berbagai cara. Implementasi ini sangat berguna untuk memahami konsep dasar linked list dan operasi yang dapat dilakukan terhadapnya.

## Guided 2

### Source Progam
```c++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR
// Deklarasi Struct Node
struct Node{
string data;
Node *next;
};

    Node *head, *tail, *baru, *bantu, *hapus;
    void init()

{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
return 1; // true
    else
return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
        int jumlah = 0;
    while (bantu != NULL){
        jumlah++;
        bantu = bantu->next;
}
return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{

// Buat Node baru
buatNode(data);
if (isEmpty() == 1){
    head = baru;
    tail = head;
    baru->next = head;
}else {
while (tail->next != head){
tail = tail->next;
}
baru->next = head;
head = baru;
tail->next = head;
}
}

// Tambah Belakang
void insertBelakang(string data)
{

// Buat Node baru
buatNode(data);
if (isEmpty() == 1){
head = baru;
tail = head;
baru->next = head;
}else {
while (tail->next != head){
tail = tail->next;
}
tail->next = baru;
baru->next = head;
}
}
// Tambah Tengah
void insertTengah(string data, int posisi)
{
if (isEmpty() == 1) {
head = baru;
tail = head;
baru->next = head;
} else {
baru->data = data;
// transversing
int nomor = 1;
bantu = head;
while (nomor < posisi - 1) {
bantu = bantu->next;
nomor++;
}
baru->next = bantu->next;
bantu->next = baru;
}
}
// Hapus Depan
void hapusDepan()
{
if (isEmpty() == 0) {
hapus = head;
tail = head;
if (hapus->next == head) {
head = NULL;
tail = NULL;
delete hapus;
} else {
while (tail->next != hapus) {
tail = tail->next;
}
head = head->next;
tail->next = head;
hapus->next = NULL;
delete hapus;
}
} else {
cout << "List masih kosong!" << endl;
}
}
// Hapus Belakang
void hapusBelakang()
{
if (isEmpty() == 0) {
hapus = head;
tail = head;
if (hapus->next == head) {
head = NULL;
tail = NULL;
delete hapus;
} else {
while (hapus->next != head){
hapus = hapus->next;
}
while (tail->next != hapus) {
tail = tail->next;
}
tail->next = head;
hapus->next = NULL;
delete hapus;
}
} else {
cout << "List masih kosong!" << endl;
}
}
// Hapus Tengah
void hapusTengah(int posisi)
{
if (isEmpty() == 0) {
// transversing
int nomor = 1;
bantu = head;
while (nomor < posisi - 1) {
bantu = bantu->next;
nomor++;
}
hapus = bantu->next;
bantu->next = hapus->next;
delete hapus;
} else {
cout << "List masih kosong!" << endl;
}
}
// Hapus List
void clearList()
{
if (head != NULL){
hapus = head->next;
while (hapus != head){
bantu = hapus->next;
delete hapus;
hapus = bantu;
}
delete head;
head = NULL;
}
cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
if (isEmpty() == 0) {
tail = head;
do {
cout << tail->data << " ";
tail = tail->next;
}
while (tail != head);
cout << endl;
} else {
cout << "List masih kosong!" << endl;
}
}
int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    
    insertDepan("Bebek");
    tampil();
    
    insertBelakang("Cicak");
    tampil();
    
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
return 0;
}
```
### Ouput Progam
<img width="690" alt="ayam" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/7709feef-9a6b-4262-a131-c0fff8ce1c3b">

### Deskripsi Progam
Program ini mengimplementasikan struktur data Circular Single Linked List (CSLL) menggunakan bahasa C++. Circular Single Linked List adalah jenis linked list di mana node terakhir menunjuk kembali ke node pertama, sehingga membentuk lingkaran. Program ini menyediakan berbagai operasi untuk manipulasi circular linked list, seperti menambah, menghapus, dan menampilkan node dari berbagai posisi. Program ini memberikan gambaran dasar tentang bagaimana menggunakan Circular Single Linked List untuk menyimpan dan memanipulasi data dalam berbagai cara. Implementasi ini sangat berguna untuk memahami konsep dasar Circular Single Linked List dan operasi yang dapat dilakukan terhadapnya.

## UNGUIDED

## Unguided 1
Buatlah program menu Linked List Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.

### Source Progam
```c++
#include <iostream>
#include <cstring>
using namespace std;

// Struktur untuk node linked list
struct Node
{
    string nama, nim_189;
    Node *next;
};

Node *head = NULL; // Pointer untuk head linked list

// Fungsi untuk menambahkan node baru di awal linked list
void tambahDepan()
{
    cout << "\n ||Tambah Depan||" << endl;
    cout << "" << endl;
    string nama, nim_189;
    cout << "Masukkan Nama : ";
    getline(cin >> ws, nama);
    cout << "Masukkan NIM : ";
    getline(cin, nim_189);

    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->nim_189 = nim_189;
    newNode->next = head;
    head = newNode;
    cout << "" << endl;
    cout << "Data telah ditambahkan" << endl;
}

// Fungsi untuk menambahkan node baru di akhir linked list
void tambahBelakang()
{
    cout << "\n ||Tambah Belakang||" << endl;
    cout << "" << endl;
    string nama, nim_189;
    cout << "Masukkan Nama: ";
    getline(cin >> ws, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim_189);

    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->nim_189 = nim_189;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "" << endl;
    cout << "Data telah ditambahkan" << endl;
}

// Fungsi untuk menambahkan node baru di tengah linked list
void tambahTengah()
{
    cout << "\n ||Tambah Tengah||" << endl;
    cout << "" << endl;
    string nama, nim_189;
    int posisi;
    cout << "Masukkan Nama: ";
    getline(cin >> ws, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim_189);
    cout << "Masukkan Posisi: ";
    cin >> posisi;

    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->nim_189 = nim_189;

    if (posisi == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    cout << "" << endl;
    cout << "Data telah ditambahkan" << endl;
}

// Fungsi untuk mengubah data node di awal linked list
void ubahDepan()
{
    cout << "\n ||Ubah Depan||" << endl;
    cout << "" << endl;
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    string nama, nim_189;
    cout << "Masukkan nama baru: ";
    getline(cin >> ws, nama);
    cout << "Masukkan NIM baru: ";
    getline(cin, nim_189);

    head->nama = nama;
    head->nim_189 = nim_189;

    cout << "" << endl;
    cout << "Data " << nama << " telah diubah" << endl;
}

// Fungsi untuk mengubah data node di akhir linked list
void ubahBelakang()
{
    cout << "" << endl;
    cout << "\n ||Ubah Belakang||" << endl;
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    string nama, nim_189;
    cout << "Masukkan nama baru: ";
    getline(cin >> ws, nama);
    cout << "Masukkan NIM baru: ";
    getline(cin, nim_189);

    temp->nama = nama;
    temp->nim_189 = nim_189;

    cout << "" << endl;
    cout << "Data " << nama << " telah diubah" << endl;
}

// Fungsi untuk mengubah data node di tengah linked list
void ubahTengah()
{
    cout << "\n ||Ubah Tengah||" << endl;
    cout << "" << endl;
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    int posisi;
    cout << "Masukkan posisi: ";
    cin >> posisi;

    Node *temp = head;
    for (int i = 1; i < posisi; i++)
    {
        if (temp == NULL)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Posisi tidak valid" << endl;
        return;
    }

    string nama, nim_189;
    cout << "Masukkan nama baru: ";
    getline(cin >> ws, nama);
    cout << "Masukkan NIM baru: ";
    getline(cin, nim_189);

    temp->nama = nama;
    temp->nim_189 = nim_189;

    cout << "" << endl;
    cout << "Data " << nama << " telah diubah" << endl;
}

// Fungsi untuk menghapus node di awal linked list
void hapusDepan()
{
    cout << "\n ||Hapus Depan||" << endl;
    cout << "" << endl;
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;

    cout << "" << endl;
    cout << "Data depan telah dihapus" << endl;
}

// Fungsi untuk menghapus node di akhir linked list
void hapusBelakang()
{
    cout << "\n ||Hapus Belakang||" << endl;
    cout << "" << endl;
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        cout << "Data telah dihapus" << endl;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    Node *deleteNode = temp->next;
    temp->next = NULL;
    delete deleteNode;

    cout << "" << endl;
    cout << "Data akhir telah dihapus" << endl;
}

// Fungsi untuk menghapus node di tengah linked list
void hapusTengah()
{
    cout << "\n ||Hapus Tengah||" << endl;
    cout << "" << endl;
    if (head == NULL)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    int posisi;
    cout << "Masukkan posisi: ";
    cin >> posisi;

    if (posisi == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Data telah dihapus" << endl;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < posisi - 1; i++)
    {
        if (temp == NULL)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Posisi tidak valid" << endl;
        return;
    }

    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;

    cout << "" << endl;
    cout << "Data ke-" << posisi << " telah dihapus" << endl;
}

// Fungsi untuk menghapus seluruh data dalam linked list
void hapusSeluruhData()
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *deleteNode = temp;
        temp = temp->next;
        delete deleteNode;
    }
    head = NULL;
    cout << "Seluruh data telah dihapus" << endl;
}

// Fungsi untuk menampilkan seluruh data dalam linked list
void tampilkanData()
{
    Node *temp = head;
    cout << "DATA MAHASISWA" << endl;
    cout << "|| NAMA "
         << "  |  "
         << "NIM"
         << "\t ||"
         << "\n"
         << endl;
    while (temp != NULL)
    {
        cout << temp->nama << "\t  |" << temp->nim_189 << endl;
        temp = temp->next;
    }
}

int main()
{
    int pilihan;
    do
    {
        cout << "Tampilan Menu:" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahDepan();
            break;
        case 2:
            tambahBelakang();
            break;
        case 3:
            tambahTengah();
            break;
        case 4:
            ubahDepan();
            break;
        case 5:
            ubahBelakang();
            break;
        case 6:
            ubahTengah();
            break;
        case 7:
            hapusDepan();
            break;
        case 8:
            hapusBelakang();
            break;
        case 9:
            hapusTengah();
            break;
        case 10:
            hapusSeluruhData();
            break;
        case 11:
            tampilkanData();
            break;
        case 0:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
```
### Ouput Progam
1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa
   <img width="687" alt="menu" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/f8f03234-c37a-450a-b269-06828dd552d1">

2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
<img width="262" alt="jawad" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/0cad3b88-1b76-44e2-a0b1-b0a083dc07f2">
<img width="225" alt="saya" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/3723f749-37a3-4bcb-893c-f96a215ae176">
<img width="240" alt="farel" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/b156d59f-5b15-40ac-a19d-efeca19213ec">
<img width="192" alt="denis" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/7dd570e1-7f37-4fc5-805b-f93896f0109a">
<img width="194" alt="Anis" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/9390e1e1-a231-49a8-b3f2-7d564830a722">
<img width="174" alt="bowo" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/33156447-91c9-4f9c-96b2-be3bf05de0bc">
<img width="179" alt="Gahar" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/ed3936f9-720d-4792-8bec-2962bf46f664">
<img width="204" alt="Udin" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/9905332e-30d7-4d67-af23-45b656c1532f">
<img width="180" alt="Ucok" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/212a95bd-55a7-4a2d-a093-27378b0a4f9f">
<img width="174" alt="Budi" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/6d6e658d-0fec-47b8-879c-a955c45c39a9">
<img width="186" alt="tampil" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/8e39866b-7cfb-4ac6-a576-bd703a7c447a">

3. Lakukan perintah berikut:

a. Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004

<img width="153" alt="wati" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/7f04154b-2ee7-470c-b98e-99dac8666738">

b. Hapus data Denis

<img width="153" alt="apusdenis" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/afed0f82-8129-4173-8955-1fb677d90255">

c. Tambahkan data berikut di awal: Owi 2330000

<img width="168" alt="Owi" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/bf0a968e-82ec-4c48-992d-e11103a4d78c">

d. Tambahkan data berikut di akhir: David 23300100

<img width="144" alt="david" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/0aebd5b5-8a97-443d-937e-059d31323fba">

e. Ubah data Udin menjadi data berikut: Idin 23300045

<img width="185" alt="idin" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/c147d309-9b33-4767-b1f5-4a18a3a53664">

f. Ubah data terkahir menjadi berikut: Lucy 23300101

<img width="183" alt="Lucy" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/e0b0dc76-d878-4d96-98a6-faa234cc5dfb">

g. Hapus data awal

<img width="150" alt="apsdpn" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/58a83374-6a42-458b-874e-e8590c85a6d6">

h. Ubah data awal menjadi berikut: Bagas 2330002

<img width="175" alt="Bagas" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/18a1ce29-e649-47b1-82c0-d6ca9be1a827">

i. Hapus data akhir

<img width="161" alt="apsblkg" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/2aebac3b-b3c6-4a0f-b0fd-c269ec6fc210">

j. Tampilkan seluruh data

<img width="178" alt="akhirlagih" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/5a6166c4-d1d6-4e26-a867-85bb8c47f7b9">


### Deskripsi Progam
Program ini mengimplementasikan struktur data linked list untuk menyimpan data mahasiswa yang terdiri dari nama dan NIM (Nomor Induk Mahasiswa). Program ini memungkinkan pengguna untuk menambahkan, mengubah, menghapus, dan menampilkan data mahasiswa dalam linked list. Linked list digunakan di sini untuk memudahkan manipulasi data karena sifat dinamisnya. Program ini memberikan berbagai fungsi untuk memanipulasi linked list secara dinamis, memungkinkan penambahan, pengubahan, penghapusan, dan penampilan data mahasiswa dengan cara yang efisien dan terstruktur.

## Kesimpulan
Linked list non-circular memiliki pointer pada node terakhir yang menunjuk ke nilai khusus, biasanya NULL, menandakan akhir list. Penambahan dan penghapusan data pada linked list non-circular umumnya dilakukan di awal (head) atau akhir (tail). Ini membuatnya efisien untuk operasi yang sering terjadi di kedua ujung list, seperti pada implementasi stack dan queue.
Di sisi lain, linked list circular memiliki pointer pada node terakhir yang justru menunjuk kembali ke node pertama, membentuk lingkaran. Hal ini memungkinkan penambahan dan penghapusan data di sembarang tempat dalam list. Linked list circular cocok untuk operasi yang sering terjadi di bagian tengah list, seperti pada implementasi circular buffer.
Singkatnya, linked list non-circular lebih sederhana dan efisien untuk operasi di awal atau akhir list, sedangkan linked list circular menawarkan fleksibilitas untuk operasi di seluruh bagian list. Pemilihan jenis linked list yang tepat bergantung pada kebutuhan operasi yang akan dilakukan dalam program.

## Refrensi
Sachi Nandan Mohanty, Pabitra Kumar Tripathy, Data Structure and Algorithms Using C++: A Practical Implementation, New York:Scrivener Publishing LLC, 14 January 2021.

"geeksforgeeks", [Online]. Available: https://www.geeksforgeeks.org/. [Accessed: April 01, 2024].
