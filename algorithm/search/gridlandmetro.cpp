#include <iostream>
#include<vector>
#include <algorithm>
#include<map>
using namespace std;
class railTrack{
public:
	long r;
	long c1, c2;
	railTrack(long r, long c1, long c2){
		this->r = r;
		this->c1 = c1;
		this->c2 = c2;
	}
};
int compare(pair<long, vector<pair<long, long>>> o1, pair<long, vector<pair<long, long>>> o2){ return (o1.first < o2.first); }
int compare_mapped(pair<long, long> o1, pair<long, long> o2) {
	return (o1.first < o2.first);
	
}
//int compare_map(pair<long, vector<pair<long, long>>> o1, pair<long, vector<pair<long, long>>> o2){ return (o1.first < o2.second); }
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	long n, m, k;
	//freopen("input.txt","r",stdin);
	long c1, c2, r;
	scanf("%ld%ld%ld", &n, &m, &k);
	vector<railTrack> arr;
	map<long, vector<pair<long,long>>> mapped_data;
	arr.reserve(k + 10);
	for (long i = 1; i <= k; i++){
		scanf("%ld%ld%ld", &r, &c1, &c2);
		mapped_data[r].push_back(make_pair(c1,c2));
		
		//arr.push_back(railTrack(r, c1, c2));
	}
	int index = 0;
	for (map<long, vector<pair<long, long>>>::iterator i = mapped_data.begin(); i != mapped_data.end(); i++){
		//cout << index++ << endl;
		sort(i->second.begin(), i->second.end(), compare_mapped);
	}
	//cout << "starting sorting" << endl;
	map<long, vector<pair<long, long>>,less<long>> new_mapped_vec;
	for (map<long, vector<pair<long, long>>>::iterator i = mapped_data.begin(); i != mapped_data.end(); i++){
		long max_val = 0;
		vector<pair<long, long>> temp_vec;
		for (vector<pair<long, long>>::iterator it = i->second.begin(); it != i->second.end();){
			int  j = 1;
			max_val = it->second;
			vector<pair<long, long>>::iterator next_it = it;
			next_it++;
			pair<long, long> temp_pair = make_pair(it->first,it->second);
			while (true){
				if (next_it != i->second.end()){
					if (it->first <= (next_it)->first && (next_it)->first <= it->second){
						max_val = it->second > (next_it)->second ? it->second : (next_it)->second;
						it->second = max_val;
					}
					else{
						 temp_pair = make_pair(it->first, max_val);
						 break;
					}
				}
				else{
					temp_pair = make_pair(it->first, max_val);
					break;
				}
				next_it++;
			}
			it = next_it;
			temp_vec.push_back(temp_pair);
		}
		sort(temp_vec.begin(), temp_vec.end(), compare_mapped);
		new_mapped_vec[i->first] = temp_vec;
	}
	
	mapped_data.erase(mapped_data.begin(),mapped_data.end());
	//sort(new_mapped_vec.begin(), new_mapped_vec.end(), compare);
	index = 0;
	/*for (map<long, vector<pair<long, long>>, less<long>>::iterator it = new_mapped_vec.begin(); it != new_mapped_vec.end(); it++){
		cout << it->first << endl;
		index++;
	}*/
	//cout<< index << endl;
	
	long long sum = 0;
	int i = 0;
	map<long, vector<pair<long, long>>, less<long>>::iterator prev_it = new_mapped_vec.begin();
	map<long, vector<pair<long, long>>, less<long>>::iterator it = new_mapped_vec.begin();
	for (; it != new_mapped_vec.end(); it++){
		long len = it->first - (i == 0 ? 1 : (prev_it)->first + 1);//arr[i].r - (i == 0 ? 1 : arr[i - 1].r + 1);
		long j = 0;
		sum = sum + ((len < 0 ? 0 : len)*m);
		//cout << sum << endl;
		vector<pair<long, long>>::iterator prev_sec_it = it->second.begin();
		for (vector<pair<long, long>>::iterator sec_it = it->second.begin(); sec_it != it->second.end(); sec_it++){
			//cout << sec_it->first << " " << sec_it->second << endl;
			sum = sum + sec_it->first - (j == 0 ? 1 : prev_sec_it->second+1);// (sec_it->first > prev_sec_it->second+1 ? prev_sec_it->second+1:sec_it->first) );
			prev_sec_it = sec_it;
			j++;
		}
		
		sum = sum + (m - prev_sec_it->second);
		prev_it = it;
		i++;
	}
	sum = sum + (n - prev_it->first)*m;
	//printf("%ld\n", sum);
	cout << sum << endl;
	
	return 0;
}