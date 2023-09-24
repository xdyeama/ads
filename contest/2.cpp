#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



int main(){

    string s = "";

    cin >> s;

    int numS = count(s.begin(), s.end(), 's');
    int numH = count(s.begin(), s.end(), 'h');
    int numE = count(s.begin(), s.end(), 'e');
    int numR = count(s.begin(), s.end(), 'r');
    int numI = count(s.begin(), s.end(), 'i');
    int numF = count(s.begin(), s.end(), 'f');

    int num = min({numS, numH, numE, numR, numI, numF/2});

    cout << num;
    
    return 0;
}