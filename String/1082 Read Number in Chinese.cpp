#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	string Wei[9] = { "","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi" };
	string Num[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	cin >> s;
	int i = 0;
	if (s[0] == '-') {
		i++;
		printf("Fu");
	}
	if (s == "0") {//�������
		printf("ling");
		return 0;
	}
	for (i;i < s.length();i++) {
		int num = s[i] - '0';//��ǰλ������
		int len = s.length() - i;//ʣ��λ��
		if (num == 0) {
			while (i < s.length() && s[i] - '0' == 0) {//�ҵ���һ������0�ĵط�
				if (len - 1 == 4)
					cout << " " << Wei[len - 1];
				i++;
				len = s.length() - i;
				num = s[i] - '0';
			}
			if (i == s.length())//�������һλ�Ͳ������ling��
				return 0;
			cout <<" "<< Num[0];
		}//��ʱs[i]�Ƿ�0��
		if (i)
			printf(" ");
		cout << Num[num];
		if (len - 1 != 0)
			cout << " " << Wei[len - 1];
	}
	return 0;
}