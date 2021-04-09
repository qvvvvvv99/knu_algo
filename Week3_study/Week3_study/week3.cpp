#include <iostream>
#include <algorithm>

using namespace std;

void match(int left, int right, int day);
char team[7][99] = { NULL };
int d;

int main() {
	int N;

	cin >> N;

	match(1, N, 0);

	for (int i = 1; i <= N; i++){
		if(team[d][i] == NULL)
			team[d][i] = (i % 2 != 0 ? 'A' : 'B');
	}
	for (int i = d + 1; i < 7; i++) {
		for (int j = 0; j <= N; j++) {
			team[i][j] = ((i + j) % N != 0 ? 'A' : 'B');
		}
	}

	for (int i = 0; i < 7; i++) {
		for (int j = 1; j <= N; j++) {
			cout << team[i][j];
		}
		cout << endl;
	}

	return 0;
}

void match(int left, int right, int day){
	if (day >= 7 || left >= right)
		return;

	int mid = (left + right) / 2;

	for (int i = left; i <= right; i++)
			team[day][i] = (i <= mid ? 'A' : 'B');
	d = max(d,day);
	
	match(left, mid, day+1);
	match(mid + 1, right, day+1);
}