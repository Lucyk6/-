#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Basic level

// 1. Declare pointer to int and initialize with nullptr
void task1() {
    cout << "=== Task 1 ===" << endl;
    int* ptr = nullptr;
    
    // Check pointer before dereferencing
    if (ptr != nullptr) {
        cout << "Value: " << *ptr << endl;
    } else {
        cout << "Pointer is nullptr. Cannot dereference." << endl;
    }
    
    // Now create a valid pointer
    int value = 42;
    ptr = &value;
    
    if (ptr != nullptr) {
        cout << "Now pointer is valid. Value: " << *ptr << endl;
    }
    cout << endl;
}

// 2. Declare integer array and print address of first element in two ways
void task2() {
    cout << "=== Task 2 ===" << endl;
    int arr[5] = {1, 2, 3, 4, 5};
    
    cout << "First element address method 1 (using array name): " << arr << endl;
    cout << "First element address method 2 (using & operator): " << &arr[0] << endl;
    cout << endl;
}

// 3. Pointer to array and print all elements using pointer arithmetic
void task3() {
    cout << "=== Task 3 ===" << endl;
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr; // Pointer to first element
    
    cout << "Array elements using pointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": " << *(ptr + i) << " at address: " << (ptr + i) << endl;
    }
    cout << endl;
}

// 4. Demonstrate difference between NULL and nullptr
void task4() {
    cout << "=== Task 4 ===" << endl;
    
    // Using NULL (old C style)
    int* ptr1 = NULL;
    
    // Using nullptr (modern C++ style)
    int* ptr2 = nullptr;
    
    cout << "Pointer initialized with NULL: " << ptr1 << endl;
    cout << "Pointer initialized with nullptr: " << ptr2 << endl;
    
    // Key difference: nullptr is type-safe
    // NULL is usually defined as 0, which can cause issues with function overloading
    
    // Example of issue with NULL:
    void func(int);    // Function taking int
    void func(int*);   // Function taking pointer
    
    // func(NULL);     // Ambiguous call - could call func(int) or func(int*)
    // func(nullptr);  // Unambiguous - will call func(int*)
    
    cout << "Note: nullptr is type-safe and should be used in modern C++" << endl;
    cout << endl;
}

// 5. Compare two pointers pointing to elements of same array
void task5() {
    cout << "=== Task 5 ===" << endl;
    int arr[5] = {1, 2, 3, 4, 5};
    
    int* ptr1 = &arr[1]; // Points to second element (value 2)
    int* ptr2 = &arr[3]; // Points to fourth element (value 4)
    
    cout << "ptr1 points to: " << *ptr1 << " at address: " << ptr1 << endl;
    cout << "ptr2 points to: " << *ptr2 << " at address: " << ptr2 << endl;
    
    // Compare pointers
    if (ptr1 < ptr2) {
        cout << "ptr1 comes before ptr2 in memory" << endl;
    } else if (ptr1 > ptr2) {
        cout << "ptr1 comes after ptr2 in memory" << endl;
    } else {
        cout << "ptr1 and ptr2 point to same location" << endl;
    }
    cout << endl;
}

// Medium level

// 6. Count positive elements in array
int countPositiveElements(int* arr, int size) {
    if (arr == nullptr || size <= 0) return 0;
    
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) > 0) {
            count++;
        }
    }
    return count;
}

// 7. Find maximum element using only pointers
int findMaxUsingPointers(int* arr, int size) {
    if (arr == nullptr || size <= 0) return 0;
    
    int max = *arr;
    int* end = arr + size;
    
    for (int* ptr = arr + 1; ptr < end; ptr++) {
        if (*ptr > max) {
            max = *ptr;
        }
    }
    return max;
}

// 8. Find distance between two elements in array
int distanceBetweenElements(int* arr, int size, int* ptr1, int* ptr2) {
    if (arr == nullptr || ptr1 == nullptr || ptr2 == nullptr) return -1;
    
    // Check if both pointers point within array bounds
    if (ptr1 < arr || ptr1 >= arr + size || ptr2 < arr || ptr2 >= arr + size) {
        return -1;
    }
    
    // Distance in number of elements
    return abs(ptr1 - ptr2);
}

// 9. Traverse array in reverse order using pointer arithmetic
void printArrayReverse(int* arr, int size) {
    if (arr == nullptr || size <= 0) return;
    
    cout << "Array in reverse order: ";
    int* end = arr + size - 1; // Pointer to last element
    
    for (int* ptr = end; ptr >= arr; ptr--) {
        cout << *ptr << " ";
    }
    cout << endl;
}

// 10. Check if pointer points to element within array
bool isPointerInArray(int* arr, int size, int* ptr) {
    if (arr == nullptr || ptr == nullptr) return false;
    
    return (ptr >= arr && ptr < arr + size);
}

// Advanced level

// 11. Safely print value via pointer (with nullptr check)
void safePrintValue(int* ptr) {
    if (ptr != nullptr) {
        cout << "Value: " << *ptr << endl;
    } else {
        cout << "Pointer is nullptr. Cannot print value." << endl;
    }
}

// 12. Copy array using pointers
void copyArrayUsingPointers(int* source, int* destination, int size) {
    if (source == nullptr || destination == nullptr || size <= 0) return;
    
    for (int i = 0; i < size; i++) {
        *(destination + i) = *(source + i);
    }
}

// 13. Swap min and max elements using pointers
void swapMinMax(int* arr, int size) {
    if (arr == nullptr || size <= 1) return;
    
    int* minPtr = arr;
    int* maxPtr = arr;
    
    // Find pointers to min and max elements
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < *minPtr) {
            minPtr = arr + i;
        }
        if (*(arr + i) > *maxPtr) {
            maxPtr = arr + i;
        }
    }
    
    // Swap values
    int temp = *minPtr;
    *minPtr = *maxPtr;
    *maxPtr = temp;
}

// 14. Count even elements without using [] notation
int countEvenElementsNoIndex(int* arr, int size) {
    if (arr == nullptr || size <= 0) return 0;
    
    int count = 0;
    int* end = arr + size;
    
    for (int* ptr = arr; ptr < end; ptr++) {
        if (*ptr % 2 == 0) {
            count++;
        }
    }
    return count;
}

// 15. Demonstrate correct and incorrect pointer comparison
void demonstratePointerComparison() {
    cout << "=== Correct pointer comparison ===" << endl;
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr1 = &arr[1];
    int* ptr2 = &arr[3];
    
    // Correct: comparing pointers to same array
    if (ptr1 < ptr2) {
        cout << "Correct: ptr1 < ptr2 (both in same array)" << endl;
    }
    
    cout << "\n=== Incorrect pointer comparison ===" << endl;
    int var1 = 10;
    int var2 = 20;
    int* ptr3 = &var1;
    int* ptr4 = &var2;
    
    // Incorrect: comparing pointers to different memory areas
    // This is undefined behavior
    cout << "Comparing pointers to different variables is undefined behavior" << endl;
    cout << "ptr3: " << ptr3 << ", ptr4: " << ptr4 << endl;
    cout << "The result of comparison is unreliable" << endl;
}

// Applied and analytical tasks

// 16. Analyze code with NULL and replace with nullptr
void analyzeAndReplaceNULL() {
    cout << "=== Analysis of NULL vs nullptr ===" << endl;
    
    // Old code using NULL
    cout << "Old code using NULL:" << endl;
    cout << "int* ptr = NULL;" << endl;
    cout << "if (ptr == NULL) { ... }" << endl;
    
    cout << "\nProblems with NULL:" << endl;
    cout << "1. NULL is usually #define NULL 0" << endl;
    cout << "2. Type issues in function overloading" << endl;
    cout << "3. Not type-safe" << endl;
    
    cout << "\nModern code using nullptr:" << endl;
    cout << "int* ptr = nullptr;" << endl;
    cout << "if (ptr == nullptr) { ... }" << endl;
    
    cout << "\nAdvantages of nullptr:" << endl;
    cout << "1. Type-safe (type is nullptr_t)" << endl;
    cout << "2. No ambiguity in function overloading" << endl;
    cout << "3. Clearer intent in code" << endl;
    cout << "4. Compatible with all pointer types" << endl;
}

// 17. Check if two pointers have same address
bool arePointersEqual(int* ptr1, int* ptr2) {
    return ptr1 == ptr2;
}

// 18. Check if two pointers point to adjacent elements
bool arePointersAdjacent(int* arr, int size, int* ptr1, int* ptr2) {
    if (arr == nullptr || ptr1 == nullptr || ptr2 == nullptr) return false;
    
    // Check if both pointers are within array bounds
    if (!isPointerInArray(arr, size, ptr1) || !isPointerInArray(arr, size, ptr2)) {
        return false;
    }
    
    // Check if they point to adjacent elements
    return (ptr1 + 1 == ptr2) || (ptr2 + 1 == ptr1);
}

// 19. Count elements greater than given value
int countGreaterThanValue(int* arr, int size, int value) {
    if (arr == nullptr || size <= 0) return 0;
    
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) > value) {
            count++;
        }
    }
    return count;
}

// 20. Demonstrate array out of bounds error
void demonstrateOutOfBoundsError() {
    cout << "=== Demonstrating array out of bounds error ===" << endl;
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    
    cout << "Array bounds: 0 to 4 (5 elements)" << endl;
    
    // Accessing within bounds
    cout << "Accessing within bounds:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << *(ptr + i) << endl;
    }
    
    cout << "\nAccessing out of bounds (ERROR):" << endl;
    cout << "Trying to access arr[5] (which doesn't exist)..." << endl;
    
    // This causes undefined behavior!
    // int value = *(ptr + 5);  // Accessing 6th element of 5-element array
    
    cout << "Why this error occurs:" << endl;
    cout << "1. Pointer arithmetic allows moving pointer beyond array bounds" << endl;
    cout << "2. C++ doesn't check array bounds at runtime" << endl;
    cout << "3. Reading/writing out of bounds causes undefined behavior" << endl;
    cout << "4. May corrupt memory, crash, or produce unexpected results" << endl;
}

// Helper function to print array
void printArray(int* arr, int size, const string& message = "") {
    if (!message.empty()) {
        cout << message << ": ";
    }
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));
    
    // Basic level tasks
    task1();
    task2();
    task3();
    task4();
    task5();
    
    // Medium level tasks
    cout << "=== Task 6 ===" << endl;
    int arr6[] = {1, -2, 3, -4, 5};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    printArray(arr6, size6, "Array");
    cout << "Positive elements: " << countPositiveElements(arr6, size6) << endl << endl;
    
    cout << "=== Task 7 ===" << endl;
    int arr7[] = {3, 7, 2, 9, 1};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    printArray(arr7, size7, "Array");
    cout << "Maximum element: " << findMaxUsingPointers(arr7, size7) << endl << endl;
    
    cout << "=== Task 8 ===" << endl;
    int arr8[] = {10, 20, 30, 40, 50};
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    int* ptr8a = &arr8[1];
    int* ptr8b = &arr8[3];
    cout << "Distance between element " << *ptr8a << " and element " << *ptr8b 
         << ": " << distanceBetweenElements(arr8, size8, ptr8a, ptr8b) << " elements" << endl << endl;
    
    cout << "=== Task 9 ===" << endl;
    int arr9[] = {1, 2, 3, 4, 5};
    int size9 = sizeof(arr9) / sizeof(arr9[0]);
    printArray(arr9, size9, "Original array");
    printArrayReverse(arr9, size9);
    cout << endl;
    
    cout << "=== Task 10 ===" << endl;
    int arr10[] = {1, 2, 3, 4, 5};
    int size10 = sizeof(arr10) / sizeof(arr10[0]);
    int* ptr10 = &arr10[2];
    int* ptr10_out = &arr10[0] - 1; // Pointer outside array
    cout << "ptr10 points to " << *ptr10 << endl;
    cout << "Is ptr10 in array? " << (isPointerInArray(arr10, size10, ptr10) ? "Yes" : "No") << endl;
    cout << "Is ptr10_out in array? " << (isPointerInArray(arr10, size10, ptr10_out) ? "Yes" : "No") << endl << endl;
    
    // Advanced level tasks
    cout << "=== Task 11 ===" << endl;
    int value11 = 100;
    int* ptr11_valid = &value11;
    int* ptr11_null = nullptr;
    
    cout << "Safe print with valid pointer: ";
    safePrintValue(ptr11_valid);
    cout << "Safe print with null pointer: ";
    safePrintValue(ptr11_null);
    cout << endl;
    
    cout << "=== Task 12 ===" << endl;
    int src12[] = {1, 2, 3, 4, 5};
    int dest12[5];
    int size12 = sizeof(src12) / sizeof(src12[0]);
    copyArrayUsingPointers(src12, dest12, size12);
    printArray(src12, size12, "Source array");
    printArray(dest12, size12, "Destination array after copy");
    cout << endl;
    
    cout << "=== Task 13 ===" << endl;
    int arr13[] = {5, 2, 8, 1, 9};
    int size13 = sizeof(arr13) / sizeof(arr13[0]);
    printArray(arr13, size13, "Before swapping min and max");
    swapMinMax(arr13, size13);
    printArray(arr13, size13, "After swapping min and max");
    cout << endl;
    
    cout << "=== Task 14 ===" << endl;
    int arr14[] = {1, 2, 3, 4, 5, 6};
    int size14 = sizeof(arr14) / sizeof(arr14[0]);
    printArray(arr14, size14, "Array");
    cout << "Even elements (no [] notation): " << countEvenElementsNoIndex(arr14, size14) << endl << endl;
    
    cout << "=== Task 15 ===" << endl;
    demonstratePointerComparison();
    cout << endl;
    
    // Applied and analytical tasks
    cout << "=== Task 16 ===" << endl;
    analyzeAndReplaceNULL();
    cout << endl;
    
    cout << "=== Task 17 ===" << endl;
    int var17a = 10, var17b = 20;
    int* ptr17a = &var17a;
    int* ptr17b = &var17b;
    int* ptr17c = &var17a;
    
    cout << "ptr17a and ptr17b point to same address? " 
         << (arePointersEqual(ptr17a, ptr17b) ? "Yes" : "No") << endl;
    cout << "ptr17a and ptr17c point to same address? " 
         << (arePointersEqual(ptr17a, ptr17c) ? "Yes" : "No") << endl << endl;
    
    cout << "=== Task 18 ===" << endl;
    int arr18[] = {1, 2, 3, 4, 5};
    int size18 = sizeof(arr18) / sizeof(arr18[0]);
    int* ptr18a = &arr18[1];
    int* ptr18b = &arr18[2];
    int* ptr18c = &arr18[3];
    
    cout << "Are " << *ptr18a << " and " << *ptr18b << " adjacent? "
         << (arePointersAdjacent(arr18, size18, ptr18a, ptr18b) ? "Yes" : "No") << endl;
    cout << "Are " << *ptr18a << " and " << *ptr18c << " adjacent? "
         << (arePointersAdjacent(arr18, size18, ptr18a, ptr18c) ? "Yes" : "No") << endl << endl;
    
    cout << "=== Task 19 ===" << endl;
    int arr19[] = {5, 10, 15, 20, 25};
    int size19 = sizeof(arr19) / sizeof(arr19[0]);
    int threshold = 12;
    printArray(arr19, size19, "Array");
    cout << "Elements greater than " << threshold << ": " 
         << countGreaterThanValue(arr19, size19, threshold) << endl << endl;
    
    cout << "=== Task 20 ===" << endl;
    demonstrateOutOfBoundsError();
    
    return 0;
}
