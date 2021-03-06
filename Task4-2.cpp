#include <iostream>
using namespace std;

struct Node {
    int item;
    Node * next;
    Node * prev;
};

struct Queue {
    Node * pHead = NULL;
    Node * pEnd = NULL;

    void Enqueue(int item) {
        Node * node = new Node;
        node->item = item;

        if (pEnd == NULL) {
            node->prev = pEnd;
            pEnd = node;
        }
        else node->prev = pHead;

        if (pHead != NULL) pHead->next = node;

        pHead = node;
    }

    int Dequeue() {
        if (!pEnd) throw 1;

        Node * temp = pEnd;

        int x = pEnd->item;
        pEnd->next->prev = NULL;
        pEnd = pEnd->next;

        delete temp;

        return x;
    }
};

int main() {
    Queue * queue = new Queue;

    queue->Enqueue(10);
    queue->Enqueue(20);
    queue->Enqueue(30);

    cout << queue->Dequeue() << endl;
}