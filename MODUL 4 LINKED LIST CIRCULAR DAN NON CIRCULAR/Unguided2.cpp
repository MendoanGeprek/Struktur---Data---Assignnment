#include <iostream>
#include <string>

using namespace std;

// Deklarasi struct Node
struct Node
{
    string nama;
    int nim;
    Node *next;
};

// Deklarasi variabel global
Node *head;
Node *tail;

// Fungsi untuk menginisialisasi linked list
void init()
{
    head = NULL;
    tail = NULL;
}

// Fungsi untuk mengecek apakah linked list kosong
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

// Fungsi untuk memasukkan data di depan linked list
void insertDepan(string nama, int nim)
{
    // Membuat node baru
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;

    // Menghubungkan node baru ke node selanjutnya (sebelumnya head)
    baru->next = head;

    // Memperbarui head untuk menunjuk ke node baru
    head = baru;

    // Jika tail masih kosong, maka tail juga menunjuk ke node baru
    if (tail == NULL)
    {
        tail = baru;
    }
}

// Fungsi untuk memasukkan data di belakang linked list
void insertBelakang(string nama, int nim)
{
    // Membuat node baru
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    // Jika linked list kosong, maka node baru menjadi node pertama dan terakhir
    if (isEmpty())
    {
        head = tail = baru;
    }
    // Jika linked list tidak kosong, maka node baru ditambahkan di belakang tail
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// Fungsi untuk menghitung jumlah node dalam linked list
int hitungList()
{
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Fungsi untuk memasukkan data di tengah linked list
void insertTengah(string nama, int nim, int posisi)
{
    // Mengecek apakah posisi valid
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan!" << endl;
        return;
    }
    // Jika posisi sama dengan 1, maka masukkan data di depan
    else if (posisi == 1)
    {
        insertDepan(nama, nim);
        return;
    }

    // Membuat node baru
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;

    // Mencari node di posisi sebelum posisi yang diinginkan
    Node *bantu = head;
    int nomor = 1;
    while (nomor < posisi - 1)
    {
        bantu = bantu->next;
        nomor++;
    }

    // Menghubungkan node baru di antara node bantu dan node selanjutnya
    baru->next = bantu->next;
    bantu->next = baru;
}

// Fungsi untuk menghapus data di depan linked list
void hapusDepan()
{
    // Jika linked list kosong, maka tampilkan pesan
    if (isEmpty())
    {
        cout << "Linked list kosong!" << endl;
        return;
    }

    // Menyimpan node yang akan dihapus
    Node *hapus = head;

    // Memperbarui head untuk menunjuk ke node selanjutnya
    head = head->next;

    // Jika head menjadi NULL, maka tail juga menjadi NULL
    if (head == NULL)
    {
        tail = NULL;
    }

    // Menghapus node yang disimpan
    delete hapus;
}

// Fungsi untuk menghapus data di belakang linked list
void hapusBelakang()
{
    // Jika linked list kosong, maka tampilkan pesan
    if (isEmpty())
    {
        cout << "Linked list kosong!" << endl;
        return;
    }

    // Menyimpan node yang akan dihapus
    Node *hapus = tail;

    // Mencari node sebelum node terakhir
    Node *bantu = head;
    while (bantu->next != tail)
    {
        bantu = bantu->next;
    }

    // Memperbarui tail
    // Memperbarui tail untuk menunjuk ke node sebelum node terakhir
    tail = bantu;
    tail->next = NULL;

    // Menghapus node yang disimpan
    delete hapus;
}

// Fungsi untuk menghapus data di tengah linked list
void hapusTengah(int posisi)
{
    // Mengecek apakah posisi valid
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan!" << endl;
        return;
    }
    // Jika posisi sama dengan 1, maka hapus data di depan
    else if (posisi == 1)
    {
        hapusDepan();
        return;
    }

    // Mencari node sebelum node yang akan dihapus
    Node *bantu = head;
    Node *hapus;
    int nomor = 1;
    while (nomor < posisi - 1)
    {
        bantu = bantu->next;
        nomor++;
    }

    // Menyimpan node yang akan dihapus
    hapus = bantu->next;

    // Menghubungkan node bantu ke node selanjutnya dari node yang dihapus
    bantu->next = hapus->next;

    // Jika node yang dihapus adalah tail, maka perbarui tail
    if (hapus == tail)
    {
        tail = bantu;
    }

    // Menghapus node yang disimpan
    delete hapus;
}

// Fungsi untuk mengubah data di depan linked list
void ubahDepan(string nama, int nim)
{
    // Jika linked list kosong, maka tampilkan pesan
    if (isEmpty())
    {
        cout << "Linked list kosong!" << endl;
        return;
    }

    // Mengubah data node head
    head->nama = nama;
    head->nim = nim;

    cout << "Data berhasil diubah!" << endl;
}

// Fungsi untuk mengubah data di belakang linked list
void ubahBelakang(string nama, int nim)
{
    // Jika linked list kosong, maka tampilkan pesan
    if (isEmpty())
    {
        cout << "Linked list kosong!" << endl;
        return;
    }

    // Mengubah data node tail
    tail->nama = nama;
    tail->nim = nim;

    cout << "Data berhasil diubah!" << endl;
}

// Fungsi untuk mengubah data di tengah linked list
void ubahTengah(string nama, int nim, int posisi)
{
    // Mengecek apakah posisi valid
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan!" << endl;
        return;
    }
    // Jika posisi sama dengan 1, maka ubah data di depan
    else if (posisi == 1)
    {
        ubahDepan(nama, nim);
        return;
    }

    // Mencari node di posisi yang diinginkan
    Node *bantu = head;
    int nomor = 1;
    while (nomor < posisi)
    {
        bantu = bantu->next;
        nomor++;
    }

    // Mengubah data node yang ditemukan
    bantu->nama = nama;
    bantu->nim = nim;

    cout << "Data berhasil diubah!" << endl;
}

// Fungsi untuk menghapus seluruh isi linked list
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
    cout << "Linked list berhasil dihapus!" << endl;
}

// Fungsi untuk menampilkan isi linked list
void tampil()
{
    Node *bantu = head;
    if (isEmpty())
    {
        cout << "Linked list kosong!" << endl;
    }
    else
    {
        cout << "Data Mahasiswa" << endl;
        cout << "Nama"
             << "            "
             << "Nim" << endl
             << endl;
        while (bantu != NULL)
        {
            cout << bantu->nama << "            " << bantu->nim << endl;
            bantu = bantu->next;
        }
        cout << endl;
    }
}

int main()
{
    init();
    string nama;
    int nim;
    int posisi;
    while (true)
    {

        // Menu program
        cout << "Program Single Linked List Non-Circular" << endl
             << "\n";
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus list" << endl;
        cout << "11. Tampilkan" << endl;
        cout << "0. Break/End" << endl;
        int pilihan;
        cout << "Pilih Operasi: ";
        cin >> pilihan;
        cout << "\n";

        switch (pilihan)
        {
        case 1:
            cout << "-Tambah Depan-" << endl
                 << endl;
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan NIM: ";
            cin >> nim;
            cout << endl
                 << endl;
            insertDepan(nama, nim);
            cout << "Data telah dimasukan " << endl;
            break;
        case 2:
            cout << "-Tambah Belakang-" << endl
                 << endl;
            cout << "Masukan nama: ";
            cin >> nama;
            cout << "Masukan NIM: ";
            cin >> nim;
            insertBelakang(nama, nim);
            cout << "Data Telah dimasukan: " << endl;
            break;
        case 3:
            cout << "-Tambah Tengah-" << endl
                 << endl;
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan NIM: ";
            cin >> nim;
            cout << "Masukan Posisi: ";
            cin >> posisi;
            insertTengah(nama, nim, posisi);
            cout << "Data Telah dimasukkan" << endl;
            break;
        case 4:
            cout << "-Ubah Depan-" << endl
                << endl;
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan Nim: ";
            cin >> nim;
            ubahDepan(nama, nim);
            break;
        case 5:
            cout << "-Ubah Belakang-" << endl
                << "\n";
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan NIM: ";
            cin >> nim;
            ubahBelakang(nama, nim);
            cout << "n"
                << "\n";
            break;
        case 6:
            cout << "-Ubah tengah-" << endl
                << "\n";
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan NIM: ";
            cin >> nim;
            cout << "Masukan Posisi: ";
            cin >> posisi;
            ubahTengah(nama, nim, posisi);
            cout << "\n"
                << "\n";
            break;
        case 7:
            hapusDepan();
            break;
        case 8:
            hapusBelakang();
            break;
        case 9:
            cout << "\n";
            cout << "Masukan Posisi: ";
            cin >> posisi;
            hapusTengah(posisi);
            break;
        case 10:
            clearList();
            break;
        case 11:
            tampil();
            break;
        case 0:
            exit(0);
        }
    }
    return 0;
}
