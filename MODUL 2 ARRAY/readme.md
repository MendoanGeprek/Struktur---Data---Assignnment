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


## UNGUIDED

## Unguided 1

### Source Progam

### Ouput Progam

### Deskripsi Progam

## Unguided 2

### Source Progam

### Output Progam

### Deskripsi Progam

## Unguided 3

### Source Progam

### Output Progam

### Deskripsi Progam

## Kesimpulan

## Refrensi

