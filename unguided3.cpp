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