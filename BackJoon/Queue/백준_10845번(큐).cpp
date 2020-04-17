#include <iostream>
#include <queue>

using namespace std;

int main(void){
	int n;
	cin >> n;
	
	queue<int> q;
	
	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		
		if(str == "push"){
			int num;
			cin >> num;
			q.push(num);
		}
		
		if(str == "pop"){
			if(!q.empty()){
			int x = q.front(); 
			q.pop();
			cout << x << "\n";
			}
			else
				cout << "-1" << "\n";
		}
		
		if(str == "size"){
			cout << q.size() << "\n";
		}
		
		if(str == "front"){
			if(!q.empty())
				cout << q.front() << "\n";
			else
				cout << "-1" << "\n";
		}
		
		if(str == "back"){
			if(!q.empty())
				cout << q.back() << "\n";
			else
				cout << "-1" << "\n";
		}
		
		if(str == "empty"){
			if(!q.empty())
				cout << "0" << "\n";
			else
				cout << "1" << "\n";
		}
		
	}
	
}
