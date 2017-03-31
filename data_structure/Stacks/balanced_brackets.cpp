#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    stack<char> stacks;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
       
        int i = 0; 
        while(i < s.size()){
                
            if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if(stacks.empty())
                    break;
                if(stacks.top() == '(' && s[i] ==')')
                    stacks.pop();
                else if(stacks.top() == '{' && s[i] == '}')
                    stacks.pop();
                else if(stacks.top() == '[' && s[i] == ']')
                    stacks.pop();
                else
                    break;
            }
            else
                stacks.push(s[i]);
            i++;
        }
        if(!stacks.empty() || i < s.size())
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        while(!stacks.empty()) stacks.pop();
        
    }
    return 0;
}
