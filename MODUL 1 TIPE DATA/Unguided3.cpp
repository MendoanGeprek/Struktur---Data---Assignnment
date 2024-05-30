#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> umur_189;

    umur_189["steven"] = 19;
    umur_189["morgan"] = 18;
    umur_189["alex"] = 20;

    cout << "Umur steven: " << umur_189["steven"] << endl;
    cout << "Umur morgan: " << umur_189["morgan"] << endl;
    cout << "Umur alex: " << umur_189["alex"] << endl;
    return 0;
}