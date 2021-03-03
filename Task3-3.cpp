#include <iostream>
using namespace std;

struct Node {
    int item;
    Node * next;
};

struct List {
    Node * pFoot = NULL;

    void add(int item) {
        Node * node = new Node;
        node->item = item;
        node->next = NULL;
        if (pFoot == NULL) {
            pFoot = node;
        }
        else {
            Node * temp = pFoot;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    int size() {
        int size = 0;

        if (!pFoot)
            return size;
        
        Node * temp = pFoot;

        while (temp->next != NULL) {
                temp = temp->next;
                size++;
            }

        size++;

        return size;
    }

    int get(int id) {
        if (!pFoot || id < 0)
            throw 1;

        if (id+1 > this->size())
            throw 1;

        int iter = 0;

        Node * temp = pFoot;

        while (iter != id) {
            temp = temp->next;
            iter++;
        }

        return temp->item;
    }

    void printAll() {
        if (!pFoot)
            throw 1;

        Node * temp = pFoot;

        while (temp->next != NULL) {
            cout << temp->item << endl;
            temp = temp->next;
        }
        
        cout << temp->item << endl;

    }
};

int main() {
    List * list = new List;

    list->add(10);
    list->add(20);
    list->add(30);

    list->printAll();

    return 0;
}