#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node
{
	int ID, Father, Mother, M, area;
	vector<int>child;
}fam[1010];

struct ANode
{
	int ID, Person;
	double Sum, area;
	bool flag = false;//
}ans[10000];
int father[10000];//ʵ�ֲ��鼯
bool visited[10000] = {false};
int find(int x)//�ҵ�û�и������Ǹ����
{
	while (x != father[x]) {
		x = father[x];
	}
	return x;
}
void Union(int a, int b)//ʹ��ID��С�Ľ���Ϊ���ڵ�
{
	int fa = find(a);
	int fb = find(b);
	if (fa > fb)
		father[fa] = fb;
	else if (fa < fb)
		father[fb] = fa;
}
bool cmp(ANode a, ANode b)
{
	if (a.area != b.area)
		return a.area > b.area;
	else
		return a.ID < b.ID;
}
int main()
{
	for (int i = 0; i < 10000; i++)
		father[i] = i;//����find����
	int N, ID, K, c;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d %d %d %d", &fam[i].ID, &fam[i].Father, &fam[i].Mother, &K);
		visited[fam[i].ID] = true;
		if (fam[i].Father != -1) {
			visited[fam[i].Father] = true;//�����˵Ľ�㣬����֮�����ͳ������
			Union(fam[i].Father, fam[i].ID);
		}
		if (fam[i].Mother != -1) {
			visited[fam[i].Mother] = true;
			Union(fam[i].Mother, fam[i].ID);
		}
		for (int j = 0;j < K;j++) {
			scanf("%d", &c);
			fam[i].child.push_back(c);
			visited[c] = true;
			Union(c, fam[i].ID);
		}
		scanf("%d %d", &fam[i].M, &fam[i].area);
	}
	for (int i = 0;i < N;i++) {
		ID = find(fam[i].ID);
		ans[ID].flag = true;//�������ID��һ����ͥ�ĸ��ڵ�
		ans[ID].ID = ID;
		ans[ID].area += fam[i].area;
		ans[ID].Sum += fam[i].M;
		//��ʱ������person����Ϊ�в�����û�з��Ӳ���fam[i].ID��
	}
	int cnt = 0;//����
	for (int i = 0;i < 10000;i++) {
		if(visited[i])//�����Ͳ���©��û�з��ӵ���
			ans[find(i)].Person++;
		if (ans[i].flag)//ÿ����ͥ�ĸ��ڵ�
			cnt++;
	}
	for (int i = 0;i < 10000;i++) {//ͳ��������Person���ܼ���AVG
		if (ans[i].flag) {
			ans[i].Sum = ans[i].Sum / ans[i].Person;
			ans[i].area = ans[i].area / ans[i].Person;
		}
	}
	sort(ans, ans + 10000, cmp);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%04d %d %.3f %.3f\n", ans[i].ID, ans[i].Person, ans[i].Sum, ans[i].area);
	return 0;
}