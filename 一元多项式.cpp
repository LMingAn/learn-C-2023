#include <iostream>
using namespace std;


//多项式定义
typedef struct PNode
{
	double coef;//系数
	int expn;//指数
	struct PNode* next;//指针域
}PNode, *polynomial;


//多项式创建
void Create(polynomial& p)
{
	int n = 0;
	cout << "输入多项式项数：";
	cin >> n;
	p = new PNode;//申请空间
	p->next = NULL;//创建带头结点单链表
	polynomial t = NULL, h = NULL;//标记
	for (int a = 1; a <= n; a++)//输入并排序
	{
		polynomial s = new PNode;//存储输入的数据
		cout << "输入第" << a << "个系数和指数：";
		cin >> s->coef >> s->expn;
		t = p;//t保存p的前结点，初值为头结点，让p只表示头结点
		h = p->next;//h指向首元结点
		while (h && h->expn < s->expn)//遍历寻找首个大于输入指数的项 *h
		{
			t = h;
			h = h->next;//h指向下一结点
		}
		s->next = h;//把输入项插入到h和其他前驱结点间
		t->next = s;
	}
}


//多项式输出
void Output(polynomial& p)//多项式输出
{
	PNode* q = p->next;
	cout << q->coef << "x" << "^" << q->expn;
	while (q->next)
	{
		q = q->next;
		if (q->coef == 0)
			continue;
		cout << "+" << q->coef << "x" << "^" << q->expn;
	}
	cout << endl;
}


//多项式相加
void Add(polynomial& p1, polynomial& p2)
{
	polynomial t = p1;//t指向p1头结点
	polynomial h = t;//标记p1头结点
	p1 = p1->next;
	p2 = p2->next;//分别指向首元结点
	while (p1 && p2)
	{
		if (p1->expn == p2->expn)
		{
			p1->coef += p2->coef;//系数相加，存入p1
			if (p1->coef)
			{
				t->next = p1;//修改后的p1当前结点放在t后
				t = p1;
				p1 = p1->next;
				polynomial r = p2;//临时存储
				p2 = p2->next;
				delete r;//删除p2原结点
			}
			else
			{
				polynomial r = p1;//临时存储
				p1 = p1->next;
				delete r;
				polynomial rr = p2;
				p2 = p2->next;
				delete rr;
			}
		}
		else if (p1->expn > p2->expn)
		{
			t->next = p2;//修改后的p2当前结点放在t后
			t = p2;
			p2 = p2->next;
		}
		else
		{
			t->next = p1;
			t = p1;
			p1 = p1->next;
		}
	}
	t->next = p1 ? p1 : p2;//插入非空多项式剩余片段
	cout << "相加结果为：" << endl;
	Output(h);
	delete p2;
}


//多项式排序
void Sort(polynomial p, polynomial head)
{
	p = head;
	polynomial t1 = p->next;
	polynomial t2 = p->next;
	polynomial t3 = NULL;
	while (t2 != t3)
	{
		while (t1->next != t3)
		{
			if (t1->expn > t1->next->expn)
			{
				t1->coef += t1->next->coef;
				t1->next->coef = t1->coef - t1->next->coef;
				t1->coef = t1->coef - t1->next->coef;
				t1->expn += t1->next->expn;
				t1->next->expn = t1->expn - t1->next->expn;
				t1->expn = t1->expn - t1->next->expn;
			}
			t1 = t1->next;
		}
		t3 = t1;
		t1 = p->next;//t1重置
	}
}


//多项式相乘
void Multiply(polynomial& p1, polynomial& p2)//相乘 -> 排序 -> 合并
{
	polynomial head2 = p2;//标记p2头结点
	polynomial head1 = new PNode;//存放相乘结果
	polynomial head = head1;
	p1 = p1->next;
	p2 = p2->next;
	while (p1)
	{
		while (p2)
		{
			polynomial t = new PNode;
			t->coef = p1->coef * p2->coef;//系数相乘
			t->expn = p1->expn + p2->expn;//指数相加
			head->next = t;
			t->next = NULL;
			head = t;
			p2 = p2->next;
		}
		p1 = p1->next;
		p2 = head2->next;//重置
	}
	Sort(head, head1);
	for (polynomial p = head1->next; p && p->next; )//合并
	{
		if (p->expn == p->next->expn)
		{
			p->coef += p->next->coef;
			p->next = p->next->next;//后一位后移
		}
		else
			p = p->next;
	}
	cout << "相乘结果为：" << endl;
	Output(head1);
}


int main()
{
	polynomial p1 = NULL, p2 = NULL;
	char t = 0;
	while (1)
	{
		cout << "输入要执行的操作 + 或 * 或 e退出：";
		cin >> t;
		switch (t)
		{
		case '+':
			Create(p1);
			cout << "第一个多项式为：" << endl;
			Output(p1);
			cout << endl;
			Create(p2);
			cout << "第二个多项式为：" << endl;
			Output(p2);
			cout << endl;
			Add(p1, p2);
			cout << endl;
			break;
		case '*':
			Create(p1);
			cout << "第一个多项式为：" << endl;
			Output(p1);
			cout << endl;
			Create(p2);
			cout << "第二个多项式为：" << endl;
			Output(p2);
			cout << endl;
			Multiply(p1, p2);
			cout << endl;
			break;
		case 'e':
			cout << "已退出" << endl;
			exit(1);
		default:
			cout << "输入错误，请重试" << endl << endl;
			break;
		}
	}
	return 0;
}