#include <iostream>
using namespace std;

struct Node {
    int d;
    Node *l, *r;
};

class BST {
public:
    Node* ins(Node* r, int x) {
        if (!r) {
            r = new Node();
            r->d = x;
            r->l = r->r = NULL;
            return r;
        }
        if (x < r->d) r->l = ins(r->l, x);
        else r->r = ins(r->r, x);
        return r;
    }

    Node* srch(Node* r, int x) {
        if (!r || r->d == x) return r;
        if (x < r->d) return srch(r->l, x);
        return srch(r->r, x);
    }

    Node* mn(Node* r) {
        while (r->l) r = r->l;
        return r;
    }

    Node* del(Node* r, int x) {
        if (!r) return r;
        if (x < r->d) r->l = del(r->l, x);
        else if (x > r->d) r->r = del(r->r, x);
        else {
            if (!r->l) {
                Node* t = r->r;
                delete r;
                return t;
            }
            else if (!r->r) {
                Node* t = r->l;
                delete r;
                return t;
            }
            Node* t = mn(r->r);
            r->d = t->d;
            r->r = del(r->r, t->d);
        }
        return r;
    }

    void in(Node* r) {
        if (!r) return;
        in(r->l);
        cout << r->d << " ";
        in(r->r);
    }
};

int main() {
    BST b;
    Node* r = NULL;

    r = b.ins(r, 50);
    b.ins(r, 30);
    b.ins(r, 70);
    b.ins(r, 20);
    b.ins(r, 40);
    b.ins(r, 60);
    b.ins(r, 80);

    b.in(r);
    cout << endl;

    b.del(r, 50);
    b.in(r);
    cout << endl;

    if (b.srch(r, 40)) cout << "Found\n";
    else cout << "Not Found\n";
}