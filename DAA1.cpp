
// ========================================================
// DAA Assignment 1
// Name: Vedanti Pacharne
// Roll No: 0052
// BE Comp (B3)
// ========================================================
// Problem Statement:
// Implement recursive and non-recursive methods to generate
// Fibonacci numbers and analyze their time & space complexities.
// Also, implement the Tower of Hanoi problem using recursion.
// ========================================================

#include <iostream>
using namespace std;

// --------------------------------------------------------
// 1. Fibonacci - Non-Recursive
// --------------------------------------------------------
void fibonacci_non_recursive(int n) {
    int a = 0, b = 1, c;
    cout << "Fibonacci Sequence (Non-Recursive): ";
    if (n >= 1) cout << a << " ";
    if (n >= 2) cout << b << " ";

    for (int i = 2; i < n; i++) {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
    cout << "Time Complexity: O(n)\n";
    cout << "Space Complexity: O(1)\n\n";
}

// --------------------------------------------------------
// 2. Fibonacci - Recursive
// --------------------------------------------------------
int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

void print_fibonacci_recursive(int n) {
    cout << "Fibonacci Sequence (Recursive): ";
    for (int i = 0; i < n; i++)
        cout << fibonacci_recursive(i) << " ";
    cout << endl;
    cout << "Time Complexity: O(2^n)\n";
    cout << "Space Complexity: O(n)\n\n";
}

// --------------------------------------------------------
// 3. Tower of Hanoi - Recursive
// --------------------------------------------------------
void tower_of_hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    tower_of_hanoi(n - 1, source, auxiliary, target);
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    tower_of_hanoi(n - 1, auxiliary, target, source);
}

// --------------------------------------------------------
// Main Function
// --------------------------------------------------------
int main() {
    int n, disks;

    cout << "Enter the number of Fibonacci terms: ";
    cin >> n;

    cout << endl;
    fibonacci_non_recursive(n);
    print_fibonacci_recursive(n);

    cout << "Enter the number of disks for Tower of Hanoi: ";
    cin >> disks;

    cout << "\nSteps to solve Tower of Hanoi with " << disks << " disks:\n";
    tower_of_hanoi(disks, 'A', 'C', 'B');

    cout << "\nTime Complexity (Tower of Hanoi): O(2^n)\n";
    cout << "Space Complexity (Tower of Hanoi): O(n)\n";

    return 0;
}

