#include<iostream>
using namespace std;
int main()
{
	int N, M, K;
	cin >> M >> K >> N;
	int seq[1010];

	for (int i = 0;i < N;i++) {
		for (int k = 0;k < K;k++) {
			cin >> seq[k];
		}
		int j = 0;//���ջ��Ԫ�صĸ���
		int num = 1;//ջ��Ԫ�ص���ʼ
		int stack[1010] = { 0 }, top = 0;//����һ��ջ
		stack[top] = num;
		while (j < K) {
			if (seq[j] < stack[top])//��ջ��Ԫ��С��312�����
				break;
			while (seq[j] > stack[top]) {
				stack[++top] = ++num;
			}
			if (top >= M)//�ݳ������
				break;
			if (seq[j] == stack[top])
				top--;
			j++;
		}
		if (j == K)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}