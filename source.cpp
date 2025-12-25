#include <iostream>
#include "fraction.h"
using namespace std;

int main() {
    int num;
    cout << "enter number of fractions: ";
    cin >> num;

    fraction* arr = new fraction[num];

    for (int i = 0; i < num; i++) {
        int a, b;
        cout << "enter fraction " << (i + 1) << " (num denom): ";
        cin >> a >> b;
        arr[i] = fraction(a, b);
    }

    cout << endl << "list:" << endl;
    fraction total;
    
    for (int i = 0; i < num; i++) {
        cout << arr[i] << endl;
        total = total + arr[i];
    }

    cout << "sum: " << total << endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}