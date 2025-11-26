#include <iostream>
using namespace std;

class St {
    int *a;
    int top;
    int n;
public:
    St(int s) {
        n = s;
        a = new int[n];
        top = -1;
    }
    bool full() { return top == n - 1; }
    bool emp() { return top == -1; }

    void push(int x) {
        if (full()) return;
        a[++top] = x;
    }

    int pop() {
        if (emp()) return -1;
        return a[top--];
    }

    int peek() {
        if (emp()) return -1;
        return a[top];
    }

    void disp() {
        for (int i = top; i >= 0; i--) cout << a[i] << " ";
        cout << endl;
    }

    ~St() { delete[] a; }
};

int main() {
    St s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.disp();
    cout << s.pop() << endl;
    s.disp();
    cout << s.peek() << endl;
}