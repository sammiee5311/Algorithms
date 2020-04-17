#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX 20001

using namespace std;

int V, E, Start;
int d[MAX];
vector <pair<int, int> > v[MAX];

void dijkstra(){
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0,Start));
	d[Start] = 0;
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		
		if(d[curr] < cost)
			continue;
		
		for(int i=0; i<v[curr].size(); i++){
			int next = v[curr][i].first;
			int nextcost = v[curr][i].second + cost;
			
			if(nextcost < d[next]){
				d[next] = nextcost;
				pq.push(make_pair(-nextcost,next));
			}
		}
	}
	for(int i=1; i<=V; i++){
		if(d[i] == INF){
			cout << "INF\n";
		}
		else
			cout << d[i] << "\n";
	}
}

int main(void){
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> V >> E >> Start;
	
	for(int i=0; i<E; i++){
		int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b,c));
	}
	
	for(int i=1; i<=V; i++){
		d[i] = INF;
	}
	
	dijkstra();
}
