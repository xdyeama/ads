#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x,ListNode *next) : val(x), next(next) {}
};


struct circularLL{
    ListNode  *head, *temp;

    circularLL(){
        head -> val = "";
        head -> next = 0;
        temp = head;
    }

    void pushFront(string word){
        ListNode *newNode;
        newListNode -> val = word;
        newListNode -> next = head;
    }

    void pushBack(string word){
        ListNode *newNode;
        newListNode -> val = word;
        newListNode -> next = 0;
        temp = head;
        while(temp){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }

    string deleteBack(){
        temp = head;
        while(temp -> next -> next != 0){
            temp = temp -> next;
        }
        string val = temp -> next -> val;
        temp -> next = 0;
        return val;
    }

    void printLL(){
        temp = head;
        while(temp){
            cout << temp -> val << " ";
            temp = temp -> next;
        }
    }
};



int main(){
    int n, k;
    cin >> n >> k;
    circularLL ll;

    ListNode *head = new ListNode();
    ListNode *temp = temp;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;  
        ListNode *newNode = new ListNode()
    }
    for(int i = 0; i < k; i++){
        string newListNodeVal = ll.deleteBack();
        ll.pushFront(newListNodeVal);
    }

    ll.printLL();

    return 0;
}