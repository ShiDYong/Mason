/********************************************************************************
* @author: mason shi
* @date: 2023/10/4 15:28
* @version: 1.0
* @description: 算法2.1
 * 架设利用线性表LA和LB分别表示两个集合A和B(即线性表中的数据元素即为集合中的成员)，现要求一个新的集合A=AUB.
 * 这就要求对线性表A进行扩大，将存在于线性表LB中而不存在于线性表LA中的数据元素插入到线性表LA中去。
********************************************************************************/
#ifndef UNION_H
#define UNION_H
#include<stdio.h>
#include"Status.h"
#include "SqList.h"

/**
 * A=AUB:计算La于Lb的并集并返回
 * @param La
 * @param Lb
 * 由于生成的并集会拼接在La上，所以La的入参为指针类型.
 *
 */
void Union(SqList *La,SqList Lb);

/**
 * 判断是否相等
 * @param e1
 * @param e2
 * @return 如果相等，则返回TRUE,否则，返回FALSE.
 */
Status equal(ElemType e1,ElemType e2);



#endif

