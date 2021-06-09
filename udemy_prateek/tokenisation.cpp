#include<iostream>
#include<vector>
#include<sstream>
#include<cstring>
using namespace std;


int main(){

// String tokenization using stringstream
// Break string about strings
string input;
getline(cin,input);

stringstream ss(input);

string token;
vector<string> tokens;
while(getline(ss,token,' ')){
    tokens.push_back(token);
}

for(auto token:tokens){
    cout<<token<<",";
}

// strok method > use character array

// char ch[1000];
// cin.getline(ch,1000);
// // strtok()
// // cout << strtok(ch," ") << endl; // Breakout about space
// // cout << strtok(ch," ") << endl; // will again give you same first token
// // cout << strtok(NULL," ") << endl; // will print next token, because strtok stores the ch array

// char *token = strtok(ch," ");
// while(token!=NULL){
//     cout<<token << endl;
//     token = strtok(NULL," ");
// }


return 0;    
}