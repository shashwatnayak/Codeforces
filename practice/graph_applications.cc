#include<iostream>
#include<bitset>
#define N 20
using namespace std;

int board[N][N] = {};
int knightBoard[N][N] = {};
//N queens
void printboard(int board[][N],int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<< board[i][j] << " ";
        }
        cout<<"\n";
    }
}

// Technique to traverse diagonals
int xrow[] = {1,-1,-1,1};
int yrow[] = {1,1,-1,-1};
bool check(int board[][N],int n,int r, int c){
// row and col search
for(int i = 0;i<n;i++){
  if(board[r][i]==1)return false;
  if(board[i][c]==1)return false;
}
// diagonal search
for(int j = 0;j<4;j++){
  for(int i = 0;i<=n;i++){
    int updx = r - i*xrow[j];
    int updy = c - i*yrow[j];
  if(updx>=0 & updx < n && updy >=0 && updy < n && board[updx][updy] == 1){
    return false;
  }
  }
}
return true;
}

bool nqueen(int n,int r){
    if(n==r){
        return true;
    }

    for(int c=0;c<n;c++){
        bool safe = check(board,n,r,c);
        if(safe){
            board[r][c] = 1;
            bool next = nqueen(n,r+1);
            if(next){
                return true;
            }
            board[r][c] = 0;
        }
    }
    return false;
}

//Declare 3 bitsets to maintain count for columns and diagonals
bitset<30>col,diag1,diag2;
void countNqueen(int n,int r,int &c){
    if(n==r){
        c++;
        return;
    }
    for(int c = 0;c<n;c++){
        if(!col[c] && !diag1[r+c] && diag2[r-c+n-1]){
            col[c] = diag1[r+c] = diag2[r-c+n-1] = 1;
            countNqueen(n,r+1,c);
            col[c] = diag1[r+c] = diag2[r-c+n-1] = 0;
        }
    }
}

//Knight Tour
bool checkVal(int x,int y,int c,int n){
if(x>=0 && x<(n*n) && y>=0 && y<(n*n)){
    return true;
}
return false;
}
int row[] = {1,2,2,1,-1,-2,-2,-1};
int col[] = {2,1,-1,-2,-2,-1,1,2};
void knightTour(int oldx,int oldy,int &c,int n){
    if(c==n*n){
        printboard(knightBoard,n);
        return;
    }
    for(int i = 0;i<8;i++){
        int newx = oldx + row[i];
        int newy = oldy + col[i];
        if(checkVal(newx,newy,c,n)){
            knightBoard[newx][newy] = c++;
            knightTour(newx,newy,c,n);
            knightBoard[newx][newy] = 0; 
        }
    }
}
int main(){
int n;
cin>>n;
// bool a = nqueen(n,0);
// if(a){
//     printboard(board,n);
// }else{
//     cout<< "No possible board"<<"\n";
// }

knightTour(0,0,1,n);
}


//Connectivity Check 
//Bi-partite
//Cycle Detection
//Hamiltonion Path
//Eulerian Path
