#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct Node
{
	int left;
	int right;
}arr[21];

int last = 0;
bool BFS(int S)
{
	queue<int>q;
	q.push(S);
	bool flag = true;//�ж��Ƿ�����ȫ������
	while (!q.empty()) {
		int temp = q.front();
		last = temp;//���������
		q.pop();
		if (arr[temp].left != -1) {
			q.push(arr[temp].left);
			if (!flag)//֮ǰ�Ѿ��н��û����/����������������˵��������ȫ������
				return false;
		}
		else {
			//��ʱ�ý��û����������
			flag = false;
		}
		if (arr[temp].right != -1) {
			q.push(arr[temp].right);
			if (!flag)//֮ǰ�Ѿ��н��û����/����������������˵��������ȫ������
				return false;
		}
		else {
			//��ʱ�ý��û����������
			flag = false;
		}
	}
	return true;//��ʱ˵������ȫ������
}
int main()
{
	int N;
	string c1, c2;
	int root[21];
	scanf("%d", &N);
	fill(root, root + N, true);
	for (int i = 0;i < N;i++) {
		cin >> c1 >> c2;
		if (c1 == "-")
			arr[i].left = -1;
		else {
			arr[i].left = stoi(c1);
			root[arr[i].left] = false;
		} 
		if (c2 == "-")
			arr[i].right = -1;
		else {
			arr[i].right = stoi(c2);
			root[arr[i].right] = false;
		} 
	}
	int r = 0;
	for (int i = 0;i < N;i++) {
		if (root[i])
			r = i;
	}
	if (BFS(r)) {
		printf("YES %d\n", last);
	}
	else printf("NO %d\n", r);
	return 0;
}