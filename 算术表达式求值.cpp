//#include <iostream>
//#include <string.h>
//#include <stdlib.h>
//#include <malloc.h>
//using namespace std;
//
//
//typedef struct//数字栈 
//{
//    float data[100000];
//    int top;
//}number;
//
//
//typedef struct//字符栈 
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
//void InitNumber(number* stack)//初始化数字栈
//{
//    stack->top = 0;
//}
//
//
//void GetTopNumber(number stack, float* e)//获取栈顶元素
//{
//    if (stack.top == 0) return;
//    else *e = stack.data[stack.top - 1];
//}
//
//
//void PushNumber(number* stack, float e)//进栈
//{
//    if (stack->top >= 100000) return;
//    else stack->data[stack->top++] = e;
//}
//
//
//void PopNumber(number* stack, float* e)//出栈
//{
//    if (stack->top == 0) return;
//    else *e = stack->data[--stack->top];
//}
//
//
//void InitSign(sign* stack)//初始化字符栈
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
//void Calculate(number* stack, char e)//计算结果
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
//        if (num2 == 0) printf("表达式错误！");
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
//            n = input[i] - '0';//字符型转换为整型 
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
//                    //与栈顶元素的优先级相比较，高于时入栈，此处判断是否入栈。 
//                    PushSign(&sig, '+');
//                else
//                {
//                    while (sig.top > 0 && sig.data[sig.top - 1] != '(')//如果栈不为空且不为左括号，则出栈 
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