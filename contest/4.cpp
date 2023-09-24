#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    long long n;
    int m;
    cin >> n >> m;
    long long curr;
    vector<long long> money;
    vector<long long> res;
    for(int i = 0; i < m; i++){
        cin >> curr;
        money.push_back(curr);
        money.push_back(curr);
    }
    sort(money.begin(), money.end());

    long long rem = n;

    for(int i = money.size() - 1; i >= 0; i--){
        if(rem >= money[i]){
            rem -= money[i];
            res.push_back(money[i]);
        }
    }

    if(rem == 0){
        cout << res.size() << endl;
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
    }else{
        cout << -1 << endl;
    }
    
    return 0;
}