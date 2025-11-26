#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = new int[n1], *R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void ms(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        ms(a, l, m);
        ms(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[] = {9, 4, 7, 2, 5, 8, 1};
    int n = sizeof(a) / sizeof(a[0]);
    ms(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}