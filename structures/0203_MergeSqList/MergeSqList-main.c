/********************************************************************************
* @author: mason shi
* @date: 2023/10/4 17:04
* @version: 1.0
* @description: 
********************************************************************************/
#include<stdio.h>
#include "MergeSqList.h"
#include "SqList.h"
// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    ElemType a[4] = {3, 5, 8, 11};
    ElemType b[7] = {2, 6, 8, 9, 11, 15, 20};

    SqList La, Lb, Lc1, Lc2,Lc3;
    int i;

    // 初始化La
    InitList(&La);
    for(i = 0; i <= 3; i++) {
        ListInsert(&La, i, a[i]);
    }

    // 初始化Lb
    InitList(&Lb);
    for(i = 0; i <= 6; i++) {
        ListInsert(&Lb, i, b[i]);
    }

    // 输出La
    printf("La = ");
    ListTraverse(La, PrintElem);

    // 输出Lb
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);

    // 归并顺序表La和Lb，算法2.2
    MergeSqList_1(La, Lb, &Lc1);
    printf("归并La和Lb为Lc1 = ");
    ListTraverse(Lc1, PrintElem);

    // 归并顺序表La和Lb，算法2.7
    MergeSqList_2(La, Lb, &Lc2);
    printf("归并La和Lb为Lc2 = ");
    ListTraverse(Lc2, PrintElem);

    //将Lc2线性表复制给Lc3
    printf("将线性表Lc2复制给Lc3后，Lc3= ");
    Lc3=Lc2;
    ListTraverse(Lc3,PrintElem);


    return 0;
}
