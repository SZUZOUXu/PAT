#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	vector<int>v;
	bool flag = true;//�жϸ����
	int level;
}family[110];

int sum[110];
int maxlevel = 0;
void DFS(int S, int level)
{
	family[S].level = level;
	if (level > maxlevel)
		maxlevel = level;
	sum[level]++;
	for (int i = 0;i < family[S].v.size();i++) {
		DFS(family[S].v[i], level + 1);
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int ID, K, IDS;
	for (int i = 0;i < M;i++) {
		scanf("%d %d", &ID, &K);
		for (int j = 0;j < K;j++) {
			scanf("%d", &IDS);
			family[ID].v.push_back(IDS);
			family[IDS].flag = false;//�Ǹ��ڵ�
		}
	}
	int root = 0;
	for (int i = 1;i <= N;i++) {//�����ҵ����ڵ�01 to N
		if (family[i].flag) {
			root = i;
			break;
		}
	}
	DFS(root, 1);
	int num = 1, numl = 1;
	for (int i = 1;i <= maxlevel;i++) {
		if (sum[i] > num) {
			num = sum[i];
			numl = i;
		}
	}
	printf("%d %d\n", num, numl);
	return 0;
}