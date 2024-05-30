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