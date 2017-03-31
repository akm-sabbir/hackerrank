#include<stdio.h>
#include<sstream>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

vector<vector<pair<int,long long>>> graph;
void init(){
	
}
bool compare(pair<int,long long> &a, pair<int,long long> &b){
	if (a.second < b.second)
		return false;
	else
		return true;
}
long long start_prims(int start_node){
	priority_queue<pair<int,long long>,vector<pair<int,long long>>,std::function<bool(pair<int,long long> &, pair<int,long long> &)>> node_queue(compare);
	node_queue.push(make_pair(start_node,0));
	int total_weight = 0;
	int tempNode;
	long long weight = 0;
	int visited[3001] = { 0 };
	//visited[start_node] = 1;
	while (!node_queue.empty()){
		tempNode = node_queue.top().first;
		if (visited[tempNode] == 0)
			weight += node_queue.top().second;
		else{
			node_queue.pop();;
			continue;
		}
		visited[tempNode] = 1;
		node_queue.pop();
		for (int i = 0; i < graph[tempNode].size(); i++){
			if (visited[graph[tempNode][i].first] == 0){
				node_queue.push(make_pair(graph[tempNode][i].first, graph[tempNode][i].second));
				
			}
		}
	}
	return weight;
}
int main(){
	int nodes;
	int edges;
	int s, d, w;
	//freopen("input.txt","r",stdin);
	cin >> nodes >> edges;
	graph.resize(3001);
	for (int i = 0; i < edges; i++){
		cin >> s >> d >> w;
		graph[s].push_back(make_pair(d,w));
		graph[d].push_back(make_pair(s,w));
	}
	cin >> nodes;
	cout <<start_prims(nodes)<<endl;
	return 1;
}