#include <iostream>
#include <climits>

using namespace std;

struct queue{
    int q[100001];
    int start, end;

    queue(){
        start = end = 1;
    }

    void push(int x){
        q[end++] = x;
    }

    void pop(){
        if(empty()){
            cout << "queue is empty" << endl;
            exit(0);
        }
        start++;
    }

    int size(){
        return end - start;
    }

    bool empty(){
        return start == end;
    }

    int front(){
        if(empty()){
            cout << "front for empty queue" << endl;
            exit(0);
        }
        return q[start];
    }

    void print(){
        while(!empty()){
            cout << front() << " ";
            pop();
        }
    }
};


int main(){
    queue q;
    int n, curr;
    int a[100000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> curr;
        q.push(curr);
    }
    // q.print();
    cout << -1 << " ";
    while(q.size() != 1){
        int prev = q.front();
        q.pop();
        // cout << "prev = " << prev << " ";
        // cout << "curr = " << q.front() << endl;
        if(prev <= q.front()){

            cout << prev << " ";
        }else{
            int min = INT_MAX;
            for(int i = q.start - 1; i >= 1; i--){
                if(q.q[i] <= q.front()){
                    min = q.q[i];
                    break;
                }
            }
            if(min != INT_MAX){
                cout << min << " ";
            }else{
                cout << -1 << " ";
            }
        }
    }

    return 0;
}