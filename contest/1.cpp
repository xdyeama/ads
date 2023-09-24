#include <iostream>

using namespace std;


int main(){
    long long n, s;
    cin >> n >> s;
    long long max = 0;

    long long curr = 0;
    for(int i = 0; i < n; i++){
        cin >> curr;
        if(curr > max && curr < s){
            max = curr;
        }
    }

    cout << max;

    return 0;
}