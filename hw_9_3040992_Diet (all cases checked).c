#include <stdio.h>

int num, cal, can = 0;
int cks[30] = {0};
void pick(int n, int sum);

int main(void){
    scanf("%d %d", &num, &cal);
    for(int i = 0; i<num; i++) scanf("%d", &cks[i]);
    pick(0, 0);

    if(can) printf("YES\n");
    else printf("NO\n");

    return 0;
}

void pick(int n, int sum){
    if(num==n) return;
    for(int i = n; i<num; i++){
        if(sum+cks[i] == cal){
            can = 1;
            return;
        }
        if(sum+cks[i]<cal) pick(i+1, sum+cks[i]);
    }

    return;
}
