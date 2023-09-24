#include <iostream>
#include <vector>


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

    void print(){
        int i = front;
        while(i != rear+1){
            if(i == max_size - 1){
                i = 0;
            }
            cout << a[i] << " ";
            i++;
        }
    }

};

deque rotation(deque deck, int n){
    for(int i = 0; i < n; i++){
        deck.pushFront(deck.getRear());
        deck.deleteRear();
    }
    return deck;
}


int main() {
    int m;
    cin >> m;
    for(int k = 0; k < m; k++){
        int n;
        cin >> n;
        deque deck;

        // 213 -> 123 -> 23 -> 32 -> 23 -> 3 -> nothing

        for(int i = n; i > 0; i--){
            deck.pushFront(i);
            deck = rotation(deck, i);
        }
        deck.print();
        cout << endl;
    }


    return 0;
}