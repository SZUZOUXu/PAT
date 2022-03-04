#include<iostream>
#include<algorithm>
#include <queue>
#define INF 0x3f3f3f
using namespace std;
int time(int h, int m)//ת����Ϊ����
{
	return 60 * h + m;
}
struct Window//ÿ�����ڵ�ʱ��
{
	//����������˷�����ɻ��ѵ���ʱ��,���ڼ������ķ�ʱ��
	int endtime = time(8, 0);
	//���׵��˷���Ľ���ʱ��,���׷���ʱ����̵ļ�Ϊ���ѡ��Ĵ���
	int poptime = endtime;
	queue<int>q;
}window[20];
int main()
{
	int N, M, K, Q;
	//��mintuesΪ��λ�洢
	int spenttime[1001] = {0};//����ķ�ʱ��
	int finishtime[1001] = {0};//�������ʱ��
	cin >> N >> M >> K >> Q;
	int i;
	for (i = 0;i < K;i++) {
		cin >> spenttime[i];
	}
	//������֮ǰ���
	int idx = 0;//��ţ��ڼ�����
	for (i = 0;i < min(N * M, K);i++) {
		window[idx % N].q.push(idx);//��idx % N���������idx�����
		window[idx % N].endtime += spenttime[idx];
		if (idx < N)//��ʱ���ڻ�û��
			window[idx].poptime = spenttime[idx];
		finishtime[idx] = window[idx % N].endtime;
		idx++;
	}
	while (idx < K) {
		//Ѱ��poptime��С�Ķ���
		int inx = -1, minpoptime = INF;
		for (i = 0;i < N;i++) {
			if (window[i].poptime < minpoptime) {
				inx = i;
				minpoptime = window[i].poptime;
			}
		}
		window[inx].q.pop();//����Ԫ�س���
		window[inx].q.push(idx);//���

		window[inx].endtime += spenttime[idx];
		window[inx].poptime += spenttime[window[inx].q.front()];
		//���׵��˷��񻨷ѵ�ʱ��,��Ϊ֮����˵ıȽ���˻�Ҫ��֮ǰ��Ҳ����
		finishtime[idx] = window[inx].endtime;
		idx++;
	}
	//���
	int queries;
	for (i = 0;i < Q;i++) {
		cin >> queries;
		if (finishtime[queries - 1] - spenttime[queries - 1] >= time(17, 0))
			cout << "Sorry" << endl;//����ʱ��Ҫ����17:00
		else
			printf("%02d:%02d\n", finishtime[queries - 1] / 60, finishtime[queries - 1] % 60);
	}

	return 0;
}