#include<iostream>
using namespace std;

void MaxSubsequm1(int A[], int N)//�����ƽ�-O(N^3)-����ȥ���һ��
{
	int i, j, k;
	int MaxSum = -1,ThisSum;
	int First = A[0], Last = A[0];//���������С���Ǹ�
	for (i = 0;i < N;i++) {
		for (j = i;j < N;j++) {
			ThisSum = 0;
			for (k = i;k <= j;k++) {
				ThisSum += A[k];
				if (ThisSum > MaxSum) {
					MaxSum = ThisSum;
					First = A[i];
					Last = A[k];
				}
			}			
		}
	}
	if (MaxSum < 0) {
		MaxSum = 0;
		First = A[0];
		Last = A[N - 1];
	}
	cout << MaxSum << " " << First << " " << Last << endl;
}

void MaxSubsequm2(int A[], int N)//�����Ľ�-O(N^2)-����ȫ��
{
	int i, j;
	int MaxSum = -1, ThisSum;
	int First, Last;
	for (i = 0;i < N;i++) {
		ThisSum = 0;
		for (j = i;j < N;j++) {
			ThisSum += A[j];
			if (ThisSum > MaxSum) {
				MaxSum = ThisSum;
				First = A[i];
				Last = A[j];
			}
		}
	}
	if (MaxSum < 0) {
		MaxSum = 0;
		First = A[0];
		Last = A[N - 1];
	}
	cout << MaxSum << " " << First << " " << Last << endl;
}

void MaxSubsequm3(int A[], int N)//��̬�滮-����ȫ��
{
	int i, MaxSum = -1, ThisSum = 0;
	int First, Last, Start = A[0];
	for (i = 0;i < N;i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
			Last = A[i];
			First = Start;//���First
		}
		if (ThisSum < 0) {//���¿�ʼ
			ThisSum = 0;
			Start = A[i + 1];//��¼��ʼ�ĵط�
		}
	}
	if (MaxSum < 0) {
		MaxSum = 0;
		First = A[0];
		Last = A[N - 1];
	}
	cout << MaxSum << " " << First << " " << Last << endl;
}

int Max(int A, int B, int C)
{
	return A > B ? (A > C ? A : C) : (B > C ? B : C);
}

int DivideAndConquer(int A[], int left, int right)//O(NlogN)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, LeftBorderSum;
	int MaxRightBorderSum, RightBorderSum;
	int First, Last;
	if (left == right) {//��ֹ�ݹ������
		if (A[left] > 0)
			return A[left];
		else return 0;
	}
	//���������е����
	int center = (left + right) / 2;
	MaxLeftSum = DivideAndConquer(A, left, center);
	MaxRightSum = DivideAndConquer(A, center + 1, right);
	//���Խ��߽�����
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (int i = center;i >= left;i--) {
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	//���Խ�ұ߽�����
	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (int i = center + 1; i <= right; i++) {
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequm4(int A[], int N)//�ֶ���֮
{
	return DivideAndConquer(A, 0, N - 1);
}
int main()
{
	int N;
	int A[10001];
	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> A[i];
	//MaxSubsequm1(A, N);
	//MaxSubsequm2(A, N);
	MaxSubsequm3(A, N);
	//cout << MaxSubsequm4(A,N) << endl;
	return 0;
}