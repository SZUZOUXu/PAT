#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N, M;
	int sum = 0;//��·�ܳ�
	int Dis[100010];
	int Sum[100010];
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> Dis[i];
		sum += Dis[i];
		Sum[i] = Sum[i - 1] + Dis[i];//������i+1����Ҫ��·��
	}
	cin >> M;
	int b, e;//��ʼ�ͽ���
	int dis;
	for (int i = 1;i <= M;i++) {
		cin >> b >> e;
		if (e < b)
			swap(b, e);
		dis = Sum[e - 1] - Sum[b - 1];
		cout << min(dis,sum-dis) << endl;
	}
	return 0;
}