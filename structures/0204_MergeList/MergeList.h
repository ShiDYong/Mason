/********************************************************************************
* @author: mason shi
* @date: 2023/10/17 21:39
* @version: 1.0
* @description: 将两个有序链表合并为一个有序链表
********************************************************************************/
#ifndef MERGLIST_H
#define MERGLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/*
 *非递减链表归并：C=A+B
 *
 */
void MergeList(LinkList *La, LinkList * Lb, LinkList *Lc);


#endif

