#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int Matrix[10010][10010];
int main()
{
	int N, m, n;
	scanf("%d", &N);
	int Num[10010];
	for (int i = 0;i < N;i++)
		scanf("%d", &Num[i]);
	sort(Num, Num + N, cmp);
	//ȷ��m��n
	for (int i = sqrt(N);i <= N;i++) {
		int b = N / i;
		if (N % i == 0 && i >= b) {
			m = i, n = b;//����m*n=N,m>=n����С��ֵ
			break;
		}
	}
	int i = 0, j = 0, cnt = 0;
	int rbi = n, lbi = 0, lbj = 1, rbj = m;//�ֱ����к��е����ұ��
	bool iflag = false, jflag = false;//�ж�˳��
	while (lbi <= rbi - 1 || lbj <= rbj - 1) {//������ߵı��С���ұ�
		if (cnt == N)
			break;
		if (lbi <= rbi - 1) {//�жϷ���
			if (!iflag) {//��->�Ҳ������
				for (i = lbi;i < rbi;i++)//
					Matrix[j][i] = Num[cnt++];
				iflag = true;
				rbi--;//��һ�ֵ��Ҳ��1
				i--;//��֤iΪ��ǰԪ����,Ҫ����һ��
			}
			else {//��->��������
				for (i = rbi - 1;i >= lbi;i--)//��ʼ��ԭ��Ҫrbi-1
					Matrix[j][i] = Num[cnt++];
				iflag = false;;
				lbi++;//��һ�ֵ�����1
				i++;
			}
		}
		if (lbj <= rbj - 1) {
			if (!jflag) {//�жϷ���
				for (j = lbj;j < rbj;j++)
					Matrix[j][i] = Num[cnt++];
				jflag = true;
				rbj--;
				j--;
			}
			else {
				for (j = rbj - 1;j >= lbj;j--)
					Matrix[j][i] = Num[cnt++];
				jflag = false;
				lbj++;
				j++;
			}
		}
	}
	//���
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (!j)
				printf("%d", Matrix[i][j]);
			else printf(" %d", Matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}