#include<iostream>
using namespace std;


int main(){
int n;
cin>>n;
int p,v,t,c = 0;
for(int i = 0;i<n;i++){
	cin>>p>>v>>t;
	if(p+v+t>=2){
		c++;
	}
}
cout<<c;
}

