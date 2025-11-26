#include <iostream>
using namespace std;

struct Node {
    int d;
    Node* n;
};

class LL {
private:
    Node* h;
public:
    LL() { h = NULL; }

    void insBeg(int x) {
        Node* t = new Node();
        t->d = x;
        t->n = h;
        h = t;
    }

    void insEnd(int x) {
        Node* t = new Node();
        t->d = x;
        t->n = NULL;
        if (!h) { h = t; return; }
        Node* p = h;
        while (p->n) p = p->n;
        p->n = t;
    }

    void insPos(int x, int pos) {
        if (pos == 1) { insBeg(x); return; }
        Node* p = h;
        for (int i = 1; p && i < pos - 1; i++) p = p->n;
        if (!p) return;
        Node* t = new Node();
        t->d = x;
        t->n = p->n;
        p->n = t;
    }

    void delBeg() {
        if (!h) return;
        Node* t = h;
        h = h->n;
        delete t;
    }

    void delEnd() {
        if (!h) return;
        if (!h->n) { delete h; h = NULL; return; }
        Node* p = h;
        while (p->n->n) p = p->n;
        delete p->n;
        p->n = NULL;
    }

    void delPos(int pos) {
        if (pos == 1) { delBeg(); return; }
        Node* p = h;
        for (int i = 1; p && i < pos - 1; i++) p = p->n;
        if (!p || !p->n) return;
        Node* t = p->n;
        p->n = t->n;
        delete t;
    }

    bool srch(int x) {
        Node* p = h;
        while (p) {
            if (p->d == x) return true;
            p = p->n;
        }
        return false;
    }

    void disp() {
        Node* p = h;
        while (p) {
            cout << p->d << " ";
            p = p->n;
        }
        cout << endl;
    }
};

int main() {
    LL l;
    l.insBeg(3);
    l.insEnd(5);
    l.insEnd(7);
    l.insPos(4, 3);
    l.disp();
    l.delBeg();
    l.disp();
    l.delEnd();
    l.disp();
    cout << l.srch(5) << endl;
    return 0;
}