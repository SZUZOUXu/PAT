#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
struct Node
{
	int weight;
	int order;//�����������˳���������±�
	int rank;
	int porder;//����ǰ��˳��
}Array[100010];
bool cmp(Node a, Node b)
{
	return a.order < b.order;
}
int main()
{
	int Np, Nc;
	cin >> Np >> Nc;
	vector<int>v(Np);
	vector<Node>w(Np);
	int num;
	for (int i = 0;i < Np;i++) {
		cin >> v[i];
	}
	for (int i = 0;i < Np;i++) {
		cin >> num;
		w[i].order = num;//��6 0 8 7...
		w[i].porder = i;//��0 1 2 3...
		w[i].weight = v[num];
	}
	queue<Node>q;
	for (int i = 0; i < Np; i++)
		q.push(w[i]);//���ո�����˳�����
	while (!q.empty()) {//���в��յ����
		int size = q.size();
		if (size == 1) {//��һ��Ԫ��
			Node temp = q.front();
			w[temp.porder].rank = 1;
			break;
		}
		int group = size / Nc;//�������󱻷ֳ��˼���
		if (size % Nc != 0)
			group += 1;
		Node maxnode;
		int maxn = -1, cnt = 0;
		for (int i = 0; i < size; i++) {
			Node temp = q.front();
			w[temp.porder].rank = group + 1;//һ��һ�ֵ��޸�rank
			q.pop();
			cnt++;
			if (temp.weight > maxn) {//����Nc�����Ľ��
				maxn = temp.weight;
				maxnode = temp;
			}
			if (cnt == Nc || i == size - 1) {
				cnt = 0;
				maxn = -1;
				q.push(maxnode);//�����Ľ���������
			}
		}
	}
	sort(w.begin(), w.end(), cmp);//����ԭ����˳���������
	for (int i = 0; i < Np; i++) {
		if (i != 0) printf(" ");
		printf("%d", w[i].rank);
	}
	return 0;
}