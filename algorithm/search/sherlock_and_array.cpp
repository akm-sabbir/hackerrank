#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100010
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int  cases;
    int n;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);
        int arr[n+1],temp[n+1];
        temp[0] = 0;
        int i;
       
        for (i = 1; i<=n; i++){
            scanf("%d",&arr[i]);
            temp[i] = arr[i] + temp[i-1];
        }
         if (n == 1){
            printf("YES\n");
            continue;
        }
        for (i = 2; i < n; i++ ){
            if((temp[n]-temp[i]) == (temp[i] - arr[i])){
                printf("YES\n");
                break;
            }
        }
        if (i == n)
            printf("NO\n");
    }
    return 0;
}
