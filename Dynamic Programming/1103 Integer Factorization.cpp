#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int>v, ans, tmpans;
int N, K, P;
void init()//��ʼ��v����Ϊ���б�NС������i^P
{
	int tmp = 0, i = 1;
	while (tmp <= N) {
		v.push_back(tmp);
		tmp = pow(i, P);
		i++;
	}
}

int maxfacsum = -1;//�ֽ���ʽ֮��
void DFS(int i, int sum, int facsum)//��v[i]�����ʼ����DFS
{
	if (tmpans.size() == K) {//����ΪK��ʱ
		if (sum == N && facsum > maxfacsum) {
			maxfacsum = facsum;
			ans = tmpans;//�洢��
		}
		return;
	}
	while (i>=1) {//i�洢������v���±�,Ҳ���Ǹ�����
		if (sum + v[i] <= N) {
			tmpans.push_back(i);
			DFS(i, sum + v[i], facsum + i);
			tmpans.pop_back();
		}
		if (i == 1)//������1�ͷ��أ�����ȥ��0��
			return;
		i--;//ֻ�����ֱ��sum+v[i]>Nʱ�Ż���i--
	}
}
int main()
{
	scanf("%d %d %d", &N, &K, &P);
	init();
	DFS(v.size() - 1, 0, 0);
	if (maxfacsum == -1) {//˵��û�д�
		printf("Impossible");
		return 0;
	}
	printf("%d = ", N);
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0) printf(" + ");
		printf("%d^%d", ans[i], P);
	}
	return 0;

}