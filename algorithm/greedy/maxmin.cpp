#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    vector<int> lists(N);
    for (int i=0; i<N; i++)
        cin >> lists[i];
    sort(lists.begin(),lists.end());
    int running_s = 0;
    int best_ind = 0;
    for(int i = 1 ; i <=lists.size()-K+1;i++){
        for(int j = i;j<i+K-1;j++)
            running_s+=abs(lists[j]-lists[j-1]);
        if(unfairness > running_s){
            best_ind = i;
            unfairness = running_s;
        }
        
        running_s = 0;
    }
    
    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    cout << unfairness << "\n";
    return 0;
}
