#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	int K;
	string s, r, t;
	map<char, bool>m;
	int cnt = 0;//Ϊmap����
	scanf("%d", &K);
	cin >> s;
	//�ж���Щ��ĸ����stucked
	int i = 0;
	while(i < s.size()) {
		bool flag = true;
		if ((i + K) <= s.size()) {//�п�����
			for (int j = i;j < i + K;j++) {
				if (s[j] != s[i]) {
					flag = false;
					break;
				}
			}
		}
		else//ʣ�೤�ȶ������ˣ��϶�����
			flag = false;
		
		if (flag) {//���ַ�Ŀǰ��stucked
			if (m.find(s[i]) != m.end()) {//�жϸ��ַ�֮ǰ�ǲ���stucked
				if (m[s[i]] == true) {//֮ǰ��
					if (r.find(s[i]) == -1)//û�д洢�������
						r += s[i];
				}
			}
			else {//���ַ���һ�γ���
				m[s[i]] = true;
				if (r.find(s[i]) == -1)
					r += s[i];
			}
			i += K;
		}
		else {//���ַ���stucked
			m[s[i]] = false;
			while (r.find(s[i]) != -1)//ɾ����Ԫ��
				r.erase(r.find(s[i]));
			i++;
		}
	}
	//��ԭ�����ַ����н��е���
	i = 0;
	while (i < s.size()) {
		if (r.find(s[i]) == -1) {
			t += s[i];
			i++;
		}
		else {//Ҫ�����޸ĵ�Ԫ��
			t += s[i];
			i += K;
		}
	}
	cout << r << endl;
	cout << t << endl;
	return 0;
}