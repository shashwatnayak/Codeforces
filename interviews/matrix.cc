#include<iostream>
using namespace std;
#define R 3
#define C 6
#define MAX 100
void spiral_traversal(int mat[R][C],int r,int c){

int i = 0;
int j = 0;
int m = r;
int n = c;
int p = 0;
while(i < m && j <n){

for(p = j;p<m;p++){
 cout << mat[i][p] << " ";   
}
i++;

for(p=i;p<m;p++){
cout<< mat[p][n-1]<< " ";
}
n--;

if(i<m){
for(p=n-1;p>=j;p++){
    cout << mat[m-1][p] << " ";
}
}
m--;

if(j<n){
for(p = m-1;p>=i;p--){
 cout << mat[p][j]<< " ";   
}
}
j++;
}
}

void binary_search(int mat[][MAX],int i,int j_low,int j_high,int x){

while(j_low < j_high){
    int j_mid = j_low + (j_high - j_low)/2;
    if(mat[i][j_mid] == x){
        cout << i << " "<<j_mid << endl;
        return;
    }else if(mat[i][j_mid] < x){
        j_high = j_mid;
    }else{
        j_low = j_mid + 1;
    }
}
cout << "NO ELEMENT FOUND \n";

}
void search_sortedmatrix(int mat[][MAX],int n,int m,int x){
if(n==1){
    return binary_search(mat,0,0,m-1,x);
}

int i_low = 0;
int i_high = n-1;
int j_mid = m/2;

while((i_low+1) < i_high){
    int i_mid = i_low + (i_high - i_low)/2;

    if(mat[i_mid][j_mid] == x){
        cout << i_mid << " " << j_mid << endl;
        return;
    }else if(mat[i_mid][j_mid] < x){
        i_high = i_mid;
    }else{
        i_low = i_mid+1;
    }
}

if(mat[i_low][j_mid] = x){
cout << i_low << " " << j_mid << endl;
}else if (mat[i_low+1][j_mid] = x){
cout<< i_low+1 << " " << j_mid << endl;
}else if(x <= mat[i_low][j_mid-1]){
    binary_search(mat,i_low,0,j_mid-1,x);
}else if(x <= mat[i_low+1][j_mid-1]){
    binary_search(mat,i_low+1,0,j_mid-1,x);
}else if(x>=mat[i_low][j_mid+1] && x<= mat[i_low][m-1]){
    binary_search(mat,i_low,j_mid+1,m-1,x);
}else{
    binary_search(mat,i_low+1,j_mid+1,m-1,x);
}


}

void rotate_ninety(int mat[][MAX],int n){
for(int i = 0;i<n/2;i++){
    for(int j = i;j<n-i-1;j++){
        int tmp = mat[i][j];
        mat[i][j] = mat[n-1-j][i];
        mat[n-1-j][i] = mat[n-1-i][n-1-j];
        mat[n-1-i][n-1-j] = mat[j][n-1-i];
        mat[j][n-1-i] = tmp;
    }
}
}

int main(){
    
}