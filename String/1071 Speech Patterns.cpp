#include<iostream>
#include<string>
#include<cctype>
#include<map>
using namespace std;
int main()
{
	string s, t;
	getline(cin, s);
	map<string, int>m;
	for (int i = 0;i < s.length();i++) {
		s[i] = tolower(s[i]);//ͳһСд
		if (isalnum(s[i])) {//����������ĸ
			t += s[i];
		}
		if (!isalnum(s[i]) || i == s.length() - 1) {
			if (t.length() != 0)
				m[t]++;//�洢���ִ���
			t = "";//���t
		}
	}
	int maxn = 0;
	string a;
	for (auto it = m.begin();it != m.end();it++) {
		if (it->second > maxn) {
			a = it->first;
			maxn = it->second;
		}
	}
	cout << a << " " << maxn;
	return 0;
}