#include <iostream>
using namespace std;

int main() {
    int a[5] = {1,2,3,4,5};
    int b[5] = {6,7,8,9};

    int * c = new int[10];

    c += *a;
    c += *b;

    cout << c[5];
}