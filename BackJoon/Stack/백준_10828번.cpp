#include <iostream>
#include <stack>
#include <string> 

using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	
	stack<int> s;
	string str;
	
	for(int i=0; i<num; i++){
		cin >> str;
		
		if(str == "push"){
			int num;
			cin >> num;
			s.push(num);
		}
		else if(str == "pop"){
			if(!s.empty()){
			int x = s.top();
			s.pop();
			cout << x << "\n";
			}
			else
			cout << "-1" << "\n";
		}
		else if(str == "size"){
			cout << s.size() << "\n";
		}
		else if(str == "empty"){
			if(!s.size())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
		else if(str == "top"){
			if(!s.empty())
				cout << s.top() << "\n";
			else
				cout << "-1" << "\n";
		}
	}
}
