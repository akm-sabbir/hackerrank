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
int ispalindrome(string num){
	int i, j;
	for (i = 0, j = num.length() - 1; i < num.length(); i++, j--){
		if (num[i] != num[j])
			break;
		if (i == j || abs(i - j) == 1)
			return 1;
	}
	return 0;
}
set<int> odd_palindrome(string &num, int &k){

	int counter = 0;
	int mid = num.length() / 2;
	set<int,less<int>> results;
	for (int i = 1; i <= mid; i++){
		if (num[mid + i] != num[mid - i]){
			if (num[mid + i] >  num[mid - i]){
				num[mid - i] = num[mid + i];
			}
			else{
				num[mid + i] = num[mid - i];
			}
			k--;
			results.insert(mid - i);
		}
		if (!k)
			break;
	}
	return results;

}
set<int> even_palindrome(string &num, int &k){
	int counter = 0;
	int mid1 = num.length() / 2;
	int mid2 = mid1 - 1;
	set<int,less<int>> results;
	if (num[mid1] != num[mid2] && k != 0){
		if (num[mid1] > num[mid2])
			num[mid2] = num[mid1];
		else
			num[mid1] = num[mid2];
		k--;
		results.insert(mid2);
	}
	if (!k)
		return results;
	for (int i = 1; i < mid1; i++){
		if (num[mid1 + i] != num[mid2 - i]){
			if (num[mid1 + i] >  num[mid2 - i]){
				num[mid2 - i] = num[mid1 + i];
			}
			else{
				num[mid1 + i] = num[mid2 - i];

			}
			results.insert(mid2 - i);
			k--;
		}
		if (!k)
			break;
	}
	return results;

}

int main(){
	int n;
	int k;
	//freopen("input.txt","r",stdin);
	//freopen("output1.txt", "w", stdout);
	cin >> n >> k;
	string number;
	cin >> number;

	if (number.length() == 1){
		if (k > 0)
			cout << "9" << endl;
		else
			cout << number << endl;
		return 0;
	}
	set<int> results;
	if (number.length() % 2 == 0){
		results = even_palindrome(number, k);
	}
	else
		results = odd_palindrome(number, k);
	//cout << k << endl;
	//if (results.size() != 0)
		//sort(results.begin(), results.end());
	int i = 0;
	//cout << number[0] << " " << number[number.length() - 1] << endl;
	while (k - 2 >= 0 && i <= number.length() / 2){
		if (number[i] == '9'){
			i++;
			continue;
		}
		if (results.find(i) != results.end()){
			k--;
		}
		else
			k -= 2;
		number[i] = '9';
		number[number.length() - 1 - i] = '9';
		i++;
	}
	
	if (k){
		int i1 = 0;
		if (results.size() != 0){
			set<int, less<int>>::iterator i1 = results.begin();
			//set<int, less<int>>::reverse_iterator ilast = results.rbegin();
			while (i1 != results.end() && k){
				if (number[*i1] != '9'){
					number[*i1] = '9';
					number[number.length()-1-*i1] = '9';
					k--;
				}
				i1++;
				//ilast++;
			}
		}
		if (k && number.length() % 2 == 1){
			number[number.length() / 2] = '9';
			k--;
		}
	
	}
	
	//cout << counter << endl;
	if (ispalindrome(number))
		cout << number << endl;
	else
		cout << "-1" << endl;
	return 0;
}
