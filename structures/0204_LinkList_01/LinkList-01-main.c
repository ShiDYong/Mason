/********************************************************************************
* @author: mason shi
* @date: 2023/10/6 10:57
* @version: 1.0
* @description: 
********************************************************************************/
#include<stdio.h>
#include "Status.h"
#include "LinkList.h"

// 判断data>e是否成立
Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

//测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main(int argc, char **argv) {
    LinkList L;
    int i;
    ElemType e;

    printf("==========InitList===========\n");
    {
        printf("....初始化单链表 L ....\n");
        InitList(&L);
    }
    PressEnterToContinue(debug);

    printf("=============ListInsert===========\n");
    {
        for (i = 0; i < 8; i++) {
            printf(" 在 L 第%d 个位置插入 \"%d\"...\n", i, 2 * i);
            ListInsert(L, i, 2 * i);
        }
        //插入头结点,链表内的数会发生倒序，因为first始终指向包含最后输入的数的结点
        ListInsert(L, 0, 1001);
        //插入尾结点
        ListInsert(L, ListLength(L), 1002);
        printf("L中的元素为： L =");
        //插入中间结点
        ListInsert(L, ListLength(L) / 2, 1002);

        ListTraverse(L, PrintElem);

    }
    PressEnterToContinue(debug);

    printf("==============ListDelete===================\n");
    {
        //删除头结点
        ListDelete(L, 10, &e);
        //删除尾结点
        ListDelete(L, 0, &e);
        //删除中间的结点
        ListDelete(L, ListLength(L) / 2, &e);
        printf("被删除的数据元素是: %d\n", e);
        printf("L中的元素为： L =");
        ListTraverse(L, PrintElem);


    }
    PressEnterToContinue(debug);
    printf("================GetElem================\n");
    {
        GetElem(L, 7, &e);
        printf("获取指定位置的数据元素结果是：%d\n", e);
    }
    PressEnterToContinue(debug);

    printf("============LocateElem===================\n");
    {
        i = LocateElem(L, 7, CmpGreater);
        GetElem(L, i, &e);
        printf("█ L 中第一个元素值大于 \"7\" 的元素是 \"%d\" \n", e);
    }
    PressEnterToContinue(debug);

    printf("==============PriorElem=================\n");
    {
        ElemType cur_e = 14;
        if (PriorElem(L, cur_e, &e) == OK)
            printf(" 元素 \"%d\"的前驱为 \"%d\" \n", cur_e, e);
        else
            printf("█ 元素 \"%d\" 的前驱不存在！\n", cur_e);


    }
    PressEnterToContinue(debug);

    printf("==============NextElem=================\n");
    {
        ElemType cur_e = 14;
        if (NextElem(L, cur_e, &e) == OK)
            printf(" 元素 \"%d\"的后驱为 \"%d\" \n", cur_e, e);
        else
            printf("█ 元素 \"%d\" 的后驱不存在！\n", cur_e);


    }
    PressEnterToContinue(debug);

    printf("================ListEmpty================\n");
    {
        if (!ListEmpty(L))
            printf("  链表L不是空链表.\n");
        else
            printf("  链表L是空链表.\n");

    }
    PressEnterToContinue(debug);

    printf("================ClearEmpty================\n");
    {
        printf("█ 清空 L 前：");
        ListEmpty(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");

        ClearList(L);

        printf("█ 清空 L 后：");
        ListEmpty(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");


    }
    PressEnterToContinue(debug);

    printf("████████ DestroyList \n");
    {
        printf("█ 销毁 L 前：");
        L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");

        DestroyList(&L);

        printf("█ 销毁 L 后：");
        L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
    }
    PressEnterToContinue(debug);
    printf("████████ CreateList_Head \n");
    {
        LinkList L;
       const char *filename = "/Users/yongshi/Downloads/MyCode/mason/structures/0204_LinkList_01/TestData_Head.txt";
        CreateList_Head(&L, 5, filename);
        printf("█ 头插法建立单链表 L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);

    return 0;
}