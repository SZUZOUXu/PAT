#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node
{
	int add;
	int data;
	int next;
}Array[100010];
int main()
{
	int N, Address, add;
	scanf("%d %d", &Address, &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &add);
		Array[add].add = add;
		scanf("%d %d", &Array[add].data, &Array[add].next);
	}
	vector<Node>res, rem;
	vector<int>tmp;//�洢���ֹ����ַ�
	while (Address != -1) {
		if (find(tmp.begin(), tmp.end(), abs(Array[Address].data)) != tmp.end()) {
			//�Ѿ������
			rem.push_back(Array[Address]);
		}
		else {
			tmp.push_back(abs(Array[Address].data));//δ�洢�ʹ洢
			res.push_back(Array[Address]);
		}
		Address = Array[Address].next;
	}
	for (int i = 0;i < res.size() - 1;i++) {
		printf("%05d %d %05d\n", res[i].add, res[i].data, res[i + 1].add);
	}
	printf("%05d %d -1\n", res[res.size() - 1].add, res[res.size() - 1].data);
	if (rem.size()) {//��ֹ����Ϊ0�����-��vector.size����ֵ��unsigned int��
		for (int i = 0;i < rem.size() - 1;i++) {
			printf("%05d %d %05d\n", rem[i].add, rem[i].data, rem[i + 1].add);
		}
		printf("%05d %d -1\n", rem[rem.size() - 1].add, rem[rem.size() - 1].data);
	}
	return 0;
}