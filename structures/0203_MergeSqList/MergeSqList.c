/********************************************************************************
* @author: mason shi
* @date: 2023/10/4 17:04
* @version: 1.0
* @description: 归并表的实现
********************************************************************************/
#include "MergeSqList.h"


void Print(ElemType e) {
    printf("%d ", e);
}

/*
 * 非递减顺序表归并： C=A+B
 * 归并顺序表La和Lb，生成新的顺序表Lc
 * 其中，La、Lb和Lc均为非递减序列
 */
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc) {
    int La_len, Lb_len;
    int i, j, k;
    ElemType ai, bj;
    i = j = 0;
    k = 0;
    //初始化Lc
    InitList(Lc);
    //获取La、Lb的长度
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);
    //分别遍历La和Lb元素取出来比较大小，偏小数据元素插入到Lc中
    while (i <= La_len - 1 && j <= Lb_len - 1) { //注意这里循环判断条件，因为数组下标是从0开始的，很容易漏掉
        GetElem(La, i, &ai);
        GetElem(Lb, j, &bj);
        //比较遍历到的元素，现将比较小的元素加入到顺序表Lc
        if (ai <= bj) {
            ListInsert(Lc, k++, ai);
            i++;
        } else {
            ListInsert(Lc, k++, bj);
            j++;
        }
    }

    //如果Lb已遍历玩，但是La还未遍历完，将La中剩余元素加入Lc
    while (i <= La_len - 1) {
        GetElem(La, i++, &ai);
        ListInsert(Lc, k++, ai);
    }
    printf("=====打印初次遍历完成后的数据========: \n");
    ListTraverse(*Lc, Print);
    //如果La已遍历完，但是Lb还没有遍历完，将Lb中剩余元素加入Lc
    while (j <= Lb_len - 1) {
        GetElem(Lb, j++, &bj);
        ListInsert(Lc, k++, bj);
    }
}

/*
 * 方法二通过充分利用指针的特性以及和指针和数组的密切关系
 * ，几乎不依赖SqList实现接口的依赖,非常简洁
 */
void MergeSqList_2(SqList La, SqList Lb, SqList *Lc) {
    ElemType *pa, *pb, *pc;
    ElemType *pa_last, *pb_last;

    pa = La.elem; //指向La第一个元素
    pb = Lb.elem;//指向Lb第一个元素
    //直接使用动态分配内存
    Lc->listSize = (*Lc).length = La.length + Lb.length;
    pc = Lc->elem = (ElemType *) malloc(Lc->listSize * sizeof(ElemType));
    if (pc == NULL)
        exit(OVERFLOW);
    pa_last = La.elem + La.length - 1; //通过指针的算术运算，指向La最后一个元素
    pb_last = Lb.elem + Lb.length - 1;

    //如果La及Lb均未遍历完
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }
    //如果Lb已经遍历完成，但La还没有遍历完成，将La中剩余元素加入Lc
    while (pa <= pa_last)
        *pc++ = *pa++;

    //同理
    while (pb <= pb_last)
        *pc++ = *pb++;
}