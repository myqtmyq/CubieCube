#pragma once

void rotate_right(vector<int> &arr, int left, int right){
    //""""Rotate array arr right between left and right.right is included."""
    int temp=arr[right];

    for(int i=right;i>left;i--)
        arr[i]=arr[i-1];
    arr[left]=temp;
}

void rotate_left(vector<int> &arr,int left,int right){
    //""""Rotate array arr left between left and right.right is included."""
    int temp=arr[left];
    for(int i=left;i<right;i++)
        arr[i]=arr[i+1];
    arr[right]=temp;
}

int c_nk(int n, int k) {
    //"""Binomial coefficient [n choose k]."""
    //int s,i,j;
    if(n<k)
        return 0;
    if(k>n/2)
        k = n - k;
    int s=1;
    int i = n;
    int j = 1;
    while(i!=n-k){
        s *= i;
        s /= j;
        i -= 1;
        j += 1;
    }
    return s;
}
