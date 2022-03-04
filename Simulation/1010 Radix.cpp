#include<iostream>
using namespace std;
//��radix���Ƶ���ת��Ϊ10���Ƶ���radix^n+...+radix^0
long long int GetNum(string N1, long long int radix)
{
	long long int sum = 0;
	for (int i = 0;i < N1.length();i++) {
		if (N1[i] <= '9') {
			sum = sum * radix + (N1[i] - '0');;
		}
		else if (N1[i] <= 'z') {
			sum = sum * radix + (N1[i] - 'a' + 10);
		}
	}
	return sum;
}
//�ҵ�N2��С�Ļ���
int GetMinRadix(string N2)
{
	char max = '0';
	for (int i = 0;i < N2.length();i++) {
		if (N2[i] > max)
			max = N2[i];
	}
	if (max <= '9')
		return max - '0' + 1;
	else if (max <= 'z')
		return max - 'a' + 11;
}
//�ҵ�����ʹN2==N1�Ļ���
long long int GetRadix(long long int Num1, string N2, long long int left, long long int right)
{
	if (left == right) {
		if (GetNum(N2, left) == Num1)
			return left;
		else
			return 0;//û���ҵ�
	}
	else if (left < right) {
		long long int center = (left + right) / 2;
		if (GetNum(N2, center) == Num1)
			return center;
		//Num2>Num1����Num2<0 �ʹ���
		else if (GetNum(N2, center) > Num1 || GetNum(N2, center) < 0)
			return GetRadix(Num1, N2, left, center);
		else if (GetNum(N2, center) < Num1)
			return GetRadix(Num1, N2, center + 1, right);
	}
	return 0;//left>right
}
int main()
{
	string N1, N2;
	int tag;
	long long int radix;
	cin >> N1 >> N2 >> tag >> radix;
	long long int Num1;
	if (tag == 1)
		Num1 = GetNum(N1, radix);
	else {
		Num1 = GetNum(N2, radix);
		N2 = N1;
	}
	int res = GetRadix(Num1, N2, GetMinRadix(N2), Num1 + 1);
	if (res == 0) {
		cout << "Impossible";
		return 0;
	}
	cout << res;
	return 0;
}