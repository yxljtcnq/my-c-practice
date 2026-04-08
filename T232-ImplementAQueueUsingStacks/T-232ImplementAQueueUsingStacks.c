#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxsize 100

typedef struct {
    int* base1;
    int* top1;
    int* base2;
    int* top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->base1 = (int*)malloc(sizeof(int) * maxsize);
    q->base2 = (int*)malloc(sizeof(int) * maxsize);
    q->top1 = q->base1;
    q->top2 = q->base2;
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->top1 - obj->base1 >= maxsize)
    {
        printf("栈满");
        return;
    }
    *obj->top1 = x;
    obj->top1++;
}

int myQueuePop(MyQueue* obj)
{
    if (obj->top2 == obj->base2) {
        int* temp = obj->top1 - 1;
        while (temp >= obj->base1)
        {
            *obj->top2 = *temp;
            obj->top2++;
            temp--;
        }
        obj->top1 = obj->base1;
    }

    obj->top2--;
    int a = *obj->top2;
    return a;
}

int myQueuePeek(MyQueue* obj)
{
    if (obj->top2 == obj->base2)
    {
        int* temp = obj->top1 - 1;
        while (temp >= obj->base1)
        {
            *obj->top2 = *temp;
            obj->top2++;
            temp--;
        }
        obj->top1 = obj->base1;
    }
    int a = *(obj->top2 - 1);
    return a;
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == obj->base1) && (obj->top2 == obj->base2);
}

void myQueueFree(MyQueue* obj)
{
    if (obj == NULL)
        return;
    free(obj->base1);
    free(obj->base2);
    free(obj);
}
/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/