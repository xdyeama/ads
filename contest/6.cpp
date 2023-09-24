#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v;

void setInitGroups(){
    for(int i = 0; i < v.size(); i++){
        v[i][i] = 1;
    }
}


void combineOp(int x, int y){
    v[x][y] = 1;
    v[y][x] = 1;
    v[x][x]++;
    v[y][y]++;
    for (int i = 0; i < v[x].size(); i++){
        if (v[x][i] == 1 && i != x && v[y][i] == 0){
            v[y][i] = 1;
            v[i][y] = 1;
            v[i][i]++;
        }else if(v[y][i] == 1 && i != y && v[x][i] == 0){
            v[x][i] = 1;
            v[i][x] = 1;
            v[i][i]++;
        }
    }
}

void checkOp(int x, int y){
    if(v[x][y] == 1 || v[y][x] == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

void checkSizeOp(int x){
    cout << v[x][x] << endl;
}

int main(){
    int n, m;
    cin >> n >> m;
    v = vector<vector<int> > (n, vector<int> (n, 0));
    setInitGroups();
    int w, x, y;
    for (int i = 0; i < m; i++){
        cin >> w;
        if(w == 1){
            cin >> x >> y;
            x--;
            y--;
            combineOp(x, y);
        }
        if(w == 2){
            cin >> x >> y;
            x--;
            y--;
            checkOp(x, y);
        }
        if( w == 3){
            cin >> x;
            x--;
            checkSizeOp(x);
        }
    }

}