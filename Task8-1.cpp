#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getSize(int number) {
    return to_string(number).size();
}

int getSortedArrayOfDigits(int *array, int number, int size) {
    for (int i = 0; number > 0; i++) {
        array[i] = number % 10;
        number /= 10;
    }
    sort(array, array + size);
    return *array;
}

int getNumber (int *array, int size) {
    int number = 0;
    for (int i = 0; i < size; i++) {
        number = number*10 + array[i];
    }
    return number;
}

void getNextPermutation(int *array, int size) {
    for (int i = size - 1; i > 0; i--)
        if (array[i] > array[i-1]) {
            int min = array[i], minj = i;
            for (int j = i; j < size - 1; j++)
                if (array[j+1] < min && array[j+1] > array[i-1]) {
                    min = array[j+1];
                    minj = j+1; 
                }
            swap(array[i-1], array[minj]);
            sort(array + i, array + size);
            break;
        }
}


int main() {
    int A, B, C, prev;

    cout << "INPUT VALUES HERE:" << endl;
    cin >> A >> B >> C;

    int sizeA = getSize(A), sizeB = getSize(B), As[sizeA], Bs[sizeB];
    As[sizeA] = getSortedArrayOfDigits(As, A, sizeA);
    Bs[sizeB] = getSortedArrayOfDigits(Bs, B, sizeB);

    while (true) {
        A = getNumber(As, sizeA);
        if (prev == A) {
            cout << "TARGET NUMBERS DOESN'T EXIST" << endl;
            return 0;
        }
        while (true) {
            B = getNumber(Bs, sizeB);
            if (prev == B) {
                sort(Bs, Bs + sizeB);
                break;
            }
            if (A + B == C) {
                cout << "TARGET NUMBERS ARE " << A << " AND " << B << endl;
                return 0;
            }
            getNextPermutation(Bs, sizeB);
            prev = B;
        }
        getNextPermutation(As, sizeA);
        prev = A;
    }
}