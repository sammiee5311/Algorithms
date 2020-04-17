#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int> > adj[801];
const int INF = 987654321;

int Distance[5];

bool visited[20001];

vector<int> dijkstra(int N, int src) {
    vector<int> dist(N+1, INF);
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        //���� ���� ���� �ͺ��� �� ª�� ��θ� �˰� �ִٸ� ���� ���� ���� �����Ѵ�.
        if (dist[here] < cost) continue;
        //������ �������� ��� �˻��Ѵ�.
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            //�� ª�� ��θ� �߰��ϸ�, dist[]�� �����ϰ� �켱���� ť�� �ִ´�.
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}
 
 
 
int main() {
    int N, E;
    int a, b, cost;
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> cost;
        adj[a].push_back({b,cost});
        adj[b].push_back({a,cost});
    }
    
    int node1, node2;
    cin >> node1 >> node2;
    vector<int> result = dijkstra(N, 1);
    vector<int> temp1 = dijkstra(N, node1);
    vector<int> temp2 = dijkstra(N, node2);
    
    int answer = min(result[node1] + temp1[node2] + temp2[N], result[node2] + temp2[node1] + temp1[N]);
 
    if (answer >= INF || answer < 0)
		cout << -1 << "\n";
 
    else
 		cout << answer << "\n";
 
  	return 0;
}
