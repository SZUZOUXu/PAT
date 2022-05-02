#include<iostream>
using namespace std;
int N;
bool Judge(int A[], int B[], int N)
{
	for (int i = 0;i < N;i++) {
		if (A[i] != B[i]) {
			return false;
		}
	}
	return true;
}
bool InsertSort(int A[],int B[], int N)
{
	int i, j;
	for (i = 1;i < N;i++) {
		int tmp = A[i];//��Ҫ���������Ԫ��
		for (j = i;j > 0 && A[j - 1] > tmp;j--) {//�����ǰ���Ԫ��С
			A[j] = A[j - 1];
		}
		A[j] = tmp;//�ڵ�ǰλ�ò���
		if (Judge(A, B, N)) {//������ԭ����һ����,�ٽ���һ��������˳�
			i++;
			int tmp = A[i];//��Ҫ���������Ԫ��
			for (j = i;j > 0 && A[j - 1] > tmp;j--) {//�����ǰ���Ԫ��С
				A[j] = A[j - 1];
			}
			A[j] = tmp;//�ڵ�ǰλ�ò���
			return true;
		}
	}
	return false;
}
//�������еĹ鲢
void Merge(int A[], int TmpA[], int L, int R, int RightEnd)//TmpA��ʱ��Ž��
{
	int LeftEnd = R - 1;
	int Tmp = L, Num = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++];
		else TmpA[Tmp++] = A[R++];
	}
	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];
	for (int i = 0;i < Num;i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];//���ƻ�A����
}
void MergePass(int A[], int B[],int TmpA[], int N,int Length)
{
	int i;
	for (i = 0;i < N - 2 * Length;i += 2 * Length)
		Merge(A, TmpA, i, i + Length, i + 2 * Length - 1);
	if (i + Length < N)//�鲢�����������
		Merge(A, TmpA, i, i + Length, N - 1);
}
void MergeSort(int A[], int B[], int N)
{
	int* TmpA;
	TmpA = (int*)malloc(N * sizeof(int));
	int Length = 1;
	while (Length < N) {
		MergePass(A, B, TmpA, N, Length);
		if (Judge(A, B, N)) {//��ͬ��
			Length *= 2;
			MergePass(A, B, TmpA, N, Length);
			return;
		}
		Length *= 2;
	}
}
int main()
{
	int A[110], B[110], A2[110];
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &A[i]);
		A2[i] = A[i];//�洢��ʼ˳��
	}
	for (int i = 0;i < N;i++) {
		scanf("%d", &B[i]);
	}
	if (InsertSort(A, B, N)) {
		printf("Insertion Sort\n");
	}
	else {
		printf("Merge Sort\n");
		for (int i = 0;i < N;i++)//��������Ϊ��ʼ����
			A[i] = A2[i];
		MergeSort(A, B, N);
	} 
	for (int i = 0;i < N;i++) {
		if (!i)
			printf("%d", A[i]);
		else printf(" %d", A[i]);
	}
	return 0;
}