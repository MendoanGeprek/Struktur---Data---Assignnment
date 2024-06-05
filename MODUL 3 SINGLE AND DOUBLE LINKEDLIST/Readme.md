# <h1 align="center">Laporan Praktikum Modul 3 Single and Double Linkedlist </h1>
<p align="center">Muhammad Djidzan N N</p>
<p align="center">2311102189</p>
<p align="center">IF 11 E</p>

## Dasar Teori
Linked list adalah sekumpulan elemen bertipe sama yang mempunyai keterurutan tertentu, yang setiap elemennya terdiri dari dua bagian. Linked list menggunakan satu variabel pointer untuk menyimpan banyak data. Tipe data pointer
bersifat dinamis, di mana variabel akan dialokasikan hanya saat dibutuhkan dan dapat direlokasikan kembali setelah tidak dibutuhkan[1]. 

Biasanya di dalam suatu linked list, terdapat istilah head dan tail.
- **Head** adalah elemen yang berada pada posisi pertama dalam suatu linked list[2].
- **Tail** adalah elemen yang berada pada posisi terakhir dalam suatu linked list[2].

### 1. Single Linked List:

Tempat yang disediakan pada
satu area memori tertentu untuk menyimpan data dikenal dengan sebutan node atau simpul. Setiap node memiliki pointer
yang menunjuk ke simpul berikutnya sehingga terbentuk satu
untaian, dengan demikian hanya diperlukan sebuah variabel pointer. Susunan berupa untaian semacam ini disebut single
linked list (NULL memiliki nilai khusus yang artinya tidak
menunjuk ke mana-mana. Biasanya, linked list pada titik akhirnya akan menunjuk ke NULL)[1].

Pembuatansingle linked listdapat dilakukan menggunakan dua jenis metode, yaitu:

- **LIFO** (last in first out), aplikasinya: stack (tumpukan)

adalah suatu metode pembuatan linked list, dimana data yang masuk paling akhir adalah data yang keluar paling awal[1].

- **FIFO** (first in first out), aplikasinya: queue (antrean)

adalah suatu metode pembuatan linked list, di mana data yang masuk paling awal adalah data yang keluar paling awal juga[1].

### 2. Double Linked List

Salah satu kelemahan single linked list adalah pointer
(penunjuk) hanya dapat bergerak satu arah, yaitu maju/mundur
atau kanan/kiri sehingga pencarian data pada single linked
list hanya dapat bergerak dalam satu arah. Untuk mengatasi
kelemahan ini, kita bisa menggunakan metode double linked
list. Linked list ini dikenal dengan nama linked list berpointer
ganda atau double linked list[1].

### 3. Circular Linked List

Circular Linked List merupakan suatu linked list dimana tail (node terakhir) menunjukan ke head (node pertama). jadi tidak ada pointer yang menunjukan NULL[1]. Ada 2 jenis circular linked list:

- Circular Single Linked List
- Circular Double Linked List
- 
## GUIDED

## Guided 1

### Source Progam
```c++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
//komponen/member
int data;
Node *next;
};
Node *head;
Node *tail;
//Inisialisasi Node
void init(){
head = NULL;
tail = NULL;
}
// Pengecekan
bool isEmpty(){
if (head == NULL)
return true;
else
return false;
}
//Tambah Depan
void insertDepan(int nilai){
//Buat Node baru
Node *baru = new Node;
baru->data = nilai;
baru->next = NULL;
if (isEmpty() == true){
head = tail = baru;
tail->next = NULL;

}
else{
baru->next = head;
head = baru;
}
}
//Tambah Belakang
void insertBelakang(int nilai){
//Buat Node baru
Node *baru = new Node;
baru->data = nilai;
baru->next = NULL;
if (isEmpty() == true){
head = tail = baru;
tail->next = NULL;
}
else{
tail->next = baru;
tail = baru;
}
}
//Hitung Jumlah List
int hitungList(){
Node *hitung;
hitung = head;
int jumlah = 0;
while( hitung != NULL ){
jumlah++;
hitung = hitung->next;
}
return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
if( posisi < 1 || posisi > hitungList() ){
cout << "Posisi diluar jangkauan" << endl;

}
else if( posisi == 1){
cout << "Posisi bukan posisi tengah" <<

endl;
}
else{
Node *baru, *bantu;
baru = new Node();
baru->data = data;
// tranversing
bantu = head;
int nomor = 1;
while( nomor < posisi - 1 ){
bantu = bantu->next;
nomor++;
}
baru->next = bantu->next;
bantu->next = baru;
}
}
//Hapus Depan
void hapusDepan() {
Node *hapus;
if (isEmpty() == false){
if (head->next != NULL){
hapus = head;
head = head->next;
delete hapus;
}
else{
head = tail = NULL;
}
}
else{
cout << "List kosong!" << endl;
}
}

//Hapus Belakang
void hapusBelakang() {
Node *hapus;
Node *bantu;
if (isEmpty() == false){
if (head != tail){
hapus = tail;
bantu = head;
while (bantu->next != tail){
bantu = bantu->next;
}
tail = bantu;
tail->next = NULL;
delete hapus;
}
else{
head = tail = NULL;
}
}
else{
cout << "List kosong!" << endl;
}
}
//Hapus Tengah
void hapusTengah(int posisi){
Node *hapus, *bantu, *bantu2;
if( posisi < 1 || posisi > hitungList() ){
cout << "Posisi di luar jangkauan" << endl;
}
else if( posisi == 1){
cout << "Posisi bukan posisi tengah" <<

endl;
}
else{
int nomor = 1;
bantu = head;
while( nomor <= posisi ){

if( nomor == posisi-1 ){
bantu2 = bantu;
}
if( nomor == posisi ){
hapus = bantu;
}
bantu = bantu->next;
nomor++;
}
bantu2->next = bantu;
delete hapus;
}
}
//Ubah Depan
void ubahDepan(int data){
if (isEmpty() == false){
head->data = data;
}
else{
cout << "List masih kosong!" << endl;
}
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
Node *bantu;
if (isEmpty() == false){
if( posisi < 1 || posisi > hitungList() ){
cout << "Posisi di luar jangkauan" <<

endl;
}
else if( posisi == 1){
cout << "Posisi bukan posisi tengah" <<

endl;
}
else{
bantu = head;
int nomor = 1;

while (nomor < posisi){
bantu = bantu->next;nomor++;
}
bantu->data = data;
}
}
else{
cout << "List masih kosong!" << endl;
}
}
//Ubah Belakang
void ubahBelakang(int data){
if (isEmpty() == false){
tail->data = data;
}
else{
cout << "List masih kosong!" << endl;
}
}
//Hapus List
void clearList(){
Node *bantu, *hapus;
bantu = head;
while (bantu != NULL){
hapus = bantu;
bantu = bantu->next;
delete hapus;
}
head = tail = NULL;
cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
Node *bantu;
bantu = head;
if (isEmpty() == false){

while (bantu != NULL){
cout << bantu->data << ends;
bantu = bantu->next;
}
cout << endl;
}
else{
cout << "List masih kosong!" << endl;
}
}
    int main(){
        
        init();
        insertDepan(3);tampil();
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
        insertTengah(7,2);
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
<img width="690" alt="waduhh" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/926271cb-481e-4dac-b7c2-ba2ba7e21b5a">

### Deskripsi Progam

Program Linked list yang dibuat adalah single linked list non-circular, di mana setiap node memiliki data integer dan pointer yang menunjuk ke node berikutnya. Kode dimulai dengan deklarasi struct `Node` yang memiliki dua anggota, `data` untuk nilai data dan `next` untuk pointer ke node berikutnya. Selanjutnya, terdapat inisialisasi dua pointer `head` dan `tail` yang awalnya menunjuk ke NULL, menandakan linked list kosong.

Fungsi-fungsi yang disediakan meliputi inisialisasi linked list, pengecekan apakah linked list kosong, penambahan node di depan dan belakang, penghitungan jumlah node, penambahan node pada posisi tertentu, penghapusan node dari depan, belakang, atau posisi tertentu, pengubahan nilai data pada node tertentu, penghapusan seluruh isi linked list, dan menampilkan isi linked list.

Di dalam `main()` function, dilakukan serangkaian operasi seperti penambahan, penghapusan, dan pengubahan nilai data pada linked list yang telah dibuat untuk memperlihatkan fungsionalitas dari implementasi linked list tersebut.

## Guided 2

### Source Progam
```c++
#include <iostream>
using namespace std;
class Node {
public:int data;
Node* prev;
Node* next;
};
class DoublyLinkedList {

public:
Node* head;
Node* tail;
DoublyLinkedList() {
head = nullptr;
tail = nullptr;

}
void push(int data) {
Node* newNode = new Node;
newNode->data = data;
newNode->prev = nullptr;
newNode->next = head;
if (head != nullptr) {
head->prev = newNode;
}
else {
tail = newNode;
}
head = newNode;
}
void pop() {
if (head == nullptr) {
return;
}
Node* temp = head;
head = head->next;
if (head != nullptr) {
head->prev = nullptr;
}
else {
tail = nullptr;
}
delete temp;
}
bool update(int oldData, int newData) {
Node* current = head;while (current != nullptr) {
if (current->data == oldData) {
current->data = newData;
return true;
}
current = current->next;
}

return false;
}
void deleteAll() {
Node* current = head;
while (current != nullptr) {
Node* temp = current;
current = current->next;
delete temp;
}
head = nullptr;
tail = nullptr;
}
void display() {
Node* current = head;
while (current != nullptr) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}
};
int main() {
DoublyLinkedList list;
while (true) {
cout << "1. Add data" << endl;
cout << "2. Delete data" << endl;
cout << "3. Update data" << endl;
cout << "4. Clear data" << endl;
cout << "5. Display data" << endl;
cout << "6. Exit" << endl;int choice;
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1: {
int data;
cout << "Enter data to add: ";
cin >> data;
list.push(data);
break;
}
case 2: {
list.pop();
break;
}
case 3: {
int oldData, newData;
cout << "Enter old data: ";
cin >> oldData;
cout << "Enter new data: ";
cin >> newData;
bool updated = list.update(oldData,

newData);

if (!updated) {
cout << "Data not found" << endl;
}
break;

}
case 4: {
list.deleteAll();
break;
}
case 5: {
list.display();
break;
}
case 6: {
return 0;
}
default: {
cout << "Invalid choice" << endl;
break;
}
}
}
return 0;
}
```
### Ouput Progam
<img width="688" alt="walulu" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/a7bc5191-52d6-4aee-94cc-e82d3ccabbc8">

### Deskripsi Progam
Program di atas merupakan implementasi dari linked list yang menggunakan struktur data berbasis node dan dilengkapi dengan kelas LinkedList untuk mengelola data. Program ini memungkinkan pengguna untuk menambahkan data ke dalam linked list, menampilkan seluruh data yang ada, menghapus data berdasarkan nama, menyisipkan data di antara dua node tertentu, menyisipkan data di awal linked list, serta mengubah data berdasarkan nama. Pengguna dapat memilih operasi yang ingin dilakukan melalui menu yang ditampilkan di layar, dan program akan menjalankan operasi sesuai dengan pilihan pengguna. Program ini menawarkan fungsionalitas dasar untuk manajemen data dan penyuntingan linked list.

## UNGUIDED

## Unguided 1
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:

a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.

b. Hapus data Akechi

c. Tambahkan data berikut diantara John dan Jane : Futaba 18

d. Tambahkan data berikut diawal : Igor 20

e. Ubah data Michael menjadi : Reyn 18

f. Tampilkan seluruh data

### Source Progam
```c++
#include <iostream>
#include <string>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string nama;
    int usia;
    Node *next;
};

Node *head = NULL; // Pointer yang menunjuk ke node pertama (head) dari linked list
Node *tail = NULL; // Pointer yang menunjuk ke node terakhir (tail) dari linked list

// Fungsi untuk menambah node baru di depan
void insertDepan(string nama, int usia)
{
    Node *baru = new Node; // Membuat node baru
    baru->nama = nama;     // Mengisi data nama pada node baru
    baru->usia = usia;     // Mengisi data usia pada node baru

    // Menambahkan node baru di depan head
    baru->next = head; // Node baru menunjuk ke node yang ditunjuk oleh head
    head = baru;       // Head menunjuk ke node baru

    // Jika linked list sebelumnya kosong, tail juga perlu diubah
    if (tail == NULL)
    {
        tail = baru;
    }
}

// Fungsi untuk menambah node baru di belakang
void insertBelakang(string nama, int usia)
{
    Node *baru = new Node; // Membuat node baru
    baru->nama = nama;     // Mengisi data nama pada node baru
    baru->usia = usia;     // Mengisi data usia pada node baru
    baru->next = NULL;     // Mengatur pointer next node baru menjadi NULL

    if (head == NULL) // Jika linked list kosong
    {
        head = baru; // Head menunjuk ke node baru
        tail = baru; // Tail juga menunjuk ke node baru karena hanya ada satu node dalam linked list
    }
    else // Jika linked list tidak kosong
    {
        tail->next = baru; // Menambahkan node baru setelah tail
        tail = baru;       // Mengubah tail untuk menunjuk ke node baru yang merupakan node terakhir
    }
}

// Fungsi untuk menambah node baru di tengah
void insertTengah(string nama, int usia, string namaSebelumnya)
{
    Node *baru = new Node; // Membuat node baru
    baru->nama = nama;     // Mengisi data nama pada node baru
    baru->usia = usia;     // Mengisi data usia pada node baru

    Node *bantu = head;
    while (bantu != NULL && bantu->nama != namaSebelumnya) // Mencari node dengan namaSebelumnya
    {
        bantu = bantu->next;
    }

    if (bantu == NULL) // Jika node dengan namaSebelumnya tidak ditemukan
    {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    baru->next = bantu->next; // Mengatur pointer next node baru
    bantu->next = baru;       // Menambahkan node baru setelah node dengan namaSebelumnya
}

// Fungsi untuk menampilkan semua data
void tampil()
{
    Node *bantu = head;
    if (bantu == NULL) // Jika linked list kosong
    {
        cout << "List kosong!" << endl;
        return;
    }

    while (bantu != NULL) // Menampilkan data setiap node dalam linked list
    {
        cout << bantu->nama << "\t" << bantu->usia << endl;
        bantu = bantu->next;
    }
}

// Fungsi untuk menghapus node dengan nama tertentu
void hapus(string nama)
{
    Node *hapus = head;
    Node *sebelum = NULL;

    while (hapus != NULL && hapus->nama != nama) // Mencari node dengan nama yang akan dihapus
    {
        sebelum = hapus;
        hapus = hapus->next;
    }

    if (hapus == NULL) // Jika node dengan nama yang akan dihapus tidak ditemukan
    {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    if (sebelum == NULL) // Jika node yang akan dihapus adalah head
    {
        head = hapus->next; // Mengubah head menjadi node setelah node yang dihapus
    }
    else
    {
        sebelum->next = hapus->next; // Mengubah pointer next node sebelumnya untuk menghapus node yang dituju
    }

    delete hapus; // Menghapus node yang dihapus dari memory
}

// Fungsi untuk mengubah data mahasiswa dengan nama tertentu
void ubahData(string nama, string namaBaru, int usiaBaru)
{
    Node *ubah = head;

    while (ubah != NULL && ubah->nama != nama) // Mencari node dengan nama yang akan diubah
    {
        ubah = ubah->next;
    }

    if (ubah == NULL) // Jika node dengan nama yang akan diubah tidak ditemukan
    {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    ubah->nama = namaBaru; // Mengubah data nama pada node yang ditemukan
    ubah->usia = usiaBaru; // Mengubah data usia pada node yang ditemukan
}

int main()
{
    // Menambahkan data
    insertBelakang("John", 19);
    insertBelakang("Jane", 20);
    insertBelakang("Michael", 18);
    insertBelakang("Yusuke", 19);
    insertBelakang("Akechi", 20);
    insertBelakang("Hoshino", 18);
    insertBelakang("Karin", 18);

    char menu;
    string nama, namaBaru;
    int usia, usiaBaru;

    // Menampilkan menu
    do
    {
        cout << "\nMenu:\n";
        cout << "a. Masukkan data\n";
        cout << "b. Hapus data Akechi\n";
        cout << "c. Tambahkan data di antara John dan Jane\n";
        cout << "d. Tambahkan data di awal\n";
        cout << "e. Ubah data Michael\n";
        cout << "f. Tampilkan seluruh data\n";
        cout << "g. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu)
        {
            // Input nama dan usia saya
        case 'a':
            cout << "Masukkan nama dan usia: ";
            cin >> nama >> usia;
            insertDepan(nama, usia);
            cout << "Data berhasil di tambahkan" << endl;
            break;
            // Hapus data akechi
        case 'b':
            hapus("Akechi");
            cout << "Data Akechi telah di hapus" << endl;
            break;
            // Tambahkan data berikut diantara John dan Jane : Futaba 18
        case 'c':
            cout << "Masukkan nama dan usia: ";
            cin >> nama >> usia;
            insertTengah("Futaba", 18, "John");
            cout << "Data futaba telah di tambahkan" << endl;
            break;
            // Tambahkan data berikut diawal : Igor 20
        case 'd':
            cout << "Masukkan nama dan usia: ";
            cin >> nama >> usia;
            insertDepan(nama, usia);
            cout << "Data telah di tambahkan" << endl;
            break;
            // Ubah data Michael menjadi : Reyn 18
        case 'e':
            cout << "Masukkan nama baru, usia baru: ";
            cin >> namaBaru >> usiaBaru;
            ubahData("Michael", namaBaru, usiaBaru);
            cout << "Data berhasil diubah" << endl;
            break;
            // Menampilkan data
        case 'f':
            tampil();
            break;
            // Keluar program
        case 'g':
            cout << "Keluar dari program." << endl;
            break;
            // Jika menu tidak valid
        default:
            cout << "Menu tidak valid!" << endl;
        }
    } while (menu != 'g');

    return 0;
}
```
### Ouput Progam

### A.
<img width="678" alt="siuu" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/4b29f48e-241d-42d9-bb70-aa0ca5fd1a72">

### B.
<img width="254" alt="ake" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/ee3e1843-609c-43cd-966f-69007730810f">

### C.
<img width="315" alt="futa" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/8f1901a0-4079-444f-b253-419d8c5518e7">

### D.
<img width="273" alt="igor" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/210bbfc4-9f25-43f0-b2e0-7fa54a3b0a9f">

### E.
<img width="255" alt="reyn" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/d29c520d-5074-4efa-9b5c-4d5f16e10309">

### F.
<img width="268" alt="jidan" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/83af4355-63af-420e-854a-e5d3d648e12a">

### Deskripsi Progam

Program di atas merupakan implementasi dari linked list yang menggunakan struktur data berbasis node dan dilengkapi dengan kelas LinkedList untuk mengelola data. Program ini memungkinkan pengguna untuk menambahkan data ke dalam linked list, menampilkan seluruh data yang ada, menghapus data berdasarkan nama, menyisipkan data di antara dua node tertentu, menyisipkan data di awal linked list, serta mengubah data berdasarkan nama. Pengguna dapat memilih operasi yang ingin dilakukan melalui menu yang ditampilkan di layar, dan program akan menjalankan operasi sesuai dengan pilihan pengguna. Program ini menawarkan fungsionalitas dasar untuk manajemen data dan penyuntingan linked list.

## Unguided 2
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.

Case:

Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
Hapus produk wardah
Update produk Hanasui menjadi Cleora dengan harga 55.000
Tampilkan menu seperti dibawah ini
Toko Skincare Purwokerto

Tambah Data
Hapus Data
Update Data
Tambah Data Urutan Tertentu
Hapus Data Urutan Tertentu
Hapus Seluruh Data
Tampilkan Data
Exit
### Source Progam

### Ouput Progam

### CASE 1
<img width="689" alt="NIHUY" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/6ff94ac2-e06d-4c2d-afd9-ab4e4c22568e">

### CASE 2
<img width="297" alt="war" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/ac08a840-da5d-4b14-ad33-6952bddd8ad1">

### CASE 3
<img width="311" alt="hana" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/9d0d0fdc-675d-4588-b6c6-c095d41cdb6f">

### CASE 4
<img width="215" alt="akhir" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/cb5db7b8-f206-4d91-8ec5-3d3162bf982b">

### Deskripsi Progam

Program ini adalah aplikasi berbasis console yang digunakan untuk mengelola daftar produk menggunakan struktur data Doubel Linked List. Doubel Linked List adalah struktur data di mana setiap elemen (node) memiliki dua pointer, satu menunjuk ke node berikutnya dan satu lagi menunjuk ke node sebelumnya, memungkinkan navigasi ke depan dan ke belakang.

Program ini memungkinkan pengguna untuk menambahkan, menghapus, memperbarui, dan menampilkan data produk, serta melakukan operasi khusus seperti menambah dan menghapus produk pada urutan tertentu.

## Kesimpulan

Linked list adalah struktur data dinamis yang terdiri dari serangkaian elemen (node) yang dihubungkan satu sama lain. Ada dua jenis utama linked list: Single Linked List dan Double Linked List. Masing-masing memiliki karakteristik, keuntungan, dan kelemahan yang berbeda. Memilih antara single dan double linked list tergantung pada kebutuhan spesifik aplikasi, terutama terkait dengan operasi yang sering dilakukan dan efisiensi yang diinginkan.

## Refrensi
https://www.journal.piksi.ac.id/ https://repository.unikom.ac.id/

"geeksforgeeks", [Online]. Available: https://www.geeksforgeeks.org/. [Accessed: March 25, 2024].
