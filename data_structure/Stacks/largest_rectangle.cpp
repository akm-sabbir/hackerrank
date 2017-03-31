#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool myfn(long i, long j) { return i<j; }
#define MAX 100099
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    long arr[MAX];
    vector<long> result;
    result.reserve(MAX*2);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    long center = 1;
    //result.push_back(arr[0]);
    long prev_height = arr[0];
    long rwidth = 0;
    long lwidth = 0;
    while(center < N){
       rwidth = 0;
       lwidth = 0;
       for (int i = center -1 ; i >=0;i-- ){
           if(arr[i] >= arr[center])
               lwidth += 1;
           else
               break;
       }
        for(int i = center + 1; i < N;i++){
            if(arr[i] >= arr[center])
                rwidth += 1;
            else
                break;
        }
        if((rwidth+lwidth+1)*arr[center] > prev_height)
            prev_height = (rwidth+lwidth+1)*arr[center];
        center++;
    }
    
    cout << prev_height <<endl;
    return 0;
}
