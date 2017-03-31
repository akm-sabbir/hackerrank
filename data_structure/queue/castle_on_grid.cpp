#include<cstdio>
#include<string>
#include<fstream>
#include<iostream>
#include <sstream>
using namespace std;
#define MAX 102
#define LARGE 25000
static char grid[MAX][MAX];
int visited[MAX][MAX];
int v[MAX][MAX][MAX];
int gridL;
int reached = 0;
int globalDist = 100;
void init(){
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			visited[i][j] = 0;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++)
				v[i][j][k] = 0;
}
int getMin(int *arr){
	int findMin = LARGE;
	for (int i = 0; i < 8; i++)
		if (arr[i] < findMin)
			findMin = arr[i];
	return findMin;
}
int dfsTraveller(int x, int y, string dir, int &gx, int &gy, int dist){
	if (x == gx  &&  y == gy){
		globalDist = globalDist > dist ? dist : globalDist;
		return globalDist;
	}
	if (v[x][y][dist] != 0)
		return globalDist;
	//cout << globalDist << " " << dist << endl;
	if (dist >= globalDist)
		return dist;
	
	if (x == 0 || y == 0)
		return 25000;
	if (x >= gridL + 1 || y >= gridL + 1)
		return 25000;
	visited[x][y] = 1;
	int *distN = new int[8];
	for (int i1=0; i1< 8; i1++)
		distN[i1] = LARGE;
	int xt, yt;
	v[x][y][dist] = globalDist;
	xt = x; yt = y;
	//if (xt + 1 <= gridL && grid[xt + 1][yt] != 'X' &&visited[xt + 1][yt] == 0){
		while (xt + 1 <= gridL && grid[xt + 1][yt] != 'X' && visited[xt+1][yt] == 0){
			//if (xt + 1== gx && yt == gy) return dist = dir != "S" ? dist + 1 :dist;
			xt++;
		}
		while (xt != x){
			visited[xt][yt] = 1;
			distN[0] = dfsTraveller(xt, yt, "S", gx, gy, dir != "S" ? dist + 1 : dist);
			visited[xt][yt] = 0;
			xt--;
		}
	//}
	xt = x; yt = y;
	//if (yt + 1 <= gridL&& grid[xt][yt + 1] != 'X' && visited[xt][yt + 1] == 0){
		while (yt + 1 <= gridL && grid[xt][yt + 1] != 'X' && visited[xt][yt + 1] == 0){
			//if (xt == gx && yt + 1 == gy) return dist = dir != "E" ? dist + 1 : dist;
			yt++;
		}
		while (yt != y){
			visited[xt][yt] = 1;
			distN[1] = dfsTraveller(xt, yt, "E", gx, gy, dir != "E" ? dist + 1 : dist);
			visited[xt][yt] = 0;
			yt--;
		}
	//}
	xt = x; yt = y;
	//if (yt- 1 > 0 && grid[xt][yt - 1] != 'X' && visited[xt][yt - 1] == 0){
		while (yt - 1 > 0 && grid[xt][yt - 1] != 'X' && visited[xt][yt-1] ==0){
			//if (xt == gx && yt - 1== gy) return dist = dir != "W" ? dist + 1 : dist;
			yt--;
		}
		while (yt != y){
			visited[xt][yt] = 1;
			distN[2] = dfsTraveller(xt, yt, "W", gx, gy, dir != "W" ? dist + 1 : dist);
			visited[xt][yt] = 0;
			yt++;
		}
	//}
	xt = x; yt = y;
	if (xt - 1 > 0 && grid[xt - 1][yt] != 'X' && visited[xt - 1][yt] == 0){
		while (xt - 1 > 0 && grid[xt - 1][yt] != 'X')
		{
		//	if (xt - 1 == gx && yt == gy) return dist = dir != "N" ? dist + 1 : dist;
			xt--;
		}
		while (xt != x){
			visited[xt][yt] = 1;
			distN[3] = dfsTraveller(xt, yt, "N", gx, gy, dir != "N" ? dist + 1 : dist);
			visited[xt][yt] = 0;
			xt++;
		}
	}
	visited[x][y] = 0;
	int minV = getMin(distN);
	globalDist = globalDist > minV? minV:globalDist;
	
	return globalDist;
}
void print(){
	for (int i = 1; i <= gridL; i++){
		for (int j = 1; j <= gridL; j++)
			cout << grid[i][j];
		cout << endl;
	}
}
int main(){
	//ifstream openFile("input.txt");
	//freopen("input.txt","r",stdin);
	stringstream ss;
	int N;
	//getline(ss, N);
	//ss << openFile;
	//ss << openFile.rdbuf();
	char *line = new char[102];
	init();
	//ss >> gridL;
	//ss.getline(line,MAX+1);
	//std::istringstream iss(line);
	
	cin >> gridL;
	for (int i = 1; i <= gridL; i++){
		//ss.getline(line, MAX + 1);
		//std::istringstream iss(line);
		for (int j = 1; j <= gridL; j++){
			cin >> grid[i][j];
		}
	}
	//print();
	//ss.getline(line, MAX + 1);
	//std::istringstream iss1(line);
	int x, y, gx, gy;
	cin >> x;
	cin >> y;
	cin >> gx;
	cin>> gy;
	gx += 1;
	gy += 1;
	cout << dfsTraveller(x+1, y+1, "C", gx, gy, 0) << endl;
	//openFile.close();
	return 1;
}