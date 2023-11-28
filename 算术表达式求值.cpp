//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <malloc.h>
//#include <math.h>
//#define maximum 100000
//
//typedef struct//数字栈 
//{
//    float data[maximum];
//    int top;
//}number;
//
//typedef struct//字符栈 
//{
//    char data[maximum];
//    int top;
//}sign;
//
//void InitNumber(number* stack);//初始化数字栈 
//void GetTopNumber(number stack, float* e);//获取栈顶元素 
//void PushNumber(number* stack, float e);//进栈 
//void PopNumber(number* stack, float* e);//出栈 
//
//void InitSign(sign* stack);
//void GetTopSign(sign stack, char* e);
//void PushSign(sign* stack, char e);
//void PopSign(sign* stack, char* e);
//
//void Calculate(number* stack, char e);
//
//number Num;
//sign sig;
//char expression[maximum];
//
//int main()
//{
//    gets_s(expression);
//    int length;
//    length = strlen(expression);
//    int i;
//    float en, n;
//    char es;
//    InitNumber(&Num);
//    InitSign(&sig);
//    for (i = 0; i < length; i++)
//    {
//        if (expression[i] >= '0' && expression[i] <= '9')
//        {
//            n = expression[i] - '0';//字符型转换为整型 
//            while (expression[i + 1] != '\0')
//            {
//                if (expression[i + 1] >= '0' && expression[i + 1] <= '9')
//                {
//                    n = n * 10 + expression[i + 1] - '0';
//                    ++i;
//                }
//                else break;
//            }
//            PushNumber(&Num, n);
//        }
//        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^' || expression[i] == '(' || expression[i] == ')')
//        {
//            switch (expression[i])
//            {
//            case '+':
//                if (sig.data[sig.top - 1] != '+' && sig.data[sig.top - 1] != '-' && sig.data[sig.top - 1] != '*' && sig.data[sig.top - 1] != '/' && sig.data[sig.top - 1] != '^')
//                    //与栈顶元素的优先级相比较， 高于时入栈，此处判断是否入栈。 
//                    PushSign(&sig, '+');
//                else
//                {
//                    while (sig.top > 0 && sig.data[sig.top - 1] != '(')//如果栈不为空切不为左括号，则出栈 
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
//
//void InitNumber(number* stack)
//{
//    stack->top = 0;
//}
//
//void GetTopNumber(number stack, float* e)
//{
//    if (stack.top == 0) return;
//    else *e = stack.data[stack.top - 1];
//}
//
//void PushNumber(number* stack, float e)
//{
//    if (stack->top >= maximum) return;
//    else stack->data[stack->top++] = e;
//}
//
//void PopNumber(number* stack, float* e)
//{
//    if (stack->top == 0) return;
//    else *e = stack->data[--stack->top];
//}
//
//void InitSign(sign* stack)
//{
//    stack->top = 0;
//}
//
//void GetTopSign(sign stack, char* e)
//{
//    if (stack.top == 0) return;
//    else *e = stack.data[stack.top - 1];
//}
//
//void PushSign(sign* stack, char e)
//{
//    if (stack->top >= maximum) return;//栈满 
//    else
//    {
//        stack->data[stack->top] = e;
//        stack->top++;
//    }
//}
//
//void PopSign(sign* stack, char* e)
//{
//    if (stack->top == 0) return;
//    else *e = stack->data[--stack->top];
//}
//
//void Calculate(number* stack, char e)// 计算结果 
//{
//    float num1, num2, result;
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