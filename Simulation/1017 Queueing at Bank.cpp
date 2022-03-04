#include<iostream>
#include<queue>
#include<algorithm>
#define maxn 10001//����Ŷ�����
#define begin 28800//08��00��s��
#define end 61200//17��00��s��
using namespace std;

struct person
{
	int come;//����ʱ��
	int time;//�ȴ���ʱ��
}p[maxn];

int cmp(person p1, person p2)//��������ʱ����������
{
	return p1.come < p2.come;
}
int main()
{
	int N, K;
	cin >> N >> K;
	int hh, mm, ss, tt;
	int sum = 0;
	int cnt = 0;//��ʵ���������
	for (int i = 0;i < N;i++) {
		scanf_s("%d:%d:%d", &hh, &mm, &ss);
		cin >> tt;
		sum = 3600 * hh + 60 * mm + ss;
		if (sum > end)
			continue;
		p[cnt].come = sum;
		p[cnt].time = tt * 60;
		cnt++;
	}
	sort(p, p + cnt, cmp);//���յ������е�ʱ���������
	priority_queue<int, vector<int>, greater<int>>q;//����������������ȶ���
	for (int i = 0;i < K;i++) {
		q.push(begin);//��ÿ�����ڵ���ʼֵ���
	}
	int total = 0;//�ܵȴ�����
	for (int i = 0;i < cnt;i++) {
		if (p[i].come < q.top()) {//���ıȶ��׽��������ʱ��Ҫ��-�ȴ�
			total += (q.top() - p[i].come);//�ȴ���ʱ��
			q.push(q.top() + p[i].time);//��������ɷ����ʱ�����
			q.pop();//���׳���
		}
		else {//���ıȶ��׽��������ʱ��Ҫ��-���õȴ�
			q.push(p[i].come + p[i].time);//ֱ�Ӱ���ҵ�����
			q.pop();//���׳���
		}
	}
	if (cnt == 0)
		printf("0.0\n");
	else
		printf("%.1f\n", (total / 60.0) / cnt * 1.0);//������
	return 0;
}