/********************************************************************************
* @author: mason shi
* @date: 2023/10/28 12:01
* @version: 1.0
* @description: 双向循环链表常用的接口
********************************************************************************/
#ifndef DULINKLIST_H
#define DULINKLIST_H

#include<stdio.h>
#include<stdlib.h>//提供malloc、realloc、free、exit原型
#include "Status.h"

/*双向循环链表元素类型定义*/
typedef int ElemType;

/*
 * 双向循环列表结构
 * 注：这里的双向循环链表存在头结点
 */
typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior; //前驱
    struct DuLNode *next; //后驱
} DuLNode;

/*指向双向循环链表结点的指针*/
typedef DuLNode *DuLinkList;

/*
 * 初始化
 * 初始化成功则返回OK，否则返回ERROR
 *
 */
Status InitList(DuLinkList *L);


/*
 * 销毁(结构)
 * 释放双向链表所占内存
 */
Status DestroyList(DuLinkList *L);

/*
 * 置空(内容)
 * 这里需要释放双向循环链表中非头结点处的空间
 */
Status ClearList(DuLinkList L);


/*
 * 判空
 * 判断双向循环链表是否包含有效数据
 * 返回值：
 * TRUE: 双向循环链表为空
 * FALSE: 双向循环链表不为空
 */
Status ListEmpty(DuLinkList L);


/*
 * 计数
 * 返回双向链表中包含的有效元素的数量
 */
int ListLength(DuLinkList L);


/*
 * 取值
 * 获取双向循环链表中第i个元素，将其存储到e中
 * 如果可以找到，则返回OK，否则返回ERROR
 */
Status GetElem(DuLinkList L, int i, ElemType *e);


/*
 * 查找
 * 返回双向循环链表中首个与e满足Compare关系的元素位序。
 * 如果不存在这样的元素，则返回0.
 */
int LocateElem(DuLinkList L, ElemType e, Status(Compare)(ElemType, ElemType));


/*
 * 前驱
 * 获取元素cur_e的前驱
 * 如果存在，将其存储到pre_e中，返回OK
 * 如果不存在，则返回ERROR
 */
Status PriorElem(DuLinkList L, ElemType cur_e, ElemType *pre_e);


/*
 * 后驱
 */
Status NextElem(DuLinkList L, ElemType cur_e, ElemType *next_e);


/*
 * 插入
 * 向双向循环链表第i个位置上插入e，插入成功则返回OK，否则返回ERROR
 */
Status ListInsert(DuLinkList L, int i, ElemType e);


/*
 * 删除
 * 删除双向链表中第i个位置上的元素，并将删除元素存储到e中
 * 删除成功则返回OK，否则返回ERROR
 */
Status ListDelete(DuLinkList L, int i, ElemType *e);

/*
 * 遍历
 * 用Visit函数访问双向循环链表L
 */
void ListTraverse(DuLinkList L, void(Visit)(ElemType));

/*
 * 获取循环链表L上第i个元素的引用
 * 注意：
 * 1.加static的含义是当前函数只在DuLinkList中使用，不会被别的文件引用
 * 2.假设链表长度为L，且需要获取第len+1个元素的引用时，由于这里是循环链表，所以返回的是头结点
 */
static DuLinkList GetElemP(DuLinkList L, int i);

#endif

