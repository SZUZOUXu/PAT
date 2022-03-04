#include<iostream>
#define INF 0x3f3f3f
using namespace std;
int main()
{
	int Capacity, Distance, Davg, N;
	cin >> Capacity >> Distance >> Davg >> N;
	float Price[30001];
	fill(Price, Price + 30001, INF);
	float P;
	int D;
	for (int i = 0;i < N;i++) {
		cin >> P >> D;
		Price[D] = P;
	}
	int MaxD = Capacity * Davg;
	int Begin = 0;//��ʼ��
	float cost = 0;//�ܻ���
	int  MinStation;
	float MinPrice, len, NowGas = 0;
	while (Begin < Distance) {
		MinPrice = INF;
		if (Price[0] == INF) {//�޷�����
			printf("The maximum travel distance = 0.00\n");
			return 0;
		}
		for (int i = Begin + 1;i <= Begin + MaxD;i++) {//�ڿ��Ե������Զ������Ѱ��
			if (i <= Distance && Price[i] < Price[Begin]) {//ֱ�ӵ���۸���͵ĵط�,��ֹ�����ݳ�
				len = i - Begin;
				//��ʱ��������
				if (!NowGas)
					cost += (len / Davg) * Price[Begin];
				else cost += ((len / Davg) - NowGas) * Price[Begin];//��ȥ�Ѿ��е���
				Begin = i;//������ʼ��
				continue;
			}
			if (i <= Distance && Price[i] < MinPrice) {
				MinPrice = Price[i];
				MinStation = i;
			}
		}
		if (Distance - Begin <= MaxD) {
			len = Distance - Begin;
			cost += (len / Davg) * Price[Begin];//��������һ��·����
			break;
		}
		if (MinPrice == INF) {//˵��û��վ����
			float result = Begin + MaxD;
			printf("The maximum travel distance = %.2f\n", result);
			return 0;
		}
		len = MinStation - Begin;
		//������
		if (!NowGas)
			cost += Capacity * Price[Begin];//�յ����
		else
			cost += (Capacity - NowGas) * Price[Begin];
		//NowGasָ������һ��վ���ʣ�����
		NowGas = Capacity - (len / Davg);//������ȥ���·���������
		Begin = MinStation;
	}
	printf("%.2f", cost);
	return 0;
}