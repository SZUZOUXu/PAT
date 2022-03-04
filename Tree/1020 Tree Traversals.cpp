#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
	int index;
	int value;
};
int postorder[31];//�������
int inorder[31];//�������
Node preorder[31];//������������Ҵ洢Ԫ���±�
int N;

void solve(int PreL, int InL, int PostL, int L, int index);
int cmp(Node a, Node b) //�����±���������
{
	return a.index < b.index;
}
int main()
{
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> postorder[i];
	}
	for (int i = 0;i < N;i++) {
		cin >> inorder[i];
	}
	
	solve(0, 0, 0, N, 0);
	sort(preorder, preorder + N, cmp);
	for (int i = 0;i < N;i++) {
		cout << preorder[i].value;
		if (i != N - 1)
			cout << " ";
	}
		
	return 0;
}

void solve(int PreL, int InL, int PostL, int L, int index)//�������
{
	if (L == 0)
		return;	
	int root = postorder[PostL + L - 1];
	preorder[PreL].value = root;
	preorder[PreL].index = index;
	//���������ҵ����ڵ��λ��
	int i;
	for (i = 0;i < N;i++) {
		if (inorder[InL + i] == root)
			break;
	}
	int l_Length = i;
	int r_Length = L - l_Length - 1;

	solve(PreL + 1, InL, PostL, l_Length, 2 * index + 1);//�������ݹ�
	solve(PreL + l_Length + 1, InL + l_Length + 1, PostL + l_Length, r_Length, 2 * index + 2);//�������ݹ�

}