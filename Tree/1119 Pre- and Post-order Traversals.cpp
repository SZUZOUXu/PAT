#include<iostream>
#include<vector>
using namespace std;
int pre[31];
int post[31];
vector<int>in;
int root;
bool unique = true;
void Traversal(int prel, int prer, int postl, int postr)
{
	if (prel == prer) {//������ֻ��һ�������
		in.push_back(pre[prel]);
		return;
	}
	if (pre[prel] == post[postr]) {//�ҵ���������
		int i = prel + 1;//����preorder�ҵ������������ڣ��ĸ����
		while (i <= prer && pre[i] != post[postr - 1])
			i++;
		//����������i-prel-1
		if (i - prel > 1) {//�������������֮�����ٸ���һ����㣬Ҳ������������
			Traversal(prel + 1, i - 1, postl, postl + (i - prel - 1) - 1);
		}
		else//����������Ϊ�գ�����ֻ�������������
			unique = false;
		in.push_back(post[postr]);//��
		Traversal(i, prer, postl + (i - prel - 1), postr - 1);
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0;i < N;i++) {
		scanf("%d", &post[i]);
	}
	
	Traversal(0, N - 1, 0, N - 1);
	printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
	for (int i = 1; i < in.size(); i++)
		printf(" %d", in[i]);
	printf("\n");
	return 0;
}