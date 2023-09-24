#include <iostream>

using namespace std;

// Stack - LIFO (Last In First Out)
// Queue - FIFO (First In First Out)
// Deque - 2 sided stack(or queue)

// Stack
struct stack{
    // [0, n)
    int a[100];
    int n;

    stack(){
        n = 0;
    }

    int size(){
        return n;
    }

    void push(int x){
        a[n++] = x;
    }

    void pop(){
        if (n == 0){
            cout << "Stack error: pop of empty stack";
            exit(0);
        }
        n--;
    }

    int top(){
        return a[n-1];
    }

};

int main(){
    stack st;
    st.push(10);
    st.push(20);
    cout << "size = " << st.size() << endl;
    cout << st.top() << endl;
    cout << "size = " << st.size() << endl;
    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.top() << endl;
    

    return 0;
}