#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseSentence(string sentence) {
    stack<char> charStack;

    for (char c : sentence) {
        charStack.push(c);
    }

    string reversedSentence = "";

    while (!charStack.empty()) {
        reversedSentence += charStack.top();
        charStack.pop();
    }

    return reversedSentence;
}

int main() {
    char pilihan;
    do {
        string kalimat;
        cout << "Masukkan kalimat: ";
        getline(cin, kalimat);

      
        if (kalimat.empty()) {
            cout << "Kalimat tidak boleh kosong. Silakan coba lagi." << endl;
            continue;
        }

        string hasil = reverseSentence(kalimat);

        cout << "Hasil Kalimat: " << hasil << endl;

        
        cout << "Apakah anda ingin mengubah kalimatnya? (y/n): ";
        cin >> pilihan;
        cin.ignore(); 
    } while (pilihan == 'y' || pilihan == 'Y');

    return 0;
}