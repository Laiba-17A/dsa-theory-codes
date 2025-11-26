#include <iostream>
using namespace std;

void hs(int a[], int n){
    for(int i=n/2-1;i>=0;i--){
        int p=i,l,r,b;
        while(true){
            l=2*p+1; r=2*p+2; b=p;
            if(l<n && a[l]>a[b]) b=l;
            if(r<n && a[r]>a[b]) b=r;
            if(b==p) break;
            swap(a[p],a[b]);
            p=b;
        }
    }
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        int p=0,l,r,b;
        while(true){
            l=2*p+1; r=2*p+2; b=p;
            if(l<i && a[l]>a[b]) b=l;
            if(r<i && a[r]>a[b]) b=r;
            if(b==p) break;
            swap(a[p],a[b]);
            p=b;
        }
    }
}

int main(){
    int a[]={9,4,7,1,3,8};
    int n=sizeof(a)/sizeof(a[0]);
    hs(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}