#include <stdio.h>

char mon[7][99];
int n, cnt;

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}
void solve(int l, int r, int dep) {
	if (l >= r || dep == 7) return;
	cnt = max(cnt, dep);
	int mid = (l + r) / 2;
	for (int i = l; i <= r; i++) {
		if (i <= mid) mon[dep][i] = 'A';
		else mon[dep][i] = 'B';
	}
	solve(l, mid, dep + 1);
	solve(mid + 1, r, dep + 1);
}

int main() {
	scanf_s(" %d", &n);
	solve(1, n, 0);
	for (int i = 0; i < cnt; i++) {
		for (int j = 1; j <= n; j++) {
			if (mon[i][j] == '\0') mon[i][j] = (j % 2 == 0) ? 'A' : 'B';
			printf("%c", mon[i][j]);
		}puts("");
	}
	while (cnt != 7) {
		for (int i = 0; i < n; i++) {
			if (i & 1) printf("A");
			else printf("B");
		}puts(""); cnt++;
	}
}
