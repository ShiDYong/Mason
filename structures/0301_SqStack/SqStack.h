/********************************************************************************
* @author: mason shi
* @date: 2023/11/8 22:07
* @version: 1.0
* @description: 栈的顺序存储结构(顺序栈)
********************************************************************************/
#ifndef SQSTACK_H
#define SQSTACK_H

#include<stdio.h>
#include<stdlib.h>
#include "Status.h"

/*宏定义*/
#define STACK_INIT_SIZE 100 //顺序栈存储空间的初始分配量
#define STACK_INCREMENT 10 //顺序栈存储空间的分配增量

/*顺序栈的元素*/

typedef int SElemType;


/*顺序栈的元素结构*/
typedef struct {
    SElemType *base; //栈底指针
    SElemType *top; //栈顶指针
    int stack_size;//当前分配的存储空间，以元素为单位
} SqStack;

/*
 * 初始化
 * 构造一个空栈。初始化成功则返回OK，否则返回ERROR
 */
Status InitStack(SqStack *S);


/*
 * 销毁(结构)
 * 释放顺序栈所占用的内存
 */
Status DestroyStack(SqStack *S);

/*
 * 置空(内容)
 * 只是清理顺序栈中存储的数据，不释放顺序栈所占的内存
 */
Status ClearStack(SqStack *S);

/*
 * 判空
 * 判断栈中是否包含有效数据
 */
Status StackEmpty(SqStack S);

/*
 * 计数
 * 返回顺序栈包含的有效元素的数量
 *
 */
int StackLength(SqStack S);

/*
 *取值
 * 返回栈顶元素，并用e接收
 */
Status GetTop(SqStack S, SElemType *e);


/*
 * 入栈
 * 将元素e压入到栈顶
 */
Status Push(SqStack *S, SElemType e);


/*
 * 出栈
 * 将栈元素弹出，并用e接收
 */
Status Pop(SqStack *S, SElemType *);

/*
*
* 遍历
* 用visit函数访问顺序栈S
*/
Status StackTraverse(SqStack S, void(Visit)(SElemType));

#endif