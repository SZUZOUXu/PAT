#include<iostream>
using namespace std;

int main()
{
	int N, M;
	int Collected[101] = { 0 };//�Ƿ���Ҷ�ӽ��1-���ǣ�0-��
	int Level[101] = { 0 };//��ʾ����
	Level[1] = 1;//���Ϊ1�ĸ��ڵ���Ϊ1
	int result[101] = { 0 };//������
	int Father[101] = { 0 };//�洢���׽��

	cin >> N >> M;//N�����н����,M����Ҷ�ӽ����
	int ID, K, L, IDS, MAXL = 1;

	for (int i = 0;i < M;i++) {
		cin >> ID >> K;
		if (K > 0)
			Collected[ID] = 1;//��Ҷ�ӽ��
		for (int j = 0;j < K;j++) {
			cin >> IDS;
			Father[IDS] = ID;
		}
	}

	//����Level��֮���Բ��������ʱ����£�����Ϊ���ܸ���㵱ʱ��û�����������ӣ�
	for (int i = 1;i <= N;i++) {
		for (int j = 0;j <= N;j++) {
			if (Father[j] == i) {
				Level[j] = Level[i] + 1;
			}
		}
	}

	//���
	for (int i = 1;i <= N;i++) {//��������
		if (Collected[i] == 0)
			result[Level[i]]++;//�ò��Ҷ�ӽ��������
		if (Level[i] > MAXL)
			MAXL = Level[i];
	}
	
	for (int i = 1;i < MAXL;i++) {
		cout << result[i] << " ";
	}
	cout << result[MAXL];
	return 0;
}