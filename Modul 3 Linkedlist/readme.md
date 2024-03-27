# <h1 align="center"> Laporan Praktium Modul-3 Single dan Double Linked List </h1>
<p align="center"> Muhammad Djidzan. N. N <p>
<p align="center"> 2311102189</p>
<p align="center"> IF-11-E</p>

## Dasar Teori 
<div style="text-align: right">
Double Linked List adalah jenis linked list yang memiliki node yang memiliki data dan dua buah reference link, biasanya disebut next dan prev, yang menunjuk ke node yang berada sebelumnya dan sesudahnya Double Linked List memiliki beberapa keunggulan terhadap Single Linked List, seperti:
  
- Double Linked List memiliki dua pointer sambungan, yang memungkinkan penyisipan bisa dilakukan sebelum data tertentu atau sesudah data tertentu
- Double Linked List dapat dilakukan dari kiri ke kanan atau dari kanan ke kiri dalam hal menyusuri list
- Double Linked List memiliki kemampuan untuk menghapus elemen dengan lebih cepat, karena tidak perlu melakukan traversal seluruh linked list

Sebagai contoh, jika kita memiliki Double Linked List yang terdiri dari beberapa elemen, kita dapat melakukan penyisipan elemen baru di awal, tengah, atau akhir linked list dengan mudah. Ketika linked list masih kosong, simpul baru akan menjadi simpul awal dan sekaligus simpul akhir dari Double Linked List.
</div>

## Guided 
### 1. Latihan Single Linked List
```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
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
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
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
// Hitung Jumlah List
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
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" <<

            endl;
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
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
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
        cout << "List kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
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
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" <<

            endl;
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
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" <<

                endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" <<

                endl;
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
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
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
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
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

### Screenshoot
<img width="688" alt="4" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/e788cf0c-e7a1-41b7-b77a-1c2c8f149063">

### 2. Latihan Double Linked List
```C++
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
class DoublyLinkedList
{

public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }
    void pop()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == oldData)
            {
                current->data = newData;
                return true;
            }
            current = current->next;
        }

        return false;
    }
    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    DoublyLinkedList list;
    while (true)
    {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
        case 2:
        {
            list.pop();
            break;
        }
        case 3:
        {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData,

                                       newData);

            if (!updated)
            {
                cout << "Data not found" << endl;
            }
            break;
        }
        case 4:
        {
            list.deleteAll();
            break;
        }
        case 5:
        {
            list.display();
            break;
        }
        case 6:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
    return 0;
}
```
### Screenshot: 
<img width="698" alt="5" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/0e52a90e-2196-41fd-86d6-3416248a6152">

## Unguided
### 1. Buatlah program menu Single Linked List Non-Circular untuk
menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan
dari user. Lakukan operasi berikut:

a. Masukkan data sesuai urutan berikut. (Gunakan insert depan,
belakang atau tengah). Data pertama yang dimasukkan adalah
nama dan usia anda.

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/f3e6575d-203d-418f-b3ac-6745b44d5585)

b. Hapus data Akechi

c. Tambahkan data berikut diantara John dan Jane : Futaba 18

d. Tambahkan data berikut diawal : Igor 20

e. Ubah data Michael menjadi : Reyn 18

f. Tampilkan seluruh data

```C++
#include <iostream>
using namespace std;

  class Node
 {
 public:
  string name;
  int age;
  Node *next;
};
class LinkedList
{
public:
 Node *head;
 LinkedList()
{
   head = NULL;
}
void insertAtFront(string name, int age)
 {
  Node *newNode = new Node();
  newNode->name = name;
  newNode->age = age;
  newNode->next = head;
  head = newNode;
 }
void insertAtEnd(string name, int age)
 {
  Node *newNode = new Node();
  newNode->name = name;
  newNode->age = age;
  newNode->next = NULL;
   if (head == NULL)
  {
  head = newNode;
  return;
   }
    Node *temp = head;
    while (temp->next != NULL)
 {
 temp = temp->next;
 }
 temp->next = newNode;
}
void insertAfter(string name, int age, string keyName){
   Node *temp = head;
   while (temp != NULL)
{
   if (temp->name == keyName)
{
    Node *newNode = new Node();
    newNode->name = name;
    newNode->age = age;
    newNode->next = temp->next;
    temp->next = newNode;
return;
  }
    temp = temp->next;
 }
   cout << keyName << " Tidak ditemukan di list." << endl;
}
void updateNode(string name, int age)
{
Node *temp = head;
 while (temp != NULL)
{
  if (temp->name == name)
{
    temp->age = age;
    return;
}
  temp = temp->next;
  }
       cout << name << " Tidak ditemukan di list." << endl;
}
void deleteNode(string name)
{
 Node *temp = head;
 Node *prev = NULL;
 while (temp != NULL)
{
  if (temp->name == name)
{
  if (prev == NULL)
{
  head = temp->next;
}
else
{
   prev->next = temp->next;
}
delete temp;
return;
 }
 prev = temp;
 temp = temp->next;
 }
    cout << name << " Tidak ditemukan di list." << endl;
 }
void clearAll()
  {
   Node *temp = head;
   while (temp != NULL)
  {
      Node *next = temp->next;
      delete temp;
      temp = next;
    }
      head = NULL;
 }

 void display()
 {
   Node *temp = head;
   while (temp != NULL)
{
      cout << "Nama: " << temp->name << ", Umur: " <<
 temp->age << endl;
        temp = temp->next;
      }
  }
};

int main()
{
  LinkedList list;
  int choice;
  string name, keyName;
  int age;
  do
 {
  cout << endl;
  cout << "MENU" << endl;
  cout << "1. Tambah Data" << endl;
  cout << "2. Perbarui Data" << endl;
  cout << "3. Hapus Data" << endl;
  cout << "4. Clear Data" << endl;
  cout << "5. Display data" << endl;
  cout << "6. Keluar" << endl;
  cout << "Masukkan Pilihanmu: ";
  cin >> choice;
  switch (choice)
 {
 case 1:
    cout << "Tambah Data: ";
   cin >> name;
   cout << "Tambah Umur: ";
   cin >> age;
   list.insertAtFront(name, age);
   break;
 case 2:
   cout << "Tambah Nama untuk Perbarui: ";
   cin >> name;
   cout << "Tambah Umur: ";
   cin >> age;
   list.updateNode(name, age);
   break;
 case 3:
  cout << "Masukkan Nama untuk Mengahapus: ";
  cin >> name;
    list.deleteNode(name);
  break;
 case 4:
  list.clearAll();
  break;
  case 5:
  list.display();
  break;
 case 6:
      cout << "Keluar Progam..." << endl;
  break;
 default:
    cout << "Pilihan Tidak Valid." << endl;
 }
} while (choice != 6);
 return 0;
 }
```

### Screenshot
#### Output.
<img width="169" alt="6" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/129c76b9-d4b9-4eae-ba9e-d9163355c2e0">


#### Case 1.
<img width="281" alt="7" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/d8d7010e-60ab-409d-a202-02554c191235">

#### Case 2.
![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/8e56773c-7db1-4305-98c3-d393a26af0bc)

#### Case 3.
![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/f0d5a15b-b054-4ed0-9829-f5ef057b54a5)

#### Case 4.
![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/73e6902f-b278-4384-ac33-e97ab2d65b93)

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/cc406b16-a1d7-40c0-8b62-9f2b11f80527)


![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/aa911434-af99-4ab0-b7b5-592ea759fb34)



Case:
1. Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific
2. Hapus produk wardah
3. Update produk Hanasui menjadi Cleora dengan harga 55.000
4. Tampilkan menu seperti dibawah ini

![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/85c328ab-1684-4af0-b845-1af8055110a5)

Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :
   
![image](https://github.com/KotaNamaki/Structure-Data-Assignment/assets/125143781/89a0d862-b2ab-40fd-8829-08d1804202cd)

```C++
#include <iostream>
#include <string>
using namespace std;
struct Node

{

string nama;
int harga;
 Node *prev;
 Node *next;
 };
  class DoubleLinkedList
  {
 private:
  Node *head;
  Node *tail;
 int size;
   public:DoubleLinkedList()
 {
  head = NULL;
  tail = NULL;
  size = 0;
 }
 void addData(string nama, int harga)
  {
    Node *node = new Node;
    node->nama = nama;
    node->harga = harga;
    node->prev = tail;
    node->next = NULL;
 if (head == NULL)
 {
   head = node;
   tail = node;
 }
 else
  {
  tail->next = node;
  tail = node;
 }
  size++;
 }
  void addDataAt(int index, string nama, int harga)
 {
  if (index < 0 || index > size)
 {
     cout << "Index out of bounds" << endl;
 return;
 }
   Node *node = new Node;
    node->nama = nama;
     node->harga = harga;
 if (index == 0)
 {
  node->prev = NULL;
  node->next = head;
  head->prev = node;
  head = node;
 }
   else if (index == size)
 {
  node->prev = tail;
  node->next = NULL;
  tail->next = node;
  tail = node;
 }
 else
 {
   Node *current = head;for (int i = 0; i < index - 1; i++)
 {
   current = current->next;
 }
  node->prev = current;
  node->next = current->next;
  current->next->prev = node;
  current->next = node;
 }
   size++;
 }
   void deleteDataAt(int index)
   {
  if (index < 0 || index >= size)
 {
     cout << "Index out of bounds" << endl; 
 return;
 }
  if (index == 0)
 {
   Node *temp = head;
   head = head->next;
   head->prev = NULL;
   delete temp;
 }
    else if (index == size - 1)
 {
      Node *temp = tail;
        tail = tail->prev;
      tail->next = NULL;
    delete temp;
 }
  else
 {
   Node *current = head; 
    for (int i = 0; i < index; i++)
 {
  current = current->next;
 }
   current->prev->next = current->next;
    current->next->prev = current->prev;
 delete current;
 }
  size--;
 }
   void clearData()
 {
 while (head != NULL)
 {
   Node *temp = head;
   head = head->next;
   delete temp;}
   tail = NULL;
 size = 0;
 }
    void displayData()
 {
      cout << "Nama Produk\tHarga" << endl;
    Node *current = head;
 while (current != NULL)
 {
       cout << current->nama << "\t\t" << current->harga
 << endl;
   current = current->next;
   }
  }
   void updateDataAt(int index, string nama, int harga)
 {
    if (index < 0 || index >= size)
 {
      cout << "Index out of bounds" << endl;
 return;
 }
  Node *current = head;
   for (int i = 0; i < index; i++)
 {
   current = current->next;
 }
    current->nama = nama;
    current->harga = harga;
 }
  };
int main()
{
   DoubleLinkedList dll;
    int choice;
    string nama;
    int harga;
    int index;
     do
 {
   cout << "Menu:" << endl;
   cout << "1. Tambah Data" << endl;
   cout << "2. Hapus Data" << endl;
   cout << "3. Update Data" << endl;
   cout << "4. Tambah Data pada Urutan Tertentu" <<
 endl;
   cout << "5. Hapus Data pada Urutan Tertentu" << endl;
   cout << "6. Hapus Semua Data" << endl;
   cout << "7. Tampilkan Data" << endl;
   cout << "8. Keluar" << endl;cout << "Pilih: ";
    cin >> choice;
 switch (choice)
 {
  case 1:
   cout << "Nama Produk: ";
  cin >> nama;
   cout << "Harga: ";
  cin >> harga;
     dll.addData(nama, harga);
 break;
 case 2:
   cout << "Index: ";
   cin >> index;
   dll.deleteDataAt(index);
   break;
 case 3:
     cout << "Index: ";
     cin >> index;
     cout << "Nama Produk: ";
     cin >> nama;
     cout << "Harga: ";
     cin >> harga;
     dll.updateDataAt(index, nama, harga);
  break;
 case 4:
    cout << "Index: ";
    cin >> index;
      cout << "Nama Produk: ";
      cin >> nama;
       cout << "Harga: ";
     cin >> harga;
     dll.addDataAt(index, nama, harga);
  break;
 case 5:
   cout << "Index: ";
   cin >> index;
   dll.deleteDataAt(index);
   break;
 case 6:
     dll.clearData();
  break;
 case 7: 
   dll.displayData();
  break;
 case 8:
   break;
 default:
      cout << "Pilihan tidak valid" << endl;
  break;
 }
    cout << endl;
  } while (choice != 8);
 return 0;
 }
```
### Case 1
<img width="240" alt="9" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/5aba1c8d-1079-4701-bd2f-ce02d54ddf16">

### Case 2
<img width="250" alt="10" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/251a8715-d1ff-4739-8c75-eb519ed4dc86">

### Case 3
<img width="236" alt="11" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/622ad6b5-87c4-4dfb-8387-ce5dc95054af">

### Case 4
<img width="228" alt="12" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/b6c228fc-cb6a-4ed6-95b8-7e617a34a585">

## Kesimpulan
<div style = "text-align: justify">
  Single dan double linked list adalah dua jenis struktur data yang berbeda dalam hal cara mereka menghubungkan elemen-elemennya. Single linked list, seperti namanya, hanya memiliki referensi ke elemen berikutnya dalam list, sedangkan double linked list memiliki referensi ke elemen sebelumnya dan berikutnya. Ini membuat double linked list memiliki keuntungan dalam beberapa operasi, seperti penghapusan dan penambahan elemen di awal atau akhir list, karena mereka dapat dengan mudah mengakses elemen sebelumnya tanpa perlu melalui elemen-elemen lainnya.

  Namun, perlu diingat bahwa meskipun double linked list memiliki keuntungan dalam hal akses ke elemen sebelumnya, ini tidak secara signifikan mempengaruhi kompleksitas waktu operasi dalam notasi Big O. Dalam kasus seperti penghapusan, baik single maupun double linked list memiliki kompleksitas waktu O(n), karena dalam kedua kasus, operasi tersebut memerlukan penelusuran melalui list untuk menemukan elemen yang akan dihapus.

  Selain itu, double linked list memiliki overhead tambahan karena setiap elemen memiliki dua referensi (satu ke elemen sebelumnya dan satu ke elemen berikutnya), yang berarti mereka menggunakan lebih banyak memori dibandingkan single linked list. Ini bisa menjadi pertimbangan dalam konteks di mana memori sangat penting.

  Secara keseluruhan, pilihan antara single dan double linked list tergantung pada kebutuhan spesifik aplikasi. Double linked list mungkin lebih cocok untuk aplikasi yang memerlukan operasi yang sering mengakses elemen sebelumnya, sementara single linked list mungkin lebih cocok untuk aplikasi yang hanya perlu akses ke elemen berikutnya, seperti dalam implementasi stack atau queue.</div>





