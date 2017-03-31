#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<long> result;
    result.reserve(105);
    map<long,long> cont1,cont2;
    int N;
    int value;
    cin >> N;
    while(N--){
        cin >>value;
        if(cont1.find(value) == cont1.end()){
            cont1.insert(make_pair(value,1));
        }else
            cont1[value]++;
    }
    cin >> N;
    while(N--){
        cin >> value;
        if(cont2.find(value) == cont2.end()){
            cont2.insert(make_pair(value,1));
        }else
            cont2[value]++;
    }
    for(map<long,long>::iterator it = cont2.begin(); it!=cont2.end();it++)
        if(cont1.find(it->first) == cont1.end())
            result.push_back(it->first);
        else if(it->second != cont1[it->first])
            result.push_back(it->first);
    sort(result.begin(),result.end());
    for(int i = 0 ; i < result.size();i++)
        if(i!= result.size() - 1)
        cout << result[i] << " ";
    cout<<result[result.size()-1]<<endl;
    return 0;
}
