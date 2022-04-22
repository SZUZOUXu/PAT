#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXN 1010
int N, L;
int G[MAXN][MAXN];

struct Node
{
	int data;
	int level;
};
int  BFS(Node S)
{
	bool collected[MAXN] = { false };//����collected
	collected[S.data] = true;//�ý���Ѿ�������
	queue<Node>q;
	q.push(S);
	int cnt = 0;
	while (!q.empty()) {
		Node top = q.front();//�׽��
		q.pop();
		int topdata = top.data;
		for (int i = 1;i <= N;i++) {
			if (G[topdata][i] == 1 && !collected[i] && top.level < L) {
				//����һ��Ľ����δ���ʹ��Ҳ�����������
				Node Next = { i,top.level + 1 };
				q.push(Next);
				collected[Next.data] = true;
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	scanf("%d %d", &N, &L);
	int M, S;
	for (int i = 1;i <= N;i++) {
		scanf("%d", &M);
		for (int j = 0;j < M;j++) {
			scanf("%d", &S);
			G[S][i] = 1;//i follows S ���Ҫ�ҵ������ĵ���
		}
	}
	int K;
	scanf("%d", &K);
	for (int i = 0;i < K;i++) {
		scanf("%d", &S);
		Node node = { S,0 };
		printf("%d\n", BFS(node));
	}
	return 0;
}