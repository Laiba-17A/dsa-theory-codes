#include <iostream>
using namespace std;

int part(int a[], int l, int r) {
    int p = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] <= p) {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[r];
    a[r] = t;
    return i + 1;
}

void qs(int a[], int l, int r) {
    if (l < r) {
        int pi = part(a, l, r);
        qs(a, l, pi - 1);
        qs(a, pi + 1, r);
    }
}

int main() {
    int a[] = {9, 4, 7, 2, 5, 8, 1};
    int n = sizeof(a) / sizeof(a[0]);
    qs(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}