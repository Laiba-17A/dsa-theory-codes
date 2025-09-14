#include <iostream>
using namespace std; 

class ResourceHolder {
private:
    int* data;

public:
    ResourceHolder() {
        data = new int[100];
    }

    ~ResourceHolder() {
        delete[] data;
        cout << "ResourceHolder destructor called." << endl;
    }
};

int main() {
    ResourceHolder* holder = new ResourceHolder();
    // ... do some work with holder
    delete holder; // Destructor is called here

    return 0;
}

