#include <iostream>
#include <climits>
#include <cmath>

using namespace std;


struct Node{
    int val;
    Node *next;

};




int main(){
    int n, val, target;
    cin >> n;
    cin >> val;
    Node *head, *temp;
    head = new Node;
    head -> val = val;
    head -> next = 0;
    temp = head;
    for(int i = 0; i < n - 1; i++){
        cin >> val;
        Node *newNode;
        newNode = new Node;
        newNode -> val = val;
        newNode -> next = 0;
        temp -> next = newNode;
        temp = temp -> next;
    }
    cin >> target;
    temp = head;
    int offset = 0;
    int count = 0;
    int minDiff = INT_MAX;

    while(temp){
        if(abs(target - temp -> val) < minDiff){
            minDiff = abs(target - temp -> val);
            offset = count;
        }
        temp = temp -> next;
        count++;
    }
    cout << offset;
    return 0;
}