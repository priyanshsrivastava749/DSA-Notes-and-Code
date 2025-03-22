#include <iostream>
using namespace std;

long long arr[100] = {0};  // Initialize array with zeros

long long fibo(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    
    if (arr[x] != 0) return arr[x]; // Check if already computed
    
    return arr[x] = fibo(x - 1) + fibo(x - 2); // Store and return result
}

int main() {
    int p = fibo(5);
    cout << p;
    return 0;
}
