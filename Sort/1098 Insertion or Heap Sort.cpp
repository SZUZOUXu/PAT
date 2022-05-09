#include<iostream>
using namespace std;

bool Judge(int A[], int B[], int N)
{
	for (int i = 0;i < N;i++) {
		if (A[i] != B[i])
			return false;
	}
	return true;
}
bool Insert_Sort(int A[], int B[], int N)//��������
{
	int i, j;
	for (i = 1;i < N;i++) {
		int tmp = A[i];
		for (j = i;j > 0 && A[j-1] > tmp;j--) {
			A[j] = A[j - 1];
		}
		A[j] = tmp;
		if (Judge(A, B, N)) {//�ٽ���һ�ֲ��ź��˳�
			i++;
			int tmp = A[i];
			for (j = i;j > 0 && A[j - 1] > tmp;j--) {
				A[j] = A[j - 1];
			}
			A[j] = tmp;
			return true;
		}
	}
	return false;
}
void Percdown(int A[], int p, int N)//��pΪ���ڵ㹹������
{
	int parent, child;
	int X = A[p];//������ڵ��ֵ
	for (parent = p;parent * 2 + 1 < N;parent = child) {
		child = 2 * parent + 1;
		if (child + 1 < N && A[child + 1] > A[child])
			child++;//�����ӽ��
		if (X >= A[child])
			break;//��������
		else A[parent] = A[child];
	}
	A[parent] = X;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Heap_Sort(int A[], int B[], int N)
{
	int i;
	for (i = N / 2;i >= 0;i--) {//��������
		Percdown(A, i, N);
	}
	for (i = N - 1;i > 0;i--) {
		swap(&A[0], &A[i]);
		Percdown(A, 0, i);
		if (Judge(A, B, N)) {
			i--;
			swap(&A[0], &A[i]);
			Percdown(A, 0, i);
			break;
		}
	}
}
int main()
{
	int A[110], B[110], A1[110];
	int N;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &A[i]);
		A1[i] = A[i];//������ʼ������
	}
	for (int i = 0;i < N;i++)
		scanf("%d", &B[i]);

	if (Insert_Sort(A, B, N)) {
		printf("Insertion Sort\n");
	}
	else {//����A����
		for (int i = 0;i < N;i++)
			A[i] = A1[i];
		Heap_Sort(A, B, N);
		printf("Heap Sort\n");
	}
	for (int i = 0;i < N;i++) {
		if (!i)
			printf("%d", A[i]);
		else printf(" %d", A[i]);
	}
	return 0;
}