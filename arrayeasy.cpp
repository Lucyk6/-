#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10; 
    int arr[SIZE]; 

    int positive = 0; 
    int negative = 0; 
    int zero = 0;    

 
    cout << "enter 10 numbers:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] > 0) {
            positive++;
        }
        else if (arr[i] < 0) {
            negative++;
        }
        else {
            zero++;
        }
    }

 
    cout << "Result:" << endl;
    cout << "+: " << positive << endl;
    cout << "-: " << negative << endl;
    cout << "0 values: " << zero << endl;

    return 0;
}
