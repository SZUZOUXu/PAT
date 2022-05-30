#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v[1010];//����ÿ�ְ��ö�Ӧ����
vector<int>s[1010];//����ÿ���˶�Ӧ�İ���
bool visited[1010] = { false };
int cnt;
void DFS(int S)//����������
{
	cnt++;
	visited[S] = true;
	for (int i = 0;i < s[S].size();i++) {//s[S][i]������v[s[S][i]][j]������
		for (int j = 0;j < v[s[S][i]].size();j++) {
			if (!visited[v[s[S][i]][j]])
				DFS(v[s[S][i]][j]);
		}
	}
}
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int N, K, h;

	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d: ", &K);
		for (int j = 0;j < K;j++) {
			scanf("%d", &h);
			v[h].push_back(i);
			s[i].push_back(h);
		}
	}
	vector<int>ans;
	for (int i = 0;i < N;i++) {
		if (!visited[i]) {
			cnt = 0;
			DFS(i);
			ans.push_back(cnt);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for (int i = 0;i < ans.size();i++) {
		if (!i)
			printf("%d", ans[i]);
		else printf(" %d", ans[i]);
	}
	return 0;
}