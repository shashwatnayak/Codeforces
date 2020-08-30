#include<iostream>
using namespace std;

//obtain remainder
int one(int n,int s){
if(n>s){
return s;
}
return !n;
}

//check if power of two
int two(int s){
if(s==1){
  return false;
}
int q = !s;
int p = q & s;
if(p==0){
  return true;
}
return false;
}
// off last set bit
int three(int n){
return n & (n-1);
}
// off last zero bit
int four(int n){
return n | (n+1);
}
// int five(int n,int s){
//
// }
// int six(int n,int s){
//
// }

// nth grey code
int seven(int n){
if(n == 0 ){
  return 0;
}
return n ^ (n>>1);

}
// int eight(int n,int s){
//
// }
int main(){
int n,s;

// scanf("%d %d",&s,&n);
// printf("s - %d \nn - %d \n",s,n);
//
// int a1 = one(n,s);
// cout<<a1<<endl;
// scanf("%d\n",&s);
// int a2 = two(s);
// cout<<a2<<endl;

// scanf("%d\n",&s);
// int a3 = three(s);
// cout<<a3<<endl;

// scanf("%d\n",&s);
// int a4 = four(s);
// cout<<a4<<endl;
}
