//#include <iostream>
//using namespace std;
//
//
//typedef struct Node
//{
//	long data;
//	struct Node* next;
//}LNode, *Linklist;
//
//
//����
//Linklist Create()
//{
//	Linklist l = new Node, r = new Node;//lΪͷ���
//	long x = 0;
//	l->next = NULL;
//	r = l;
//	cout << "���뵥����-1��������" << endl;
//	cin >> x;
//	while (x != -1)
//	{
//		Linklist s = new Node;
//		s->data = x;
//		s->next = r->next;
//		r->next = s;
//		r = s;
//		cin >> x;
//	}
//	r->next = NULL;
//	return l;
//}
//
//
//���
//void Output(LNode* l)
//{
//	LNode* r = NULL;
//	r = l;
//	while (r->next != NULL)
//	{
//		r = r->next;
//		cout << r->data << ' ';
//	}
//	cout << endl;
//}
//
//
//����
//Linklist Sort(LNode* l)
//{
//	LNode* p1 = NULL, * p2 = NULL;
//	p1 = l->next;//p1ָ����Ԫ���
//	while (p1 != NULL)//�̶�p1λ�ã������ָ��p2��ָ����֮���໥�Ƚϴ�С
//	{
//		p2 = p1->next;
//		while (p2 != NULL)//����ָ��p2
//		{
//			if (p1->data > p2->data)
//			{
//				p1->data += p2->data;
//				p2->data = p1->data - p2->data;
//				p1->data = p1->data - p2->data;
//			}
//			p2 = p2->next;
//		}
//		p1 = p1->next;
//	}
//	return l;
//}
//
//
//int main()
//{
//	Linklist l = Create();
//	cout << "δ��������" << endl;
//	Output(l);
//	Sort(l);
//	cout << "���������" << endl;
//	Output(l);
//	return 0;
//}