#include<iostream>
using namespace std;
/*
int main()
{
	int a, b, len = 0;
	cin >> a >> b;
	int c = a + b;

	int k = c;
	if (k < 0)
		k = -k;
	while (k > 0) {
		k /= 10;
		len++;
	}
	if (c == 0)//�������Ϊ0�����
		len = 1;
	int yu, i;
	yu = len % 3;
	int t[8];
	k = c;
	if (k < 0)
		k = -k;
	for (i = 0;i < len;i++) {
		t[i] = k % 10;
		k /= 10;
	}
	len--;
	if (c < 0)
		cout << "-";
	int flag = 0;//�ж��Ƿ��������
	while (yu > 0) {
		cout << t[len];
		len--;
		yu--;
		flag = 1;
	}

	while (len >= 0) {
		if ((len + 1) % 3 == 0 && flag == 1)
			cout << ",";
		cout << t[len];
		len--;
		flag = 1;
	}
	return 0;
}
*/
int main()
{
	int a, b;
	cin >> a >> b;
	char ans[8];//��������ַ�������
	sprintf_s(ans, sizeof(ans), "%d", a + b);
	int len = strlen(ans);
	for (int i = 0;i < len;i++) {
		cout << ans[i];
		if (ans[i] != '-' && (i != len - 1) && (len - i - 1) % 3 == 0) 
			cout << ",";//����ʣ��3n����ʱ Ҫ��',' 
	}
	return 0;
}