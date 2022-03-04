#include<iostream>
#include<vector>
using namespace std;
bool isMirror, flag = true;
int N;
vector<int> pre, post;

void PostOrder(int s, int e)//sΪ���ڵ㡢eΪ���Ľ��(���������ʼ�ͽ������)
{
	if (!flag || s > e) 
		return;
	int i = s + 1, j = e;//iΪ�������ĸ�,jΪ�����������Ľ��
	if (isMirror == false) {//���Ǿ���������С����������
		while (i <= e && pre[s] > pre[i]) i++;//����ȸ��ڵ�С�͵���
		while (j > s && pre[s] <= pre[j]) j--;//����ȸ��ڵ��͵ݼ�
	}
	else if (isMirror == true) {//������
		while (i <= e && pre[s] <= pre[i]) i++;           
		while (j > s && pre[s] > pre[j])  j--;
	}
	if (i - j != 1) {//��ʱi��Ӧ�Ľ��ȸ�С��j��Ӧ�Ľ��ȸ������Ϊ1
		flag = false;
		return;
	}
	//����-������
	PostOrder(s + 1, i - 1);//������
	PostOrder(i, e);//������
	post.push_back(pre[s]);//���ڵ����

}
int main()
{
	cin >> N;
	pre.resize(N);
	for (int i = 0;i < N;i++) {
		cin >> pre[i];
	}
	if (N > 1 && pre[1] - pre[0] > 0) //�ٶ��Ǿ����
		isMirror = true;
	PostOrder(0, N - 1);
	if (!flag)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 0;i < post.size();i++) {
			if (i)
				cout << " ";
			cout << post[i];
		}
	}
	return 0;
}