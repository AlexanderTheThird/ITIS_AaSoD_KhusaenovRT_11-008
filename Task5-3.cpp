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

SList * Union(SList * a, SList * b) {
    SList * c = new SList;
    Node * tempa = a->pHead;
    Node * tempb = b->pHead;

    while (tempa->next != NULL || tempb->next != NULL) {
        if (tempa->item < tempb->item) {
            c->add(tempa->item);
            tempa = tempa->next;
            continue;
        }
        if (tempa->item > tempb->item) {
            c->add(tempb->item);
            tempb = tempb->next;
            continue;
        }
        if (tempa->item == tempb->item) {
            c->add(tempb->item);
            if (tempa->next != NULL && tempb->next != NULL) {
                tempa = tempa->next;
                tempb = tempb->next;
            }
            else break;
        }
    }
    if (tempa->next == NULL) {
        while (tempb->next != NULL) {
            tempb = tempb->next;
            c->add(tempb->item);
        }
    }
    if (tempb->next == NULL) {
        while (tempa->next != NULL) {
            tempa = tempa->next;
            c->add(tempa->item);
        }
    }
    return c;
}

SList * Intersect(SList * a, SList * b) {
    SList * c = new SList;
    Node * tempa = a->pHead;
    Node * tempb = b->pHead;

    while (tempa->next != NULL || tempb->next != NULL) {
        if (tempa->item < tempb->item) {
            tempa = tempa->next;
            continue;
        }
        if (tempa->item > tempb->item) {
            tempb = tempb->next;
            continue;
        }
        if (tempa->item == tempb->item) {
            c->add(tempb->item);
            if (tempa->next != NULL && tempb->next != NULL) {
                tempa = tempa->next;
                tempb = tempb->next;
            }
            else break;
        }
    }
    return c;
}

SList * Difference(SList * a, SList * b) {
    SList * c = new SList;
    Node * tempa = a->pHead;
    Node * tempb = b->pHead;

    while (tempa->next != NULL || tempb->next != NULL) {
        if (tempa->item < tempb->item) {
            c->add(tempa->item);
            tempa = tempa->next;
            continue;
        }
        if (tempa->item > tempb->item) {
            tempb = tempb->next;
            continue;
        }
        if (tempa->item == tempb->item) {
            if (tempa->next != NULL && tempb->next != NULL) {
                tempa = tempa->next;
                tempb = tempb->next;
            }
            else break;
        }
    }
    return c;
}

int main() {
    SList * a = new SList;

    a->add(1);
    a->add(3);
    a->add(4);
    a->add(6);
    a->add(5);

    SList * b = new SList;

    b->add(2);
    b->add(3);
    b->add(4);
    b->add(6);
    b->add(8);

    SList * c = Difference(a, b);

    cout << "Difference:" << endl;
    cout << c->get(0) << endl;
    cout << c->get(1) << endl;

    c = Intersect(a, b);

    cout << "Intersect:" << endl;
    cout << c->get(0) << endl;
    cout << c->get(1) << endl;
    cout << c->get(2) << endl;

    c = Union(a, b);

    cout << "Union:" << endl;
    cout << c->get(0) << endl;
    cout << c->get(1) << endl;
    cout << c->get(2) << endl;
    cout << c->get(3) << endl;
    cout << c->get(4) << endl;
    cout << c->get(5) << endl;
    cout << c->get(6) << endl;

    return 0;
}