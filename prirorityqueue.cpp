#include <iostream>
using namespace std;

class PQ {
    int *a, n, sz;
    void up(int i){
        int p=(i-1)/2;
        while(i>0 && a[i]>a[p]){
            swap(a[i],a[p]);
            i=p; p=(i-1)/2;
        }
    }
    void dn(int i){
        int l,r,b;
        while(true){
            l=2*i+1; r=2*i+2; b=i;
            if(l<sz && a[l]>a[b]) b=l;
            if(r<sz && a[r]>a[b]) b=r;
            if(b==i) break;
            swap(a[i],a[b]);
            i=b;
        }
    }
public:
    PQ(int s){ n=s; a=new int[n]; sz=0; }
    void push(int x){ if(sz<n){ a[sz]=x; up(sz++); } }
    int pop(){ if(sz==0) return -1; int x=a[0]; a[0]=a[--sz]; dn(0); return x; }
    int top(){ return sz>0?a[0]:-1; }
    void disp(){ for(int i=0;i<sz;i++) cout<<a[i]<<" "; cout<<endl; }
    ~PQ(){ delete[] a; }
};

int main(){
    PQ q(10);
    q.push(20); q.push(15); q.push(30); q.push(10);
    q.disp();
    cout<<q.top()<<endl;
    q.pop();
    q.disp();
}