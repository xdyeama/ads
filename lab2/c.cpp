#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

struct LL{
    Node *head = new Node();
    Node *tail;

    LL(){
        tail = head;
    }

    void addElement(int x){
        Node *temp;
        temp = head;
        Node *newNode = new Node(x);
        while(temp -> next != nullptr){

            temp = temp -> next;
        }
        temp -> next = newNode;
        tail = newNode;
    }

    void addElements(int n){
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            Node *newNode = new Node(x);
            tail -> next = newNode;
            tail = newNode;
        }
        head = head -> next;
    }

    void removeEverySecond(){
        int i = 1;
        Node *temp;
        temp = head;
        while(temp && temp -> next){
            Node *targetNode = temp -> next;
            temp -> next = temp -> next -> next;
            temp = temp -> next;
            free(targetNode);
            i++;
        
        }
    }

    void printElements(){
        Node *temp;
        temp = head;
        while(temp){
            cout << temp -> val << " ";
            temp = temp -> next;

        }
    }
};

int main(){
    int n;
    cin >> n;
    LL ll;
    ll.addElements(n);
    ll.removeEverySecond();
    ll.printElements();
    return 0;
}