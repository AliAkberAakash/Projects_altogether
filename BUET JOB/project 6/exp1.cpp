int select(int *a, int s, int e, int k){

    if(e-s+1 <= 5){
        sort(a+s, a+e);
        return s+k-1;
    }

    for(int i=0; i<(e+1)/5; i++){
        int left = 5*i;
        int right = left + 4;
        if(right > e) right = e;
        int median = select(a, 5*i, 5*i+4, 3);
        swap(a[median], a[i]);
    }

    return select(a, 0, (e+1)/5, (e+1)/10);
}
