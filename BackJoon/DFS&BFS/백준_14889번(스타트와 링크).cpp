#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,a,b,ans=987654321;
int MAP[20][20];
bool visited[20];

void DFS(int curr_player, int cnt){
	if(cnt == N/2){
		vector<int> team_link, team_start;
		
		for(int i=0; i<N; i++){
			if(visited[i])
				team_start.push_back(i);
			else
				team_link.push_back(i);
		}
		
		int stat_start = 0, stat_link = 0;
		for(int i=0; i<team_start.size(); i++){
			for(int j=i+1; j<team_start.size(); j++){
				int start_x = team_start[i], start_y = team_start[j];
				int link_x = team_link[i], link_y = team_link[i];
				stat_start += MAP[start_x][start_y] + MAP[start_y][start_x];
				stat_link += MAP[link_x][link_y] + MAP[link_y][link_x];
			}
		}
		
		ans = min(ans, abs(stat_start-stat_link));
		return;
	}
	
	for(int i = curr_player+1; i < N; i++){
		if(!visited[i]){
			visited[i] = 1;
			DFS(i,cnt+1);
			visited[i] = 0;
		}
	}
}

int main(void){
	cin >> N;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> MAP[i][j];
		}
	}
	
	DFS(0,0);
	
	cout << ans;
}
