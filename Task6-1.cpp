#include <iostream>
using namespace std;


struct MaxHeap
{
    int * array = new int[2];
    int size = -1;
    int maxSize = 2;
    int Parent(int i) { return (i - 1) / 2; }
    int LeftChild(int i) { return 2 * i + 1; }
    int RightChild(int i) { return 2 * i + 2; }

    int GetMax() { return array[0]; }

    void SiftUp(int i)
    {
        while (i > 1 && array[i] > array[Parent(i)]) {
            int temp = array[i];
            array[i] = array[Parent(i)];
            array[Parent(i)] = temp;
            i = Parent(i);
        }
    }

    void SiftDown(int i) 
    {
        int maxIndex = i;

        if (array[LeftChild(i)] > array[maxIndex]) maxIndex = LeftChild(i);
        if (array[RightChild(i)] > array[maxIndex]) maxIndex = RightChild(i);

        if (maxIndex != i && maxIndex <= this->size ) {
            int temp = array[maxIndex];
            array[maxIndex] = array[i];
            array[i] = temp;
            SiftDown(maxIndex);
        }
    }

    void Insert(int p)
    {
        if (size+1 < maxSize) {
            size++;
            array[size] = p;
            SiftUp(size);
        }
        else {
            int * temp = new int[maxSize*2];
            for (int iter = 0; iter < maxSize; iter++) {
                temp[iter] = array[iter];
            }
            array = temp;
            maxSize *= 2;
            Insert(p);
        }
    }

    int ExtractMax()
    {   
        int result = array[0];
        array[0] = array[size];
        size--;
        SiftDown(0);
        return result;
    }
};

int main()
{
    MaxHeap * heap = new MaxHeap;
    heap->Insert(20);
    heap->Insert(11);
    heap->Insert(15);
    heap->Insert(9);
    heap->Insert(7);
    heap->Insert(16);
    heap->Insert(21);
    cout << heap->GetMax() << endl;
    cout << heap->ExtractMax() << endl;
    cout << heap->GetMax() << endl;

    return 0;
}