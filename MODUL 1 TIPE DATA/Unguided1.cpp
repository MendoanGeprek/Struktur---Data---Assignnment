#include <iostream>
using namespace std;

void bilangan(int num)
{
    cout << "Bilangan integer yang dimasukkan: " << num << endl;
}

void charakter(char c)
{
    cout << "Karakter yang dimasukkan: " << c << endl;
}

int main()
{
    int angka_189;
    char karakter;

    cout << "Masukkan sebuah bilangan integer: ";
    cin >> angka_189;

    cout << "Masukkan sebuah karakter: ";
    cin >> karakter;

    bilangan(angka_189);
    charakter(karakter);

    return 0;
}