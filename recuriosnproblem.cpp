#include <iostream>

void towerOfHanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        // Base case: Move the top disk from source to target peg.
        std::cout << "Move disk" << n << "  from " << source << " to " << target << std::endl;
        return;
    }

    // Move n-1 disks from source to auxiliary peg using target peg as the auxiliary.
    towerOfHanoi(n - 1, source, target, auxiliary);

    // Move the nth disk from source to target peg.
    std::cout << "Move disk " << n << " from " << source << " to " << target << std::endl;
    std::cout<<auxiliary<<std::endl;

    // Move the n-1 disks from auxiliary peg to target peg using source peg as the auxiliary.
    towerOfHanoi(n - 1, auxiliary, source, target);
}

int main() {
    int n = 4; // Number of disks
    char source = 'A', auxiliary = 'B', target = 'C'; // Pegs

    std::cout << "Tower of Hanoi with " << n << " disks:" << std::endl;
    towerOfHanoi(n, source, auxiliary, target);

    return 0;
}

