#include <iostream>

using namespace std;

// Eratosthenes Algorithm
// Input: n
// Output: Prime numbers in range from [1, n]
// prime number p => p is divisible by only 1 and p (p != 1)

// Time complexity:  O(n log(log(n)))
// n/2 + n/3 + n/5 + ... + n/pmax => n(1/2 + 1/3 + 1/5 + ... + 1/n) -> Harmonic series => O(n*log(log(n)))

bool marks[100005];

int main(){
    int n;
    cin >> n;

    marks[1] = false;

    // nonoptimized algorithm
    // for(int i = 2; i <= n; i++){
    //     if(!marks[i]){
    //         for(int j = 2 * i; j <= n; j += i){
    //             marks[j] = true;
    //         }
    //     }
    // }

    // optimized algorithm
    for(int i = 2; i <= n / i; i++){ // i * i <= n
        if(!marks[i]){
            for(int j = i * i; j <= n; j += i){
                marks[j] = true;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(!marks[i]) 
            cout << i << " ";
    }
    cout << endl;
    return 0;
}