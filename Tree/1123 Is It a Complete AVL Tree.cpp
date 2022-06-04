#include<iostream>
#include<queue>
using namespace std;
typedef struct Node* BinTree;
struct Node
{
	int data, height;
	BinTree left, right;
};

BinTree BuildTree(int V);//��VΪ��㽨��
int GetHeight(BinTree T);//�������ĸ߶�
int Max(int a, int b);
BinTree LL(BinTree T);
BinTree RR(BinTree T);
BinTree LR(BinTree T);
BinTree RL(BinTree T);
BinTree Insert(BinTree T, int V);
void Levelorder(BinTree T);
int main()
{
	int N;
	BinTree T = NULL;//��ʼ��
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		int V;
		scanf("%d", &V);
		T = Insert(T, V);
	}
	//�������
	Levelorder(T);
	return 0;
}
BinTree BuildTree(int V)
{
	BinTree T = (BinTree)malloc(sizeof(struct Node));
	T->data = V;
	T->left = T->right = NULL;
	T->height = 0;
	return T;
}
int GetHeight(BinTree T)
{
	if (!T)
		return -1;
	else return T->height;
}
int Max(int a, int b)
{
	return a > b ? a : b;
}
BinTree LL(BinTree T)
{
	BinTree B = T->left;
	T->left = B->right;
	B->right = T;
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	B->height = Max(GetHeight(B->left), T->height) + 1;
	return B;
}
BinTree RR(BinTree T)
{
	BinTree B = T->right;
	T->right = B->left;
	B->left = T;
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	B->height = Max(GetHeight(B->left), T->height) + 1;
	return B;
}
BinTree LR(BinTree T)
{
	T->left = RR(T->left);
	return LL(T);
}
BinTree RL(BinTree T)
{
	T->right = LL(T->right);
	return RR(T);
}
BinTree Insert(BinTree T, int V)
{
	if (!T)
		T = BuildTree(V);
	else if (V < T->data) {
		T->left = Insert(T->left, V);
		//���¶��ϵ���
		if (GetHeight(T->left) - GetHeight(T->right) == 2) {//���ƻ��Ľ��
			if (V < T->left->data)
				T = LL(T);
			else
				T = LR(T);
		}
	}
	else if (V > T->data) {
		T->right = Insert(T->right, V);
		//�Ը��½���·�����ϵ���AVL��
		if (GetHeight(T->right) - GetHeight(T->left) == 2) {
			if (V > T->right->data)
				T = RR(T);
			else
				T = RL(T);
		}
	}
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	return T;
}
void Levelorder(BinTree T)
{
	queue<BinTree>q;
	q.push(T);
	bool flag1 = true, flag2 = true;//�ж��Ƿ�����ȫ������
	bool first = true;
	while (!q.empty()) {
		BinTree tmp = q.front();
		q.pop();
		if (first) {
			printf("%d", tmp->data);
			first = false;
		}
		else printf(" %d", tmp->data);
		if (tmp->left != NULL) {
			q.push(tmp->left);
			if (!flag1)//֮ǰ�Ѿ��н��û����/������ ��������˵��������ȫ������
				flag2 = false;//flag2�����Ƿ�����ȫ������
		}
		else
			flag1 = false;

		if (tmp->right != NULL) {
			q.push(tmp->right);
			if (!flag1)
				flag2 = false;
		}
		else
			flag1 = false;
	}
	if (flag2)
		printf("\nYES");
	else printf("\nNO");
}