#include <iostream>
#include <deque>

using namespace std;

deque<int> de;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		
		if(str == "push_front"){
			int x;
			cin >> x;
			de.push_front(x);
		}
		
		if(str == "push_back"){
			int x;
			cin >> x;
			de.push_back(x);
		}
		
		if(str == "pop_front"){
			if(!de.empty()){
			int x = de.front();
			de.pop_front();
			cout << x << "\n";
			}
		else
			cout << "-1" << "\n";
		}
		
		if(str == "pop_back"){
			if(!de.empty()){
			int x = de.back();
			de.pop_back();
			cout << x << "\n";
			}
		else
			cout << "-1" << "\n";
		}
		
		if(str == "size"){
			cout << de.size() << "\n";
		}
		
		if(str == "empty"){
			if(!de.empty())
				cout << "0" << "\n";
			else
				cout << "1" << "\n";
		}
		
		if(str == "front"){
			if(!de.empty())
				cout << de.front() << "\n";
			else
				cout << "-1" << "\n";
		}
		
		if(str == "back"){
			if(!de.empty())
				cout << de.back() << "\n";
			else
				cout << "-1" << "\n";
		}
		
	}
}

