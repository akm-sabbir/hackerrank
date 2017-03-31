#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<stack>
#include <algorithm>
#include<sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string str;
    stack<long> stacks;
    stack<long> backup;
	getline(cin, str);
	//int table[100][30];
	std::string::size_type sz;
	int N = std::stoi(str, &sz);
	string op, s;
	int setting = 0;
    //long max = -1;
    long number2;
	while (N--){
		getline(cin, str);
        stringstream ss(str);
        ss >> op ;
        int number1 = std::stoi(op, &sz);
        
       
        if(number1 == 1){
            ss >> s;
            number2 = std::stol(s,&sz);
            if(backup.empty() || backup.top() <= number2){
                backup.push(number2);
            }
            stacks.push(number2);
        }
        else if(number1 == 2){
            if(!stacks.empty()){
                if(stacks.top() == backup.top())
                    backup.pop();
                stacks.pop();
            }
        }
        else
            cout << backup.top() << endl;
    
    }
    return 0;
}
