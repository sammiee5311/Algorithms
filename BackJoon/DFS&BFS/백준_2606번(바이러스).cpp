#include<cstdio>
#include<vector>
#include<queue>
 
using namespace std;
 
vector<vector<int> > map;
vector<bool> visit;
queue<int> q;
int computer_num, ans = 0, cnt=0;

void dfs(int x)
{
    ans++;
    visit[x] = true;
 
    for (int k = 0; k < map[x].size(); k++)
    {
        if (!visit[map[x][k]])
			dfs(map[x][k]);
    }
    return;
}
 
 
void bfs(int idx){
	q.push(idx);
	visit[idx] = 1;
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0; i<map[x].size(); i++){
			int y = map[x][i];
			
			if(!visit[y]){
				q.push(y);
				visit[y] = 1;
				cnt++;
			}
		}
	}
}
int main()
{
    int n, from, to;
    scanf("%d %d", &computer_num, &n);
    visit.resize(computer_num + 1);
    map.resize(computer_num + 1);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &from, &to);
        map[from].push_back(to);
        map[to].push_back(from);
    }
 
    //dfs(1);
    bfs(1);
 
    printf("%d", cnt);
    return 0;
}

