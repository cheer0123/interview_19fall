#include <stdio.h>
#include <iostream> 
#include <vector> 
using namespace std;

bool halfP(vector<int> &A) {
    int sum = 0;
    for(int a:A) {
        sum += a;
    }
    if(sum %2 != 0) return false;
    
    // dp[i][j] := given sum j at ith element
    int n = A.size();
    vector< vector<int> > dp(n+1, vector<int>(sum/2+1, false));
    dp[0][0] = true;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum/2; j++) {
            if(A[i-1] <= j) dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i]];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum/2];
}

int main() {
    vector<int> A;
    A.push_back(4);
    A.push_back(2);
    A.push_back(8);

    bool isHalfP = halfP(A);
    cout<<isHalfP<<endl;
    return 1;
}