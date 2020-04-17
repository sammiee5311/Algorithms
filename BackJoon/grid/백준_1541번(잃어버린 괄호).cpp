#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	string s; //������ �Է��� ����
	string num; //���� �ȿ� ���ڸ� ������ ����
	queue<int> q; //���ڸ� ���� ����
	int ans = 0; //���� ����� ����
 
    //������ �Է��ϰ� ���ڵ��� ��� ã�Ƽ� ť �ȿ� �־��ش�.
	cin >> s;
	for (unsigned int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') { //������ ���
			num = num + s[i];
		}
		else { //���ڰ� �ƴ� ���
			q.push(stoi(num)); //���ڸ� ť�� �ִ´�.
			num.clear(); //���ڸ� ���� ���� �ʱ�ȭ
		}
		if (i == s.size() - 1) { //�Ŀ� ������ �����̸�
			q.push(stoi(num)); //���ڸ� ť�� �ִ´�.
			num.clear(); //���ڸ� ���� ���� �ʱ�ȭ
		}
	}
 
	ans = q.front(); //�켱 ù��° ���� ans�ȿ� �ִ´�. (����� ù��° ���ں��� �ϱ� ���Ͽ�)
	q.pop(); //ť�� ù��° ���Ҹ� ��
	for (unsigned int i = 0; i < s.size(); i++) { //���Ŀ��� -��ȣ�� ������ �� ��� +��ȣ�� ���ϴ� ����
		if (s[i] == '+') { //�����̸�
			ans = ans + q.front(); //ť�� ù��° ���Ҹ� ans�� �����ش�.
			q.pop(); //ť�� ù��° ���Ҹ� ��
		}
		else if(s[i] == '-') { //�����̸�
			break; //Ż��
		}
	}
    
	while (q.size()) { //ť�� �� ������
		ans = ans - q.front(); //ť �ȿ� ��� ���Ҹ� ���ش�.
		q.pop();
	}
    
	cout << ans;
}
