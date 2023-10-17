/********************************************************************************
* @author: mason shi
* @date: 2023/10/6 10:56
* @version: 1.0
* @description: 线性表的链式存储结构(链表)接口实现
 * 包含算法： 2.8、2.9、2.10、2.11
********************************************************************************/
#include "LinkList.h"

/*
 * 初始化链表
 * 只是初始化一个头结点
 * 通过使用指向指针的指针：可以在多层指针之间进行导航，以便访问或修改数据，这在某些情况下非常有用，
 *                      特别是在处理多维数组、动态内存分配或构建复杂数据结构时。
 */
Status InitList(LinkList *L) {//指向指针的指针，等价于：Lnode **list
    //注意参数指针变量L是指向LinkList，而LinkList也是一个指针变量
    //LinkList 是一个指向单链表第一个节点的指针
    //(*L) 用于用新分配的内存的地址更新指针L
    (*L) = (LinkList) malloc(sizeof(LNode));
    if (*L == NULL) exit(OVERFLOW);
    //L指向一个链表节点，这行将新创建的节点的next指针设置为NULL，
    // 表示它是链表中的第一个节点，并且没有 跟随它的其他节点。
    (*L)->next = NULL;
    return OK;
}


/*
 * 销毁结构
 * 释放链表所占内存,头结点也会被清理
 */
Status DestroyList(LinkList *L) {
    LinkList p;
    //确保表结构存在
    if (L == NULL || *L == NULL)
        return ERROR;
    p = *L;
    //释放单链表所有结点所占用的内存
    while (p != NULL) {
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }
    //头结点一起清理
    *L = NULL;
    return OK;


}

/*
 * 置空内容
 * 这里需要释放链表中非头结点处的空间
 */
Status ClearList(LinkList L) {
    LinkList pre, p;
    //确保链表存在
    if (L == NULL) return ERROR;
    p = L->next;
    //释放链表上所有结点所占用的内存
    while (p != NULL) {
        pre = p;
        p = p->next;
        free(pre);
    }
    L->next = NULL;
    return OK;

}

/*
 * 判空：链表中是否包含有效数据
 */
Status ListEmpty(LinkList L) {
    //链表只有头结点时，认为该链表为空
    if (L != NULL && L->next == NULL)
        return TRUE;
    else
        return FALSE;

}


/*
 * 获取链表长度
 * 返回链表中包含的有效元素的数量
 */
int ListLength(LinkList L) {
    LinkList p;
    int i;
    //确保链表不为空链表
    if (L != NULL && L->next == NULL) return 0;
    i = 0;
    p = L->next;
    //遍历所有结点
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}


/*
 * 算法：2.8
 * 取值:获取链表中第i个位置的元素，并将元素数据存储到e中
 *
 *
 */
Status GetElem_01(LinkList L, int i, ElemType *e) {
    int k;
    //确保合理范围内
    if (i < 0 || i > ListLength(L)) return ERROR;
    k = 0;
    L = L->next;//第一个头结点数据为空,少了会导致少一个
    while (L != NULL && k <= i) {
        if (k == i) {
            *e = L->data;
            return OK;
        }
        L = L->next;
        k++;
    }
    return ERROR;

}

Status GetElem(LinkList L, int i, ElemType *e) {
    LinkList p;
    int j;

    //确保链表保存且不为空
    if (L == NULL || L->next == NULL) return ERROR;

    p = L;
    j = 0;
    //寻找第i-1个结点，且保证该结点的后继不为NULL
    while (p->next != NULL && j < i) {
        p = p->next;
        j++;
    }

    //如果遍历到头了，或者i的值不合规(比如i<=0),说明没找到合乎目标的结点
    if (p->next == NULL || j > i) return ERROR;
    *e = p->next->data;
    return OK;

}


/*
 * 查找：返回链表中首个与e满足compare关系的元素位序。
 *
 */
Status LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
    int i;
    LinkList p;
    //确保链表存在且不为空表
    if (L == NULL || L->next == NULL) return ERROR;
    i = 0; //i的初始值为第1个元素的位序
    p = L->next; //p的初始值位第1个元素的指针
    while (p != NULL && !compare(p->data, e)) {
        i++;
        p = p->next;
    }
    if (p != NULL)
        return i;
    else
        return 0;
}


/*
 * 前驱：获取元素cur_e的前驱，如果存在，将其存储到pre_e中，返回OK
 */
Status PriorElem_02(LinkList L, ElemType cur_e, ElemType *pre_e) {
    LinkList p;
    //确保链表存在且不为空
    if (L == NULL || L->next == NULL) return ERROR;
    p = L->next;//指向第1个元素
    //头结点没有前驱，不要忘记
    if (p->data == cur_e)
        return ERROR;
    while (p != NULL) {
        if (p->next->data == cur_e) {
            *pre_e = p->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;

}

/*
 * 这里使用指针追踪法
 */
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e) {
    LinkList pre, next;
    //确保链表存在且不为空表
    if (L == NULL || L->next == NULL) return ERROR;

    //指向第一个元素
    pre = L->next;
    //第一个元素没有前驱
    if (pre->data == cur_e) return ERROR;

    //指向第二个元素
    next = pre->next;
    //从第二个元素开始，查找cur_e的位置
    while (next != NULL && next->data != cur_e) {
        pre = next;
        next = next->next;
    }
    //如果没有找到元素cur_e，查找失败，返回ERROR
    if (next == NULL) return ERROR;
    *pre_e = pre->data;
    return OK;

}

/*
 * 后驱：获取元素cur_e的后驱，如果存在，将其存储到next_e中，返回OK
 */
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e) {
    LinkList pre;
    //确保链表存在且不为空
    if (L == NULL || L->next == NULL) return ERROR;
    //指向第1个元素
    pre = L->next;

    //从第1个元素开始，查重cur_e的位置，且保证该结点的后继不为NULL
    while (pre->next != NULL && pre->data != cur_e)
        pre = pre->next;

    //如果没找到cur_e，或者找到了，但它没有后继将，均返回ERROR
    if (pre->next == NULL) return ERROR;

    *next_e = pre->next->data;
    return OK;

}

/*
 * 算法： 2.9
 * 插入：向链表中第i个位置插入e，插入成功则返回OK，否则返回ERROR
 */
Status ListInsert(LinkList L, int i, ElemType e) {
    LinkList p, s;
    int j;
    //确保链表存在
    if (L == NULL) return ERROR;

    //寻找第i-1个结点，且保证该结点本身不为NULL
    for (p = L, j = 0; p != NULL && j < i; p = p->next, j++);
    //如果遍历到头了，或者i的值不合规(i<=0)，说明没找到合乎的结点
    if (p == NULL || j > i) return ERROR;

    //生成新结点
    if ((s = (LinkList) malloc(sizeof(LNode))) == NULL) exit(OVERFLOW);
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/*
 * 算法： 2.10
 * 删除：删除链表第i个位置上的元素，并将被删除元素存储到e中
 */
Status ListDelete(LinkList L, int i, ElemType *e) {
    LinkList p, q;
    int j;
    //确保链表存在且不是空链表
    if (L == NULL || L->next == NULL) return ERROR;
    p = L;
    j = 0;
    //寻找第i-1个结点，且保证该结点的后继结点不为NULL
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    //如果遍历到头了，或者i的值不合规，说明没有找到合乎目标的结点
    if (p->next == NULL || j > i) return ERROR;

    //删除第i个结点
    q = p->next;
    p->next = q->next;
    *e = q->data;
    //释放被删除结点的所占的内存
    free(q);
    return OK;
}


/*
 * 遍历
 * 用visit函数访问链表L
 */
Status ListTraverse(LinkList L, void(Visit)(ElemType)) {
    //确保链表存在且不为空链表
    if (L == NULL || L->next == NULL) return ERROR;
    L = L->next;
    while (L != NULL) {
        Visit(L->data);
        L = L->next;
    }
    printf("\n");
}

/*
 * ████████ 算法2.11 ████████
 *
 * 头插法创建链表:也就是从链表开始处插入结点，从表尾到表头逆向建立单链表的算法,即链表内的数据会发生倒置
 *
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
Status CreateList_Head(LinkList *L, int n, char *path) {
    int i;
    LinkList p;
    FILE *fp;
    int readFromConsole; //是否从控制台读取数据
    //如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    if (readFromConsole) {
        //建立头结点
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;//先建立一个带头结点的单链表
        printf("请输入%d个降序元素： ", n);
        for (i = 0; i <= n; i++) {
            //生成新结点
            p = (LinkList) malloc(sizeof(LNode));
            //填充数据,并插入到链表中
            scanf("%d", &(p->data));
            p->next = (*L)->next;
            (*L)->next = p;
        }

    } else {
        //打开文件，准备读取测试数据,注意这里要决定路径
        fp = fopen(path, "r");
        if (fp == NULL) return ERROR;
        //建立头结点
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;
        for (i = 0; i <= n; i++) {
            //生成新结点
            p = (LinkList) malloc(sizeof(LNode));
            //填充数据，并插入到链表中
            ReadData(fp, "%d", &(p->data));
            p->next = (*L)->next;
            (*L)->next = p;

        }
        fclose(fp);
    }
    return OK;
}

/*
 * 尾插法创建链表
 *【备注】
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而允许选择从预设的文件path中读取测试数据。
 * 如果需要从控制台读取数据，则path为NULL或者为空串，
 * 如果需要从文件中读取数据，则需要在path中填写文件名信息。
 */
Status CreateList_Tail(LinkList *L, int n, char *path) {
    int i;
    LinkList p, q;
    FILE *fp;
    int readFromConsole;    // 是否从控制台读取数据

    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;

    if (readFromConsole) {
        // 建立头结点
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;

        printf("请输入%d个升序元素：", n);

        for (i = 1, q = *L; i <= n; ++i) {
            // 生成新结点
            p = (LinkList) malloc(sizeof(LNode));

            // 填充数据，并插入到链表中
            scanf("%d", &(p->data));

            q->next = p;
            q = q->next;
        }

        q->next = NULL;
    } else {
        // 打开文件，准备读取测试数据
        fp = fopen(path, "r");
        if (fp == NULL) {
            return ERROR;
        }

        // 建立头结点
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;

        for (i = 1, q = *L; i <= n; ++i) {
            // 生成新结点
            p = (LinkList) malloc(sizeof(LNode));

            // 填充数据，并插入到链表中
            ReadData(fp, "%d", &(p->data));

            q->next = p;
            q = q->next;
        }

        q->next = NULL;

        fclose(fp);
    }

    return OK;
}