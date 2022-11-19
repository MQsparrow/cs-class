#include <stdio.h>
#include <math.h>
#include <limits.h>

int same(int n, int m);
int max(int a, int b);
int dp[1010][1010] = {0};
char org[1010], rev[1010];

int main(){
    int n, m;
    scanf("%d %d ", &n, &m);
    for(int i = 0; i<n; i++){
        scanf("%c", &org[i]);
        rev[n-i-1] = org[i];
    }
    if(n-same(n, n) <= m) printf("Yes\n");
    else printf("No\n");

    return 0;
}

int max(int a, int b){
    if(a<b) return b;
    else return a;
}

int same(int n, int m){
    if(n == 0 || m == 0) dp[n][m] = -1;
    else{
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(org[i] == rev[j]){
                    if(!dp[i][j]) same(i, j);
                    if(!(dp[i][j]+1)) dp[i+1][j+1] = 1;
                    else dp[i+1][j+1] = dp[i][j] + 1;
                }
                else{
                    if(!dp[i+1][j]) same(i+1, j);
                    if(!dp[i][j+1]) same(i, j+1);
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
    }

    return dp[n][m];
}
