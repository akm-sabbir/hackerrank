#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<sstream>
#include<stack>
using namespace std;

stack<pair<string,int>> stacks;
string container;
pair<string,int> append(string str){
    container.append(str);
    //stacks.push(make_pair(str,1));
    return make_pair(str,1);
}
pair<string,int> deletes(int k){
    string sub = container.substr(container.size()-k,container.size());
   // stacks.push(make_pair(sub,2));
    container = container.substr(0,container.size()-k);
    return make_pair(sub,2);
}
void undo(){
    pair<string,int> temp = stacks.top();
    if(temp.second == 1)
        deletes(temp.first.size());
    if(temp.second == 2)
        append(temp.first);
    stacks.pop();
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
	string str;
	getline(cin, str);
	//int table[100][30];
	std::string::size_type sz;
	N = std::stoi(str, &sz);
	string op, s;
	//cout << N << endl;
	//trieTree<int> *root = new trieTree<int>(30);
	//root->init();
	int setting = 0;
    int number;
    int n ;
	while (setting < N){
		getline(cin, str);
        stringstream iss(str);
        iss >> n;
        if(n == 1){
            iss >> s;
            stacks.push(append(s));
        }
        if(n == 2){
            iss >> number;
            stacks.push(deletes(number));
        }
        if(n == 3){
            iss >> number;
            cout << container[number-1] << endl;
        }
        if(n == 4)
            undo();
        setting++;
    }
    return 0;
}
