#include <iostream>
using namespace std;

int main() {
    int n;
    int nums;
    int sum = 0;
    
    cin >> n;

    while (n > 0) {
        n -= 1;
        cin >> nums;
        sum += nums;
    }

    cout << sum;
}