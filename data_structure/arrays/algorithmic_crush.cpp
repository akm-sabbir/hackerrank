#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
bool comparePairs(const std::pair<long, pair<long,int>>& lhs, const std::pair<long,pair<long, int>>& rhs)
{
	return lhs.first > rhs.first;
}
class object{
public:
	long long cur;
	long long running;
	int sign;
	char I;
	object(long long &a, long long &b,int sign){
		this->cur = a;
		this->running = b;
		this->sign = sign;
	}
	object(){
		this->cur = 0;
		this->running = 0;
		this->sign = 1;
		this->I = 'I';
	}
};
void assign_mapper(map<long,object> &mapper,long a,long K,int sign){
	mapper[a] = object();
	if (sign == 1)
		mapper[a].running = K;
	else
		mapper[a].cur = K;
}
int main(){
	//freopen("input.txt", "r", stdin);
	int  M, N;
	cin >> N >> M;
	long a, b;
	long K;
	map<long, object> mapper;
	int sets = 0;
	while (M--){
		cin >> a >> b >> K;
		sets = 0;
		if (mapper.find(a) == mapper.end()){
			assign_mapper(mapper, a, K, 1);
		}
		else{
			mapper[a].running += K;	
		}
		if (mapper.find(b) == mapper.end())
			assign_mapper(mapper, b, K, 0);
		else
			mapper[b].cur += K;
		
	}
	//std::sort(mapper.begin(), mapper.end(), comparePairs);
	long long running_max = 0;
	long long so_far_max = 0;
	for (map<long, object>::iterator it = mapper.begin(); it != mapper.end(); it++){
		//cout << it->first << endl;
		running_max += it->second.running;
		if (running_max > so_far_max)
			so_far_max = running_max;
		running_max -= it->second.cur;
	}
	cout << so_far_max << endl;
}