#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Fungsi untuk melakukan Selection Sort pada string
void selectionSort(string &str) {
    int n = str.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (str[j] < str[minIndex]) {
                minIndex = j;
            }
        }
        swap(str[i], str[minIndex]);
    }
}

// Fungsi untuk melakukan Binary Search pada string yang sudah diurutkan
void binarySearch(const string &sortedStr, char target) {
    int left = 0;
    int right = sortedStr.size() - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedStr[mid] == target) {
            found = true;
            break;
        } else if (sortedStr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        cout << "Huruf '" << target << "' ditemukan pada index: ";
        for (int i = 0; i < sortedStr.size(); ++i) {
            if (sortedStr[i] == target) {
                cout << i << " "; // Index dimulai dari 1
            }
        }
        cout << endl;
    } else {
        cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;
    }
}

int main() {
    string inputStr;
    char target;

    // Ambil input kalimat
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, inputStr);

    // Ambil input huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;

    // Sortir kalimat
    selectionSort(inputStr);

    // Tampilkan kata yang sudah diurutkan
    cout << "Kata yang sudah diurutkan: ";
    for (char c : inputStr) {
        cout << c << " ";
    }
    cout << endl;

    // Lakukan binary search dan tampilkan hasilnya
    binarySearch(inputStr, target);

    return 0;
}