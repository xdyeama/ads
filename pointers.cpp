#include <iostream>

using namespace std;

#define LOG(x) cout << x << endl

int main(){
    // int x = 10;
    // int* ptr = &x;
    // *ptr = 1;
    // LOG(x);

    char* buffer = new char[8];

    memset(buffer, 10, 8);

    LOG(*(&buffer));
}

