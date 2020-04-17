#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

queue<int> q;
stack<int> s;
string result;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int N,temp,num = 1;;
	cin >> N;
	
	
	for(int i=0; i<N; i++){
		cin >> temp;
		
		q.push(temp);
	}
	
	for(int i=0; i<q.front(); i++){
		s.push(num++);
		result += '+';
	}
	
	result += '-';
	q.pop();
	s.pop();
	
	bool impossible = false;
	
	while(1){
		if(q.empty())
			break;
		int current = q.front();
		
		if(s.empty() || current > s.top()){
			s.push(num++);
			result += '+';
		}
	
		else if(current == s.top()){
			result += '-';
			q.pop();
			s.pop();
		}
		
		else if(current < s.top()){
			impossible = true;
			break;
		}
			
	}
	
	if(impossible)
		cout << "NO";
	else
		for(int i=0; i<result.size(); i++){
			cout << result[i] << "\n";
		}
}
