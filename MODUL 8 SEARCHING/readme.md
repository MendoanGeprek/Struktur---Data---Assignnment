# <h1 align="center"> Laporan Praktikum Modul 8_Searching</h1>
<p align="center"> Muhammad Djidzan. N. N <p>
<p align="center"> 2311102189 </p>

## Dasar Teori Searching

Searching adalah proses mendapatkan data dengan cara menelusuri sekumpulan data[1]. Berdasarkan pada jenis operasi pencarian, algoritme searching umumnya diklasifikasikan ke dalam dua kategori:

### 1. Searching Sequential Search ###

Teknik pencarian dengan metode sequential adalah sebuah teknik pencarian yang membandingkan setiap elemen data dengan data yang dicari[1]. Pencarian dilakukan dengan membandingkan sebuah elemen data yang dicari dengan elemen pertama sampai dengan terakhir jika data yang dicari ditemukan maka pencarian akan dihentikan[1].

### 2. Searching Binary Search ###

Proses pencarian dengan binary search hanya dapat dilakukan pada kumpulan data yang sudah diurutkan terlebih dahulu[1]. Pencarian dilakukan pada array yang telah diurutkan dengan berulang kali membagi interval pencarian menjadi dua[1]. Pencarian dimulai dengan interval yang mencakup seluruh array[1]. Jika nilai yang dicari pada pencarian kurang dari item di tengah interval, per sempit interval ke bagian bawah[1]. Jika nilai yang dicari pada pencarian lebih besar dari item di tengah interval, per sempit interval ke bagian atas[1]. Dilakukan proses pemeriksaan secara berulang hingga nilainya ditemukan atau intervalnya kosong[1].

## Guided 1
```c++
#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana\n " << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu)
    {
        cout << "\n angka " << cari << " ditemukan pada indeks ke - " << i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```
## Screenshot Progam

![image](https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/954b935c-496d-4ed0-8564-951f7ec01fa1)

## Deskripsi Progam
Program dimulai dengan mendefinisikan array `data` yang berisi sepuluh elemen integer. Selanjutnya, program mencari nilai `cari` dalam array menggunakan algoritma Sequential Search, di mana setiap elemen dari array diiterasi secara berurutan untuk memeriksa apakah nilainya sama dengan nilai yang dicari. Jika nilai tersebut ditemukan, program akan menghentikan pencarian dan menampilkan indeks di mana nilai ditemukan. Jika tidak ditemukan, program akan menampilkan pesan bahwa nilai tidak dapat ditemukan dalam array. Setelah pencarian selesai, hasilnya ditampilkan kepada pengguna.
## Guided 2
```c++
#include <iostream>
#include <iomanip>
using namespace std;
// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
void selection_sort(int arr[], int n)
{
    int temp, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void binary_search(int arr[], int n, int target)
{
    int awal = 0, akhir = n - 1, tengah, b_flag = 0;
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target)
        {
            b_flag = 1;
            break;
        }
        else if (arr[tengah] < target)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    if (b_flag == 1)
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\nData tidak ditemukan\n";
}
int main()
{
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData awal: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    // Urutkan data dengan selection sort
    selection_sort(arrayData, 7);
    cout << "\nData diurutkan: ";
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    // Lakukan binary search
    binary_search(arrayData, 7, cari);
    return 0;
}
```
## Screenshot Progam

![image](https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/4b55cfb1-bb90-4159-ae86-c603f7fc44d2)

## Deskripsi Program

Program mendeklarasikan array `arrayData` yang berisi tujuh elemen integer yang belum diurutkan. Kemudian, terdapat fungsi `selection_sort` yang mengurutkan array menggunakan algoritma Selection Sort. Setelah itu, program meminta pengguna untuk memasukkan nilai yang ingin dicari. Setelah nilai dimasukkan, array diurutkan menggunakan fungsi `selection_sort` dan hasilnya ditampilkan. Selanjutnya, program melakukan pencarian biner menggunakan fungsi `binary_search`, di mana array yang telah diurutkan digunakan untuk mencari nilai yang dimasukkan pengguna. Jika nilai tersebut ditemukan, program akan menampilkan indeks di mana nilai tersebut ditemukan. Jika tidak ditemukan, program akan menampilkan pesan bahwa nilai tidak ditemukan dalam array. Hasil pencarian ditampilkan kepada pengguna.

## Unguided 1

1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

## Source Code 1
```c++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Fungsi untuk melakukan Selection Sort pada string
void selectionSort(string &str) {
    int n = str.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (str[j] < str[minIndex]) {
                minIndex = j;
            }
        }
        swap(str[i], str[minIndex]);
    }
}

// Fungsi untuk melakukan Binary Search pada string yang sudah diurutkan
void binarySearch(const string &sortedStr, char target) {
    int left = 0;
    int right = sortedStr.size() - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedStr[mid] == target) {
            found = true;
            break;
        } else if (sortedStr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        cout << "Huruf '" << target << "' ditemukan pada index: ";
        for (int i = 0; i < sortedStr.size(); ++i) {
            if (sortedStr[i] == target) {
                cout << i << " "; // Index dimulai dari 1
            }
        }
        cout << endl;
    } else {
        cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;
    }
}

int main() {
    string inputStr;
    char target;

    // Ambil input kalimat
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, inputStr);

    // Ambil input huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;

    // Sortir kalimat
    selectionSort(inputStr);

    // Tampilkan kata yang sudah diurutkan
    cout << "Kata yang sudah diurutkan: ";
    for (char c : inputStr) {
        cout << c << " ";
    }
    cout << endl;

    // Lakukan binary search dan tampilkan hasilnya
    binarySearch(inputStr, target);

    return 0;
}
```

## Screenshot Progam

![image](https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/3a713b25-0019-4ba5-bf5c-6dc642aab81c)


## Deskripsi Progam

Program meminta pengguna untuk memasukkan sebuah kalimat. Kemudian, program meminta pengguna untuk memasukkan huruf yang ingin dicari dalam kalimat tersebut. Setelah itu, program mengurutkan kalimat menggunakan fungsi `selectionSort`, yang merupakan implementasi dari algoritma Selection Sort untuk string. Setelah kalimat diurutkan, program mencari huruf yang dimasukkan pengguna dalam kalimat menggunakan algoritma Binary Search dengan fungsi `binarySearch`. Jika huruf tersebut ditemukan, program akan menampilkan indeks atau posisi huruf tersebut dalam kalimat. Jika tidak ditemukan, program akan menampilkan pesan bahwa huruf tidak ditemukan dalam kalimat. Hasil pencarian ditampilkan kepada pengguna.

## Unguided 2

2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

## Source Code 2
```c++
#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk memeriksa apakah karakter adalah vokal
bool isVokal(char c) {
    return (c == 'a' || c == 'A' ||  c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
}

int main() {
    string sentence;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, sentence);

    int vokalCount = 0;

    // Melakukan pencarian berurutan untuk menghitung huruf vokal
    for (char c : sentence) {
        if (isVokal(c)) {
            vokalCount++;
        }
    }

    cout << "Jumlah huruf vokal dalam kalimat: " << vokalCount << endl;

    return 0;
}
```

## Screenshot Progam

![image](https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/af0dff04-b94a-4fc2-b9e3-cca348a63c2d)

## Deskripsi Progam

Program meminta pengguna untuk memasukkan sebuah kalimat. Kemudian, program menggunakan sebuah fungsi `isVokal` untuk memeriksa apakah sebuah karakter merupakan huruf vokal atau tidak. Setelah itu, program melakukan pencarian berurutan pada setiap karakter dalam kalimat untuk menghitung jumlah huruf vokal. Setiap kali program menemukan sebuah huruf vokal, nilai variabel `vokalCount` akan ditambah satu. Setelah pencarian selesai, program akan menampilkan jumlah huruf vokal yang ditemukan dalam kalimat kepada pengguna.

## Unguided 3

3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

## Source Code 3
```c++
#include <iostream>
using namespace std;

int main()
{
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]); // Menghitung ukuran array
    int target = 4;
    int count = 0;

    // Sequential Search untuk menghitung jumlah angka 4
    for (int i = 0; i < size; i++)
    {
        if (data[i] == target)
        {
            count++;
        }
    }

    cout << "Data = { 9, 4, 1, 4, 7, 10, 5, 4, 12, 4 }\n" << endl;
    cout << "Jumlah angka " << target << " dalam array : " << count << endl;

    return 0;
}
```
## Screenshot Program

![image](https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/286a46a3-cabc-4cb0-90e1-60478a1820a7)

## Deskripsi Program

Array yang digunakan dalam program ini adalah array `data` yang telah diberikan nilai-nilai awal. Program ini mencari jumlah kemunculan angka tertentu, dalam hal ini angka 4, dalam array tersebut. 

Pertama, program menghitung ukuran array dengan membagi ukuran total array dengan ukuran satu elemen array. Kemudian, program melakukan iterasi melalui setiap elemen array dengan menggunakan loop `for`. Setiap elemen dicek apakah sama dengan angka yang dicari (`target`). Jika ditemukan, variabel `count` akan bertambah satu. Setelah pencarian selesai, program akan menampilkan array yang digunakan beserta jumlah kemunculan angka yang dicari kepada pengguna.

## Kesimpulan

Searching adalah proses menemukan nilai tertentu dalam kumpulan data. Metode pencarian umum meliputi Sequential Search dan Binary Search. Sequential Search, sederhana namun memiliki kompleksitas waktu O(n), sedangkan Binary Search, lebih efisien dengan kompleksitas waktu O(log n) untuk data yang terurut. Pemilihan metode tergantung pada sifat data dan kebutuhan aplikasi.

## Refrensi 

[1] Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. (2020). (n.p.): Penerbit Andi.
