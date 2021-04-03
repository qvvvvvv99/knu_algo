#include <iostream>

using namespace std;

int main() {
	int M, n, dmin = 0, dsum = 0, minplace = 0, cnt = 0, flag, l = 0;

	cin >> M;
	cin >> n;
	int* d = new int[n + 1];
	int* t = new int[n + 2];
	int* T = new int[n + 2];
	int* P = new int[n + 2];
	int* path = new int[n + 2];

	for (int i = 0; i <= n; i++) {
		cin >> d[i];
	}
	t[0] = 0; t[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	T[0] = 0; P[0] = -1;
	for (int k = 1; k <= n + 1; k++) {
		for (int j = k - 1; j >= 0; j--) {
			dsum += d[j];
			if (dsum <= M) {
				if (k == 1) {
					T[1] = t[1];
					dmin = T[1];
				}
				else {
					dmin = T[k - 1] + t[k];
				}
				if (dmin >= T[j] + t[k]) {
					dmin = T[j] + t[k];
					minplace = j;
				}
			}
		}
		dsum = 0;
		T[k] = dmin;
		P[k] = minplace;
	}
	
	flag = P[n + 1];
	while (flag > 0) {
		cnt++;
		path[l] = flag;
		flag = P[flag];
		l++;
	}
	cout << T[n + 1] << endl << cnt << endl;
	
	for (int i = l-1; i >= 0; i--)
		cout << path[i] << ' ';
	//cout << endl;

	delete[]d;
	delete[]t;
	delete[]T; 
	delete[]P;
	delete[]path;

	return 0;
}