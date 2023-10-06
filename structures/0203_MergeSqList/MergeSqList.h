/********************************************************************************
* @author: mason shi
* @date: 2023/10/4 16:57
* @version: 1.0
* @description: 归并非降序顺序表：已知线性表La和Lb中的数据元素按值非递减排列，现要求将La和Lb归并为一个新的线性表
 *              Lc，且Lc中的数据元素仍非按值递减有序排列
********************************************************************************/
#include "Status.h"
#include "SqList.h"
#include <stdio.h>

/*
 * 非递减顺序表归并： C=A+B
 * 归并顺序表La和Lb，生成新的顺序表Lc
 * 其中，La、Lb和Lc均为非递减序列
 */
void MergeSqList_1(SqList La, SqList Lb,SqList *Lc);

/*
 * 非递减顺序表归并： C=A+B
 * 归并顺序表La和Lb，生成新的顺序表Lc
 * 其中，La、Lb和Lc均为非递减序列
 */
void MergeSqList_2(SqList La, SqList Lb,SqList *Lc);
