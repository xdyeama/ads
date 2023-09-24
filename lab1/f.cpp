#include <iostream>
#include <climits>
#include <vector>
#include <cstring>

using namespace std;

#define max_size 100005

vector<int> primes;
bool isPrimes[max_size];



void eratoth_sieve(){
    memset(isPrimes, true, sizeof(isPrimes));
    
    for(int i = 2; i*i < max_size; i++){
        if(isPrimes[i] == true){
            for(int j = i * i; j < max_size; j += i){
                isPrimes[j] = false;
            }
        }
    }

    for(int i = 2; i < max_size; i++){
        if(isPrimes[i] == true){
            primes.push_back(i);
        }
    }
}


int main(){
    int n;
    cin >> n;

    eratoth_sieve();

    cout << primes[n-1];
    
    return 0;
}