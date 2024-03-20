#include <iostream>
using namespace std;

int input;
int bil[10];
int minim, maksim;
double rata;

int main(){

    while(true){
    cout << "\t" "\t" << "MENU" << endl;
    cout << "\t" << "1. INPUT ARRAY" << endl;
    cout << "\t" << "2. TAMPIL ARRAY" << endl;
    cout << "\t" << "3. CARI NILAI MINIMMUM" << endl;
    cout << "\t" << "4. CARI NILAI MAKSIMUM" << endl;
    cout << "\t" << "5. HITUNG RATA - RATA" << endl;

    cout << "MASUKAN PILIHAN : ";
    cin >> input;

    cout << endl;

    switch (input)
    {
    case 1 : 
        {
            for(int i = 0; i < 10; i++){
                cout << "MASUKAN BILANGAN KE - " << i + 1 << " : ";
                cin >> bil[i];
            }
            cout << endl;
        break;
        }
    case 2 : 
        {
            cout << "ARRAY YANG DI INPUT : ";
            for (int i = 0; i < 10; i++){
                cout << bil[i] << " ";
            }
        cout << endl;
        }
    cout << endl;
    break;
    case 3 :
        {
            minim = bil[0];
            for(int i = 0; i < 10; i++){
                if(bil[i] < minim){
                    minim = bil[i];
                }
            }
            cout << "NILAI MINIMUM DARI ARRAY TERSEBUT : " << minim << endl;
            cout << endl;
        }
    break;
    case 4 :
        {
            maksim = bil[0];
            for (int i = 0; i < 10; i++){
                if(bil[i] > maksim){
                    maksim = bil[i];
                }
            }
            cout << "NILAI MAKSIMUM DARI ARRAY TERSEBUT : " << maksim << endl;
            cout << endl;
        }
    break;
    case 5 :
        {
            for(int i = 0; i < 10; i++){
                rata += bil[i] / 12;
            }
            cout << "RATA - RATA DARI ARRAY TERSEBUT : " << rata;
        }
        cout << endl;
        cout << endl;
        break;
    }
}
    return 0;
}