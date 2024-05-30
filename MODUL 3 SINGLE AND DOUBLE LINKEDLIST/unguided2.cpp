#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk linked list
struct Node
{
  string nama_produk;
  int harga_189;
  Node *prev;
  Node *next;
};

// Kelas untuk Doubly Linked List
class DoublyLinkedList
{
private:
  Node *head; // Pointer ke node pertama
  Node *tail; // Pointer ke node akhir
public:
  // Konstruktor
  DoublyLinkedList()
  {
    head = nullptr;
    tail = nullptr;
  }

  void NewFunction(Node *newNode)
  {
    tail->next = newNode;
  }

  // Fungsi untuk menyisipkan node di akhir linked list
  void insertAtEnd(string nama_produk, int harga_189)
  {
    Node *newNode = new Node();
    newNode->nama_produk = nama_produk;
    newNode->harga_189 = harga_189;
    newNode->next = nullptr;
    if (head == nullptr)
    {
      newNode->prev = nullptr;
      head = newNode;
      return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }

  // Fungsi untuk menghapus node dengan nama produk tertentu
  void deleteNode(string nama_produk)
  {
    if (head == nullptr)
    {
      cout << "Linked list kosong." << endl;
      return;
    }
    if (head->nama_produk == nama_produk)
    {
      Node *temp = head;
      head = head->next;
      if (head != nullptr)
      {
        head->prev = nullptr;
      }
      delete temp;
      return;
    }
    Node *temp = head;
    while (temp != nullptr && temp->nama_produk != nama_produk)
    {
      temp = temp->next;
    }
    if (temp == nullptr)
    {
      cout << "Node dengan nama produk " << nama_produk << " tidak ditemukan." << endl;
      return;
    }
    if (temp->next != nullptr)
    {
      temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
    delete temp;
  }

  // Fungsi untuk mengubah harga_189 dari node dengan nama produk tertentu
  void updateData(string nama_produk, int hargaBaru, string namaBaru)
  {
    Node *current = head;
    while (current != NULL)
    {
      if (current->nama_produk == nama_produk)
      {
        current->harga_189 = hargaBaru;
        current->nama_produk = namaBaru;
        cout << "Data produk " << nama_produk << " berhasil diupdate!" << endl;
        return;
      }
      current = current->next;
    }
    cout << "Data tidak ditemukan" << endl;
  }

  // Fungsi untuk menambahkan data pada urutan Node tertentu
  void tambahDataUrutanTertentu(string nama_produk, int harga_189, int urutan)
  {
    Node *newNode = new Node();
    newNode->nama_produk = nama_produk;
    newNode->harga_189 = harga_189;

    Node *current = head;
    int pos = 1;
    while (current != NULL && pos < urutan)
    {
      current = current->next;
      pos++;
    }

    if (current == NULL)
    {
      cout << "Urutan tidak valid" << endl;
      return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL)
      current->next->prev = newNode;
    current->next = newNode;
    cout << "Berhasil menambahkan data!" << endl;
  }

  // Fungsi untuk menghapus node berdasarkan urutan yang ditentukan
  void hapusDataUrutanTertentu(int urutan)
  {
    if (head == nullptr)
    {
      cout << "Linked List Kosong." << endl;
      return;
    }

    Node *current = head;
    int pos = 0;
    while (current != nullptr && pos < urutan)
    {
      current = current->next;
      pos++;
    }

    if (current == nullptr || current == tail)
    {
      cout << "Urutan tidak valid" << endl;
      return;
    }

    if (current == head)
    {
      head = current->next;
      if (head != nullptr)
        head->prev = nullptr;
    }
    else if (current == tail)
    {
      tail = current->prev;
      tail->next = nullptr;
    }
    else
    {
      current->prev->next = current->next;
      current->next->prev = current->prev;
    }
    delete current;
    cout << "Data pada urutan " << urutan << " berhasil dihapus!" << endl;
  }

  // Fungsi untuk menghapus semua node dalam linked list
  void deleteAll()
  {
    Node *temp = head;
    while (temp != nullptr)
    {
      Node *nextNode = temp->next;
      delete temp;
      temp = nextNode;
    }
    head = nullptr;
  }

  // Fungsi untuk menampilkan seluruh data dalam linked list
  void display()
  {
    Node *temp = head;
    cout << "\nNama Produk\tHarga" << endl;
    while (temp != nullptr)
    {
      cout << temp->nama_produk << "   \t" << temp->harga_189 << endl;
      temp = temp->next;
    }
  }
};

int main()
{
  DoublyLinkedList produkList;
  string nama_produk, namaBaru;
  int harga_189, hargaBaru, urutan;

  // Menambahkan data produk sesuai permintaan
  produkList.insertAtEnd("Originote", 60000);
  produkList.insertAtEnd("Somethinc", 150000);
  produkList.insertAtEnd("Skintific", 100000);
  produkList.insertAtEnd("Wardah", 50000);
  produkList.insertAtEnd("Hanasui", 30000);

  // Menampilkan menu
  cout << "Toko Skincare Purwokerto" << endl;
  cout << "1. Tambah Data" << endl;
  cout << "2. Hapus Data" << endl;
  cout << "3. Update Data" << endl;
  cout << "4. Tambah Data Urutan Tertentu" << endl;
  cout << "5. Hapus Data Urutan Tertentu" << endl;
  cout << "6. Hapus Seluruh Data" << endl;
  cout << "7. Tampilkan Data" << endl;
  cout << "8. Exit" << endl;

  int choice;
  while (true)
  {
    cout << "\nMasukkan pilihan Anda: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      cout << "Masukkan nama produk: ";
      cin >> nama_produk;
      cout << "Masukkan harga_189: ";
      cin >> harga_189;
      produkList.insertAtEnd(nama_produk, harga_189);
      cout << "Berhasil menambahkan data!" << endl;
      break;
    }
    case 2:
    {
      cout << "Masukkan nama produk yang akan dihapus: ";
      cin >> nama_produk;
      produkList.deleteNode(nama_produk);
      cout << "Data dengan nama " << nama_produk << " berhasil dihapus!" << endl;
      break;
    }
    case 3:
    {
      cout << "Masukkan nama produk yang akan diupdate: ";
      cin >> nama_produk;
      cout << "Masukkan harga_189 baru: ";
      cin >> hargaBaru;
      cout << "Masukkan nama produk baru: ";
      cin >> namaBaru;
      produkList.updateData(nama_produk, hargaBaru, namaBaru);
      break;
    }
    case 4:
    {
      cout << "Masukkan nama produk: ";
      cin >> nama_produk;
      cout << "Masukkan harga_189: ";
      cin >> harga_189;
      cout << "Masukkan urutan(dihitung dari 0): ";
      cin >> urutan;
      produkList.tambahDataUrutanTertentu(nama_produk, harga_189, urutan);
      break;
    }
    case 5:
    {
      int urutan;
      cout << "Masukkan urutan produk yang akan dihapus(dihitung dari 0): ";
      cin >> urutan;
      produkList.hapusDataUrutanTertentu(urutan);
      break;
    }
    case 6:
    {
      produkList.deleteAll();
      cout << "Semua data telah dihapus!" << endl;
      break;
    }
    case 7:
    {
      produkList.display();
      break;
    }
    case 8:
    {
      cout << "Terima kasih telah menggunakan program." << endl;
      return 0;
    }
    default:
    {
      cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
      break;
    }
    }
  }

  return 0;
}