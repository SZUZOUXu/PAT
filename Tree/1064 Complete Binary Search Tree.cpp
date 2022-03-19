#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int>v;
int node[1010];
int tree[1010];
void Levelorder(int L, int R, int root)
{
	int len = R - L + 1;//�������ĳ���
	if (len == 0)
		return;
	if (len == 1) {
		tree[root] = node[L];
		return;
	}
	int Level = 1, cnt = 1;
	while (cnt < len) {
		cnt += pow(2, Level);
		Level++;
	}
	int Countlength = pow(2, Level - 1) - 1;//��ȥ���һ����ܳ���
	int Lastlength = len - Countlength;//ʵ�����һ��ĳ���
	int Maxlength = pow(2, Level - 1);//���һ�����ĳ���
	int LeftLastlength = Lastlength < (Maxlength / 2) ? Lastlength : (Maxlength / 2);//���һ���������ĳ���
	int Leftlength = LeftLastlength + pow(2, Level - 2) - 1;//������
	tree[root]=node[L+Leftlength];
	Levelorder(L, L + Leftlength - 1, 2*root+1);//������
	Levelorder(L + Leftlength + 1,R, 2*root+2);//������
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> node[i];
	}
	sort(node, node + N);
	Levelorder(0, N - 1, 0);
	for (int i = 0;i < N;i++) {
		if (!i)
			cout << tree[i];
		else cout << " " << tree[i];
	}
	return 0;
}