int solver(int **ptr, int *sum, char *s){
    int len = strlen(s), cnt = 0;
    for(int i = 0; i<len; i++){
        if(*(s+i) == '-' || ('0' <= *(s+i) && *(s+i) <= '9')){
            int temp = 0, sign = 1;
            if(*(s+i) == '-'){
                i++;
                sign = -1;
            }
            while('0' <= *(s+i) && *(s+i) <= '9'){
                temp*=10;
                temp+=(*(s+i)-'0');
                i++;
            }
            temp*=sign;
            **(ptr+cnt) = temp;
            cnt++;
            i--;
        }
    }
    for(int i = 0; i<cnt; i++) *sum+=(**(ptr+i));
    return cnt;
}
