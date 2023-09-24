#include <iostream>

using namespace std;


struct char_stack{
    char a[100000];
    int n;

    char_stack(){
        n = 0;
    }

    bool empty(){
        return n == 0;
    }

    bool size(){
        return n;
    }

    void push(char c){
        a[n++] = c;
    }

    void pop(){
        if(empty()){
            cout << "queue is empty" << endl;
            exit(0);
        }
        n--;
    }

    char top(){
        if(empty()){
            cout << "queue is empty" << endl;
            exit(0);
        }
        return a[n-1];
    }

    string get_string(){
        string s = "";
        while(!empty()){
            s += top();
            pop();
        }
        return s;
    }
};

int main(){
    char_stack a, b;
    string s1, s2;
    cin >> s1;
    cin >> s2;

    for(int i = 0; i < s1.size(); i++){
        if(s1[i] == '#'){
            if(!a.empty()){
                a.pop();
            }
        }else{
            a.push(s1[i]);
        }
    }
    for(int i = 0; i < s2.size(); i++){
        if(s2[i] == '#'){
            if(!b.empty()){
                b.pop();
            }
        }else{
            b.push(s2[i]);
        }
    }
    if(a.get_string() == b.get_string()){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}