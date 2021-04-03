#include <iostream> // input/output stream : 표준입출력 라이브러리(= C언어의 <stdio.h>와 동일)
#include <cmath>	// fmax(), fmin() 수학계산 함수 사용 라이브러리
using namespace std;	// C++ 표준에서 정의한 이름 공간중 하나

long long Combi(int n, int k);

int main() {
	int n, k;
	long long result;

	cin >> n >> k;	// 사용자 입력받기 
	if ((n < 1 && n > 4000000) || (k < 0 && k > n)) {
		cout << "잘못된 입력" << endl;	// cout : 출력 함수
		exit(0);
	}
	result = Combi(n, k);
	cout << result << endl;
	return 0;
}

long long Combi(int n, int k) {
	long long *B1 = new long long[n + 1];	// 동적할당 : data_type *array = new data_type[size];
	long long* B2 = new long long[n + 1];

	// ary[i] = upper_ary[i] + upper_ary[i-1] ( 0 < i < k)
	// ary[i] = 1 (i = 0 or i = k)
	// 한줄을 구하기 위해서 바로 이에 줄만 있으면 가능
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= fmin(i, k); j++) {
			if (i % 2 == 0) {
				if (j == 0 || j == i)
					B1[j] = 1;
				else
					B1[j] = B2[j - 1] + B2[j];	// 바로 윗숫자와 그 왼쪽 숫자 합
			}
			else {
				if (j == 0 || j == i)
					B2[j] = 1;
				else
					B2[j] = B1[j - 1] + B1[j];
			}
		}
	}
	if (n % 2 == 0)
		return B1[k] % 1000000007;
	else
		return B2[k] % 1000000007;
}

//int Combi(int n, int k) {
//	N[0] = 1;
//	// factorial 수 커짐 따라 범위 초과로 배열에 넣지 못함!!!
//	for (int i = 1; i <= n; i++)
//		N[i] = N[i - 1] * i;
//
//	std::cout << (N[n] / (N[k] * N[n - k])) << std::endl;
//}