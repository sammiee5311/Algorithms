#include <iostream>
#include <algorithm>
#define INF 100000000

using namespace std;

int n,m;
int graph[101][101];

void floyd(){
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j)
					continue; 
				else if(graph[i][k] && graph[k][j]){
					if(graph[i][j] == 0)
						graph[i][j] = graph[i][k] + graph[k][j];
					else
						graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
				}
			}
		}
	}
}

int main(void){
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			graph[i][j] = INF;
		}
	}
	
	for(int i=0; i<m; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		if(graph[from][to] > cost){
			graph[from][to] = cost;
		}
	}
	
	floyd();
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j || graph[i][j] == INF)
				cout << "0 ";
			else
				cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}
