#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}
#define MAX 200000
int  visited[MAX];
int counter;
void init(){
    
    for(long i = 0 ; i < MAX;i++)
        visited[i]=0;
}
void dfs(vector<vector<int>> &pairs, int elem){
    visited[elem]=1;
    for(long i = 0; i< pairs[elem].size();i++){
        if(visited[pairs[elem][i]] == 0){
            counter+=1;
            dfs(pairs,pairs[elem][i]);
        }
    }
    return;
}
int main()
{ 
    int N, I;
    cin >> N >> I;
    
    init();
    vector<vector<int> > pairs(N);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
 
    long long result = 0;
    
    /** Write code to compute the result using N,I,pairs **/
    vector<int>r;
    for (long i = 0; i < N;i++){
        counter = 0;
        if(visited[i] == 0){
            counter+=1;
            dfs(pairs,i);
            r.push_back(counter);
        }
        
    }
    
    long countering = 1;
    for (int i =0;i < r.size();i++){
        result+= r[i]*(N-r[i]);
        N-=r[i];
    }
    cout << result << endl;
    return 0;
}
