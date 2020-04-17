#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 8

using namespace std;

int N,M,space,ans;
int MAP[MAX][MAX];
int C_MAP[MAX][MAX];
bool check[MAX*MAX];
bool visited[MAX][MAX];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

vector<pair<int, int> > emp, vi;

void BFS(int a, int b){
	queue<pair<int, int> > q;
	q.push(make_pair(a,b));
	visited[a][b] = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >=0 && ny >= 0 && nx < N && ny < M){
				if(visited[nx][ny] == 0 && C_MAP[nx][ny] == 0){
					C_MAP[nx][ny] = 2;
					visited[nx][ny] = 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

int cnt_safe_area(){
	int cnt=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(C_MAP[i][j] ==0)
				cnt++;
		}
	}
	return cnt;
}

void spread_virus(){
	
	int cnt=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			C_MAP[i][j] = MAP[i][j];
		}
	}
	memset(visited, 0, sizeof(visited));
	
	for(int i=0; i<space; i++){
		if(cnt == 3) break;
		
		if(check[i] == 1){
			int x = emp[i].first;
			int y = emp[i].second;
			C_MAP[x][y] = 1;
			cnt++;
		}
	}
	
	for(int i=0; i<vi.size(); i++){
		int x = vi[i].first;
		int y = vi[i].second;
		BFS(x,y);
	}
	
	int tmp_ans = cnt_safe_area();
	ans = max(ans,tmp_ans);
}

void Make_wall(int index, int cnt){
	
	if(cnt==3){
		spread_virus();
		return;
	}
	
	for(int i=index; i<space; i++){
		if(check[i] == 1) continue;
		check[i] = 1;
		Make_wall(i,cnt+1);
		check[i] = 0;
	}
}

int main(void){
	
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> MAP[i][j];
			if(MAP[i][j] == 0)
				emp.push_back(make_pair(i,j));
			else if(MAP[i][j] == 2)
				vi.push_back(make_pair(i,j));
		}
	}
	space = emp.size();
	
	Make_wall(0,0);
	
	cout << ans;
}

