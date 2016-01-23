#include <bits/stdc++.h>

using namespace std;

int maxSubarrayProduct(int* arr,int n) {
    int mx,max_end,min_end;
    mx=max_end=min_end=arr[0];
    int i=1;
    while(i<n) {
        if(!arr[i]) {
            max_end=min_end=0;
        }
        else if(arr[i]>0) {
            max_end=max(arr[i],max_end*arr[i]);
            min_end=min(arr[i],min_end*arr[i]);
        } else {
            int temp=max_end;
            max_end=max(arr[i],min_end*arr[i]);
            min_end=min(arr[i],temp*arr[i]);
        }
        mx=max(mx,max_end);
        i++;
    }
    return mx;
}

int main()
{
	int arr[] = {1, -2, -3, 0, 7, -8, -2};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Maximum Sub array product is %d", 
			maxSubarrayProduct(arr, n));
	return 0;
}
