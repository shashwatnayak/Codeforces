#include<iostream>
using namespace std;

int main(){
	string a;
	int c = 0;
	int n;
	cin>>n;
	while(n--){
		cin>>a;
		if(a == "++X"){
			++c;
		}else if(a == "X++"){
			c++;
		}else if(a == "--X"){
			--c;
		}else{
			c--;
		}
	}
	cout<<c;
	return 0;
}