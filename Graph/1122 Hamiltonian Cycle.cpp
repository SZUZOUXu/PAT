#include<iostream>
#include<vector>
#include<set>
using namespace std;
int G[201][201];
int main()
{
	int N, M, v1, v2;
	scanf("%d %d", &N, &M);
	for (int i = 0;i < M;i++) {
		scanf("%d %d", &v1, &v2);
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
	int K, n, V;

	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &K);
		vector<int>v;
		set<int>s;
		bool flag = true;

		for (int j = 0;j < K;j++) {
			scanf("%d", &V);
			v.push_back(V);
			s.insert(V);
		}
		if (s.size() != N || K - 1 != N)//������ȫ����������ظ����
			flag = false;
		if (v[0] != v[K - 1])//�����㻷
			flag = false;
		for (int i = 0; i < K - 1; i++)
			if (G[v[i]][v[i + 1]] == 0) 
				flag = false;
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}