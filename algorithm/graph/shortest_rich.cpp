#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

class graph{
  public:
    int nodes;
    vector<int> *edges;
    void set_nodes(int n){
        this->nodes = n;
        this->edges = new vector<int>[n+1];
    }
    void add_edge(int s, int d){
        this->edges[s].push_back(d);
        this->edges[d].push_back(s);
    }
};
void start_dfs(int s, graph *g, int *visited){
    //static int visited[9999] = {0};
    for (vector<int>::iterator it = g->edges[s].begin(); it != g->edges[s].end(); it++){
        if(visited[s] + 6 < visited[*it]){
            visited[*it] = visited[s] + 6;
            start_dfs(*it,g,visited);
        }
    }
    return;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int node;
    int edge;
    int s,d;
    cin >> n;
    while(n--){
        cin >> node >> edge;
        graph *g = new graph();
        g->set_nodes(node);
        for (int i = 0; i <  edge; i++){
            cin >> s >> d;
            g->add_edge(s,d);
        }
        cin >> s;
        int *visited =new int[9999]; //= new vector<int>();
        for(int i = 0; i < 9999; i++)
            visited[i] = 99999;
        visited[s] = 0;
        start_dfs(s,g,visited);
        for (int i = 1; i <=node;i++){
            if(i == s)
                continue;
            else if(visited[i] == 99999){
                cout<<-1<<" ";
            }else
                cout << visited[i] << " ";
        }
        cout<< endl;
        delete g;
       
    }
    return 0;
}
