#include <iostream>
#include <vector>

#define INF 2e9

using namespace std;

int N,M,A,B,C;
vector <pair<pair<int, int>,int > > Edge;
int Dist[510] = {INF};

void bellman(){
	
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 0; j < Edge.size(); j++)
        {
            int From = Edge[j].first.first;
            int To = Edge[j].first.second;
            int Cost = Edge[j].second;
 
            if (Dist[From] == INF) continue;
 
            if (Dist[To] > Dist[From] + Cost) Dist[To] = Dist[From] + Cost;
        }
    }
 
    for (int i = 0; i < Edge.size(); i++)
    {
        int From = Edge[i].first.first;
        int To = Edge[i].first.second;
        int Cost = Edge[i].second;
 
        if (Dist[From] == INF) continue;
        if (Dist[To] > Dist[From] + Cost)
        {
            cout << -1 << "\n";
            return;
        }
    }
 
    for (int i = 2; i <= N; i++)
    {
        if (Dist[i] == INF) cout << -1 << "\n";
        else cout << Dist[i] << "\n";
    }
}

int main(void){
	cin >> N >> M;
	
	for(int i=0; i<M; i++){
		cin >> A >> B >> C;
		Edge.push_back(make_pair(make_pair(A,B),C));
	}
	
	fill(Dist,Dist+501,INF);

	Dist[1] = 0;

	bellman();
}
