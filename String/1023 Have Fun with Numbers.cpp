#include<iostream>
#include<string>
using namespace std;
int main() {
	string s1, s2;
	cin >> s1;
	int r = 0;
	for (int i = s1.length() - 1; i >= 0; i--) {
		int a = (s1[i] - '0') * 2 + r;//��ǰλ
		s2 += to_string(a % 10);//�洢��2֮��Ľ��(�����෴)
		r = a / 10;//��λ
	}
	if (r != 0)
		s2 += to_string(r);
	int flag = 1;
	int arr1[10] = { 0 }, arr2[10] = {0};//�洢ÿ�����ֳ��ֵĴ���
	for (int i = 0; i < s1.length(); i++)
		arr1[s1[i] - '0']++;
	for (int i = 0; i < s2.length(); i++)
		arr2[s2[i] - '0']++;
	for (int i = 0; i < 10; i++) {
		if (arr1[i] != arr2[i]) {
			flag = 0; //��ʾ��һ��
			break;
		}
	}
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = s2.length() - 1; i >= 0; i--)
		cout << s2[i];
	return 0;
}
