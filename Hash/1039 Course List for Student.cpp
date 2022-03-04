#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];
int getid(char* name) //hashɢ��
{
	int id = 0;
	for (int i = 0; i < 3; i++)
		id = 26 * id + (name[i] - 'A');
	id = id * 10 + (name[3] - '0');
	return id;
}
int main()
{
	int N, K;
	int id = 0;
	cin >> N >> K;
	int C, S, n;//����γ���š�ѧ������string->int�����
	int cnt = 0;//����
	char name[5];
	for (int i = 0;i < K;i++) {
		cin >> C >> S;
		for (int j = 0;j < S;j++) {
			cin >> name;
			id = getid(name);
			v[id].push_back(C);
		}
	}
	
	for (int i = 0;i < N;i++) {
		cin >> name;
		id = getid(name);
		sort(v[id].begin(), v[id].end());
		cout << name << " " << v[id].size();
		for (int j = 0; j < v[id].size(); j++) {
			cout << " " << v[id][j];
		}
		cout << endl;
	}
	return 0;
}