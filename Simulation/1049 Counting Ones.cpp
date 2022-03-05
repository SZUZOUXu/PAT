#include<iostream>
#include<string>
using namespace std;

int CountOnes(int N)
{
	int count = 0;
	int factor = 1;//��λ��ʼ
	int higher, lower, cur;
	while (N / factor != 0) {
		higher = N / (factor * 10);//��ǰλ�ĸ�λ
		lower = N - (N / factor) * factor;//��ǰλ�ĵ�λ
		cur = (N / factor) % 10;//��ǰλ
		switch (cur) {
		case 0://��ǰλΪ0����ǰλ��1�������ɸ�λ����
			count += higher * factor;
			break;
		case 1://��ǰλΪ1����ǰλ��1�����ɸ�λ�͵�λ+1����
			count += higher * factor + lower + 1;
			break;
		default://��ǰλ����1����ǰλ��1�����ɸ�λ+1����
			count += (higher + 1) * factor;
		}
		factor = factor * 10;
	}
	return count;
}
int main()
{
	int N;
	cin >> N;
	cout << CountOnes(N) << endl;
	return 0;
}