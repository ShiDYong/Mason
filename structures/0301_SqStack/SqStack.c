/********************************************************************************
* @author: mason shi
* @date: 2023/11/8 22:07
* @version: 1.0
* @description: 顺序栈常用接口的实现
********************************************************************************/
#include "SqStack.h"

/*
 * 初始化
 * 构造一个空栈。初始化成功则返回OK，否则返回ERROR
 */
Status InitStack(SqStack *S) {
    //判断栈指针是否为空
    if (S == NULL) return ERROR;
    //分配元素内存
    (*S).base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if ((*S).base == NULL) exit(OVERFLOW);

    (*S).top = (*S).base;
    (*S).stack_size = STACK_INIT_SIZE;
    return OK;

}


/*
 * 销毁(结构)
 * 释放顺序栈所占用的内存
 */
Status DestroyStack(SqStack *S) {
    if (S == NULL) return ERROR;
    free((*S).base);
    (*S).base = NULL;
    (*S).top = NULL;
    (*S).stack_size = 0;
    return OK;
}

/*
 * 置空(内容)
 * 只是清理顺序栈中存储的数据，不释放顺序栈所占的内存
 */
Status ClearStack(SqStack *S) {

    if (S == NULL || (*S).base == NULL) return ERROR;
    (*S).top = (*S).base;
    return OK;

}

/*
 * 判空
 * 判断栈中是否包含有效数据
 */
Status StackEmpty(SqStack S) {
    if (S.top == S.base) return TRUE;
    else return FALSE;
}

/*
 * 计数
 * 返回顺序栈包含的有效元素的数量
 *
 */
int StackLength(SqStack S) {
    if (S.base == NULL) return 0;
    return (int) (S.top - S.base);
}

/*
 *取值
 * 返回栈顶元素，并用e接收
 */
Status GetTop(SqStack S, SElemType *e) {

    if (S.base == NULL || S.top == S.base) return 0;
    *e = *(S.top - 1); //这里设计的数据结构，栈顶指针为空，不存储元素
}


/*
 * 入栈
 * 将元素e压入到栈顶
 */
Status Push(SqStack *S, SElemType e) {
    if (S == NULL || (*S).base == NULL) return ERROR;

    //判断是否满栈，需要追加存储空间
    if ((*S).top - (*S).base >= (*S).stack_size) {
        (*S).base = (SElemType *) realloc((*S).base, ((*S).stack_size + STACK_INCREMENT) * sizeof(SElemType));
        if ((*S).base == NULL) exit(OVERFLOW);
        (*S).top = (*S).base + (*S).stack_size;
        (*S).stack_size += STACK_INCREMENT;
    }
    //进栈先赋值，栈顶指针再自增
    *(S->top++) = e;
    return OK;
}


/*
 * 出栈
 * 将栈元素弹出，并用e接收
 */
Status Pop(SqStack *S, SElemType *e) {
    if (S == NULL || (*S).base == NULL || (*S).top == (*S).base) return ERROR;

    //出栈指针先递减，在赋值
    *e = *(--(*S).top);
    return OK;
}

/*
*
* 遍历
* 用visit函数访问顺序栈S
*/
Status StackTraverse(SqStack S, void(Visit)(SElemType)) {
    SElemType *p = S.base;

    if (S.base == NULL) {
        return ERROR;
    }

    while (p < S.top) {
        Visit(*p++);
    }

    printf("\n");

    return OK;
}
