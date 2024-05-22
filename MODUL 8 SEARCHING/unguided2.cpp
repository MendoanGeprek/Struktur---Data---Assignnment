#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk memeriksa apakah karakter adalah vokal
bool isVokal(char c) {
    return (c == 'a' || c == 'A' ||  c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
}

int main() {
    string sentence;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, sentence);

    int vokalCount = 0;

    // Melakukan pencarian berurutan untuk menghitung huruf vokal
    for (char c : sentence) {
        if (isVokal(c)) {
            vokalCount++;
        }
    }

    cout << "Jumlah huruf vokal dalam kalimat: " << vokalCount << endl;

    return 0;
}