#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b="";
	cin >> a;
	int i = 0, cnt = 0;
	
	while (a[i] != 'E') {
		if (a[i] >= '0' && a[i] <= '9') {
			b += a[i];
			cnt++;//��¼�м�λ����
		}
		i++;
	}
	//��ʱa[i]=='E'
	string s;
	i++;
	if (a[i] == '+') {
		i++;
		for (;i < a.size();i++) {
			s += a[i];
		}
		int len = atoi(s.c_str());
		if (len >= cnt - 1)
			b.insert(b.end(), len - cnt + 1, '0');//��β�ĵط�����
		else
			b.insert(cnt - len + 1, 1, '.');
	}
	else if (a[i] == '-') {
		i++;
		for (;i < a.size();i++) {
			s += a[i];
		}
		int len = atoi(s.c_str());
		b.insert(0, len, '0');//��ʼ�ĵط�����
		b.insert(1, 1, '.');//����С����
	}
	if (a[0] == '-')
		printf("-");

	cout << b;

	return 0;
}