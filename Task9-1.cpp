#include <iostream>
using namespace std;

void divideByNumber(int number, int change) {
    int count = 0;
    while (change >= number) {
        change -= number;
        count++;
    }
    if (number == 10) divideByNumber(5, change);
    if (number == 5) divideByNumber(1, change);
    
    cout << count << " ";
}

int main() {
    int change;

    cout << "INPUT X: ";
    cin >> change;
    cout << endl;

    divideByNumber(10, change);

    return 0;
}