#include <stdio.h>
#include <math.h>

void draw(int n, int a, int b);
void ws(int n, int a, int b);
void bl(int n, int a, int b, int num);

char carpet[10000][10000];

int main(){
    int n;
    scanf("%d", &n);
    draw(n, 0, 0);
    int len = pow(2, n+1);
    for(int i = 0; i<len; i++){
        for(int j = 0; j<len; j++) printf("%c", carpet[i][j]);
        printf("\n");
    }

    return 0;
}

void draw(int n, int a, int b){
    if(n == 1){
        for(int i = 0; i<4; i++){
            if(!(i%3)){
                carpet[a+i][b] = carpet[a+i][b+3] = '.';
                carpet[a+i][b+1] = carpet[a+i][b+2] = '#';
            }
            else carpet[a+i][b] = carpet[a+i][b+1] = carpet[a+i][b+2] = carpet[a+i][b+3] = '#';
        }
    }
    else if(!(n%2)){
        int len = pow(2, n);
        draw(n-1, a, b); draw(n-1, a+len, b);
        draw(n-1, a, b+len); draw(n-1, a+len, b+len);
    }
    else{
        int len = pow(2, n-1);
        draw(n-1, a+len, b+len);
        ws(len, a, b); ws(len, a+len*3, b);
        ws(len, a, b+len*3); ws(len, a+len*3, b+len*3);
        bl(len, a+len, b, 1); bl(len, a+len*2, b, 0);
        bl(len, a, b+len, 2); bl(len, a, b+len*2, 0);
        bl(len, a+len*3, b+len, 3); bl(len, a+len*3, b+len*2, 1);
        bl(len, a+len, b+len*3, 3); bl(len, a+len*2, b+len*3, 2);
    }
}

void ws(int n, int a, int b){
    for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) carpet[a+i][b+j] = '.';
}

void bl(int n, int a, int b, int num){
    for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) carpet[a+i][b+j] = '#';
    if(!num) for(int i = 0; i<n/2; i++) for(int j = 0; j<n/2; j++) carpet[a+i][b+j] = '.';
    else if(num == 1) for(int i = 0; i<n/2; i++) for(int j = 0; j<n/2; j++) carpet[a+i+n/2][b+j] = '.';
    else if(num == 2) for(int i = 0; i<n/2; i++) for(int j = 0; j<n/2; j++) carpet[a+i][b+j+n/2] = '.';
    else if(num == 3) for(int i = 0; i<n/2; i++) for(int j = 0; j<n/2; j++) carpet[a+i+n/2][b+j+n/2] = '.';
}
