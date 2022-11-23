#include <stdio.h>

int num, basket, max = 0;
int weight[30] = {0}, value[30] = {0};
void chose(int n, int w_sum, int v_sum);

int main(void){
    scanf("%d", &num);
    for(int i = 0; i<num; i++) scanf("%d", &weight[i]);
    for(int i = 0; i<num; i++) scanf("%d", &value[i]);
    scanf("%d", &basket);
    chose(0, 0, 0);

    printf("%d\n", max);

    return 0;
}

void chose(int n, int w_sum, int v_sum){
    if(num==n) return;
    for(int i = n; i<num; i++){
        if(w_sum+weight[i]<=basket && max<v_sum+value[i])
            max = v_sum+value[i];
        if(w_sum+weight[i]<=basket)
            chose(i+1, w_sum+weight[i], v_sum+value[i]);
    }
    return;
}
