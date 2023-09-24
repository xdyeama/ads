#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define max_size 100005


int main(){
    int size;
    cin >> size;
    string input;
    cin >> input;

    queue<char> data;

    int scount = 0;
    int kcount = 0;

    for(int i = 0; i < size; i++){
        data.push(input[i]);
        if(input[i] == 'S'){
            scount++;
        }else{
            kcount++;
        }
    }

    int kSkipcount = 0;
    int sSkipcount = 0;


    while(scount > 0 && kcount > 0){
        char el = data.front();
        if(el == 'S'){
            if(sSkipcount > 0){
                sSkipcount--;
                scount--;
            }else{
                kSkipcount++;
                data.push(el);
            }
        }else{
            if(kSkipcount > 0){
                kSkipcount--;
                kcount--;
            }else{
                sSkipcount++;
                data.push(el);
            }
        }
        data.pop();
    }


    if(data.front() == 'K'){
        cout << "KATSURAGI" << endl;
    }else{
        cout << "SAKAYANAGI" << endl;
    }
}