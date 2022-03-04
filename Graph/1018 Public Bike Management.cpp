#include<iostream>
#include<vector>
using namespace std;
#define maxn 501
#define INF 0x3f3f3f

int G[maxn][maxn];//�ڽӾ���
int Dist[maxn];//�洢��̾���
bool visited[maxn] = { false };//�Ƿ���ʹ�
vector<int> prenode[maxn];//�洢��һ�����
vector<int> path, tmppath;
int CMax, N, Sp, M;
int C[501];//�洢ÿ���ص�ĵ�����
int minsend = INF, minback = INF;//��С����ֵ����С����ֵ

void Dijkstra(int S);
void DFS(int vi);

int main()
{
	fill(G[0], G[0] + maxn * maxn, INF);
	cin >> CMax >> N >> Sp >> M;
	int i;
	for (i = 1;i <= N;i++) {
		cin >> C[i];
	}
	int S1, S2, T;
	for (i = 0;i < M;i++) {
		cin >> S1 >> S2 >> T;
		G[S1][S2] = T;
		G[S2][S1] = T;
	}
	Dijkstra(0);
	DFS(Sp);
	printf("%d ", minsend);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d", path[i]);
		if (i)
			printf("->");
	}
	printf(" %d\n", minback);
	return 0;	
}

void Dijkstra(int S)//��Դ���·��
{
	fill(Dist, Dist + maxn, INF);
	Dist[S] = 0;
	while (1) {
		int u = -1;//δ��¼������Ȩֵ��С
		int mint = INF;
		for (int i = 0;i < N;i++) {
			if (!visited[i] && Dist[i] < mint) {
				mint = Dist[i];
				u = i;
			}
		}
		if (u == -1)//û���ҵ�
			return;
		visited[u] = true;//�Ѿ������ʹ�
		for (int i = 0; i <= N; i++) {
			if (!visited[i] && G[u][i] != INF) {
				if (Dist[u] + G[u][i] < Dist[i]) {
					Dist[i] = Dist[u] + G[u][i];
					prenode[i].clear();
					prenode[i].push_back(u);
				}
				else if (Dist[u] + G[u][i] == Dist[i]) {
					prenode[i].push_back(u);
				}
			}
		}
	}
}

void DFS(int vi)//����������ĵص�
{
	if (vi == 0) {//��ʱ�Ѿ��ǵ���ԭ����
		tmppath.push_back(0);
		int minsendtmp = 0, minbacktmp = 0;
		for (int i = tmppath.size() - 2; i >= 0; i--) {//�����������ѵĵص�
			int t = tmppath[i];//��ʼ��Ϊ�����ѵĵص�ǰһ��
			if (minbacktmp + C[t] < CMax / 2)//�ж��Ƿ�Ҫ���س�
				//˵�����÷��س���Ҫ����ȥ��
				minsendtmp += CMax / 2 - (minbacktmp + C[t]), minbacktmp = 0;
			else {//Ҫ���س�
				if (C[t] > CMax / 2)//����
					minbacktmp += C[t] - CMax / 2;//��ľ�Ҫ��ȥ��ʱ�����
				else//����
					minbacktmp -= CMax / 2 - C[t];//ֱ�Ӽ�ȥ
			}
		}
		if (minsendtmp < minsend)//����·��
			path = tmppath, minsend = minsendtmp, minback = minbacktmp;
		else if (minsendtmp == minsend && minbacktmp < minback)
			path = tmppath, minback = minbacktmp;
		tmppath.pop_back();//ԭ��(0)����
		return;//��ʱ��һ��·���Ѿ�������
	}
	tmppath.push_back(vi);
	for (int i = 0; i < prenode[vi].size(); i++)//�����ý��֮ǰ�Ľ��
		DFS(prenode[vi][i]);
	tmppath.pop_back();//��vi�����㵯��
}