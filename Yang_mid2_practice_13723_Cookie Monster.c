#include <stdio.h>
#include <string.h>

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int more7(char str1[300], char str2[300]){
    int len1 = strlen(str1), len2 = strlen(str2);
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i<len1; i++) if(str1[i] == '7') sum1++;
    for(int i = 0; i<len2; i++) if(str2[i] == '7') sum2++;
    if(sum2 < sum1) return 0;
    else if(sum1 < sum2) return 1;
    else return -1;
}

int max(char str1[300], char str2[300]){
    if(strlen(str2) < strlen(str1)) return 0;
    else if(strlen(str1) < strlen(str2)) return 1;
    else{
        int len = strlen(str1);
        for(int i = 0; i<len; i++){
            if(str2[i] < str1[i]) return 0;
            else if(str1[i] < str2[i]) return 1;
        }
    }
}

int main(){
    char ans[1010][300];
    for(int i = 0; i<1010; i++) ans[i][0] = '\0';
    int n, m, num, ord[1010] = {0}, eat[1010] = {0};
    scanf("%d%d", &n, &m); num = n;
    while(num--){
        ord[n-num-1] = n-num-1;
        char s[300], temp[300];
        scanf("%s", s);
        int len = strlen(s);
        for(int i = 0; i<=len; i++){
            int cnt = 0;
            while(s[i] != '|' && s[i] != '\0'){
                temp[cnt] = s[i];
                cnt++; i++;
            } cnt--;
            int sum = 0;
            for(int i = 0; i<=cnt; i++){
                if('0' <= temp[cnt-i] && temp[cnt-i] <= '9')
                    sum+=(temp[cnt-i]-'0')*pow(16, i);
                else sum+=(10+temp[cnt-i]-'A')*pow(16, i);
            }
            int t = sum; cnt = 0;
            while(t){
                cnt++; t/=10;
            } temp[cnt] = '\0'; cnt--;
            for(int i = 0; i<=cnt; i++){
                temp[cnt-i] = '0'+sum%10;
                sum/=10;
            }
            strcat(ans[n-num-1], temp);
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(more7(ans[ord[i]], ans[ord[j]]) == 1) swap(&ord[i], &ord[j]);
            else if(more7(ans[ord[i]], ans[ord[j]]) == -1){
                if(max(ans[ord[i]], ans[ord[j]])) swap(&ord[i], &ord[j]);
            }
        }
    }

    for(int i = 0; i<m; i++) eat[i] = ord[i];
    for(int i = 0; i<m; i++){
        for(int j = i+1; j<m; j++){
            if(!max(ans[eat[i]], ans[eat[j]])) swap(&eat[i], &eat[j]);
        }
    }

    for(int i = 0; i<m; i++) printf("%s\n", ans[eat[i]]);

    return 0;
}
