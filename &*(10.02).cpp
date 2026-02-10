1) #include <iostream>
using namespace std;

void byValue(int x)
{
    x *= 2;
}

void byReference(int& x)
{
    x *= 2;
}

void byPointer(int* x)
{
    *x *= 2;
}

int main()
{
    int a = 5;

    byValue(a);
    cout << a << endl;

    byReference(a);
    cout << a << endl;

    byPointer(&a);
    cout << a << endl;
}

2)
