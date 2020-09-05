#include<iostream>
#include<bitset>
using namespace std;

#define N 20
int board[N][N] = {};

// For printing table
void printboard(int n){
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
  return true;   // exit condition if search reaches (n,n) block
}
for(int c = 0 ;c<n;c++){
  bool cc = check(board,n,r,c);
  if(cc){                      // check to place
    board[r][c] = 1;           // if possible, place
    bool newpath = nqueen(n,r+1); // go to next row
    if(newpath){                  // if ended search return true,block(n,n) not reached but all option exhausted
      return true;
    }
    board[r][c] = 0;              //otherwise backtrack at last to previous queen block
  }
}
return false;
}

//Print possible solutions

bitset<30>col,d1,d2;
void search(int r,int n,int &count){
  if(r==n){
    count ++;
    return;
  }
  for(int c = 0;c<n;c++){
    if(!col[c] && !d1[r+c] && !d2[r-c+n-1]){
      col[c] = d2[r-c+n-1] = d1[r+c] = 1;
      search(r+1,n,count);
      col[c] = d2[r-c+n-1] = d1[r+c] = 0;
    }
  }
}
int main(){
  int n;
  cin>>n;
  //n = 4;
  //printboard(n);
  // bool c = nqueen(n,0);
  // if(c){
  //   printboard(n);
  // }else if(n<=3){
  //   cout<< "Not a valid board size \n";
  // }
  int ans = 0;
  search(0,n,ans);
  cout<<ans << " ";
}
