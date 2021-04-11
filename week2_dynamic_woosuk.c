#include <stdio.h>
int min(int arr[],int arr2[], int m, int n);
int main() {
	int maxdis = 0, n = 0, dis[6] = { 0 }, time[6] = { 0 };
	scanf_s("%d %d", &maxdis, &n);
	if (n > 100)
		return;
	for (int i = 0; i < n+1; i++) {
		scanf_s("%d", &dis[i]);
		if (dis[i] < 1)
			return; // is that correct receiving from 0 to 6?
	}//dis = {100 30 100 40 50 60}
	for (int j = 1; j < n + 1;j++) {
		scanf_s("%d", &time[j]);
	}
	
	min(time,dis, maxdis, n);

	return 0;
}

int min(int arr[], int arr2[], int m, int n) {
	int j = 0, l=0, count =0, o=0, d=0, flag;
	int t[7] = { 0 };
	int p[7] = { 0 };
	p[0] = -1;
	for (int i = 1; i < n + 2; i++) {
		int min = 99999;
		l = j; 
		//l's init value is 0 and insert j value(j's init is 0)
		while(j<i){
			int chk = 0;
			int distance = 0;
			//t[i] = t[j] + arr[i]; //arr[i] value is time[]
			for (int k = j; k < i; k++)
				distance += arr2[k];
			if (distance > m) {
				j++;
			}
			else {
				chk = t[j] + arr[i];
				/* arr[i] -> arr[i+1] change
				for (int k = j; k <i; k++)
					distance += arr2[k]; // arr2[k] value is dis[]
				if (distance > m)
					flag = 1;
				if (t[i] < min) {
					min = t[i];
					p[i] = j;
				}*/
				if (chk < min) {
					min = chk;
					t[i] = min;
					p[i] = j;
				}
				j++;
			}
		}
		j = l;
	}
	printf("%d\n", t[n]);
	for (int h = 1; h < n + 2; h++) {
		if (o != p[h]) {
			o = p[h];
			count++;
		}
	}
	printf("%d\n", count);
	for (int g = 1; g < n + 2; g++) {
		if (d != p[g]) {
			d = p[g];
			printf("%d ", d);
		}
	}
}

