#include <iostream>
#include "SharedPtr.h"
using std::cout;
int main() {

    SharedPtr<int> ptr1(new int(151));
    cout << "--- Shared pointers ptr1 ---\n";
    cout << ptr1;
    {
        // ptr2 pointing to same integer
        // which ptr1 is pointing to
        // Shared pointer reference counter
        // should have increased now to 2.
        SharedPtr<int> ptr2 = ptr1;
        cout << "--- Shared pointers ptr1, ptr2 ---\n";
        cout << ptr1;
        cout << ptr2;
        {
            // ptr3 pointing to same integer
            // which ptr1 and ptr2 are pointing to.
            // Shared pointer reference counter
            // should have increased now to 3.
            SharedPtr<int> ptr3(ptr2);
            cout << "--- Shared pointers ptr1, ptr2, ptr3 ---\n";
            cout << ptr1;
            cout << ptr2;
            cout << ptr3;
        }

        // ptr3 is out of scope.
        // It would have been destructed.
        // So shared pointer reference counter
        // should have decreased now to 2.
        cout << "--- Shared pointers ptr1, ptr2 ---\n";
        cout << ptr1;
        cout << ptr2;
    }

    // ptr2 is out of scope.
    // It would have been destructed.
    // So shared pointer reference counter
    // should have decreased now to 1.
    cout << "--- Shared pointers ptr1 ---\n";
    cout << ptr1;

    return 0;

    return 0;
}