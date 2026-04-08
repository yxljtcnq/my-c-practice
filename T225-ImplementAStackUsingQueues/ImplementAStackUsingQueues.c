#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAXSIZE 100
typedef struct {
    int* base;
    int front;
    int rear;

} MyStack;


MyStack* myStackCreate() {
    // 修复1：只分配1个栈结构体（你原来写了MAXSIZE个，错）
    MyStack* s = (MyStack*)malloc(sizeof(MyStack));
    // 修复2：给base分配数组内存（解决野指针！核心报错原因）
    s->base = (int*)malloc(sizeof(int) * MAXSIZE);
    // 修复3：初始化头尾指针为0（你原来没初始化，是随机值）
    s->front = 0;
    s->rear = 0;
    return s;
}

void myStackPush(MyStack* obj, int x) {
    obj->base[obj->rear] = x;
    obj->rear += 1;
}

int myStackPop(MyStack* obj) {
    int a = obj->base[obj->rear - 1];
    obj->base[obj->rear] = 0;
    obj->rear -= 1;
    return a;
}


int myStackTop(MyStack* obj) {
    int a = obj->base[obj->rear - 1];
    return a;

}

bool myStackEmpty(MyStack* obj) {
    if (obj->rear == obj->front)
        return true;
    else
        return false;
}


void myStackFree(MyStack* obj) {
    free(obj->base);
    free(obj);
}


/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/