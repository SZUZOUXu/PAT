#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//dp[]����dp[1]~dp[m]
int dp[10010], w[10010];//dp[i]��ʾ����ͺ�<=i��������
bool choice[10010][110];//�洢�����ʹ���dp[],N-10^4,M-10^2
int cmp1(int a, int b) { return a > b; }
int main() 
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    sort(w + 1, w + n + 1, cmp1);//��������,��ΪҪ�����С���������
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {//jҪ����ȸñ�ֵ�󣬱�mС
            if (dp[j] <= dp[j - w[i]] + w[i]) {//�������Ҫ��
                choice[i][j] = true;//ȡ�����к�j����ͨ��Ӳ��i
                dp[j] = dp[j - w[i]] + w[i];
            }
        }
    }
    if (dp[m] != m) printf("No Solution");
    else {
        vector<int> arr;
        int v = m, index = n;
        while (v > 0) {//�ӱ�ֵ��С��Ӳ�ҿ�ʼ
            if (choice[index][v] == true) {//��ɱ�ֵv����ͨ��w[index]
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}