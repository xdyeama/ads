#include <iostream>

using namespace std;

#define max_size 100005


struct deque{
    int a[max_size];
    int front, rear;

    deque(){
        front = -1;
        rear = 0;
    }

    void pushFront(int x){
        if(isFull()){
            cout << "Error: deque is full";
            exit(0);
        }
        if(isEmpty()){
            front = 0;
            rear = 0;
        }
        else if(front == 0){
            front = max_size - 1;
        }else{
            front--;
        }
        a[front] = x;
    }

    void pushRear(int x){
        if(isFull()){
            cout << "Error: deque is full";
            exit(0);
        }
        if(isEmpty()){
            front = 0;
            rear = 0;
        }
        else if(rear == max_size - 1){
            rear = 0;
        }else{
            rear++;
        }
        a[rear] = x;
    }

    void deleteFront(){
        if(isEmpty()){
            cout << "Error: deque is empty";
            exit(0);
        }
        if(front == rear){
            front = -1;
            rear = -1;
        }else if(front == max_size - 1){
            front = 0;
        }else{
            front++;
        }
    }

    void deleteRear(){
        if(isEmpty()){
            cout << "Error: deque is empty";
            exit(0);
        }
        if (front == rear){
            front = -1;
            rear = -1;
        }else if(rear == 0){
            rear = max_size - 1;
        }else{
            rear--;
        }
    }

    int getFront(){
        if(isEmpty()){
            cout << "Error: deque is empty";
            exit(0);
        }
        return a[front];
    }

    int getRear(){
        if(isEmpty()){
            cout << "Error: deque is empty";
            exit(0);
        }
        return a[rear];
    } 

    bool isEmpty(){
        return (front == -1);
    }

    bool isFull(){
        return ((front == 0 && rear == max_size - 1)
            || front == rear + 1);
    }

    void getSumAndDelete(){
        if(front == -1){
            cout << "error" << endl;
        }else{
            int first_num = getFront();
            int second_num = getRear();
            int sum = first_num + second_num;
            if(front == rear){
                deleteFront();
            }else{
                deleteFront();
                deleteRear();
            }
            cout << sum << endl;
        }
    }
};

int main(){
    deque dq;
    char ch;
    int a;
    while(true){
        cin >> ch;
        if(ch == '+'){
            cin >> a;
            dq.pushFront(a);
        }else if(ch == '-'){
            cin >> a;
            dq.pushRear(a);
        }
        else if(ch == '*'){
            dq.getSumAndDelete();
        }else{
            break;
        }
    }
    return 0;
}