#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N, M;
	int Num[100010];
	scanf_s("%d %d", &N, &M);
	for (int i = 0;i < N;i++) {
		scanf_s("%d", &Num[i]);
	}
	sort(Num, Num + N);
	for (int i = 0;i < N;i++) {
		int left = i+1, right = N;//i+1->N���ܹ������=M��coin
		while (left < right) {
			int mid = (left + right) / 2;
			if (Num[mid] > M) {
				right = mid;//�����
				continue;
			}
			if (Num[i] + Num[mid] > M)
				right = mid;//�����
			else if (Num[i] + Num[mid] == M) {
				printf("%d %d\n", Num[i], Num[mid]);
				return 0;
			}
			else if (Num[i] + Num[mid] < M)
				left = mid + 1;//���ұ�
		}
		if (Num[i] > M)
			break;
	}
	printf("No Solution\n");
	return 0;
}