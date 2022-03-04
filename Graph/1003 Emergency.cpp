#include<iostream>
using namespace std;
#define INF 100000
typedef struct GNode* MGraph;
struct GNode {
	int Nv;//����
	int Ne;//����
	int G[501][501];
};

typedef struct ENode* Edge;
struct ENode {
	int V1, V2;
	int Weight;//Ȩ��
};
int c1, c2;
int Weight[501] = { 0 };//�洢·��Ȩ��
int collected[501] = { 0 };//�ý���Ƿ񱻷���
int Dist[501];//���·������
int Num[501] = { 0 };//���·��������
int Gather[501] = { 0 };//���֧Ԯ�Ӽ�����
MGraph CreateGraph(int N)
{
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Ne = 0;
	Graph->Nv = N;
	fill(Graph->G[0], Graph->G[0] + 501 * 501, INF);
	return Graph;
}
void InsertGraph(MGraph Graph, Edge E)
{
	/*�����<V1,V2>*/
	Graph->G[E->V1][E->V2] = E->Weight;
	/*����ͼ*/
	Graph->G[E->V2][E->V1] = E->Weight;
}
MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int Nv;
	cin >> Nv;
	Graph = CreateGraph(Nv);
	cin >> Graph->Ne;
	cin >> c1 >> c2;
	for (int i = 0;i < Graph->Nv;i++)
	{
		cin >> Weight[i];
	}
	if (Graph->Ne != 0) {
		for (int i = 0;i < Graph->Ne;i++) {
			E = (Edge)malloc(sizeof(struct ENode));
			cin >> E->V1 >> E->V2 >> E->Weight;
			InsertGraph(Graph, E);
		}
	}
	
	return Graph;
}
void Dijikstra(MGraph Graph)
{
	fill(Dist, Dist + 501, INF);
	Dist[c1] = 0;//��ʼ��
	Gather[c1] = Weight[c1];//����ʼ��ľ�Ԯ�Ӹ���
	Num[c1] = 1;//���·��������1��

	while (1)
	{
		int u = -1, mindist = INF;
		for (int j = 0;j < Graph->Nv;j++) {
			if (collected[j] == 0 && Dist[j] < mindist) {
				mindist = Dist[j];
				u = j;//δ��¼������Dist��С��
			}
		}
		if (u == -1)//�����Ķ��㲻����
			break;
		collected[u] = -1;//�����ʹ���
		for (int j = 0;j < Graph->Nv;j++) {
			if (collected[j] == 0 && Graph->G[u][j] != INF) {//δ���ʹ����ڽ��
				if (Dist[j] > Dist[u] + Graph->G[u][j]) {
					Dist[j] = Dist[u] + Graph->G[u][j];//�������·������
					Num[j] = Num[u];//�������·��������
					Gather[j] = Gather[u] + Weight[j];//����·���ϵľ�Ԯ����
				}
				else if (Dist[j] == Dist[u] + Graph->G[u][j]) {
					Num[j] += Num[u];//����·������
					if (Gather[j] < Gather[u] + Weight[j])//��ʱ��Ҫ�Ҿ�Ԯ���������
						Gather[j] = Gather[u] + Weight[j];
				}
			}
		}
	}
}
int main()
{
	MGraph Graph;
	Graph = BuildGraph();
	Dijikstra(Graph);
	cout << Num[c2] << " " << Gather[c2];
	return 0;
}