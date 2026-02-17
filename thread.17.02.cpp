1) #include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void task_1(long long& result) {
    long long sum = 0;
    for (long long i = 1; i <= 5000; i++)
        sum += i;
    result = sum;  
}


void task_2(long long& result) {
    long long sum = 0;
    for (long long i = 500; i <= 10000; i++)
        sum += i;
    result = sum;
}

void task_3(long long& result) {
    long long sum = 0;
    for (long long i = 10000; i <= 15000; i++)
        sum += i;
    result = sum;
}

void task_4(long long& result) {
    long long sum = 0;
    for (long long i = 15000; i <= 20000; i++)
        sum += i;
    result = sum;
}

int main() {

    long long result1 = 0, result2 = 0, result3 = 0, result4 = 0;

    auto start_time = chrono::high_resolution_clock::now();

    thread t1(task_1, ref(result1));
    thread t2(task_2, ref(result2));
    thread t3(task_3, ref(result3));
    thread t4(task_4, ref(result4));

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    long long total_sum = result1 + result2 + result3 + result4;

    cout << "Sum: " << total_sum << endl;
    cout << "Time: " << duration.count() << " ms" << endl;

    return 0;
}

2) slow
#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    auto start = chrono::high_resolution_clock::now();

    long long sum = 0;
    for (long long i = 1; i <= 200000000; i++)
        sum += i;

    auto end = chrono::high_resolution_clock::now();

    cout << "Sum: " << sum << endl;
    cout << "Time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
}
