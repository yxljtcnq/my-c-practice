#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include< stdlib.h >
#define MAXNUM 100
 
typedef struct SqStack
{
	int* base;
	int* top;
	int stacksize;
}SqStack;

//初始化栈
void InitStack(SqStack* s)
{
	s->base = (SqStack*)malloc(sizeof(SqStack) * MAXNUM);
	if (s->base == NULL)
	{
		printf("内存分配失败");
		return;
	}
	s->top = s->base;
	s->stacksize = MAXNUM;
	return;
}
//判断是否栈满
void stackFull(SqStack* s)
{
	if (s->top > MAXNUM)
	{
		printf("栈已经满了");
		return ;
	}
	return ;

}


//入栈
void push(SqStack* s,int e)
{
	*s->top = e;
	s->top++;

}

//出栈
void pop(SqStack* s,int e)
{
	e = s->top;
	s->top--;
}



int main()
{
	SqStack s;
	InitStack(&s);
	free(s.base);

}





























//typedef char StackType;
////栈的结构体
//typedef struct Stack
//{
//    StackType* arr;
//    int top;
//    int capacity;
//}Stack;
////初始化栈
//void StackInit(Stack* head)
//{
//    assert(head);
//    head->arr = NULL;
//    head->top = head->capacity = 0;
//}
////压栈
//void StackPush(Stack* head, StackType x)
//{
//    assert(head);
//    if (head->top == head->capacity)
//    {
//        int newcapacity = head->capacity == 0 ? 4 : head->capacity * 2;
//        head->capacity = newcapacity;
//        StackType* newarr = (StackType*)realloc(head->arr, sizeof(StackType) * newcapacity);
//        head->arr = newarr;
//    }
//    head->arr[head->top++] = x;
//}
////弹出top元素
//void StackPop(Stack* head)
//{
//    assert(head && head->top);
//    head->top--;
//}
////读取top元素
//StackType StackTop(Stack* head)
//{
//    assert(head->top);
//    return head->arr[head->top - 1];
//}
//
//bool isValid(char* s) {
//    char* ch = s;
//    Stack stack;
//    StackInit(&stack);
//    while (*ch != '\0')  //循环条件判断
//    {
//        if (*ch == '(' || *ch == '[' || *ch == '{')
//        {
//            StackPush(&stack, *ch);
//        }
//        else
//        {
//            //如果第一个字符为右括号，栈里面为空，返回false
//            if (stack.top == 0)
//            {
//                return false;
//            }
//            char c = StackTop(&stack);
//            StackPop(&stack);
//            //符号不匹配
//            if ((c == '(' && *ch != ')') ||
//                (c == '[' && *ch != ']') ||
//                (c == '{' && *ch != '}'))
//            {
//                return false;
//            }
//        }
//        ch++;
//    }
//    //检查栈里面是否为空不为则数量不匹配
//    return stack.top == 0;
//}