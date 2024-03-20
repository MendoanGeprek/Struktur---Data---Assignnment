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