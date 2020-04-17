#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n,ans=0,num_area,Max_height;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int MAP[101][101];
bool visited[101][101];
int cnt[101][101];

vector<pair<int, int> > v;

void copy_MAP(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cnt[i][j] = MAP[i][j];
		}
	}
}

void make_MAP(int h){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(cnt[i][j] <= h)
				cnt[i][j] = 0;
			else
				v.push_back(make_pair(i,j));
		}
	}
}

int bfs(int a, int b){
	queue<pair<int,int> > q;
	q.push(make_pair(a,b));
	visited[a][b] = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < n && ny < n){
				if(visited[nx][ny] == 0 && cnt[nx][ny] != 0){
					visited[nx][ny] = 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

int main(void){
	cin >> n;
	
	Max_height = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> MAP[i][j];
			if(MAP[i][j] > Max_height)
				Max_height = MAP[i][j];			
		}
	}
	
	for(int h=0; h<100; h++){
		num_area = 0;
		v.clear();
		memset(visited,false,sizeof(visited));
		if(h>Max_height)
			break;

		copy_MAP();
		make_MAP(h);
		
		for(int i=0; i<v.size(); i++){
			int x = v[i].first;
			int y = v[i].second;
			
			if(visited[x][y] == false){
				num_area++;
				bfs(x,y);
			}
		}
		ans = max(ans, num_area);
	}
	
	cout << ans;
}
