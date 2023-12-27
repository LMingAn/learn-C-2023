#include <iostream>
using namespace std;


//����ʽ����
typedef struct PNode
{
	double coef;//ϵ��
	int expn;//ָ��
	struct PNode* next;//ָ����
}PNode, *polynomial;


//����ʽ����
void Create(polynomial& p)
{
	int n = 0;
	cout << "�������ʽ������";
	cin >> n;
	p = new PNode;//����ռ�
	p->next = NULL;//������ͷ��㵥����
	polynomial t = NULL, h = NULL;//���
	for (int a = 1; a <= n; a++)//���벢����
	{
		polynomial s = new PNode;//�洢���������
		cout << "�����" << a << "��ϵ����ָ����";
		cin >> s->coef >> s->expn;
		t = p;//t����p��ǰ��㣬��ֵΪͷ��㣬��pֻ��ʾͷ���
		h = p->next;//hָ����Ԫ���
		while (h && h->expn < s->expn)//����Ѱ���׸���������ָ������ *h
		{
			t = h;
			h = h->next;//hָ����һ���
		}
		s->next = h;//����������뵽h������ǰ������
		t->next = s;
	}
}


//����ʽ���
void Output(polynomial& p)//����ʽ���
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


//����ʽ���
void Add(polynomial& p1, polynomial& p2)
{
	polynomial t = p1;//tָ��p1ͷ���
	polynomial h = t;//���p1ͷ���
	p1 = p1->next;
	p2 = p2->next;//�ֱ�ָ����Ԫ���
	while (p1 && p2)
	{
		if (p1->expn == p2->expn)
		{
			p1->coef += p2->coef;//ϵ����ӣ�����p1
			if (p1->coef)
			{
				t->next = p1;//�޸ĺ��p1��ǰ������t��
				t = p1;
				p1 = p1->next;
				polynomial r = p2;//��ʱ�洢
				p2 = p2->next;
				delete r;//ɾ��p2ԭ���
			}
			else
			{
				polynomial r = p1;//��ʱ�洢
				p1 = p1->next;
				delete r;
				polynomial rr = p2;
				p2 = p2->next;
				delete rr;
			}
		}
		else if (p1->expn > p2->expn)
		{
			t->next = p2;//�޸ĺ��p2��ǰ������t��
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
	t->next = p1 ? p1 : p2;//����ǿն���ʽʣ��Ƭ��
	cout << "��ӽ��Ϊ��" << endl;
	Output(h);
	delete p2;
}


//����ʽ����
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
		t1 = p->next;//t1����
	}
}


//����ʽ���
void Multiply(polynomial& p1, polynomial& p2)//��� -> ���� -> �ϲ�
{
	polynomial head2 = p2;//���p2ͷ���
	polynomial head1 = new PNode;//�����˽��
	polynomial head = head1;
	p1 = p1->next;
	p2 = p2->next;
	while (p1)
	{
		while (p2)
		{
			polynomial t = new PNode;
			t->coef = p1->coef * p2->coef;//ϵ�����
			t->expn = p1->expn + p2->expn;//ָ�����
			head->next = t;
			t->next = NULL;
			head = t;
			p2 = p2->next;
		}
		p1 = p1->next;
		p2 = head2->next;//����
	}
	Sort(head, head1);
	for (polynomial p = head1->next; p && p->next; )//�ϲ�
	{
		if (p->expn == p->next->expn)
		{
			p->coef += p->next->coef;
			p->next = p->next->next;//��һλ����
		}
		else
			p = p->next;
	}
	cout << "��˽��Ϊ��" << endl;
	Output(head1);
}


int main()
{
	polynomial p1 = NULL, p2 = NULL;
	char t = 0;
	while (1)
	{
		cout << "����Ҫִ�еĲ��� + �� * �� e�˳���";
		cin >> t;
		switch (t)
		{
		case '+':
			Create(p1);
			cout << "��һ������ʽΪ��" << endl;
			Output(p1);
			cout << endl;
			Create(p2);
			cout << "�ڶ�������ʽΪ��" << endl;
			Output(p2);
			cout << endl;
			Add(p1, p2);
			cout << endl;
			break;
		case '*':
			Create(p1);
			cout << "��һ������ʽΪ��" << endl;
			Output(p1);
			cout << endl;
			Create(p2);
			cout << "�ڶ�������ʽΪ��" << endl;
			Output(p2);
			cout << endl;
			Multiply(p1, p2);
			cout << endl;
			break;
		case 'e':
			cout << "���˳�" << endl;
			exit(1);
		default:
			cout << "�������������" << endl << endl;
			break;
		}
	}
	return 0;
}