#include <iostream>
#include <vector>

using namespace std;

#define max_size 100005


int get_winner(int b, int n){
    if(b == 0 && n == 9){
        return 0;
    }else if(b == 9 && n == 0){
        return 1;
    }else if(b > n){
        return 0;
    }else{
        return 1;
    }
}

struct card_stack{
    int cards[10];
    int top, bottom;

    card_stack(){
        top = -1;
        bottom = 0;
    }

    bool isEmpty(){
        return top == -1;
    }

    void addCard(int x){
        if(isEmpty()){
            top = 0;
            bottom = 0;
        }
        else if(bottom == 10 - 1){
            bottom = 0;
        }else{
            bottom++;
        }
        cards[bottom] = x;
    }

    void removeCard(){
        if(top == bottom){
            top = -1;
            bottom = -1;
        }else if(top == 10 - 1){
            top = 0;
        }else{
            top++;
        }
    }

    int getTopCard(){
        return cards[top];
    }
};

int main(){
    int curr, num_turns = 0;
    int first[5], second[5];
    card_stack boris, nursik;

    for(int i = 0; i < 5; i++){
        cin >> first[i];
    }
    for(int i = 0; i < 5; i++){
        cin >> second[i];
    }
    for(int i = 0; i < 5; i++){
        boris.addCard(first[i]);
    }
    for(int i = 0; i < 5; i++){
        nursik.addCard(second[i]);
    }

    while(true){
        if(num_turns > 1000000){
            cout << "blin nichya";
            break;
        }else if(boris.isEmpty()){
            cout << "Nursik " << num_turns;
            break;
        }else if(nursik.isEmpty()){
            cout << "Boris " << num_turns;
            break;
        }else{
            int boris_card = boris.getTopCard();
            int nursik_card = nursik.getTopCard();

            int res = get_winner(boris_card, nursik_card);

            if(res == 0){
                nursik.removeCard();
                boris.removeCard();
                boris.addCard(boris_card);
                boris.addCard(nursik_card);
            }else{
                boris.removeCard();
                nursik.removeCard();
                nursik.addCard(boris_card);
                nursik.addCard(nursik_card);
            }
            num_turns++;
        }
    }
    return 0;
}