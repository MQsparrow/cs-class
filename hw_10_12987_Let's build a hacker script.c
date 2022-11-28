#include <stdio.h>
#include <string.h>

char s[30], p[30], ans[30];
int len_s, len_p, can = 0;

void check(int idx_s, int idx_p, int len);

int main(){
    scanf("%s %s", s, p);
    len_s = strlen(s);
    len_p = strlen(p);
    check(0, 0, 0);
    if(!can) printf("What the hack!?\n");

    return 0;
}

void check(int idx_s, int idx_p, int len){
    if(idx_s == len_s){
        if(idx_p == len_p){
            can = 1;
            for(int i = 0; i<len-1; i++) printf("%c", ans[i]);
            if(ans[len-1] != ' ') printf("%c\n", ans[len-1]);
            else printf("\n");
        }
        return;
    }
    else if(idx_p == len_p){
        if(idx_s == len_s){
            can = 1;
            for(int i = 0; i<len-1; i++) printf("%c", ans[i]);
            if(ans[len-1] != ' ') printf("%c\n", ans[len-1]);
            else printf("\n");
        }
        return;
    }
    else if(p[idx_p] == '#'){
        ans[len] = s[idx_s]; len++;
        ans[len] = ' ';
        check(idx_s+1, idx_p+1, len+1);
        check(idx_s+1, idx_p, len);
    }
    else if(s[idx_s] == p[idx_p]) check(idx_s+1, idx_p+1, len);
    else return;
}
