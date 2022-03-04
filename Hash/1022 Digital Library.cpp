#include<iostream>
#include<set>//����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
#include<unordered_map>//��ϣ��
#include<string>
using namespace std;


int main()
{
	int n, m;
	cin >> n;
	string id, title, author, publisher, publishyear, key;
	getchar();//���뻻�з�
	unordered_map<string, set<string>> mp;//key, value ��valueֵҲ����id��������
	for (int i = 0;i < n;i++) {
		getline(cin, id);
		getline(cin, title);
		mp[title].insert(id);//title�����ڲ�ѯid��keyֵ
		getline(cin, author);
		mp[author].insert(id);
		while (cin >> key) {//����ÿһ��keyֵ���б���
			char c = getchar();//����ո�
			mp[key].insert(id);
			if (c == '\n')break;//keyֵ�������
		}
		getline(cin, publisher);
		mp[publisher].insert(id);
		getline(cin, publishyear);
		mp[publishyear].insert(id);
	}
	cin >> m;
	int num;
	getchar();
	while (m--) {
		getline(cin, key);
		num = key[0] - '0';//��λ������
		key = key.substr(3);//�ӵ���λ��ĩβ����
		cout << num << ": " << key << endl;
		if (mp[key].size() == 0) {//û�ҵ�
			cout << "Not Found" << endl;
		}
		else {
			for (auto it : mp[key]) {//��ȡauto����+ ��ǿfor ѭ��(auto����)
				cout << it << endl;
			}
		}
	}
	return 0;
}