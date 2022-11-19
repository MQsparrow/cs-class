#include <stdio.h>

void eat(int num);
int c[30] = {0}, rec[30] = {0}, can = 0;
int n, m;

int main(){
    scanf("%d %d ", &n, &m);
    for(int i = 0; i<n; i++) scanf("%d", &c[i]);
    for(int i = 0; i<n; i++){
        eat(i);
        if(can) break;
    }
    if(can) printf("YES\n");
    else printf("NO\n");

    return 0;
}

void eat(int num){
    if(num == 0) return;
    else{
        for(int i = 0; i<n-num; i++){
            int sum = 0;
            for(int j = i; j<=i+num; j++) sum+=c[j];
            for(int j = i; j<=i+num; j++){
                if(sum-c[j] == m){
                    can = 1;
                    return;
                }
            }
        }
    }
}
