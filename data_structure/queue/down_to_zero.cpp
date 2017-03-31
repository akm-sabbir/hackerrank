#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000099
int prime_numbers[MAX];
int table[MAX];
long get_factor(long number){

	long range = ceil(sqrt(number));
	while (range){
		if ((number%range) == 0)
			return number / range > range ? number / range : range;
		range--;
	}
	return 1;
}

void determine_primes(){
	long l = 2;
	while (l < MAX){
		if (prime_numbers[l] == 0){
			unsigned long long next = l*l;
			while (next < MAX){
				prime_numbers[next] = 1;
				next += l;
			}

		}

		l++;
	}

}
void fill_tab(long init, long number){


	for (long i = init; i <= number; i++){
		if (prime_numbers[i] == 0)
			table[i] = table[i - 1] + table[1];
		else{
			long number = get_factor(i);
			table[i] = (table[number] + 1) < (table[i - 1] + table[1]) ? (table[number] + 1) : (table[i - 1] + table[1]);
			//table[i] = table[number] + 1;
		}
	}
}
void fillTable(){

	for (int i = 0; i < MAX; i++) table[i] = -1;
	table[0] = 0;
	table[1] = 1;
	table[2] = 2;
	table[3] = 3;
	for (int i = 2; i < MAX; i++){
		if (table[i] == -1 || table[i] > table[i-1] + 1)
			table[i] = table[i - 1] + 1;
		for (int j = 1; j <= i && i*j <= MAX; j++){
			if (table[i*j] == -1 || (table[i] + 1 )< table[i*j])
				table[i*j] = table[i] + 1;
		}
	}
}
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	//freopen("input.txt","r",stdin);
	//freopen("input.txt","r",stdin);
	int N;
	cin >> N;
	
	//determine_primes();
	//table[1] = 1;
	//table[2] = 2;
	//table[3] = 3;
	long last_max = 3;
	fillTable();
	long number;
	while (N--){
		cin >> number;
		if (table[number])
			cout << table[number] << endl;
		else{
			/*if (last_max + 1 < number){
				fill_tab(last_max + 1, number);
				last_max = number;
			}*/
			cout << table[number] << endl;
		}
	}

	return 0;
}