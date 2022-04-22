#include<iostream>
#include<string>
using namespace std;

int N;
int Inorder[31];
int Preorder[31];
int Postorder[31];

void solve(int PreL, int InL, int PostL, int len);

int main()
{
	string s;
	int num;
	int Intop = 0, Pretop = 0, Posttop = 0;
	int stack[31] = { 0 }, top = 0;//������ջ��ջ��ָ��,ָ��ջ����һ��Ԫ��
	scanf("%d", &N);
	for (int i = 0;i < 2 * N;i++) {
		cin >> s;
		if (s == "Push") {
			scanf("%d", &num);
			stack[top++] = num;
			Preorder[Pretop++] = num;//Push����Preorder
		}
		else {
			top--;
			Inorder[Intop++] = stack[top];
		}
	}
	solve(0, 0, 0, N);
	for (int i = 0;i < N;i++) {
		if (!i)
			printf("%d", Postorder[i]);
		else printf(" %d", Postorder[i]);
	}
	return 0;
}
void solve(int PreL, int InL, int PostL, int len)
{
	int root = Preorder[PreL];
	if (len == 0)
		return;
	Postorder[PostL + len - 1] = root;//����������Ҳ�Ϊ���ڵ��λ��
	//����Inorderȷ����������
	int i;
	for (i = InL;i < N;i++) {
		if (Inorder[i] == root)
			break;
	}
	int leftlen = i - InL;
	int rightlen = len - leftlen - 1;
	solve(PreL + 1, InL, PostL, leftlen);//�ݹ�������
	solve(PreL + leftlen + 1, InL + leftlen + 1, PostL + leftlen, rightlen);//�ݹ�������
}