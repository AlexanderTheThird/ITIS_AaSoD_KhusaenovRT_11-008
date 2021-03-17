#include <iostream>
using namespace std;


struct Node {
    int item;
    Node * next;
};


struct SList {
    Node * pHead = NULL;
    int size = 0;
    
    void add(int item) {
        Node * node = new Node;
        node->item = item;
        node->next = NULL;
        this->size++;
        if (!pHead || pHead->item >= node->item) {
            node->next = pHead;
            pHead = node;
        }
        else {
            if (pHead->next == NULL) pHead->next = node;
            else {
                Node * temp = pHead;
                while (true) {
                    if (node->item > temp->next->item) {
                        if (temp->next->next == NULL) {
                            temp = temp->next;
                            break;
                        }
                        temp = temp->next;
                        continue;
                    }
                    if (temp->next->item > node->item) {
                        node->next = temp->next;
                        temp->next = node;
                        break;
                    }
                    else {
                        this->size--;
                        break;
                    }
                }
                temp->next = node;
            }
        }
    }

    int get(int id) {
        if (id >= this->size) throw 1;
        Node * temp = pHead;
        for (int counter = 0; counter < id; counter++) temp = temp->next;
        return temp->item;
    }

    void remove(int id) {
        if (id >= this->size) throw 1;
        Node * temp = pHead;
        this->size--;
        if (id == 0) {
            pHead = temp->next;
        }
        else {
            for (int counter = 0; counter < id-1; counter++) temp = temp->next;
            temp->next = temp->next->next;
        }
    }
};

int main() {
    SList * list = new SList;

    list->add(10);
    list->add(30);
    list->add(20);
    list->add(40);
    list->add(40);
    list->add(5);

    cout << list->get(0) << endl;
    cout << list->get(1) << endl;
    cout << list->get(2) << endl;
    cout << list->get(3) << endl;
    cout << list->get(4) << endl;
    cout << list->get(5) << endl;

    return 0;
}