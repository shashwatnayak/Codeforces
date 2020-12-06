#include<iostream>
#include<string>
using namespace std;


// Not tested
class TrieNode{
    public:
        TrieNode *child[26];
        bool is_end;
    TrieNode(){
        for(int i = 0;i<26;i++){
            child[i] = NULL;
        }
        is_end = false;
    }
};

void insert(TrieNode *root, string key){
TrieNode *tmp = root;
for(int i = 0;i<key.size();i++){
    int idx = key[i] - 'a';
    if(!tmp->child[idx]){
        tmp->child[i] = new TrieNode();
    }
    tmp = tmp->child[idx];
}
tmp->is_end = true;
}
bool search(TrieNode *root,string key){
 TrieNode *tmp = root;
for(int i = 0;i<key.size();i++){
    int idx = key[i] - 'a';
    if(!tmp->child[idx]){
        return false;
    }
    tmp = tmp->child[idx];
}
return (tmp !=NULL && tmp->is_end);
}
int main(){
string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
int n = sizeof(keys)/sizeof(keys[0]); 

TrieNode * root = new TrieNode();

for(int i = 0;i<n;i++){
    insert(root,keys[i]);
}

cout << search(root,"any");
cout << "\n";
cout<< search(root,"their");
return 0;
}