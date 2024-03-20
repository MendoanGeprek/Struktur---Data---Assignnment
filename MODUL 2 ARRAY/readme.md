# <h1 align="center">Laporan Praktikum Modul ARRAY</h1>
<p align="center">Muhammad Djidzan N. N.</p>
<p align="center">2311102189/IF-11-E</p>

## Dasar Teori
A.Pengertian Array

Array adalah suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Elemen-elemen array tersusun secara sekuensial dalam memori komputer. Semua elemem array bertipe sama. Array cocok untuk organisasi kumpulan data homogen yang ukuran atau jumlah elemen maksimumnya telah diketahui dari awal. Homogen adalah bahwa setiap elemen dari sebuah array tertentu haruslah mempunyai tipe data yang sama. Array dibagi menjadi :

1. Array Satu Dimensi

Array Satu Dimensi
Array satu dimensi tidak lain adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda. Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutan Deklarasi : Type_Data Nama_Variabel [index] Misalnya : int A[5];

2.  Array Dua Dimensi

Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi terdapat dua jumlah elemen array yang terdapat di dalam kurung siku dan keduanya boleh tidak sama. Deklarasi : Type_Data Nama_Variabel [Index1] [index2]; Misal : int A[3][2];

3.  Array Tiga Dimensi

Array tiga dimensi digunakan untuk mengelola data dalam bentuk 3 dimensi atau tiga sisi. Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3]; Misal : int A [3][4][2];

4.  Array Banyak Dimensi

Sebenarnya array banyak dimensi ini tidak terlalu sering dipakai seperti halnya array satu dimensi, dua dimensi, dan tiga dimensi. Array banyak dimensi ini pada dasarnya sama dengan array sebelimnya kecuali pada jumlah dimensinya. Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3] [ndex4].....; Misal : int A [3][4][2][5];

## Guided
### 1. Program input array tiga dimensi
```C++
    
    #include <iostream>
    using namespace std;
    // PROGRAM INPUT ARRAY 3 DIMENSI
    int main()
    {
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout <<endl;
    }
```
### Deskripsi Program

Program tersebut berfungsi untuk menginputkan data ke dalam array tiga dimensi dan kemudian menampilkannya. Program ini terdiri dari tiga bagian utama:

1.Input Data:

Program meminta kita untuk memasukkan nilai-nilai ke dalam array tiga dimensi menggunakan tiga nested loop.

2.Output Data:

Setelah semua data dimasukkan, program akan menampilkan nilai-nilai dari array tiga dimensi yang telah dimasukkan oleh kita.

3.Tampilan Array:

Program juga menampilkan array dalam bentuk yang lebih sederhana, dengan menampilkan setiap baris dari array dalam satu baris dengan menggunakan perulangan.
### 2. Program mencari nilai maksimal pada array

```C++
#include <iostream>
using namespace std;

int main()
{
    int maks,a,i = 1,lokasi;
    cout << "masukan panjang array : ";
    cin >> a;
    int array[a];
    cout << "masukan" << a << "angka\n";
    for (i= 0; i < a; i++)
    {
        cout << "array ke "<< (i) << ": ";
        cin >> array[i];

    }
    maks = array [0];
    for (i = 0; i < a;i++);
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi= i;
        }
    }
    cout<< "nilai maksimum adalah"<< maks << "berada di array ke"<<lokasi<<endl;
}
```

#### Deskrpisi Program

Program tersebut bertujuan untuk mencari nikai maksimum yang sudah diinputkan.

### Unguided

### 1.Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
```C++
#include <iostream>

using namespace std;

int main() {
    
    
    int arr[] = {1, 2, 3, 4, 5 ,6 ,7 ,8 ,9 ,10};

        cout << "Data array: ";
        for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Nomor genap: ";
    for (int i = 0; i < 10; ++i) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    cout << "Nomor ganjil: ";
    for (int i = 0; i < 10; ++i) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
```
### Ouput
<img width="687" alt="1" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/b78bc6a2-b56f-455c-b4ae-a004f56f8bbd">

### Deskripsi Progam

Progam tersebut bertujuan untuk memisahkan angka ganjil dan angka genap dari array 1 sampai 10

### 2.Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!
```C++
#include <iostream> 
using namespace std; 
 
int main() { 
  int x, y, z; 
 
  cout << "Masukkan ukuran array (x y z): "; 
  cin >> x >> y >> z; 
 
  int arr[x][y][z]; 
 
  for (int i = 0; i < x; i++) { 
    for (int j = 0; j < y; j++) { 
      for (int k = 0; k < z; k++) { 
        cout << "Input array [" << i << "][" << j << "][" << k << "] = "; 
        cin >> arr[i][j][k]; 
      } 
    } 
    cout << endl; 
  } 
 
  cout << endl; 
  for (int i = 0; i < x; i++) { 
    for (int j = 0; j < y; j++) { 
      for (int k = 0; k < z; k++) { 
        cout << "Data array [" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl; 
      } 
    } 
  } 
 
  cout << endl; 
  for (int i = 0; i < x; i++) { 
    for (int j = 0; j < y; j++) { 
        for (int k = 0; k < z; k++) { 
        cout << arr[i][j][k] << " "; 
        }    
        cout << endl; 
    } 
    cout << endl;  
    } 
return 0;
 
}
```

### Ouput
<img width="692" alt="2" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/288d84ed-8ed4-4ae9-9404-069b3eafc088">

### Deskrpisi Program

Program tersebut bertujuan untuk memasukkan jumlah elemen matriks dan ukuran matriks dalam format "baris kolom", kemudian meminta kita untuk memasukkan nilai-nilai elemen dari matriks tiga dimensi. Setelah itu, program akan menampilkan data matriks beserta tampilan matriks satu per satu dengan nomor urutan matriks.

### 3.Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!
```C++
#include <iostream>
using namespace std;

int input;
int bil[10];
int minim, maksim;
double rata;

int main(){

    while(true){
    cout << "\t" "\t" << "MENU" << endl;
    cout << "\t" << "1. INPUT ARRAY" << endl;
    cout << "\t" << "2. TAMPIL ARRAY" << endl;
    cout << "\t" << "3. CARI NILAI MINIMMUM" << endl;
    cout << "\t" << "4. CARI NILAI MAKSIMUM" << endl;
    cout << "\t" << "5. HITUNG RATA - RATA" << endl;

    cout << "MASUKAN PILIHAN : ";
    cin >> input;

    cout << endl;

    switch (input)
    {
    case 1 : 
        {
            for(int i = 0; i < 10; i++){
                cout << "MASUKAN BILANGAN KE - " << i + 1 << " : ";
                cin >> bil[i];
            }
            cout << endl;
        break;
        }
    case 2 : 
        {
            cout << "ARRAY YANG DI INPUT : ";
            for (int i = 0; i < 10; i++){
                cout << bil[i] << " ";
            }
        cout << endl;
        }
    cout << endl;
    break;
    case 3 :
        {
            minim = bil[0];
            for(int i = 0; i < 10; i++){
                if(bil[i] < minim){
                    minim = bil[i];
                }
            }
            cout << "NILAI MINIMUM DARI ARRAY TERSEBUT : " << minim << endl;
            cout << endl;
        }
    break;
    case 4 :
        {
            maksim = bil[0];
            for (int i = 0; i < 10; i++){
                if(bil[i] > maksim){
                    maksim = bil[i];
                }
            }
            cout << "NILAI MAKSIMUM DARI ARRAY TERSEBUT : " << maksim << endl;
            cout << endl;
        }
    break;
    case 5 :
        {
            for(int i = 0; i < 10; i++){
                rata += bil[i] / 12;
            }
            cout << "RATA - RATA DARI ARRAY TERSEBUT : " << rata;
        }
        cout << endl;
        cout << endl;
        break;
    }
}
    return 0;
}
```

### Ouput
<img width="694" alt="3" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/517456af-7fe3-4fb9-b5d4-83337f1dd3bd">

### Deskripsi Progam
Program tersebu bertujuan untuk memasukkan jumlah elemen dalam sebuah array, kemudian mengisi array dengan nilai-nilai yang dimasukkan oleh pengguna. Setelah itu, kita dapat memilih menu untuk mencari nilai maksimum, minimum, atau rata-rata dari elemen-elemen array yang dimasukkan. Program menggunakan switch case untuk mengimplementasikan pilihan kita, di mana setiap kasus melakukan iterasi melalui array untuk mencari nilai maksimum, minimum, atau menghitung rata-rata, dan kemudian menampilkan hasilnya sesuai dengan pilihan yang dibuat oleh kita. Jika kita memasukkan pilihan yang tidak valid, program akan memberikan pesan kesalahan.

## Kesimpulan

Array merupakan struktur data dasar: Array adalah struktur data yang paling dasar dalam pemrograman. Dalam array, kita dapat menyimpan kumpulan data dengan tipe yang sama dan mengaksesnya menggunakan indeks.

Jenis-jenis array:

Array Satu Dimensi: Merupakan kumpulan data dengan tipe yang sama yang disusun dalam satu baris. Setiap elemen memiliki sebuah indeks yang dimulai dari 0. Array Dua Dimensi: Merupakan kumpulan array satu dimensi yang disusun dalam baris dan kolom. Setiap elemen memiliki dua indeks: indeks baris dan indeks kolom. Array Multidimensi: Merupakan array dengan dimensi lebih dari dua. Ini termasuk array tiga dimensi, array empat dimensi, dan seterusnya. Array ini memiliki lebih dari dua indeks dan digunakan untuk representasi data yang lebih kompleks. Dengan memahami konsep dan implementasi dari berbagai jenis array, kita dapat memproyeksikan struktur data yang lebih kompleks dan memahami cara mengakses dan memanipulasi data dalam program. Array adalah fondasi penting untuk mempelajari struktur data lainnya dalam pemrograman.
