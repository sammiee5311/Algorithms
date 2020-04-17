#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	string s; //수식을 입력할 변수
	string num; //수식 안에 숫자를 저장할 변수
	queue<int> q; //숫자를 넣을 공간
	int ans = 0; //답을 출력할 변수
 
    //수식을 입력하고 숫자들을 모두 찾아서 큐 안에 넣어준다.
	cin >> s;
	for (unsigned int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') { //숫자인 경우
			num = num + s[i];
		}
		else { //숫자가 아닌 경우
			q.push(stoi(num)); //숫자를 큐에 넣는다.
			num.clear(); //숫자를 담을 변수 초기화
		}
		if (i == s.size() - 1) { //식에 마지막 숫자이면
			q.push(stoi(num)); //숫자를 큐에 넣는다.
			num.clear(); //숫자를 담을 변수 초기화
		}
	}
 
	ans = q.front(); //우선 첫번째 수를 ans안에 넣는다. (계산을 첫번째 숫자부터 하기 위하여)
	q.pop(); //큐에 첫번째 원소를 팝
	for (unsigned int i = 0; i < s.size(); i++) { //수식에서 -기호를 만나기 전 모든 +기호를 더하는 과정
		if (s[i] == '+') { //덧셈이면
			ans = ans + q.front(); //큐에 첫번째 원소를 ans에 더해준다.
			q.pop(); //큐에 첫번째 원소를 팝
		}
		else if(s[i] == '-') { //뺄셈이면
			break; //탈출
		}
	}
    
	while (q.size()) { //큐가 빌 때까지
		ans = ans - q.front(); //큐 안에 모든 원소를 빼준다.
		q.pop();
	}
    
	cout << ans;
}
