#include<iostream>
using namespace std;
struct Node
{
	int Next;
	int Data;
}Array[100010];
int main()
{
	int Ad, N, K;
	scanf("%d %d %d", &Ad, &N, &K);
	for (int i = 0;i < N;i++) {
		int Address;
		scanf("%d", &Address);
		scanf("%d %d", &Array[Address].Data, &Array[Address].Next);
	}
	int Count = 0,Address=Ad;
	while (Address != -1) {//��������
		Address = Array[Address].Next;
		Count++;
	}
	bool flag = true;//�ж��Ƿ��ǵ�һ�����
	int NextHead = Ad, LastEnd = -1;//ͷ�����β���
	int Head;
	while (Count >= K) {//������ת������
		int Ptr1 = NextHead;
		int Ptr2 = Array[Ptr1].Next;
		for (int i = 0;i < K - 1 ;i++) {
			int Ptr3 = Array[Ptr2].Next;//�ȴ洢Ptr2��Next������ᶪ��
			Array[Ptr2].Next = Ptr1;
			Ptr1 = Ptr2;
			Ptr2 = Ptr3;
		}
		Array[NextHead].Next = Ptr2;//�ٶ�֮����Ҫ�޸ģ�ֱ�ӽӵ���һ�ֵ���ʼ
		if (flag) {
			Head = Ptr1;
			flag = false;
		}
		else {
			Array[LastEnd].Next = Ptr1;//����һ��
		}
		LastEnd = NextHead;
		NextHead = Ptr2;
		Count -= K;
	}
	//�����
	int i = Head;
	while (Array[i].Next != -1) {
		printf("%05d %d %05d\n", i, Array[i].Data, Array[i].Next);
		i = Array[i].Next;
	}
	printf("%05d %d %d\n", i, Array[i].Data, Array[i].Next);//���һ��
	return 0;
}