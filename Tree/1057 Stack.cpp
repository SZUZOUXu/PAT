#include<iostream>
#include<stack>
#include<string>
using namespace std;
#define lowbit(i) ((i)&(-i))//ȡ���λ��1
const int maxn = 100010;
stack<int>s;
//��״���飬������sum�ͽ����޸�
int c[maxn];//��״���飬ÿ�������������������ֵĴ���
void update(int x, int v)//�����޸�(v���������x�Ĵ���)
{
	for (int i = x;i < maxn;i += lowbit(i)) {
		c[i] += v;//˳����������
	}
}
int getsum(int x)//�����ѯ,С�ڵ���x�����ĸ���
{
	int sum = 0;
	for (int i = x;i >= 1;i -= lowbit(i)) {
		sum += c[i];
	}
	return sum;
}

void PeekMedian() //���ַ�
{
	int left = 1, right = maxn, mid;//Key��֤>0
	int k = (s.size() + 1) / 2;//����Ҫ��ĵ�k��С����
	while (left < right) {
		mid = (left + right) / 2;
		if (getsum(mid) >= k)//С�ڵ���mid�����ĸ�������k��
			right = mid;
		else
			left = mid + 1;
	}
	printf("%d\n", left);
}
int main()
{
	int N, Key;
	cin >> N;
	string cmd;
	for (int i = 0;i < N;i++) {
		cin >> cmd;
		if (cmd == "Push") {
			cin >> Key;
			s.push(Key);
			update(Key, 1);
		}
		else if (cmd == "Pop") {
			if (!s.empty()) {
				update(s.top(), -1);
				printf("%d\n", s.top());
				s.pop();
			}
			else {
				printf("Invalid\n");
			}
		}
		else {//Ѱ���м�ֵ
			if (!s.empty())
				PeekMedian();
			else
				printf("Invalid\n");
		}
	}
	return 0;
}