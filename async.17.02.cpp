#include <iostream>
#include <future>
#include <chrono>
using namespace std;

long long task_1() {
    long long sum = 0;
    for (long long i = 1; i <= 50000000; i++)
        sum += i;
    return sum;  
}

long long task_2() {
    long long sum = 0;
    for (long long i = 50000000; i <= 100000000; i++)
        sum += i;
    return sum;
}

long long task_3() {
    long long sum = 0;
    for (long long i = 100000000; i <= 150000000; i++)
        sum += i;
    return sum;
}

long long task_4() {
    long long sum = 0;
    for (long long i = 150000000; i <= 200000000; i++)
        sum += i;
    return sum;
}

int main() {


    auto start_time = chrono::high_resolution_clock::now();

    future<long long> f1 = async(task_1);
    future<long long> f2 = async(task_2);
    future<long long> f3 = async(task_3);
    future<long long> f4 = async(task_4);

    long long result1 = f1.get();
    long long result2 = f2.get();
    long long result3 = f3.get();
    long long result4 = f4.get();

    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    long long total_sum = result1 + result2 + result3 + result4;

    cout << "Sum: " << total_sum << endl;
    cout << "Time: " << duration.count() << " ms" << endl;
    return 0;
}
