#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	bool flag = true;
	scanf("%d", &N);
	string a, b, suffix, s = "";
	getchar();//���뻻�з�
	getline(cin,a);
	for (int i = 1;i < N;i++) {
		getline(cin, b);
		int s1 = a.length() - 1;
		int s2 = b.length() - 1;
		while (s1>=0&&s2>=0&&a[s1] == b[s2]) {
			s += a[s1];
			s1--;s2--;
		}
		if (!s.size()) {//s�ǿյ�
			flag = false;
		}
		else {//����s��Ϊ�ղ�����
			if (!suffix.size()) {
				suffix = s;//��ת��suffix
			}
			else if (suffix.length() > s.length()) {//�µĺ�׺Ҫ����
				string k = "";//��ʱ���׺
				int i = 0;
				while (i < s.length()) {
					if (suffix[i] == s[i]) {
						k += suffix[i];
						i++;
					}
					else
						break;
				}

				suffix = k;
			}
			else if (suffix.length() > s.length()) {//�µĺ�׺Ҫ����
				string k = "";//��ʱ���׺
				int i = 0;
				while (i < suffix.length()) {
					if (suffix[i] == s[i]) {
						k += suffix[i];
						i++;
					}
					else
						break;
				}

				suffix = k;
			}
		}
		s = "";//���s
		a = b;//����a
	}
	if (!flag)
		cout << "nai" << endl;
	else {
		reverse(suffix.begin(), suffix.end());
		cout << suffix << endl;
	}
	return 0;
}