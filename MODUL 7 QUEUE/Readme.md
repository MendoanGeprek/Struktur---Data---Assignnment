# <h1 align="center"> Laporan Praktikum Modul 7_Queue</h1>
<p align="center"> Muhammad Djidzan. N. N <p>
<p align="center"> 2311102189 </p>

## Dasar Teori Queue

Queue sering kita jumpai dalam aktivitas sehari-hari. Proses Queue merupakan suatu proses yang berkaitan dengan kedatangan pelanggan pada suatu fasilitas pelayanan, menunggu untuk mendapatkan pelayanan hingga akhirnya mendapatkan pelayanan dan meninggalkan fasilitas pelayanan. Banyak model Queue menggunakan sistem server tunggal, sistem fase tunggal, dan sistem fase tunggal multi-server. Saat ini masih terdapat fasilitas layanan yang belum memanfaatkan teknologi untuk memberikan kemudahan bagi penggunanya.

## Guided
```c++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
    string queueTeller[5];       // Fungsi pengecekan

bool isFull()
{ // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{ // Antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueueAntrian(string data)
{ // Fungsi menambahkan antrian
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty())
        { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        }
        else
        { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}
void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}
int countQueue()
{ // Fungsi menghitung banyak antrian
    return back;
}
void clearQueue()
{ // Fungsi menghapus semua antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}
void viewQueue()
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] <<

                endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
## Screenshot Progam
<img width="689" alt="lau" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/8899e4ca-3a7a-4da6-b8b0-4e430abaa0bb">

## Deskripsi Progam
Program C++ ini simulasikan sistem antrian sederhana untuk teller. Program ini memungkinkan penambahan, penghapusan, dan penampilan pelanggan di antrian. Antrian memiliki kapasitas maksimum 5 pelanggan

## Unguided 
1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi
linked list

2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM
Mahasiswa

## Source Code 1
```c++
#include <iostream>
using namespace std;

struct Node {
  string data;
  Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isFull() {
  return false;
}

bool isEmpty() {
  return front == nullptr;
}

void enqueueAntrian(string data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;

  if (isEmpty()) {
    front = newNode;
    back = newNode;
  } else {
    back->next = newNode;
    back = newNode;
  }
}

void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Queue kosong" << endl;
    return;
  }

  Node* temp = front;
  front = front->next;
  delete temp;

  if (front == nullptr) {
    back = nullptr;
  }
}

int countQueue() {
  int count = 0;
  Node* current = front;
  while (current != nullptr) {
    count++;
    current = current->next;
  }
  return count;
}

void clearQueue() {
  while (front != nullptr) {
    Node* temp = front;
    front = front->next;
    delete temp;
  }
  back = nullptr;
}

void viewQueue() {
  cout << "Data Queue Teller:" << endl;
  Node* current = front;
  while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

int main() {
  enqueueAntrian("Smokey");
  enqueueAntrian("Fukada");
  viewQueue();
  cout << "Jumlah Queue = " << countQueue() << endl;
  dequeueAntrian();
  viewQueue();
  cout << "Jumlah Queue = " << countQueue() << endl;
  clearQueue();
  viewQueue();
  cout << "Jumlah Queue = " << countQueue() << endl;
  return 0;
}
```

## Screenshot Progam
<img width="683" alt="ulu" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/bfd1c458-3a44-4fd1-a834-05337cb1a31f">

## Deskripsi Progam
Program C++ ini adalah implementasi dari struktur antrian (queue) yang digunakan untuk menangani operasi penambahan, penghapusan, dan penampilan data. Program ini menggunakan struktur data Node untuk mewakili setiap elemen di antrian, dengan atribut data untuk menyimpan nilai dan next untuk menghubungkan elemen ke elemen berikutnya.

## Source Code 2
```c++
#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string namaMahasiswa;
    string nim;
    Node *next;
};

Node *front = nullptr;
Node *back = nullptr;

bool isFull()
{
    return false;
}

bool isEmpty()
{
    return front == nullptr;
}

void enqueueAntrian(string nama, string nim)
{
    Node *newNode = new Node;
    newNode->namaMahasiswa = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty())
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Queue Kosong" << endl;
        return;
    }

    Node *temp = front;
    front = front->next;
    delete temp;

    if (front == nullptr)
    {
        back = nullptr;
    }
}

int countQueue()
{
    int count = 0;
    Node *current = front;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue()
{
    while (front != nullptr)
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
}

void viewQueue()
{
    cout << "Data Queue Mahasiswa:" << endl;
    Node *current = front;
    while (current != nullptr)
    {
        cout << "Nama: " << current->namaMahasiswa << ", NIM: " << current->nim << endl;
        current = current->next;
    }
}

int main()
{
    enqueueAntrian("Lauda", "87987912");
    enqueueAntrian("Hunt", "31323412");
    viewQueue();
    dequeueAntrian();
    viewQueue();
    return 0;
}
```

## Screenshot Progam
<img width="684" alt="alala" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/a4293504-3480-4eff-b341-9f5ae111b9b5">

## Deskripsi Progam
Program C++ ini adalah implementasi dari struktur antrian (queue) yang digunakan untuk menangani operasi penambahan, penghapusan, dan penampilan data. Program ini menggunakan struktur data Node untuk mewakili setiap elemen di antrian, dengan atribut namaMahasiswa dan nim untuk menyimpan informasi mahasiswa dan atribut next untuk menghubungkan elemen ke elemen berikutnya.

## Kesimpulan
Queue dalam C++ adalah struktur data FIFO yang dapat diimplementasikan dengan array atau linked list. Implementasi dengan array memiliki kapasitas tetap, sedangkan linked list memungkinkan penambahan elemen dinamis. Operasi dasar meliputi EnQueue, DeQueue, IsEmpty, IsFull, dan Peek/Front. Penelitian terbaru menyoroti penggunaan queue dalam optimisasi antrian dan jaringan komputer, serta analisis efisiensi memori dan performa algoritma.

## Refrensi 
[1] A. D. Istoko, Pengembangan Mesin Antrean Berbasis Web Menggunakan Raspberry Dan ESP8266, Yogyakarta, Indonesia: Skripsi, 2018.
[2] D. J. N. Salim, W. Sanjaya, A. R. Pamungkas dan A. K. Indarto, “Sistem Antrian Berbasis Web Menggunakan Raspberry dan ESP8266,” Go Infotech: Jurnal Ilmiah STMIK AUB, vol. 25, pp. 62-70, 2019.





