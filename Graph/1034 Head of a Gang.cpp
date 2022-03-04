#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#define maxn 2001
int weight[maxn];
int G[maxn][maxn];//�ڽӾ���
bool visited[maxn];

using namespace std;

int cnt = 0;//����
int N, K;
int Count, maxi, total, maxId;
map<string, int> m;//��hash��string->int����
vector<string> ss, ans;//ss���������룬ans���

void DFS(int S);
void GetAns();
bool cmp(string a, string b);

int main()
{
	cin >> N >> K;
	string S1, S2;
	int s1, s2;//�洢ת���������
	int T;
	for (int i = 0;i < N;i++) {
		cin >> S1 >> S2 >> T;
		//�������S1��S2ת����int����
		if (m.find(S1) != m.end()) {//�ҵ���
			s1 = m[S1];
		}
		else {
			m[S1] = cnt;//�������
			s1 = m[S1];
			ss.push_back(S1);
			cnt++;
		}
		if (m.find(S2) != m.end()) {
			s2 = m[S2];
		}
		else {
			m[S2] = cnt;
			s2 = m[S2];
			ss.push_back(S2);
			cnt++;
		}
		G[s1][s2] = T;//����ģ���������total���ᣫ����
		
		weight[s1] += T;//���¶�Ӧ����Ȩ��
		weight[s2] += T;
	}
	GetAns();
	sort(ans.begin(), ans.end(), cmp);//������ĸ��������
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}

void DFS(int S)
{
	Count++;//�ж����Ⱥ���м���
	visited[S] = 1;
	if (weight[S] > maxi) {
		maxi = weight[S];
		maxId = S;//���Ȩֵ���˵�
	}
	for (int i = 0;i < cnt;i++) {
		if (G[S][i] > 0) {
			total += G[S][i];//�ܹ���
			if (!visited[i])
				DFS(i);
		}
	}
}
void GetAns()
{
	for (int i = 0; i < cnt; i++) {
		Count = 0; maxi = 0; total = 0;//����
		if (visited[i] == 0)
			DFS(i);
		if (Count > 2 && total > K) {//total�������Ⱥ��Ȩֵ������
			string s = ss[maxId] + " " + to_string(Count);//ת��Ϊstring
			ans.push_back(s);
		}
	}
}

bool cmp(string a, string b)
{
	return a < b;//��������
}