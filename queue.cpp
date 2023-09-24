#include <iostream>

using namespace std;

struct queue{
    int a[100];
    int start, end, size;

    queue(){
        start = end = 0;
    }

    void push(int x){
        a[end++] = x;
    }

    void pop(){
        if (empty()){
            cout << "Error: pop of empty queue" << endl;
            exit(0);
        }
        start++;
    }

    int sizee(){
       return end - start;
    };

    bool empty(){
        return start == end;
    }

    int front(){
        if (empty()){
            cout << "Error: front of empty queue" << endl;
            exit(0);
        }
        return a[start];
    }
};


int main(){
    queue q;
    cout << "Is queue empty: " << q.empty() <<  endl;
    q.push(1);
    q.push(2);
    cout << "queue from element " << q.front() << endl;
    cout << "queue size " << q.sizee() << endl;
    cout << "Is queue empty: " << q.empty() << endl;
    q.pop();
    cout << "queue from element " << q.front() << endl;
    cout << "queue size " << q.sizee() << endl;
    cout << "Is queue empty: " << q.empty() << endl;


    return 0;
}