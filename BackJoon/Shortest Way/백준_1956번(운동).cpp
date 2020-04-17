#include <iostream>
#include <algorithm>
#define INF 100000000

using namespace std;

int V,E;
int graph[402][402];

void floyd(){
	for(int k=1; k<=V; k++){
		for(int i=1; i<=V; i++){
			for(int j=1; j<=V; j++){
				if(i == j)
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
	cin >> V >> E;
	
	for(int i=1; i<=V; i++){
		for(int j=1; j<=V; j++){
			graph[i][j] = INF;
		}
	}
	
	for(int i=0; i<E; i++){
		int a,b,c;
		cin >> a >> b >> c;
		
		if(graph[a][b] > c)
			graph[a][b] = c;
	}
	
	floyd();
	
	int min = INF;
	
	for(int i=1; i<=V; i++){
		for(int j=1; j<=V; j++){
			if(i == j)
				continue;
			else
				if(graph[i][j] + graph[j][i] < min)
					min = graph[i][j] + graph[j][i];
		}
	}
	
	if(min == INF)
		cout << "-1";
	else
		cout << min;
}
