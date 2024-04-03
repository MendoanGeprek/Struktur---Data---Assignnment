# <h1 align="center"> Laporan Praktium Modul 4 Circular dan Non-Circular Linked List </h1>
<p align="center"> Muhammad Djidzan. N. N <p>
<p align="center"> 2311102189 </p>

## Dasar Teori
<div style="text-align: right">
  
Daftar tertaut adalah struktur data yang bisa linier atau non-linier, bergantung pada implementasinya. Dalam daftar tertaut, elemen dialokasikan secara acak dalam memori dan elemen dihubungkan melalui pointer. Hal ini memungkinkan penggunaan memori yang lebih efisien daripada array. Dalam bab ini, kita akan membahas karakteristik empat jenis daftar tertaut: daftar tertaut tunggal, daftar tertaut ganda, daftar tertaut melingkar, dan daftar tertaut judul. Daftar tertaut melingkar adalah tipe khusus dari daftar tertaut di mana simpul terakhir menunjuk  ke simpul pertama, sehingga menciptakan perulangan. Hal ini memungkinkan akses berkelanjutan ke daftar tanpa menentukan titik awal atau akhir. Daftar tertaut melingkar berguna dalam aplikasi yang datanya harus diproses secara terus menerus, seperti aplikasi atau simulasi waktu nyata [1].

Selain fitur-fiturnya, daftar tertaut juga digunakan dalam berbagai aplikasi.Mereka sangat berguna dalam sistem manajemen memori, di mana pengumpulan sampah dapat dilakukan ketika hanya ada sedikit  atau tidak ada ruang tersisa di daftar memori kosong, atau ketika prosesor dalam keadaan idle dan mempunyai waktu luang untuk melakukan pengumpulan sampah. Sistem manajemen memori menggunakan konsep kompresi, mengumpulkan semua blok ruang kosong dan menempatkannya di  lokasi di dalam  blok bebas tersebut. Hal ini memungkinkan penggunaan memori lebih efisien dan mengurangi fragmentasi [1].
</div>

## Guided
### Guided 1. Single linked Non-Circular List
```C++
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
### Screenshot
<img width="686" alt="1" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/c63c6976-476b-461a-9f64-2634c4a23a61">

### Deskripsi Progam
Program di atas memiliki kemampuan untuk menampilkan data yang dapat
dimodifikasi, ditambahkan, dan dihapus sesuai keinginan pengguna. Hal ini
dimungkinkan melalui penggunaan fungsi yang menyediakan menu untuk
menambahkan, mengubah, dan menghapus data menggunakan Linked list noncircular. Dalam program ini, if-else statement dan while loop digunakan untuk
memenuhi kondisi data yang akan ditampilkan. Setelah data sesuai dengan kondisi
yang dimaksudkan, program akan berhenti berulang dan menampilkan data yang
diinginkan.

### Guided 2 Single linked Circular 
```C++
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

### Screenshot

<img width="686" alt="2" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/b2a37440-35b1-4744-8f80-da5f12b8a047">

### Deskripsi Progam 
Dalam program di atas, terdapat penggunaan linked list non-circular. Program ini
menampilkan beberapa nama hewan seperti Ayam, Bebek, Sapi, dan Cicak, di mana
setiap hewan memiliki posisi yang telah ditentukan. Dalam hal ini, posisi keempat
hewan dapat diubah, ditambah, dan dihapus dari data karena fungsi linked list
memungkinkan pengubahan data dengan menambahkan, mengurangi, dan
menghapus elemen-elemen dalam linked list. Dengan demikian, program di atas
berhasil menerapkan linked list dengan mengombinasikan linked list dengan
statement lain seperti if-else, while, do-while, dan struct.

## Unguided

### Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.

1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan
NIM mahasiswa, berikut contoh tampilan output dari nomor 1:

- Tampilan Menu

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/f123c124-e000-4cd7-a45d-24a5c40f3897)

- Tampilan Operasi Tambah

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/9c3f290c-f38f-4054-b66c-fda108e3efe3)

- Tampilan Operasi hapus

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/67df71ef-b2fb-4339-b2ee-5b5d12283c6d)

- Tampilan Operasi Ubah

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/7922b99b-a2f4-4f52-ba11-9c6eb8667d1f)

- Tampilan Operasi tampil data

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/24503401-6fdd-4ed7-826a-3e8c1eb4b0fd)

2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/6b09d7e6-2c62-411d-9fda-ba874d58a4d5)

3. Lakukan perintah berikut:

a) Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004

b) Hapus data Denis

c) Tambahkan data berikut di awal: Owi 2330000

d) Tambahkan data berikut di akhir: David 23300100

e) Ubah data Udin menjadi data berikut: Idin 23300045

f) Ubah data terkahir menjadi berikut: Lucy 23300101

g) Hapus data awal

h) Ubah data awal menjadi berikut: Bagas 2330002

i) Hapus data akhir

j) Tampilkan seluruh data

```C++
#include <iostream>
using namespace std;

struct Node
{
string name;
string nim;
Node *next;
};
Node *head;
Node *tail;

//untuk menginisialkan
void init()
{
head = NULL;
tail = NULL;
}
bool isEmpty()
{
    if (head == NULL)
    {
return true;
    }else
    {
return false;
}
}

// Tambah data di index pertama
void insertDepan(string name, string nim)
{
Node *newNode = new Node;
newNode->name = name;
newNode->nim = nim;
newNode->next = NULL;
    if (isEmpty() == true)
    {head = tail = newNode;
    tail->next = NULL;
}else{newNode->next = head;
    head = newNode;
}
cout << "Data " << name << " berhasil ditambahkan" <<endl;
}

// Tambah data di bagian index terbesar atau terakhir
void insertBelakang(string name, string nim)
{
Node *newNode = new Node;
newNode->name = name;
newNode->nim = nim;
newNode->next = NULL;
    if (isEmpty() == true)
    {head = tail = newNode;
}else{tail->next = newNode;
    tail = newNode;
}
cout << "Data " << name << " berhasil ditambahkan" <<endl;
}

// Prosedur untuk menghitung list yang ada
int hitungList()
{
Node *hitung;
hitung = head;
int jumlah = 0;
while (hitung != NULL){jumlah++;
        hitung = hitung->next;
}
return jumlah;
}

// Tambah data dibagian atntar index atau data list
void insertTengah(string name, string nim, int posisi)
{
Node *newNode = new Node;
newNode->name = name;
newNode->nim = nim;
newNode->next = nullptr;

if (posisi == 1){newNode->next = head;
    head = newNode;
cout << "Data " << name << " berhasil ditambahkan pada posisi "<< posisi << endl;
return;
}

Node *prevNode = head;
for (int i = 1; i < posisi - 1 && prevNode != nullptr;
i++)
{
    prevNode = prevNode->next;
}
    if (prevNode == nullptr)
{
    cout << "Posisi tidak ditemukan" << endl;
return;
}
newNode->next = prevNode->next;
prevNode->next = newNode;
cout << "Data " << name << " berhasil ditambahkan pada posisi "<< posisi << endl;
}

// Prosedur untuk menghapus data di posisi tertentu
void remove()
{
bool loop = true;
while (loop)
{
int posisi;
cout << "----- Hapus Data -----\n";
cout << "1. Posisi Depan\n"
<< "2. Posisi Tengah\n"
<< "3. Posisi Belakang\n"
<< "4. Keluar\nMasukan Pilihan: ";
cin >> posisi;

// Untuk menghapus data index ke 0 atau data list pertama
if (posisi == 1)
{
Node *hapus;

if (isEmpty() == false)
{
if (head->next != NULL)
{
hapus = head;
head = head->next;
delete hapus;
cout << "Data berhasil dihapus!" <<endl;
}
    else{head = tail = NULL;
}
}
    else
{
cout << "List kosong!" << endl;
}
}

// untuk menghapus data antar index sesuai posisi
else if (posisi == 2)
{
int pos;
cout << "Masukan posisi yang ingin dihapus: ";
cin >> pos;
Node *bantu, *hapus, *sebelum;
if (pos < 1 || pos > hitungList())
{
    cout << "Posisi di luar jangkauan" << endl;
}
    else if (pos == 1)
{
cout << "Posisi bukan posisi tengah" <<
endl;
}
else
{
int nomor = 1;
bantu = head;
    while (nomor <= pos)
    {
        if (nomor == pos - 1)
        {sebelum = bantu;
        }
    if (nomor == pos)
        {hapus = bantu;
        }bantu = bantu->next;
        nomor++;
}
    sebelum->next = bantu;
    delete hapus;
    cout << "Data berhasil dihapus!" << endl;
}
}

// untuk menghapus data diindex terbesar atau terakhir
    else if (posisi == 3)
            {Node *hapus;
            Node *bantu;
    if (isEmpty() == false)
{
    if (head != tail)
    {hapus = tail;
    bantu = head;
    while (bantu->next != tail)
            {bantu = bantu->next;
            }
        tail = bantu;
        tail->next = NULL;
        delete hapus;
        cout << "Data berhasil dihapus!" <<endl;
    }else{head = tail = NULL;
        }
}
    else
{
    cout << "List kosong!" << endl;
}
}

// pilihan untuk keluar dari fungsi remove
    else if (posisi == 4)
            {cout << "Keluar" << endl;
            loop = false;
            }else
            {
            cout << "Input tidak valid!" << endl;
            }
        }
}

// untuk mengubah data index 0 atau pertama
void ubahDepan(string name, string nim)
{
    if (isEmpty() == 0)
        {head->name = name;
        head->nim = nim;
        }else{cout << "List masih kosong!" << endl;
            }
}

// untuk mengubah data diantara index sesuai posisi
void ubahTengah(string name, string nim, int posisi)
{
Node *bantu;
    if (isEmpty() == 0)
        {
    if (posisi < 1 || posisi > hitungList())
        {cout << "Posisi di luar jangkauan" << endl;
        }else if (posisi == 1){cout << "Posisi bukan posisi tengah" << endl;
                                }else{bantu = head;
                                    int nomor = 1;
    while (nomor < posisi)
{
    bantu = bantu->next;
    nomor++;
}
    bantu->name = name;
    bantu->nim = nim;
    }
    }else{cout << "List masih kosong!" << endl;
        }
}

// untuk mengubah data di index terbesar atay terakhir
void ubahBelakang(string name, string nim)
{
    if (isEmpty() == 0){tail->name = name;
                        tail->nim = nim;
                        }else{cout << "List masih kosong!" << endl;
                            }
}

// untuk menampilkan data list dalam program
void display()
{
    if (head == NULL)
        {cout << "List kosong!" << endl;
        return;
        }
Node *current = head;
int o = 1;
    while (current != NULL)
            {cout << o++ << ". "<< "Nama: " << current->name << endl;
            cout << " NIM: " << current->nim << endl;
            current = current->next;
            }
}

int main(){
    int choice;
    int choice_data;
    string name, nim;
    int posisi;

loop_menu:cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR: "<< endl;
cout << "1. Tambah data" << endl;
cout << "2. Hapus data" << endl;
cout << "3. Ubah data" << endl;
cout << "4. Tampilkan data" << endl;
cout << "5. Keluar" << endl;
cout << "Masukkan pilihan dari menu (1-5): ";
cin >> choice;
    switch (choice)
            {case 1:
            {   cout << "----- Tambahkan Data -----\n";
                cout << "Masukan Posisi Data : \n";
                cout << "1. Posisi di Depan\n";
                cout << "2. Posisi di Belakang\n";
                cout << "3. Posisi di Tengah\n";
                cout << "4. Keluar\n";
    loop_choice_data:
        cout << "Masukan pilihan Anda (1-4): ";
        cin >> choice_data;
    if (choice_data == 1)
{
    cout << "--Posisi di Depan--\n";
    cout << "Masukkan Nama: ";
    cin >> name;
    cout << "Masukkan NIM: ";
    cin >> nim;
    insertDepan(name, nim);
}
else if (choice_data == 2)
{
    cout << "--Posisi di Belakang--\n";
    cout << "Masukkan Nama: ";
    cin >> name;
    cout << "Masukkan NIM: ";
    cin >> nim;
    insertBelakang(name, nim);
}
else if (choice_data == 3)
{
    cout << "--Posisi di Tengah--\n";
    cout << "Masukkan Nama: ";
    cin >> name;
    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Masukan Posisi: ";
    cin >> posisi;
    insertTengah(name, nim, posisi);
}
else if (choice_data == 4)
{
    cout << "Keluar dari Menu Tambah Data\n";
    goto loop_menu;
}else
{
    cout << "Pilihan Anda Tidak Valid\n";
}
    goto loop_choice_data;
    break;
}case 2:
{
remove();
break;
}case 3:
{
    string newNim, newName;
    int pilihan, posisi;
    cout << "----- Ubah Data -----\n";
    cout << "1. Ubah Depan\n"
    << "2. Ubah Tengah\n"
    << "3. Ubah Belakang\n";
    cout << "Masukan pilihan anda: ";
    cin >> pilihan;
    if (pilihan == 1){
        cout << "Masukan nama yang baru: ";
        cin >> newName;
        cout << "Masukan NIM yang baru: ";
        cin >> newNim;
        ubahDepan(newName, newNim);
        }else if (pilihan == 2){
                    cout << "Masukab nama yang baru: ";
                    cin >> newName;
                    cout << "Masukan NIM yang baru: ";
                    cin >> newNim;
                    cout << "Masukan data posisi yang ingin diubah: ";
                    cin >> posisi;
                    ubahTengah(newName, newNim, posisi);
                }else if (pilihan == 3){
                            cout << "Masukan nama yang baru: ";
                            cin >> newName;
                            cout << "Masukan NIM yang baru: ";
                            cin >> newNim;
                            ubahBelakang(newName, newNim);
                        }
                        break;
                        }case 4:{
                            cout << "----- Tampilkan Data -----\n";
                            display();
                        break;
                            }case 5:{
                                cout << "Terima kasih!" << endl;
                            return 0;
                        break;
                                }
                        default:{
                            cout << "Pilihan tidak valid" << endl;
                            }
}
goto loop_menu;
return 0;
}
```
