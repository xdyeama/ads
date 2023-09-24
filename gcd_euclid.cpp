#include <iostream>

using namespace std;

// Euclidean algorithm
// Time complexity: O(log(A * B)) = O(logA + logB)
// Worst case (Fibonacci Numbers): gcd(F(n), F(n+1)) => gcd(F(n-1), F(n)) => .. => gcd(1, 0) n steps

int gcd(int a, int b){

    if (b == 0) return a;

    return gcd(b, a % b);
}

int main(){
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << endl;

    return 0;
}