#include <iostream>
using namespace std;

int main() {
    int x;
    int p = 1;
    int two = 1;

    cin >> x;

    while (x > two*2) {
        p++;
        two *= 2;
    }

    cout << p-1;
}

