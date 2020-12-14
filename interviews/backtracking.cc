#include<iostream>
using namespace std;

const int n = 10;
// rat in a maze
bool check(int x,int y,int n,int mat[][n]){
if(x<0 && y < 0 && x >=n && y>=n && mat[x][y] == 0){
    return false;
}
return true;
}
bool ratmaze(bool sol[][n],int mat[][n],int x,int y,int n){
    if(x == n-1 && y == n-1 && mat[x][y] == 1 && sol[x][y] == 1){
        return true;
    }
    if(check(x,y,n,mat)){
        sol[x][y] = 1;
        // Move right
        if(ratmaze(sol,mat,x+1,y,n)){
            return true;
        }
        // Move Down
        if(ratmaze(sol,mat,x,y+1,n)){
            return true;
        }
        // otherwise backtrack
        sol[x][y] = 0;
        return false;
    }
    return false;
}
bool ratinmaze(int mat[][n],int n){
bool sol[n][n] = {};

bool res = ratmaze(sol,mat,0,0,n);
if(res){
    return true;
}
return false;
}


// Knight Tour 
// N Queen
// Permutation of string
// Find shortest safe route in a path with landmines
// Sudoku Solver
// m coloring
// combinational sum
// subset sum
void test_cases(){
    int n = 4;
    int mat[n][n] = {};
    ratinmaze(mat,n);
}
int main(){
test_cases();    
}