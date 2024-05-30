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