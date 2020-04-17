#include <iostream>

#include <deque>


using namespace std;


deque<int> deq;


/* 큐 상태 확인 위한 임시 함수

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


    //1~N으로 큐 채우기(위치값)

    for (int i = 1; i <= N; i++) {

        deq.push_back(i);

    }

    count = 0;

    //printQue();

    for (int i = 0; i < M; i++) {

        cin >> input;


        if (deq.front() == input) {

            //입력받은 값이 맨 앞에 있을 경우 바로 출력 (연산횟수포함X)

            deq.pop_front();

            //printQue();

        }

        else {

            index = 1;

            for (it = deq.begin(); it < deq.end(); it++) {

                if (*it == input) {

                    //입력받은 값의 위치를 찾음

                    //cout << index << endl;

                    break;

                }

                index++;

            }

            

            //그 인덱스로부터 양 끝의 거리 구하기

            left = index - 1;

            right = deq.size() - index + 1;


            if (left >= right) {

                //왼쪽으로 데이터 보내기

                //cout << "왼쪽으로 보내기 " << left << " " << right << endl;

                for (int j = 0; j < right; j++) {

                    deq.push_front(deq.back());

                    deq.pop_back();

                }

                count += right;

                deq.pop_front();

                //printQue();

            }

            else if (left <= right) {

                //오른쪽으로 데이터 보내기

                //cout << "오른쪽으로 보내기" << left << " " << right << endl;

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

