#include <stdio.h>
#include <math.h>
#include <limits.h>

void walk(int x, int y, int steps);
char path[510][510];
int n, m, at[510][510] = {0}, max;

int main(){
    int num;
    scanf("%d", &num);
    while(num--){
        max = INT_MAX;
        int check = 1, sx, sy;
        scanf(" %d %d", &n, &m);
        for(int i = 0; i<n; i++){
            scanf("%s", path[i]);
            if(check){
                for(int j = 0; j<m; j++){
                    if(path[i][j] == 'S'){
                        check = 0;
                        sx = i; sy = j;
                        break;
                    }
                }
            }
        }
        walk(sx, sy, 0);
        if(max == INT_MAX) printf("-1\n");
        else printf("%d\n", max);
    }

    return 0;
}

void walk(int x, int y, int steps){
    at[x][y] = 1;
    if(path[x][y] == 'F'){
        if(steps<max) max = steps;
        at[x][y] = 0;

        return;
    }
    else if(max<=steps){
        at[x][y] = 0;

        return;
    }
    if(x+1<n && (path[x+1][y] == '$' || path[x+1][y] == 'F')&& !at[x+1][y]) walk(x+1, y, steps+1);
    if(y+1<m && (path[x][y+1] == '$' || path[x][y+1] == 'F')&& !at[x][y+1]) walk(x, y+1, steps+1);
    if(0<=x-1 && (path[x-1][y] == '$' || path[x-1][y] == 'F') && !at[x-1][y]) walk(x-1, y, steps+1);
    if(0<=y-1 && (path[x][y-1] == '$' || path[x][y-1] == 'F') && !at[x][y-1]) walk(x, y-1, steps+1);
    at[x][y] = 0;

    return;
}
