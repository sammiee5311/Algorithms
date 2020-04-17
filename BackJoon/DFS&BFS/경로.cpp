#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > map;
vector<bool> visit;
queue<int> q;


int bfs(int start,int end) {
	q.push(start);
	visit[start] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == end)
			return true;

		for (int i = 0; i < map[x].size(); i++) {
			int y = map[x][i];

			if (!visit[y]) {
				q.push(y);
				visit[y] = 1;
			}
		}
	}
	return false;
}
int main(void)
{
	int from, to;
	visit.resize(10);
	map.resize(10);

	map[0].push_back(1);
	map[1].push_back(2);
	map[1].push_back(3);
	map[2].push_back(4);
	map[2].push_back(3);
	map[3].push_back(4);
	map[3].push_back(5);
	map[5].push_back(6);
	map[5].push_back(7);
	map[6].push_back(8);


	//dfs(1);
	bool a = bfs(1,8);
	cout << a;
}

