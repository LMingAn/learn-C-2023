//#include <iostream>
//#include <string.h>
//#include <stdlib.h>
//#include <malloc.h>
//using namespace std;
//
//
//typedef struct//����ջ 
//{
//    float data[100000];
//    int top;
//}number;
//
//
//typedef struct//�ַ�ջ 
//{
//    char data[100000];
//    int top;
//}sign;
//
//
//number Num;
//sign sig;
//char input[100000];
//
//
//void InitNumber(number* stack)//��ʼ������ջ
//{
//    stack->top = 0;
//}
//
//
//void GetTopNumber(number stack, float* e)//��ȡջ��Ԫ��
//{
//    if (stack.top == 0) return;
//    else *e = stack.data[stack.top - 1];
//}
//
//
//void PushNumber(number* stack, float e)//��ջ
//{
//    if (stack->top >= 100000) return;
//    else stack->data[stack->top++] = e;
//}
//
//
//void PopNumber(number* stack, float* e)//��ջ
//{
//    if (stack->top == 0) return;
//    else *e = stack->data[--stack->top];
//}
//
//
//void InitSign(sign* stack)//��ʼ���ַ�ջ
//{
//    stack->top = 0;
//}
//
//
//void GetTopSign(sign stack, char* e)
//{
//    if (stack.top == 0) return;
//    else *e = stack.data[stack.top - 1];
//}
//
//
//void PushSign(sign* stack, char e)
//{
//    if (stack->top >= 100000) return;
//    else
//    {
//        stack->data[stack->top] = e;
//        stack->top++;
//    }
//}
//
//
//void PopSign(sign* stack, char* e)
//{
//    if (stack->top == 0) return;
//    else *e = stack->data[--stack->top];
//}
//
//
//void Calculate(number* stack, char e)//������
//{
//    float num1 = 0, num2 = 0, result = 0;
//    PopNumber(stack, &num2);
//    PopNumber(stack, &num1);
//    switch (e)
//    {
//    case '+':
//        result = num1 + num2;
//        PushNumber(stack, result);
//        break;
//    case '-':
//        result = num1 - num2;
//        PushNumber(stack, result);
//        break;
//    case '*':
//        result = num1 * num2;
//        PushNumber(stack, result);
//        break;
//    case '/':
//        if (num2 == 0) printf("���ʽ����");
//        else
//        {
//            result = num1 / num2;
//            PushNumber(stack, result);
//            break;
//        }
//    case '^':
//        result = pow(num1, num2);
//        PushNumber(stack, result);
//        break;
//    }
//}
//
//
//int main()
//{
//    gets_s(input);
//    int length = 0;
//    length = strlen(input);
//    int i = 0;
//    float en = 0, n = 0;
//    char es = 0;
//    InitNumber(&Num);
//    InitSign(&sig);
//    for (i = 0; i < length; i++)
//    {
//        if (input[i] >= '0' && input[i] <= '9')
//        {
//            n = input[i] - '0';//�ַ���ת��Ϊ���� 
//            while (input[i + 1] != '\0')
//            {
//                if (input[i + 1] >= '0' && input[i + 1] <= '9')
//                {
//                    n = n * 10 + input[i + 1] - '0';
//                    ++i;
//                }
//                else break;
//            }
//            PushNumber(&Num, n);
//        } 
//        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^' || input[i] == '(' || input[i] == ')')
//        {
//            switch (input[i])
//            {
//            case '+':
//                if (sig.data[sig.top - 1] != '+' && sig.data[sig.top - 1] != '-' && sig.data[sig.top - 1] != '*' && sig.data[sig.top - 1] != '/' && sig.data[sig.top - 1] != '^')
//                    //��ջ��Ԫ�ص����ȼ���Ƚϣ�����ʱ��ջ���˴��ж��Ƿ���ջ�� 
//                    PushSign(&sig, '+');
//                else
//                {
//                    while (sig.top > 0 && sig.data[sig.top - 1] != '(')//���ջ��Ϊ���Ҳ�Ϊ�����ţ����ջ 
//                    {
//                        PopSign(&sig, &es);
//                        Calculate(&Num, es);
//                    }
//                    PushSign(&sig, '+');
//                }
//                break;
//            case '-':
//                if (sig.data[sig.top - 1] != '+' && sig.data[sig.top - 1] != '-' && sig.data[sig.top - 1] != '*' && sig.data[sig.top - 1] != '/' && sig.data[sig.top - 1] != '^')
//                    PushSign(&sig, '-');
//                else
//                {
//                    while (sig.top > 0 && sig.data[sig.top - 1] != '(')
//                    {
//                        PopSign(&sig, &es);
//                        Calculate(&Num, es);
//                    }
//                    PushSign(&sig, '-');
//                }
//                break;
//            case '*':
//                if (sig.data[sig.top - 1] != '*' && sig.data[sig.top - 1] != '/' && sig.data[sig.top - 1] != '^')
//                    PushSign(&sig, '*');
//                else
//                {
//                    while (sig.top > 0 && sig.data[sig.top - 1] != '(')
//                    {
//                        PopSign(&sig, &es);
//                        Calculate(&Num, es);
//                    }
//                    PushSign(&sig, '*');
//                }
//                break;
//            case '/':
//                if (sig.data[sig.top - 1] != '*' && sig.data[sig.top - 1] != '/' && sig.data[sig.top - 1] != '^')
//                    PushSign(&sig, '/');
//                else
//                {
//                    while (sig.top > 0 && sig.data[sig.top - 1] != '(')
//                    {
//                        PopSign(&sig, &es);
//                        Calculate(&Num, es);
//                    }
//                    PushSign(&sig, '/');
//                }
//                break;
//            case '^':
//                if (sig.data[sig.top - 1] != '^')
//                    PushSign(&sig, '^');
//                else
//                {
//                    while (sig.top > 0 && sig.data[sig.top - 1] != '(')
//                    {
//                        PopSign(&sig, &es);
//                        Calculate(&Num, es);
//                    }
//                    PushSign(&sig, '^');
//                }
//            case '(':
//                PushSign(&sig, '(');
//                break;
//            case ')':
//                while (sig.data[sig.top - 1] != '(')
//                {
//                    PopSign(&sig, &es);
//                    Calculate(&Num, es);
//                }
//                PopSign(&sig, &es);
//            }
//        }
//    }
//    while (sig.top > 0)
//    {
//        PopSign(&sig, &es);
//        Calculate(&Num, es);
//    }
//    GetTopNumber(Num, &en);
//    printf("%.0f\n", en);
//    return 0;
//}