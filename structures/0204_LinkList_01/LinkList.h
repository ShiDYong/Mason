/********************************************************************************
* @author: mason shi
* @date: 2023/10/6 09:34
* @version: 1.0
* @description: 线性表的链式存储结构(链表)操作接口
 * 包含算法： 2.8、2.9、2.10、2.11
********************************************************************************/
#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Status.h"

/*单链表元素类型定义*/
typedef int ElemType;

/*
 * 单链表结构
 * 注：这里的但链表存在头结点
 * 这里的结点类型声明要使用结构标记，而不是结构定义：
 * 要求：在结构有一个指向相同结构类型的指针成员时，要求使用使用结构标记，没有node标记，就没有办法声明nex
 */
typedef struct LNode {
    ElemType data; //数据结点
    struct LNode *next; //指向下一个结点的指针
} LNode;

//下面代码指向 LNode 结构的指针创建类型别名 LinkList。
// 换句话说，LinkList 是一个指向单链表第一个节点的指针。
//该类型用于定义链表的头，使得管理和操作链表更加容易。
typedef LNode *LinkList;

/*
 * 初始化链表
 */
Status InitList(LinkList *L);


/*
 * 销毁结构
 * 释放链表所占内存
 */
Status DestroyList(LinkList *L);


/*
 * 置空内容
 * 这里需要释放链表中非头结点处的空间
 */
Status ClearList(LinkList L);

/*
 * 判空：链表中是否包含有效数据
 */
Status ListEmpty(LinkList L);


/*
 * 获取链表长度
 * 返回链表中包含的有效元素的数量
 */
int ListLength(LinkList L);


/*
 * 算法：2.8
 * 取值:获取链表中第i个位置的元素，并将元素数据存储到e中
 *
 *
 */
Status GetElem(LinkList L, int i, ElemType *e);


/*
 * 查找：返回链表中首个与e满足compare关系的元素位序。
 *
 */
Status LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));


/*
 * 前驱：获取元素cur_e的前驱，如果存在，将其存储到pre_e中，返回OK
 */
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e);

/*
 * 后驱：获取元素cur_e的后驱，如果存在，将其存储到next_e中，返回OK
 */
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e);

/*
 * 算法： 2.9
 * 插入：向链表中第i个位置插入e，插入成功则返回OK，否则返回ERROR
 */
Status ListInsert(LinkList L, int i, ElemType e);

/*
 * 算法： 2.10
 * 删除：删除链表第i个位置上的元素，并将被删除元素存储到e中
 */
Status ListDelete(LinkList L, int i, ElemType *e);


/*
 * 遍历
 * 用visit函数访问链表L
 */
Status ListTraverse(LinkList L, void(Visit)(ElemType));

/*
 * ████████ 算法2.11 ████████
 *
 * 头插法创建链表
 *
 *
 *【备注】
 *
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而允许选择从预设的文件path中读取测试数据。
 *
 * 如果需要从控制台读取数据，则path为NULL或者为空串，
 * 如果需要从文件中读取数据，则需要在path中填写文件名信息。
 */
Status CreateList_Head(LinkList *L, int n, char *path);

/*
 * 尾插法创建链表
 *【备注】
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而允许选择从预设的文件path中读取测试数据。
 * 如果需要从控制台读取数据，则path为NULL或者为空串，
 * 如果需要从文件中读取数据，则需要在path中填写文件名信息。
 */
Status CreateList_Tail(LinkList *L, int n, char *path);


#endif