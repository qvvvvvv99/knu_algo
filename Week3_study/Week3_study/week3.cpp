#include <iostream>
#include <algorithm>	// max() 함수 사용 가능 라이브러리

using namespace std;	// std:: 라는 네임스페이스 생략가능

void match(int left, int right, int day);	// 원숭이 팀 배정 함수
char team[7][99] = { NULL };	// 최대 99마리의 원숭이의 7일 동안 팀 배정할 배열 전역변수 선언 후 NULL로 초기화
int d;	// main에서 match() 함수 종료 후 며칠 동안 팀배정이 완료되었는지 확인하는 변수

int main() {
	int N;

	cin >> N;	// 2 ~ 99 사이 원숭이 마리 수 입력

	match(1, N, 0);	// N마리 원숭이 팀배정

	for (int i = 1; i <= N; i++){	// 원숭이의 수에 따라 팀배정 받은 일수가 다른 원숭이 존재
		if(team[d][i] == NULL)		// 팀배정 하루 덜 받은 원숭이 찾기
			team[d][i] = (i % 2 != 0 ? 'A' : 'B');	// 팀배정해주기
	}// 모든 원숭이가 같은 일수에 팀배정 완료
	for (int i = d + 1; i < 7; i++) {	// 남은 일수 만큼
		for (int j = 0; j <= N; j++) {
			team[i][j] = ((i + j) % N != 0 ? 'A' : 'B');	// 원숭이 팀배정(중복되지 않게)
		}
	}

	for (int i = 0; i < 7; i++) {	// 출력
		for (int j = 1; j <= N; j++) {
			cout << team[i][j];
		}
		cout << endl;
	}

	return 0;
}

void match(int left, int right, int day){
	if (day >= 7 || left >= right)	// 종료조건 : 7일의 팀배정 완료 or 왼쪽이 오른쪽보다 크거나 같을 경우
		return;

	int mid = (left + right) / 2;	// 중간을 기준으로 분할

	for (int i = left; i <= right; i++)
			team[day][i] = (i <= mid ? 'A' : 'B');	// 중간을 기준으로 작으면 'A'팀 크면 'B'팀
	d = max(d,day);	// 재귀함수 간에 팀배정한 일수가 변경되는 것을 방지
					// 중요중요!!! 없으면 비슷한데 정답 아님!!
	match(left, mid, day+1);	// 'A'팀끼리 재귀함수를 통해 분할정복 반복
	match(mid + 1, right, day+1);	// 'B'팀끼리 재귀함수를 통해 분할정복 반복
}