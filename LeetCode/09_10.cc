//Sort the Matrix Diagonal

class Solution {
public:
    
    void solve(int l,int r,vector<vector<int>> &mat){
        vector<int>tmp;
        int x_size = mat.size();
        int y_size = mat[0].size();
        int i = l;
        int j = r;
        
        while(i<x_size && j < y_size){
            tmp.push_back(mat[i][j]);
            i++;
            j++;
        }
        sort(tmp.begin(),tmp.end());
        int k = 0;
        i = l;
        j = r;
        while(i<x_size && j<y_size){
            mat[i][j] = tmp[k];
            i++;
            j++;
            k++;
        }
        
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int x_size = mat.size();
        int y_size = mat[0].size();
        
      
        for(int i = 0;i<x_size;i++){
            solve(i,0,mat);
        }
        for(int j = 1;j<y_size;j++){
            solve(0,j,mat);
        }
        
        return mat;
    }
};
// Print Subset
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> ans;
        for(int i = 0;i<(1<<n);i++){
            vector<int> subset;
            for(int j = 0;j<n;j++){
                if(i&(1<<j)){
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
            subset.clear();
        }
        
        return ans;
    }

};