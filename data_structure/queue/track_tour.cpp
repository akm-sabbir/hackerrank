#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long tank = 0;
    long petrol, dist;
    int N;
    int startP = 0;
    int tracker = 0;
    cin >> N;
    while(N--){
        
        cin >> petrol >> dist;
        tank += (petrol - dist);
        tracker++;
        if(tank < 0){
            tank = 0;
            startP = tracker;
        }
        
    }
    cout << startP << endl;
    return 0;
}
