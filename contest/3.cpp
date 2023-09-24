#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    long long n;
    cin >> n;
    vector<long long> inp(n);
    vector<long long> comb(n);
    for(int i = 0; i < n; i++){
        cin >> inp[i];
    }
    for(int i = 0; i < n; i++){
        cin >> comb[i];
    }

    int l = 0;
    int r = n - 1;
    for(int i = 0; i < n; i++){
        if(inp[i] != comb[i]){
            l = i;
            break;
        }
    }
    for(int i = n-1; i > 0; i--){
        if(inp[i] != comb[i]){
            r = i;
            break;
        }
    }

    sort(inp.begin() + l, inp.begin() + r + 1);

    if(inp == comb){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}