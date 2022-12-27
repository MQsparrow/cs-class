#include <stdio.h>
#include <string.h>

int main(){
    char in[510], all[510];
    int len, pt; gets(in); len = 0; pt = 0;
    memset(all, 0, 500);
    char* token = strtok(in, "/");
    while(token){
        int stp = 0, ln = strlen(token);
        if(strstr(token, "left")){
            if(pt) pt--;
            stp = 4;
        }
        else if(strstr(token, "right")){
            if(pt<len) pt++;
            stp = 5;
        }
        else if(strstr(token, "newline")){
            all[pt] = '\n';
            pt++; len++; stp = 7;
        }
        else if(strstr(token, "backspace")){
            if(pt){
                for(int i = pt-1; i<len; i++) all[i] = all[i+1];
                pt--; len--;
            }
            stp = 9;
        }
        if(pt == len){
            for(int i = stp; i<ln; i++){
                all[pt] = token[i];
                pt++; len++;
            }
        }
        else{
            char temp[510];
            strncpy(temp, all, pt);
            int tp = pt;
            for(int i = stp; i<ln; i++){
                temp[tp] = token[i];
                tp++;
            }
            int tl = tp;
            for(int i = pt; i<len; i++){
                temp[tl] = all[i];
                tl++;
            }
            pt = tp;
            len = tl;
            strcpy(all, temp);
        }
        token = strtok(NULL, "/");
    }
    all[len] = '\0';
    printf("%s", all);

	return 0;
}
