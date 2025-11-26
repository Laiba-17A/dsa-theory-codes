#include <iostream>
using namespace std;

class Q {
    int *a;
    int f, r, n, cnt;
public:
    Q(int s) {
        n = s;
        a = new int[n];
        f = 0;
        r = -1;
        cnt = 0;
    }

    bool full() { return cnt == n; }
    bool emp() { return cnt == 0; }

    void enq(int x) {
        if (full()) return;
        r = (r + 1) % n;
        a[r] = x;
        cnt++;
    }

    int deq() {
        if (emp()) return -1;
        int x = a[f];
        f = (f + 1) % n;
        cnt--;
        return x;
    }

    int fr() {
        if (emp()) return -1;
        return a[f];
    }

    void disp() {
        if (emp()) return;
        int i = f;
        for (int c = 0; c < cnt; c++) {
            cout << a[i] << " ";
            i = (i + 1) % n;
        }
        cout << endl;
    }

    ~Q() { delete[] a; }
};

int main() {
    Q q(5);
    q.enq(10);
    q.enq(20);
    q.enq(30);
    q.disp();
    cout << q.deq() << endl;
    q.disp();
    cout << q.fr() << endl;
}