#include <iostream>
#include <vector>
#include <cstring>

#define INF 2e9

using namespace std;

int TC,N,M,W,S,E,T;
string ans;
int graph[501] = { INF };
vector <pair<pair<int,int>, int> > v;

void bellman(){
	graph[1] = 0;
	
	for(int i=1; i<=N-1; i++){
		for(int j=0; j<v.size(); j++){
			int from = v[j].first.first;
			int to = v[j].first.second;
			int cost = v[j].second;
			
			if(graph[from] == INF)
				continue;
			if(graph[to] > graph[from] + cost)
				graph[to] = graph[from] + cost;
		}
	}
	
	for(int i=0; i<v.size(); i++){
		int from = v[i].first.first;
		int to = v[i].first.second;
		int cost = v[i].second;
		
		if(graph[from] == INF)
			continue;
		if(graph[to] > graph[from] + cost){
			ans = "YES";
			return;
		}
	}
	ans = "NO";
}

int main(void){
	cin >> TC;
	
	while(TC--){
		cin >> N >> M >> W;

		memset(graph,-1,sizeof(graph));
		v.clear();
		
		for(int i=0; i<M; i++){
			cin >> S >> E >> T;
			v.push_back(make_pair(make_pair(S,E),T));
			v.push_back(make_pair(make_pair(E,S),T));
		}
		
		for(int i=0; i<W; i++){
			cin >> S >> E >> T;
			v.push_back(make_pair(make_pair(S,E),-T));
		}
		
		bellman();
		
		cout << ans << "\n";
	}
}
