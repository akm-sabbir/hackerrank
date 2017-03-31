#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string str;
    int arr[26];
    cin >> str;
    for (int i = 0 ; i < 26 ;i++)
        arr[i] = 0;
    int rem = -1;
    for (int i = 0; i < str.size();i++){
        arr[str[i]-97]++;
        if(rem < 0)
            rem = str[i]-97;
    }
    
    int base = arr[rem];
    int count = 0;
    for( int i = rem; i < 26;i++){
        
        if(arr[i] > 0 && abs(base - arr[i])>=1) count++;
    }
   
    if(count > 1)
       cout << "NO";
    else cout <<"YES";
    cout << endl;
    return 0;
}
