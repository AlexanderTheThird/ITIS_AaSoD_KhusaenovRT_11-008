#include <iostream>
using namespace std;

int main() {
    int len;

    cout << "ENTER LENGTH OF ARRAY HERE: ";
    cin >> len;

    int variants[4] = {1, 1, 0, 0};

    if (len <= 0) {
        cout << "IT SEEMS THAT AN ARRAY WITH THIS LENGTH DOESN'T EXIST";
        return 0;
    }

    while (len > 2) {
        len--;
        variants[2] = variants[0] + variants[1];
        for (int i = 0; i < 3; i++) {
            variants[i] = variants[i+1];
        }
    }

    cout << "COUNT OF VARIANTS IS " << variants[1] << endl;
    return 0;
}