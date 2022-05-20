#include<iostream>
#include<string>
using namespace std;
int main()
{
	int N;
	string s;
	int t;
	string ones[14] = { "tret" ,"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string tens[14] = { "tret" ,"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	scanf("%d", &N);
	getchar();//���뻻�з�
	for (int i = 0;i < N;i++) {
		getline(cin, s);//����
		if (s[0] >= '0' && s[0] <= '9') {//����ת��Ϊ������
			t = atoi(s.c_str());//ת��Ϊint����
			if (t >= 13) {//ע���λ��0���ô�ӡ
				if(t % 13 == 0)
					cout << tens[t / 13] << endl;
				else 
					cout << tens[t / 13] << " " << ones[t % 13] << endl;
			}
			else {
				cout << ones[t] << endl;
			}

		}
		else {//������ת��Ϊ����
			if (s.size() == 3 || s.size() == 4) {//ֻ��һ�����ֵ����
				bool flag = false;
				for (int i = 0;i < 14;i++) {
					if (s == ones[i]) {
						printf("%d\n", i);
						flag = true;
						break;
					}	
				}
				if (!flag) {//��tens��
					for (int i = 0;i < 14;i++) {
						if (s == tens[i])
							printf("%d\n", i * 13);
					}
				}
			}
			else {
				string s1, s2;
				int r = 0;
				s1 = s.substr(0, 3);
				s2 = s.substr(4, 3);
				for (int i = 0;i < 14;i++) {
					if (s1 == tens[i])
						r += i * 13;
					if (s2 == ones[i])
						r += i;
				}
				printf("%d\n", r);
			}
		}
	}
	return 0;
}