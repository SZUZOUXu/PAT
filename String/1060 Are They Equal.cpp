#include<iostream>
#include<string>
using namespace std;

string s1, s2, a1, a2;

string translate(int n, string s) {
	int size = s.size(), i = 0, count = 0;
	string temp;
	for (; i < size && s[i] == '0'; i++);//ȡ����һ����0���ַ�
	if (s[i] == '.') {//С��
		i++;
		for (; s[i] == '0'; i++)count--;
		bool judge = false;//��ֹ0.0���������ݣ�ֻ��judgeΪtrueʱ��count����Ч	
		for (; temp.size() < n && i < size; i++) {//ȡ��nλ��Ч����
			temp.push_back(s[i]);
			judge = true;
		}
		while (temp.size() < n)
			temp.push_back('0');//����0
		if (!judge)
			count = 0;
	}
	else {//>0
		for (int j = i;s[j] != '.' && j < size;j++)
			count++;//С����ǰ�м�λ��Ч����
		for (; s[i] != '.' && temp.size() < n && i < size; i++)
			temp.push_back(s[i]);//��С����ǰnλ��Ч����
		if (temp.size() < n)
			i++;
		for (; i < size && temp.size() < n; i++)//�����ʹ�С�������
			temp.push_back(s[i]);
		while (temp.size() < n)
			temp.push_back('0');
	}
	temp += ("*10^" + to_string(count));
	return temp;
}

int main() {
	int n = 0;
	scanf("%d", &n);
	cin >> s1 >> s2;
	a1 = translate(n, s1);
	a2 = translate(n, s2);
	if (a1 == a2) cout << "YES 0." << a1;
	else cout << "NO 0." << a1 << " 0." << a2;
	return 0;
}
