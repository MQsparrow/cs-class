unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k){
    unsigned* lk;
    unsigned** lm;
    unsigned*** ln;
    lk = (unsigned*)malloc(sizeof(unsigned)*n*m*k);
    lm = (unsigned**)malloc(sizeof(unsigned*)*n*m);
    ln = (unsigned***)malloc(sizeof(unsigned**)*n);
    for(unsigned i = 0; i<n; i++){
        ln[i] = (lm+i*m);
        for(unsigned j = 0; j<m; j++)
            lm[i*m+j] = lk+(i*m+j)*k;
    }
    return ln;
}

void delete_3d_array(unsigned ***arr){
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}
