#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define begin 28800//��ʼ��ʱ��
#define end 75600//������ʱ��
using namespace std;

int N;

struct Person
{
	int arrive;//����ʱ��
	float wait;//�ȴ�ʱ��
	int serve;//����ʱ��
	int play;//ѵ��ʱ��
	int tag;//�Ƿ���VIP
	bool served = false;//�Ƿ񱻷����
}p[10001];

struct table
{
	int poptime = begin;//����ʱ��
	int count = 0;//�Ӵ�����
	bool vip;
};
vector<table> tables;
bool cmp1(Person a, Person b)
{
	return a.arrive < b.arrive;
}
bool cmp2(Person a, Person b)
{
	return a.serve < b.serve;
}
int FindNextVIP(int vip_id) //��ѯ�����е�һ��û�б������VIP
{
	vip_id++;
	while (vip_id < N && !p[vip_id].tag)
		vip_id++;
	return vip_id >= N ? 0 : vip_id;
}
void alloc(int id, int table_id)//Ϊ��id���˷�������
{
	if (tables[table_id].poptime <= p[id].arrive)//����Ҫ�ȴ�
		p[id].serve = p[id].arrive;//����ʱ���뵽��ʱ��һ��
	else
		p[id].serve = tables[table_id].poptime;//����ʱ�������ӵĿ���ʱ��һ��
	tables[table_id].poptime = p[id].serve + p[id].play;
	tables[table_id].count++;//�Ӵ�������+1
	p[id].wait = round((p[id].serve - p[id].arrive) / 60.0);
	p[id].served = true;

}

int main()
{
	int i;
	int hh, mm, ss, tt, tag;
	cin >> N;
	int sum = 0;
	for (i = 0;i < N;i++) {
		scanf_s("%d:%d:%d %d %d", &hh, &mm, &ss, &tt, &tag);
		sum = 3600 * hh + 60 * mm + ss;
		p[i].arrive = sum;
		p[i].play = p[i].play <= 120 ? tt * 60 : 120 * 60;//ѵ��ʱ��ҪС��120
		p[i].tag = tag;
	}
	int K, M;
	cin >> K >> M;
	tables.resize(K + 1);//��ʼ������
	int table;
	for (i = 0;i < M;i++) {
		cin >> table;
		tables[table].vip = true;
	}
	sort(p, p + N, cmp1);//���յ�����ʱ���������
	int vip_id = FindNextVIP(-1);//�ҵ�VIP���ڵ�λ��
	i = 0;
	while (i < N) {
		if (p[i].serve) {//�ҵ�δ���������
			i++;
			continue;//�����ַ�ʽ����VIP�û�
		}
		int min_table_id = -1;//�����ұ����С������
		int min = 0x3f3f3f;//��̵Ŀ���ʱ��
		for (int j = 1;j <= K;j++) {//�������������ҵ����е�����
			if (tables[j].poptime < min) {
				min = tables[j].poptime;
				min_table_id = j;
			}
			if (tables[j].poptime <= p[i].arrive) {//���ڿ��е�����
				min_table_id = j;
				break;
			}
		}
		if (tables[min_table_id].poptime >= end || p[i].arrive >= end)
			break;//�Ŷӽ���
		if (p[i].tag == 1) {//��VIP�����
			int vip_table_id = -1;//vip�����п����������С
			for (int j = 1;j <= K;j++) {//�����Ƿ��п��е�VIP����
				if (tables[j].vip && tables[j].poptime <= p[i].arrive) {
					vip_table_id = j;
					break;
				}
			}
			if (i == vip_id)
				vip_id = FindNextVIP(vip_id);//������һ��VIP��λ��
			if (vip_table_id == -1) {//û��VIP��ֻ�ܷ�����ͨ����
				alloc(i++, min_table_id);
			}
			else {
				alloc(i++, vip_table_id);
			}
		}//����VIP�����
		else {
			if (tables[min_table_id].vip) {//��VIP����
				if (!p[vip_id].serve && p[vip_id].arrive <= tables[min_table_id].poptime) {
					//��VIP�û���û�������Ҹ�VIP��ӵ�ʱ�����ӻ�δ����
					alloc(vip_id, min_table_id);
					vip_id = FindNextVIP(vip_id);
					continue;
				}
			}
			alloc(i++, min_table_id);//��������û�
		}
	}
	sort(p, p + N, cmp2);//����serve��ʱ���������
	for (int j = 0;j < N;j++) {
		if (p[j].served) {
			printf("%02d:%02d:%02d ", p[j].arrive / 3600, (p[j].arrive % 3600) / 60,
				(p[j].arrive % 3600) % 60);
			printf("%02d:%02d:%02d %.0f\n", p[j].serve / 3600, (p[j].serve % 3600) / 60,
				(p[j].serve % 3600) % 60,p[j].wait);
		}
	}
	for (int j = 1;j <= K;j++) {
		if (j != 1) printf(" ");
		printf("%d", tables[j].count);
	}
	return 0;
}