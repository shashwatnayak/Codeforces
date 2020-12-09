#include<iostream>
#include<vector>
using namespace std;

// Catalan - Recursive
unsigned long long catalan(unsigned long long int n){
    unsigned long long int res = 0;
    for(int i = 0;i<n;i++){
        res+= catalan(i) * catalan(n-i-1);
    }

    return res;
}

// Catalan - DP
unsigned long long catalandp(unsigned long long int n){
    unsigned long long int dp[n+1];
    dp[0] = dp[1] = 1;
    for(int i = 2;i<n;i++){
        dp[i] = 0;
        for(int j = 0;j<i;i++){
            dp[i] += dp[j] * dp[n-j-1];
        }
    }
    return dp[n];
}
// Binomial Coefficient - Recursive
int binomialCoefficient(int n,int k){
    if(k>n){
        return 0;
    }
    if(k == 0 || k == n){
        return 1;
    }
    return binomialCoefficient(n-1,k) + binomialCoefficient(n-1,k-1);

}

// Binomial Coefficient - DP
int binomialdp(int n,int k){

    int dp[n+1][k+1];
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<= min(i,k);j++){
            if(i == 0 || j == i){
                dp[i][j] = 1;
            }else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[n][k];
}

// Permutation - recursive
int permutation(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*(permutation(n-1));
}

// Permutation - DP 
int permutationdp(int n){
    int dp[n+1];
    for(int i = 0;i<=n;i++){
        if(i==0 || i == 1){
            dp[i] = 1;
        }else{
            dp[i] = i*dp[i-1];
        }
    }
    return dp[n];
}
/*Coin Change Recursive*/
int CoinChange(int arr[],int m,int n){
    // Found solution, add count
    if(n==0){
        return 1;
    }
    // sum < 0, remove it;
    if(n<0){
        return 0;
    }
    // array count goes less than 0 when sum > 0, false case
    if(m<=0 && n>=1){
        return 0;
    }
    return CoinChange(arr,m-1,n) + CoinChange(arr,m,n-arr[m-1]);
}

/*Coin Change - DP*/

int CoinChangeDP(int arr[],int m,int n){
int dp[n+1][m];
for(int i = 0;i<m;i++){
    dp[0][i] = 1;
}
for(int i = 1;i<=n;i++){
    for(int j = 0;j<m;j++){
        if(i-arr[j] < 0){
            dp[i][j] = 0;
        }
        if(j<=0 || i-arr[j] >=1){
            dp[i][j] = 0;
        }
        dp[i][j] = dp[i][j-1] + dp[i-arr[j]][j];
    }
}
}

// Knapsack - Recursive
int Knapsack(int w,int wt[],int val[],int n){
    if(n == 0 || w == 0){
        return 0;
    }
    if(wt[n-1] > w){
        return Knapsack(w,wt,val,n-1);
    }else{
        return max(val[n-1] + Knapsack(w-wt[n-1],wt,val,n-1),Knapsack(w,wt,val,n-1));
    }
}
// Knapsack - Iterative
int Knapsackdp(int w,int wt[],int val[],int n){
int dp[n+1][w+1];

for(int i = 0;i <=n;i++){
    for(int j = 0;j<=w;j++){
        if(i == 0 || j == 0){
            dp[i][j] = 0;
        }else if(wt[i-1] > j){
            dp[i][j] = dp[i-1][j];
        }else{
            dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]],dp[i-1][j]);
        }
    }

    return dp[n][w];
}
}

// Edit Distance - Recursive
int editDistance(string s1,string s2,int m,int n){
if(m==0){
    return n;
}
if(n==0){
    return m;
}
if(s1[m-1] == s2[n-1]){
    return editDistance(s1,s2,m-1,n-1);
}
return (1 + min(min(editDistance(s1,s2,m-1,n),editDistance(s1,s2,m,n-1)),
        editDistance(s1,s2,m-1,n-1)));
}

// EditDistance - DP

int editDistanceDP(string s1,string s2,int m,int n){
    int dp[m+1][n+1];

    for(int i = 0;i<=m;i++){
        for(int j = 0;j<=n;j++){
            if(i == 0){
                dp[i][j] = j;
            }else if(j == 0){
                dp[i][j] = i;
            }else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1 + min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
            }

        }
    }
}

// Max Path Sum - DP only down and diagonal movement

int maxPathSum(vector<vector<int> > mat){
    int r = mat.size();
    int c = mat[0].size();
    for(int i = 1;i<r;i++){
        for(int j = 0;j<c;j++){
            if(j > 0 && j < c-1){
                mat[i][j] += max(mat[i-1][j],
                                max(mat[i-1][j-1],mat[i-1][j+1]));
            }else if(j>0){
                mat[i][j] += max(mat[i-1][j],mat[i-1][j-1]); 
            }else if(j < c - 1){
                mat[i][j] += max(mat[i-1][j],mat[i-1][j+1]); 

            }
        }
    }
    return mat[r-1][c];
}
int main(){

}