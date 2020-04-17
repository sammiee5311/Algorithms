#include <iostream>

#include <deque>


using namespace std;


deque<int> deq;


/* ť ���� Ȯ�� ���� �ӽ� �Լ�

void printQue() {

    for (int i = 0; i < deq.size(); i++) {

        cout << deq.at(i) << " ";

    }

    cout << endl;

}

*/


int main() {

    int N, M, input, index, count, left,right;

    

    deque<int>::iterator it;

    cin >> N >> M;


    //1~N���� ť ä���(��ġ��)

    for (int i = 1; i <= N; i++) {

        deq.push_back(i);

    }

    count = 0;

    //printQue();

    for (int i = 0; i < M; i++) {

        cin >> input;


        if (deq.front() == input) {

            //�Է¹��� ���� �� �տ� ���� ��� �ٷ� ��� (����Ƚ������X)

            deq.pop_front();

            //printQue();

        }

        else {

            index = 1;

            for (it = deq.begin(); it < deq.end(); it++) {

                if (*it == input) {

                    //�Է¹��� ���� ��ġ�� ã��

                    //cout << index << endl;

                    break;

                }

                index++;

            }

            

            //�� �ε����κ��� �� ���� �Ÿ� ���ϱ�

            left = index - 1;

            right = deq.size() - index + 1;


            if (left >= right) {

                //�������� ������ ������

                //cout << "�������� ������ " << left << " " << right << endl;

                for (int j = 0; j < right; j++) {

                    deq.push_front(deq.back());

                    deq.pop_back();

                }

                count += right;

                deq.pop_front();

                //printQue();

            }

            else if (left <= right) {

                //���������� ������ ������

                //cout << "���������� ������" << left << " " << right << endl;

                for (int j = 0; j < left; j++) {

                    deq.push_back(deq.front());

                    deq.pop_front();

                }

                count += left;

                deq.pop_front();

                //printQue();

            }

        }

    }

    cout << count << endl;

    return 0;

}

