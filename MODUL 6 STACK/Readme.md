# <h1 align="center">Laporan Praktikum Modul 6 Stack </h1>
<p align="center">Muhammad Djidzan. N. N</p>
<p align="center">231102189</p>
<p align="center">IF 11 E</p>

## Dasar Teori Stack
Tumpukan atau Stack adalah struktur data yang mengikuti prinsip "Last In, First Out" (LIFO), yang berarti elemen yang terakhir dimasukkan ke dalam tumpukan akan menjadi elemen pertama yang diambil. Ini mirip dengan tumpukan buku di atas meja; buku yang terakhir diletakkan di atas tumpukan akan menjadi yang pertama diambil.
Dasar-dasar tumpukan meliputi operasi dasar seperti:

1.Push: Menambahkan elemen baru ke atas tumpukan.

2.Pop: Menghapus elemen teratas dari tumpukan.

3.Top/Peek: Mendapatkan nilai elemen teratas tanpa menghapusnya.

4.IsEmpty: Memeriksa apakah tumpukan kosong.

5.IsFull (pada implementasi statis): Memeriksa apakah tumpukan penuh.

6.Size: Mendapatkan jumlah elemen dalam tumpukan.

Tumpukan digunakan dalam banyak aplikasi, termasuk pemrosesan ekspresi aritmatika, manajemen memori dalam sistem komputer, pengolahan bahasa alami, dan masih banyak lagi.

## Guided
source code

```c++
#include <iostream>
using namespace std;
string arrayBuku[5];
int maksimal = 5, top = 0;
bool isFull()
{
    return (top == maksimal);
}
bool isEmpty()
{
    return (top == 0);
}
void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}
void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}
void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}
int countStack()
{
    return top;
}
void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}
void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}
int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");
    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();
    return 0;
}
```
## Ouput
<img width="631" alt="gu" src="https://github.com/MendoanGeprek/Struktur---Data---Assignnment/assets/161665370/c577abc3-a869-411c-a72f-e838a1b9be67">

## Deskripsi Progam
Program ini adalah implementasi sederhana dari struktur data stack dalam bahasa C++. Program ini termasuk metode untuk menambahkan, menghapus, melihat, dan menghitung elemen dalam stack. Stack ini diwakili oleh array string, dan program ini menunjukkan berbagai operasi pada stack ini.

## Unguided 
   
## 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

## Source Code 
```C++
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string str) {
    stack<char> st;
    for (char c : str) {
        st.push(c);
    }
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }
    return str == reversed;
}

int main() {
    string input;
    cout << "String Kata: ";
    getline(cin, input);
    if (isPalindrome(input)) {
        cout << "String ini Palindrome." << endl;
    } else {
        cout << "String ini bukan Palindrome." << endl;
    }
    return 0;
}
```

## Ouput
