#include <iostream>
#include <vector>
using namespace std;
vector<int> sum, resultArr;
int n, m;
void Func(int i, int& j, int& tempsum) {
    int left = i, right = n;
    while (left < right) {
        int mid = (left + right) / 2;//����
        if (sum[mid] - sum[i - 1] >= m)//i->mid��ֵ��������
            right = mid;//���
        else//i->mid��ֵС������
            left = mid + 1;//�ұ�
    }
    j = right;
    tempsum = sum[j] - sum[i - 1];//i->j�����е�ֵ
}
int main() {
    cin >> n >> m;
    sum.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];//��ʾ1-i�������ֵ��ۺ�
    }
    int minans = sum[n];
    for (int i = 1; i <= n; i++) {
        int j, tempsum;
        Func(i, j, tempsum);
        if (tempsum > minans) continue;
        if (tempsum >= m) {
            if (tempsum < minans) {
                resultArr.clear();//��գ�����С�͵���㴦��ʼ��¼
                minans = tempsum;//������С��
            }
            resultArr.push_back(i);
            resultArr.push_back(j);
        }
    }
    for (int i = 0; i < resultArr.size(); i += 2)
        printf("%d-%d\n", resultArr[i], resultArr[i + 1]);
    return 0;
}