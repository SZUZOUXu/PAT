#include <iostream>
using namespace std;
int main() 
{
    int Num[100010];
    int N;
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        scanf("%d", &Num[i]);
    }
    int num = 0;
    for (int i = 0;i < N;i++) {
        if (Num[i] != i) {
            num++;
            while (Num[i] != i) {//���Ŀ�ʼ
                if (Num[i] == 0)
                    num--;//��0�ڵĻ�Ϊ��Ԫ�ظ���-1
                else
                    num++;//��0�ڵĻ�Ϊ��Ԫ�ظ���+1
                int tmp = Num[i];
                Num[i] = i;
                i = tmp;//����i��Num[i]��ֵ
            }
        }
    }
    printf("%d", num);
    return 0;
}
