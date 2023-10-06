/********************************************************************************
* @author: mason shi
* @date: 2023/10/2 17:54
* @version: 1.0
* @description:验证顺序表常用的接口是否正常使用
********************************************************************************/
#include<stdio.h>
#include"SqList.h"

//测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}

//判断data>e是否成立
Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

int main(int argc, char **argv) {
    SqList L; //待操作的顺序表
    int i;
    ElemType e;
    printf("=========InitList===========\n");
    {
        printf("初始化顺序表 L....\n");
        InitList(&L);
    }
    PressEnterToContinue(debug);
    printf("ListEmpty\n");
    {
        if (ListEmpty(L) == TRUE)
            printf("L为空！！\n");
        else
            printf("L不为空！！\n");
    }

    printf("=========ListInsert========\n");
    {
        for (i = 0; i <= 8; i++) {
            printf("作为示范，在L第%d个位置插入 \"%d\"....\n", i, 2 * i);
            ListInsert(&L, i, 2 * i);
        }
    }
    PressEnterToContinue(debug);

    printf("=============ListTraverse \n");
    {
        printf("L 中的元素为：L= ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);

    printf("===========ListLength==========\n");
    {
        printf("顺序表中的长度为：Length= %d\n", ListLength(L));
    }
    PressEnterToContinue(debug);

    printf("=============ListDelete==========\n");
    {
        printf(" 删除前的元素：L= ");
        ListTraverse(L, PrintElem);
        printf(" 尝试删除L中第6个元素...\n");
        if (ListDelete(&L, 6, &e) == OK)
            printf(" 删除成功，被删除元素是：\"%d\"\n", e);
        else
            printf(" 删除失败，第6个元素在顺序表中不存在!\n");
        printf(" 删除后的元素：L= ");
        ListTraverse(L, PrintElem);

    }
    PressEnterToContinue(debug);

    printf("GetElem \n");
    {
        GetElem(L, 4, &e);
        printf(" L 中第4个元素位置为 \"%d\"\n", e);
    }
    PressEnterToContinue(debug);

    printf(" LocateELem \n");
    {
        i = LocalElem(L, 7, CmpGreater);
        printf(" L中第一个元素值大于 \"7\"的元素是 \"%d\" \n", L.elem[i]);
    }
    PressEnterToContinue(debug);

    printf("=============PriorElem=============");
    {
        ElemType cur_e = 6;
        if (PriorElem(L, cur_e, &e) == OK)
            printf(" 元素 \"%d\" 的前驱为 \"%d\" \n", cur_e, e);
        else
            printf(" 元素 \"%d\"的前驱不存在！\n", cur_e);

    }
    PressEnterToContinue(debug);

    printf(" NextElem \n");
    {
        ElemType cur_e = 6;
        if (NextElem(L, cur_e, &e) == OK)
            printf(" 元素 \"%d\" 的后驱为 \"%d\" \n", cur_e, e);
        else
            printf(" 元素 \"%d\"的后驱不存在！\n", cur_e);


    }
    PressEnterToContinue(debug);


    printf("████████ ClearList \n");
    {
        printf("█ 清空 L 前：");
        if (ListEmpty(L) == TRUE) {
            printf(" L 为空！！\n");
        } else {
            printf(" L 不为空！\n");
        }

        ClearList(&L);

        printf("█ 清空 L 后：");
        if (ListEmpty(L) == TRUE) {
            printf(" L 为空！！\n");
        } else {
            printf(" L 不为空！\n");
        }
    }
    PressEnterToContinue(debug);


    printf("████████ DestroyList \n");
    {
        printf("█ 销毁 L 前：");
        if (L.elem != NULL) {
            printf(" L 存在！\n");
        } else {
            printf(" L 不存在！！\n");
        }

        DestroyList(&L);

        printf("█ 销毁 L 后：");
        if (L.elem != NULL) {
            printf(" L 存在！\n");
        } else {
            printf(" L 不存在！！\n");
        }
    }
    PressEnterToContinue(debug);


    return 0;

}