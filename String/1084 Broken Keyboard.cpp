#include<iostream>
using namespace std;
int main()
{
	string letter = { "abcdefghijklmnopqrstuvwxyz"};
	string s1, s2, t;
	cin >> s1 >> s2;
	for (int i = 0;i < s1.length();i++) {
		if (s2.find(s1[i]) == -1 && t.find(s1[i]) == -1) {//ȱʧ��Ԫ����δ�洢
			if (letter.find(s1[i]) != -1) {//��СдӢ����ĸ�����
				if (t.find(s1[i] - 32) != -1)//�Ѿ���������Ĵ�д
					continue;
				t += s1[i] - 32;//���дӢ����ĸ
			}
			else t += s1[i];
		}
	}
	cout << t << endl;
	return 0;
}