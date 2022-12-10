#include <stdio.h>
#include <string.h>

int t, n, h, p[21], dp[21][21][21][21][21][21];

int max(int x, int y) {
    return x > y ? x : y;
}

int solve(int pn, int a, int b, int c, int d, int e){//
    if(dp[pn][a][b][c][d][e] != -1) return dp[pn][a][b][c][d][e];
    if(n <= pn) return dp[pn][a][b][c][d][e] = n+1;
    int val = pn+1, tmp;
    if(p[pn] == 1){
        if(a+4<=h) val = max(val, solve(pn+1, a+4, b, c, d, e));
        if(b+4<=h) val = max(val, solve(pn+1, a, b+4, c, d, e));
        if(c+4<=h) val = max(val, solve(pn+1, a, b, c+4, d, e));
        if(d+4<=h) val = max(val, solve(pn+1, a, b, c, d+4, e));
        if(e+4<=h) val = max(val, solve(pn+1, a, b, c, d, e+4));
        tmp = max(max(a, b), max(c, d));
        if(tmp+1<=h) val = max(val, solve(pn+1, tmp+1, tmp+1, tmp+1, tmp+1, e));
        tmp = max(max(b, c), max(d, e));
        if(tmp+1<=h) val = max(val, solve(pn+1, a, tmp+1, tmp+1, tmp+1, tmp+1));
    } else if(p[pn] == 2){
        tmp = max(a, b);
        if(tmp+2<=h) val = max(val, solve(pn+1, tmp+2, tmp+2, c, d, e));
        tmp = max(b, c);
        if(tmp+2<=h) val = max(val, solve(pn+1, a, tmp+2, tmp+2, d, e));
        tmp = max(c, d);
        if(tmp+2<=h) val = max(val, solve(pn+1, a, b, tmp+2, tmp+2, e));
        tmp = max(d, e);
        if(tmp+2<=h) val = max(val, solve(pn+1, a, b, c, tmp+2, tmp+2));
    } else if(p[pn] == 3){
        tmp = max(max(a, b+1), c);
        if(tmp+2<=h) val = max(val, solve(pn+1, tmp+1, tmp+2, tmp+1, d, e));
        tmp = max(max(b, c+1), d);
        if(tmp+2<=h) val = max(val, solve(pn+1, a, tmp+1, tmp+2, tmp+1, e));
        tmp = max(max(c, d+1), e);
        if(tmp+2<=h) val = max(val, solve(pn+1, a, b, tmp+1, tmp+2, tmp+1));
    } else{
        tmp = max(max(a, b), c-1);
        if(tmp+2<=h) val = max(val, solve(pn+1, tmp+1, tmp+2, tmp+2, d, e));
        tmp = max(max(b, c), d-1);
        if(tmp+2<=h) val = max(val, solve(pn+1, a, tmp+1, tmp+2, tmp+2, e));
        tmp = max(max(c, d), e-1);
        if(tmp+2<=h) val = max(val, solve(pn+1, a, b, tmp+1, tmp+2, tmp+2));
        tmp = max(a, b+1);
        if(tmp+2<=h) val = max(val, solve(pn+1, tmp+2, tmp+1, c, d, e));
        tmp = max(b, c+1);
        if(tmp+2<=h) val = max(val, solve(pn+1, a, tmp+2, tmp+1, d, e));
        tmp = max(c, d+1);
        if(tmp+2<=h) val = max(val, solve(pn+1, a, b, tmp+2, tmp+1, e));
        tmp = max(d, e+1);
        if(tmp+2<=h) val = max(val, solve(pn+1, a, b, c, tmp+2, tmp+1));
    }
    return dp[pn][a][b][c][d][e] = val;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &h);
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i<n; i++) scanf("%d", &p[i]);
        int at = solve(0, 0, 0, 0, 0, 0);
        if(at == n+1) printf("Win\n");
        else printf("Lose at %d\n", at);
    }
}
