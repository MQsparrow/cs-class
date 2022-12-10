#include <stdio.h>
#include <string.h>

char alf[26][6] = {
    "*-\0", "-***\0", "-*-*\0", "-**\0", "*\0",
    "**-*\0", "--*\0", "****\0", "**\0", "*---\0",
    "-*-\0", "*-**\0", "--\0", "-*\0", "---\0",
    "*--*\0", "--*-\0", "*-*\0", "***\0", "-\0",
    "**-\0", "***-\0", "*--\0", "-**-\0", "-*--\0", "--**\0"
};

int find(char t[6], int len);

int main(){
    int n, ttl = 0, len_t = 0, cnt, num;
    char s[1010], temp[6], ans[1010];
    memset(temp, 0, 6);
    memset(s, 0, 1010);
    memset(ans, 0, 1010);
    scanf("%d", &n);
    scanf("%s", s);
    for(int i = 0; i<n; i++){
        cnt = 0;
        if(s[i] == '='){
            while(s[i] == '='){
                cnt++; i++;
            }i--;
            if(cnt == 1) temp[len_t] = '*';
            else if(cnt == 3) temp[len_t] = '-';
            len_t++;
        }
        else if(s[i] == '.'){
            while(s[i] == '.'){
                cnt++; i++;
            } i--;
            if(cnt != 1){
                ans[ttl] = 'A'+find(temp, len_t);
                ttl++; len_t = 0;
                memset(temp, 0, 6);
                if(cnt != 3){
                    ans[ttl] = ' ';
                    ttl++;
                }
            }
        }
    }

    ans[ttl] = 'A'+find(temp, len_t);
    ttl++;

    while(ans[ttl-1] == ' ') ttl--;
    ans[ttl] = '\0';
    printf("%s\n", ans);

    return 0;
}

int find(char t[6], int len){
    for(int i = 0; i<26; i++){
        int is = 1, ln = strlen(alf[i]);
        if(ln == len){
            for(int j = 0; j<len; j++){
                if(t[j] != alf[i][j]){
                    is = 0;
                    break;
                }
            }
        }
        else is = 0;
        if(is) return i;
    }
}
