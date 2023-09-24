#include <iostream>
#include <cassert>

using namespace std;

struct node{
    int data;
    node *nxt = nullptr;  

    node(){
        data = 0;
    }

    node(int _data, node *_nxt){
        data = _data;
        nxt = _nxt;
    }
};

struct linked_list{
    node *head = nullptr;

    node* get_tail(){
        if (head == nullptr){
            return nullptr;
        }
        node* curr = head;
        while(curr -> nxt != nullptr){
            curr = curr -> nxt;
        }
        return curr;
    }

    node* get(int pos){
        node *curr = head;
        for (int i = 0; i < pos; i++){
            if(curr == nullptr){
                return nullptr;
            }
            curr = curr -> nxt;
        }
        return curr;
    }

    void insert_begin(int data){
        node *new_node = new node(data, head);
        head = new_node;
    }

    void insert_tail(int data){
        node *tail = get_tail();
        node *new_node = new node(data, nullptr);
        tail -> nxt = new_node;
    }

    void insert(int pos, int data){
        // insert at pos i means
        // put element with data at pos i
        // while moving everythin after that element to the right
        if(pos == 0){
            insert_begin(data);
            return;
        }
        node *A = get(pos - 1);
        if (A == nullptr){
            insert_tail(data);
            return;
        }
        node *B = A -> nxt;
        node *new_node = new node(data, B); // new_node -> B
        A -> nxt = new_node; // A -> new_node
    }

    void del_begin(){
        if (head == nullptr){
            return;
        }
        node *oldhead = head;
        head = head->nxt;
        delete oldhead;
    }

    void del_end(){
        if(head == nullptr){ // empty list
            return;
        }
        if(head -> nxt == nullptr){ // head is tail
            delete head;
            head = nullptr;
            return;
        }
        node *cur = head;
        while(cur->nxt->nxt != nullptr){ // search a node before the tail
            cur = cur -> nxt;
        }
        delete cur -> nxt;
        cur -> nxt = nullptr;
    }
    
    void del(int pos){
         
    }

    void output(){
        cout << "[";
        node *cur = head;
        while(cur != nullptr){
            cout << cur -> data << ", "; 
            cur = cur -> nxt;
        }
        cout << "]" << "\n";
    }
};

int main(){
    linked_list LL;
    LL.insert(0, 10);
    LL.insert(1, 20);
    LL.insert(2, 30);
    LL.insert(3, 40);

    LL.insert(2, 50); 
    LL.output();


    cout << LL.get(3) -> data << endl;
    return 0;
}