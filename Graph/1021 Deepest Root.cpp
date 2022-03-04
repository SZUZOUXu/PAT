#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 10001
vector <int>G[MAXN];
vector <int>p;
int N;
int maxd, maxD = -1;
bool visited[MAXN] = { false };//�Ƿ���ʹ�
int in[MAXN];//���Ӹý��ı���

void DFS(int S, int deep);

int main()
{
	memset(in, 0, sizeof(in));
	cin >> N;
	int S1, S2;
	for (int i = 0;i < N - 1;i++) {
		cin >> S1 >> S2;
		G[S1].push_back(S2);
		G[S2].push_back(S1);
		in[S1]++;
		in[S2]++;
	}
	int cnt = 0;//�ж��Ƿ���ͨ
	for (int k = 1;k <= N;k++) {
		fill(visited, visited + MAXN, false);//���÷��ʽ��
		maxd = 0;//����������
		if (k == 1) {
			for (int i = 1;i <= N;i++) {//����ͼ
				if (!visited[i]) {
					DFS(i, 1);
					cnt++;
				}
			}
			if (cnt > 1) {//����ͨ�����
				printf("Error: %d components", cnt);
				return 0;
			}
		}
		else {
			if (in[k] != 1) {//���ӵı���>1��һ���������������ȵ���ʼ��
				continue;
			}
			DFS(k, 1);
		}
		if (maxd > maxD) {
			maxD = maxd;
			p.clear();
			p.push_back(k);//�洢�����ȵĽ��
		}
		else if (maxd == maxD) {
			p.push_back(k);
		}
	}
	for (int i = 0;i < p.size();i++) {
		cout << p[i] << endl;
	}

	return 0;
}

void DFS(int S, int deep)//dfs�ҵ�������
{
	visited[S] = true;
	//����S��ÿ���ڽӵ�
	for (int i = 0;i < G[S].size();i++) {
		if (!visited[G[S][i]]) {
			visited[G[S][i]] = true;
			if (deep > maxd) {
				maxd = deep;
			}
			DFS(G[S][i], deep + 1);
		}
	}
}