#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct Person
{
	string ID;
	int score;
	int rank;
	int location;
	int lrank;
}person[30001];

bool cmp(Person a,Person b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else if (a.ID != b.ID)
		return (a.ID.compare(b.ID) < 0);
}
int main()
{
	int N, K;
	string ID;
	int score;
	int begin = 0;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> K;
		for (int j = begin;j < begin + K;j++) {
			cin >> person[j].ID >> person[j].score;
			person[j].location = i;
		}
		//sort(person + begin, person + begin + K, cmp);
		//person[begin].lrank = 1;//�ȸ�ÿ��������һλͬѧ����
		//for (int m = begin + 1;m < begin + K;m++) {
		//	if (person[m].score == person[m - 1].score)
		//		person[m].lrank = person[m - 1].lrank;
		//	else
		//		person[m].lrank = m - begin + 1;//�ڼ���ͬѧ���ǵڼ�λ
		//}
		for (int j = begin;j < begin + K;j++) {//����ȷ��lrank
			int lrank = 1;
			for (int t = begin;t < begin + K;t++) {
				if (person[t].score > person[j].score)
					lrank++;
			}
			person[j].lrank = lrank;
		}
		begin += K;
	}
	sort(person, person + begin, cmp);
	person[0].rank = 1;
	for (int i = 1;i < begin;i++) {
		if (person[i].score == person[i - 1].score) {
			person[i].rank = person[i - 1].rank;
		}
		else {
			person[i].rank = i + 1;//�ڼ���ͬѧ���ǵڼ�λ
		}
	}
	cout << begin << endl;
	for (int i = 0;i < begin;i++)
		cout << person[i].ID << " " << person[i].rank << " " << person[i].location << " " << person[i].lrank << endl;
	return 0;
}