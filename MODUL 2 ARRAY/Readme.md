# <h1 align="center">Laporan Praktikum Modul 2 Array </h1>
<p align="center">Muhammad Djidzan N N</p>
<p align="center">231102189</p>
<p align="center">IF 11 E</p>

## Dasar Teori

Array dalam bahasa C++ adalah sebuah struktur data yang digunakan untuk menyimpan sekumpulan data dengan tipe data yang sama. Setiap elemen array dapat diakses menggunakan indeks yang unik. Array sangat berguna dalam banyak kasus, seperti menyimpan daftar nilai, daftar nama, atau data lainnya.

Berikut adalah penjelasan singkat tentang array dalam C++:

1. Deklarasi Array
Deklarasi array adalah proses mendefinisikan sebuah variabel sebagai array dan menentukan ukuran atau panjang array tersebut.

2. Inisialisasi Array
Inisialisasi array dalam C++ adalah proses memberikan nilai awal pada elemen-elemen array saat deklarasi atau setelah deklarasi.

3. Mengakses Elemen Array
Mengakses elemen array berarti mengambil atau memodifikasi nilai dari elemen tertentu dalam array tersebut. Untuk mengakses elemen array, Anda perlu menggunakan indeks yang sesuai dengan posisi elemen dalam array. Indeks array dalam C++ dimulai dari 0.

4. Ukuran Array
Ukuran array mengacu pada jumlah maksimum elemen yang dapat disimpan dalam array tersebut. Ukuran array harus ditentukan saat deklarasi dan tidak dapat diubah selama runtime (waktu program berjalan).

## GUIDED

## Guided 1

### Source Progam
```c++
#include <iostream>
using namespace std;

int main(){

int arr[2][3][3];
for(int x = 0;x<2;x++)
{
    for (int y = 0; y < 3;y++)
    {
        for(int z = 0; z < 3;z++)
        {
        cout<< "input array["<< x << "]["<< y << "]["<< z <<"] = ";
    cin>> arr [x][y][z];
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
        cout << "Data Array[" << x << "][" << y << "][" << z
 << "] = " << arr[x][y][z] << endl;
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
    cout << endl;
 }
 }
```

### Ouput Progam
<img width="682" alt="jegerr" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/82f78e36-08cd-474a-8331-f3ba9c15f388">

### Deskripsi Progam
Program ini menggunakan array tiga dimensi untuk menerima input dari pengguna, menampilkan data yang dimasukkan, dan kemudian mencetak array dalam bentuk matriks.

## Guided 2

### Source Progam
```c++
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

### Ouput Progam
<img width="694" alt="wahaaa" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/7f5771c0-8a33-4443-bbe4-2799260a2da5">

### Deskripsi Progam
Program ini adalah sebuah aplikasi berbasis console yang ditulis dalam bahasa pemrograman C++. Tujuan dari program ini adalah untuk menerima input berupa elemen-elemen sebuah array dari pengguna, kemudian mencari nilai maksimum dari array tersebut beserta posisi (indeks) di mana nilai maksimum tersebut berada.

## UNGUIDED

## Unguided 1
Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

### Source Progam
```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> data(n);
    vector<int> genap_189, ganjil;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (data[i] % 2 == 0)
        {
            genap_189.push_back(data[i]);
        }
        else
        {
            ganjil.push_back(data[i]);
        }
    }

    cout << "Data Array  : ";
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "Nomor Genap  : ";
    for (int i = 0; i < genap_189.size(); i++)
    {
        cout << genap_189[i] << " ";
    }
    cout << endl;

    cout << "Nomor Ganjil  : ";
    for (int i = 0; i < ganjil.size(); i++)
    {
        cout << ganjil[i] << " ";
    }
    cout << endl;

    return 0;
}
```
### Ouput Progam
<img width="684" alt="mekdidi" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/b2e8176a-3b97-457e-a1c5-acc07b7d3bcb">

### Deskripsi Progam
program ini adalah untuk mengklasifikasikan elemen-elemen sebuah array menjadi dua kelompok: bilangan genap dan bilangan ganjil. Program ini menggunakan vector untuk menyimpan elemen-elemen array serta hasil klasifikasinya.

## Unguided 2
Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!
 
### Source Progam
```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int dim1_189, dim2, dim3;
  cout << "Masukkan ukuran dimensi 1: ";
  cin >> dim1_189;
  cout << "Masukkan ukuran dimensi 2: ";
  cin >> dim2;
  cout << "Masukkan ukuran dimensi 3: ";
  cin >> dim3;

  // Membuat array tiga dimensi dengan ukuran yang ditentukan oleh pengguna
  vector<vector<vector<int>>> array3D(dim1_189, vector<vector<int>>(dim2, vector<int>(dim3)));

  // Mengisi array dengan input pengguna
  cout << "Masukkan elemen array (dim1_189 x dim2 x dim3):\n";
  for (int i = 0; i < dim1_189; ++i)
  {
    for (int j = 0; j < dim2; ++j)
    {
      for (int k = 0; k < dim3; ++k)
      {
        cin >> array3D[i][j][k];
      }
    }
  }

  // Menampilkan elemen array
  cout << "Elemen array:\n";
  for (int i = 0; i < dim1_189; ++i)
  {
    for (int j = 0; j < dim2; ++j)
    {
      for (int k = 0; k < dim3; ++k)
      {
        cout << "array3D[" << i << "][" << j << "][" << k << "] = " << array3D[i][j][k] << endl;
      }
    }
  }

  return 0;
}
```
### Output Progam
<img width="690" alt="sahyuu" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/a7f9c39a-76bd-43ed-9dff-93b6db2a3f14">

### Deskripsi Progam
program ini adalah untuk membuat, mengisi, dan menampilkan elemen-elemen dari sebuah array tiga dimensi dengan ukuran yang ditentukan oleh pengguna.

## Unguided 3
Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

### Source Progam
```c++
#include <iostream>
using namespace std;

int input_189;
int bil[10];
int minim, maksim;
double rata;

int main()
{

    while (true)
    {
        cout << "\t"
                "\t"
             << "MENU" << endl;
        cout << "\t" << "1. INPUT ARRAY" << endl;
        cout << "\t" << "2. TAMPIL ARRAY" << endl;
        cout << "\t" << "3. CARI NILAI MINIMMUM" << endl;
        cout << "\t" << "4. CARI NILAI MAKSIMUM" << endl;
        cout << "\t" << "5. HITUNG RATA - RATA" << endl;

        cout << "MASUKAN PILIHAN : ";
        cin >> input_189;

        cout << endl;

        switch (input_189)
        {
        case 1:
        {
            for (int i = 0; i < 10; i++)
            {
                cout << "MASUKAN BILANGAN KE - " << i + 1 << " : ";
                cin >> bil[i];
            }
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "ARRAY YANG DI INPUT : ";
            for (int i = 0; i < 10; i++)
            {
                cout << bil[i] << " ";
            }
            cout << endl;
        }
            cout << endl;
            break;
        case 3:
        {
            minim = bil[0];
            for (int i = 0; i < 10; i++)
            {
                if (bil[i] < minim)
                {
                    minim = bil[i];
                }
            }
            cout << "NILAI MINIMUM DARI ARRAY TERSEBUT : " << minim << endl;
            cout << endl;
        }
        break;
        case 4:
        {
            maksim = bil[0];
            for (int i = 0; i < 10; i++)
            {
                if (bil[i] > maksim)
                {
                    maksim = bil[i];
                }
            }
            cout << "NILAI MAKSIMUM DARI ARRAY TERSEBUT : " << maksim << endl;
            cout << endl;
        }
        break;
        case 5:
        {
            for (int i = 0; i < 10; i++)
            {
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
### Output Progam
<img width="687" alt="wululu" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/263b78c3-c8ce-41a4-8423-f3041249e589">
<img width="680" alt="wiliili" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/1348644a-5fc0-4e50-8494-2a539766dfc0">

### Deskripsi Progam
program ini adalah untuk mengelola array dengan ukuran tetap (10 elemen) melalui menu interaktif yang memungkinkan pengguna untuk melakukan berbagai operasi pada array tersebut. Operasi yang bisa dilakukan antara lain menginput array, menampilkan array, mencari nilai minimum, mencari nilai maksimum, dan menghitung rata-rata nilai elemen array.

## Kesimpulan
Array adalah struktur data yang digunakan untuk menyimpan sejumlah elemen data yang memiliki tipe yang sama. Elemen-elemen ini disimpan dalam lokasi memori yang berurutan, yang memungkinkan akses cepat dan efisien ke setiap elemen berdasarkan indeksnya. Secara keseluruhan, array adalah alat yang sangat berguna dalam pemrograman yang memungkinkan penyimpanan dan pengolahan data yang efisien. Namun, penting untuk memahami batasan-batasannya dan memilih struktur data yang tepat sesuai kebutuhan aplikasi.

## Refrensi
Pratama, M. A. (2020, March 29). STRUKTUR DATA ARRAY DUA DIMENSI  PADA PEMROGRAMAN C++. 

C++ Arrays. diakses dari https://www.w3schools.com/cpp/cpp_arrays.asp#:~:text=Arrays%20are%20used%20to%20store,separate%20variables%20for%20each%20value
