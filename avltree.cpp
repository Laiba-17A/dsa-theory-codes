#include <iostream>
using namespace std;

struct Node {
    int d, h;
    Node *l, *r;
};

int ht(Node* n) {
    if (!n) return 0;
    return n->h;
}

int bal(Node* n) {
    if (!n) return 0;
    return ht(n->l) - ht(n->r);
}

int mx(int a, int b) { return (a > b) ? a : b; }

Node* nw(int x) {
    Node* n = new Node();
    n->d = x;
    n->l = n->r = NULL;
    n->h = 1;
    return n;
}

Node* rr(Node* y) {
    Node* x = y->l;
    Node* t = x->r;
    x->r = y;
    y->l = t;
    y->h = mx(ht(y->l), ht(y->r)) + 1;
    x->h = mx(ht(x->l), ht(x->r)) + 1;
    return x;
}

Node* lr(Node* x) {
    Node* y = x->r;
    Node* t = y->l;
    y->l = x;
    x->r = t;
    x->h = mx(ht(x->l), ht(x->r)) + 1;
    y->h = mx(ht(y->l), ht(y->r)) + 1;
    return y;
}

Node* ins(Node* r, int x) {
    if (!r) return nw(x);
    if (x < r->d) r->l = ins(r->l, x);
    else if (x > r->d) r->r = ins(r->r, x);
    else return r;

    r->h = 1 + mx(ht(r->l), ht(r->r));

    int b = bal(r);

    if (b > 1 && x < r->l->d) return rr(r);
    if (b < -1 && x > r->r->d) return lr(r);
    if (b > 1 && x > r->l->d) {
        r->l = lr(r->l);
        return rr(r);
    }
    if (b < -1 && x < r->r->d) {
        r->r = rr(r->r);
        return lr(r);
    }

    return r;
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
        if (!r->l || !r->r) {
            Node* t = r->l ? r->l : r->r;
            if (!t) {
                t = r;
                r = NULL;
            } else *r = *t;
            delete t;
        } else {
            Node* t = mn(r->r);
            r->d = t->d;
            r->r = del(r->r, t->d);
        }
    }

    if (!r) return r;

    r->h = 1 + mx(ht(r->l), ht(r->r));
    int b = bal(r);

    if (b > 1 && bal(r->l) >= 0) return rr(r);
    if (b > 1 && bal(r->l) < 0) {
        r->l = lr(r->l);
        return rr(r);
    }
    if (b < -1 && bal(r->r) <= 0) return lr(r);
    if (b < -1 && bal(r->r) > 0) {
        r->r = rr(r->r);
        return lr(r);
    }

    return r;
}

void in(Node* r) {
    if (!r) return;
    in(r->l);
    cout << r->d << " ";
    in(r->r);
}

int main() {
    Node* r = NULL;
    r = ins(r, 30);
    r = ins(r, 20);
    r = ins(r, 40);
    r = ins(r, 10);
    r = ins(r, 25);
    r = ins(r, 50);

    in(r);
    cout << endl;

    r = del(r, 40);
    in(r);
    cout << endl;
}