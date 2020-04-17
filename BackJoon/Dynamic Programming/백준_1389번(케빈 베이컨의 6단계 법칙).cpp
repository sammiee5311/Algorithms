#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M,result;
int visited[100];
vector<vector<int> > v;


void init(){
	for(int i=0; i<=N; i++)
		visited[i] = 0;
}

int bfs(int start){
	 queue<int> q;
	 int step=0, curr, size;
	 
	 q.push(start);
	 
	 while(!q.empty()){
	 	size = q.size();
	 	
	 	for(int j=0; j<size; j++){
	 		curr = q.front();
	 		q.pop();
	 		
	 		for(int i=0; i<v[curr].size(); i++){
	 			if(visited[v[curr][i]] == 0){
	 				visited[v[curr][i]] = step+1;
	 				q.push(v[curr][i]);
				 }
			 }
		 }
		 
		step++;
	 }
	 step = 0;
	 
	 for(int i=1; i<=N; i++){
	 	if(i == start)
	 		continue;
	 	step += visited[i];
	 }
	 
	 return step;
}

int main(void){
	cin >> N >> M;
	
	v.resize(N+1);
	
	for(int i=0; i<M; i++){
		int a,b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int min=100,ans=0;

	for(int i=1; i<=N; i++){
		init();
		result = bfs(i);
		if(result < min){
			min = result;
			ans = i;
		}
	}
	
	cout << ans;
}
