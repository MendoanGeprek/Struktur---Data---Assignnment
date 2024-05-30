#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    int umur;
};
class Mobil
{
private:
    string merek_189;
    int tahunProduksi;

public:
    Mobil(string merek_189, int tahunProduksi)
    {
        this->merek_189 = merek_189;
        this->tahunProduksi = tahunProduksi;
    }
    void tampilkanInfo()
    {
        cout << "Merek mobil: " << merek_189 << endl;
        cout << "Tahun produksi: " << tahunProduksi << endl;
    }
};
int main()
{
    Mahasiswa mhs;
    mhs.nama = "Budi";
    mhs.umur = 20;
    cout << "Nama mahasiswa: " << mhs.nama << endl;
    cout << "Umur mahasiswa: " << mhs.umur << endl;
    Mobil mobil("Toyota", 2020);
    mobil.tampilkanInfo();

    return 0;
}