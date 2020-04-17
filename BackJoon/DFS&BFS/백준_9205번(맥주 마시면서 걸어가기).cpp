#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100 + 2; 

int N;
vector<int> graph[MAX];
bool visited[MAX];

int distance(pair<int,int> p1, pair<int,int> p2){
	return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

void DFS(int node){
	visited[node] = true;
	
	for(int i=0; i<graph[node].size(); i++){
		int next = graph[node][i];
		if(visited[next] == false)
			DFS(next);
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int test_case;
	cin >> test_case;
	
	for(int i=0; i<test_case; i++){
		for(int j=0; j<MAX; j++)
			graph[j].clear();
		memset(visited,false,sizeof(visited));
			
		cin >> N;
		vector<pair<int, int> > coord;
			
		for(int j=0; j<N+2; j++){
			int x,y;
			cin >> y >> x;
			
			coord.push_back(make_pair(y,x));
		}
		
		for(int j=0; j<N+2; j++){
			for(int k=j+1; k<N+2; k++){
				if(distance(coord[j], coord[k]) <= 50*20){
					graph[j].push_back(k);
					graph[k].push_back(j);
				}
			}
		}
		
		DFS(0);
		
		if(visited[N+1])
			cout << "happy\n";
		else
			cout << "sad\n"
	}
}
