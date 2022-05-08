#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

struct Node
{
	string plate;
	int sum = 0;
	bool state = false;
}Array[10010];

struct queries
{
	vector<string>v;
	int time = 0;
}q;
bool cmp(Node a, Node b)
{
	return a.sum < b.sum;
}
bool cmp2(string a, string b)
{
	return a.compare(b) < 0;
}
int main()
{
	int N, K, hh, mm, ss;
	int result[10010];
	vector<Node>v;
	map<string, int>mp;//�洢������ͣ��ʱ��
	string state;
	scanf("%d %d", &N, &K);
	for (int i = 0;i < N;i++) {
		cin >> Array[i].plate;
		scanf(" %d:%d:%d ", &hh, &mm, &ss);
		cin >> state;
		Array[i].sum = 3600 * hh + 60 * mm + ss;
		if (state == "in")
			Array[i].state = true;
		else Array[i].state = false;
	}
	sort(Array, Array + N, cmp);

	string name;
	int cnt = 0;//������Ч��in��out��result������
	int c = 0;//map key->value����
	for (int i = 0;i < N;i++) {
		if (Array[i].state) {//����in
			name = Array[i].plate;
			for (int j = i + 1;j < N;j++) {
				if (Array[j].plate == name && Array[j].state) {
					//˵��������in in out�����������ǰһ��in
					break;
				}
				if (Array[j].plate == name && !Array[j].state) {
					//��Գɹ�
					result[cnt++] = Array[i].sum;
					result[cnt++] = Array[j].sum;
					if (mp.find(Array[j].plate) != mp.end()) {
						//֮ǰ�Ѿ������
						mp[Array[j].plate] += Array[j].sum - Array[i].sum;
					}
					else //֮ǰû�д洢��
						mp[Array[j].plate] = Array[j].sum - Array[i].sum;
					if (mp[Array[j].plate] > q.time) {
						q.time = mp[Array[j].plate];
						q.v.clear();
						q.v.push_back(Array[j].plate);
					}
					else if (mp[Array[j].plate] == q.time) {
						q.v.push_back(Array[j].plate);
					}
					break;//�ҵ��˾ͽ�����һ��ѭ��
				}
			}
		}
	}
	for (int i = 0;i < K;i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int sum = 3600 * hh + 60 * mm + ss;
		int count = 0;//��ʱ����ж��ٳ�
		for (int j = 0;j < cnt;j+=2) {
			if (result[j] <= sum && result[j + 1] > sum)
				count++;
			if (result[j] > sum)
				break;
		}
		printf("%d\n", count);
	}
	sort(q.v.begin(), q.v.end(), cmp2);
	for (int i = 0;i < q.v.size();i++) {
		cout << q.v[i] << " ";
	}
	hh = q.time / 3600;
	mm = (q.time % 3600) / 60;
	ss = (q.time % 3600) % 60;
	printf("%02d:%02d:%02d", hh, mm, ss);
	return 0;
}