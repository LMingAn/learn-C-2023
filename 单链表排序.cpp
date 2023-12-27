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
//创建
//Linklist Create()
//{
//	Linklist l = new Node, r = new Node;//l为头结点
//	long x = 0;
//	l->next = NULL;
//	r = l;
//	cout << "输入单链表（-1结束）：" << endl;
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
//输出
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
//排序
//Linklist Sort(LNode* l)
//{
//	LNode* p1 = NULL, * p2 = NULL;
//	p1 = l->next;//p1指向首元结点
//	while (p1 != NULL)//固定p1位置，与遍历指针p2所指向结点之间相互比较大小
//	{
//		p2 = p1->next;
//		while (p2 != NULL)//遍历指针p2
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
//	cout << "未排序单链表：" << endl;
//	Output(l);
//	Sort(l);
//	cout << "排序后单链表：" << endl;
//	Output(l);
//	return 0;
//}