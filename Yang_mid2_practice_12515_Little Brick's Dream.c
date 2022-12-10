#include <stdio.h>
#include <string.h>

int a[10000010] = {0}, ans[10000010] = {0}, max = 0, max_idx = 0, cnt = 0;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; i++){
        int sum = 0;
        scanf(" %d", &a[i]);
        if(max <= a[i]){
            sum = i;
            max = a[i];
            max_idx = i;
        }
        else{
            for(int j = i-1; max_idx<j; j--){
                if(a[j]<=a[i]) sum++;
                else break;
            }
        }
        if(sum == m){
            ans[cnt] = i+1;
            cnt++;
        }
    }

    if(!cnt) printf("ouo\n");
    else{
        for(int i = 0; i<cnt-1; i++) printf("%d ", ans[i]);
        printf("%d\n", ans[cnt-1]);
    }

    return 0;
}
