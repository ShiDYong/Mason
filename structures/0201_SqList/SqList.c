/********************************************************************************
* @author: mason shi
* @date: 2023/10/2 17:54
* @version: 1.0
* @description: 线性表的顺序存储结构(顺序表)
********************************************************************************/
#include "SqList.h"

Status InitList(SqList *L) {
    //分配指定容量的内存，如果分配失败，则返回NULL,构造一个空的线性表L
    L->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (L->elem == NULL)
        //存储分配失败
        exit(OVERFLOW);
    L->length = 0;  //空表的长度为0
    L->listSize = LIST_INIT_SIZE;//初始存储容量
    return OK; //初始化成功

}

/*
 * 销毁线性表结构
 * 释放顺序表所占内存
 */
Status DestroyList(SqList *L) {
    //确保顺序表结构存在
    if (L == NULL || L->elem == NULL)
        return ERROR;
    //释放顺序表内存
    free(L->elem);
    //释放内存后置空指针
    L->elem = NULL;
    //顺序表长度跟容量都归零
    L->length = 0;
    L->listSize = 0;
    return OK;

}

/*
 * 将内容置空
 * 只是清理顺序表存储的数据，不释放顺序表所占内存。
 */
Status ClearList(SqList *L) {
    //确保顺序表结构存在
    if (L == NULL || L->elem == NULL)
        return ERROR;
    L->length = 0;
    return OK;
}

/*
 * 判空
 * 判断顺序表是否包含有效数据
 */
Status ListEmpty(SqList L) {
    return L.length == 0 ? TRUE : FALSE;

}

/*
 * 计数
 * 返回顺序表包含的有效元素的数量
 */
int ListLength(SqList L) {
    return L.length;
}

/*
 * 取值
 * 获取顺序表中第i个元素，将起存储到e中
 * 如果可以找到，返回OK，否则，返回ERROR
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数，但这不符合编码的通用约定。
 * 通常，i的含义应该指索引，即从0开始计数。
 */
Status GetElem(SqList L, int i, ElemType *e) {
    //i的合法范围是：[0,length-1]
    if (i < 0 || i > L.length - 1)
        return ERROR; //超过链表有效元素的数量对应的长度,即数组越界
    *e = L.elem[i - 1];
    return OK;
}

/*
 *  查找
 *  在顺序表中查找第1个与e满足compare()的元素的位序，若找到则返回其在L中的位序，否则返回0
 *  SqList L：这是要在其中搜索元素 e 的顺序列表（或数组）。 SqList 可能表示列表的数据结构或类型定义。
    ElemType e：这是您要在列表 L 中搜索的元素。ElemType 表示列表中元素的数据类型。
    Status (*compare)(ElemType, ElemType)：这部分有点复杂。 它似乎是一个指向比较函数的函数指针，该比较函数采用两个ElemType参数并返回一个Status。
    详细含义如下：
    (*compare)：这是一个指向函数的指针。
    (ElemType, ElemType)：该函数采用两个 ElemType 类型的参数。
    Status：这是compare 指向的函数的返回类型。
    该函数指针的目的是允许您指定一个自定义比较函数，该函数将用于将列表 L 中的元素与目标元素 e 进行比较。 这是一种灵活的方法，可让您定义如何确定元素之间的相等或比较。
 */
int LocalElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
    int i;
    ElemType *p;
    //确保顺序表结构存在
    if (L.elem == NULL)
        return ERROR;
    /*
    * i的初值为第1个元素的位序
    * 其实，更自然的写法是将i初始化为第1个元素的索引
    * 但由于教材中是按位序计数的，所以这里仍写作位序
    */
    i = 0;
    //p的初始值为第1个元素的存储的位置
    p = L.elem;
    //遍历顺序表
    while (i < L.length && !compare(*p++, e)) i++;
    if (i < L.length)
        return i;
    else
        return 0;

}

/*
 * 前驱
 * 获取元素cur_e的前驱，
 * 如果存在，将起存储到pre_e中，返回OK
 * 如果不存在，则返回ERROR
 */
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e) {
    int i;
    //确保表结构存在，且最少包含两个元素
    if (L.elem == NULL || L.length < 2)
        return ERROR;

    //进行遍历查看传入cur_e是否在顺序表中
    for (i = 0; i < L.length - 1; i++)
        if (L.elem[i] == cur_e) {
            *pre_e = L.elem[i - 1];
            return OK;
        }
    return ERROR;

}

/*
 * 后继
 * 获取元素cur_e的后继
 * 如果存在，将其存储到next_e中，返回OK，
 * 如果不存在，则返回ERROR
 */
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e) {
    int i = 0;
    //确保表结构存在，且至少有两个元素
    if (L.elem == NULL || L.length < 2)
        return ERROR;
    //从第一个元素开始，查找cur_e的位置
    while (i < L.length - 1 && L.elem[i] != cur_e) i++;
    //如果cur_e是最后一个元素(没有后驱，或者没找到元素cur_e)，返回ERROR
    if (i >= L.length - 1)
        return ERROR;
    //存储cur_e的后驱
    *next_e = L.elem[i + 1];
    return OK;
}

/*
 *    算法2.4
 *    插入
 * 向顺序表插入第i个位置上插入e，插入成功则返回OK，否则返回ERROR
 * 【备注】
 * 教材中i的含义是元素位置，从1开始计数，这里我们根据数组下标从0开始
 */
Status ListInsert(SqList *L, int i, ElemType e) {
    ElemType *newBase;
    ElemType *p, *q;
    //确保i的值合法
    if (i < 0 || i > L->length) return ERROR;
    //判断当前储存空间是否已经满，如果已满需要扩容
    if (L->length >= L->listSize) {
        newBase = (ElemType *) realloc(L->elem, (L->listSize + LIST_INIT_SIZE) * sizeof(ElemType));
        if (newBase == NULL) exit(OVERFLOW);//动态分配内存失败
        //新地址
        L->elem = newBase;
        //增加存储存储容量
        L->listSize += LIST_INIT_SIZE;
    }
    //确定插入的位置
    q = &(L->elem[i]);
    //将插入位置后的所有元素往右挪动，腾出位置
    if (L->length != 0) //如果插入是第一个数据元素，就不需要挪动
        for (p = &(L->elem[L->length - 1]); p >= q; --p)
            *(p + 1) = *p;//这里好好理解下
    //插入e
    *q = e;
    //表自增1
    L->length++;
    return OK;

}

/*
 *  算法： 2.5
 *  删除
 * 删除顺序表第i个位置上的元素，并将被删除元素存储到e中
 * 删除成功则返回OK，否则返回ERROR
 */
Status ListDelete(SqList *L, int i, ElemType *e) {
    ElemType *p, *q;
    //确保表结构存在
    if (L == NULL || L->elem == NULL) return ERROR;
    //确保i值不会越界
    if (i < 0 || i > L->length - 1) return ERROR;
    //获取被删除位置的内存地址
    p = &(L->elem[i - 1]);
    //获取被删除元素
    *e = *p; //一般删除方法都会把删除的数据作为返回值
    //表尾元素的位置
    q = &(L->elem[L->length - 1]);
    //从被删除元素的位置整体向左移动一位，被删除元素的位置上会有新元素进来
    for (++p; p <= q; ++p)
        *(p - 1) = *p; //这里要好好理解下,稍稍有点绕
    //表自减1
    L->length--;
    return OK;

}

/*
 * 遍历
 * 用visit函数访问顺序表L
 * ，ListTraverse 是一个以序列列表 (L) 和函数指针 (Visit) 作为参数的高阶函数。 它迭代列表中的元素并将函数 Visit 应用于每个元素。
 * (SqList L, void(Visit)(ElemType)):
   This is the function's parameter list. It consists of two parameters:
   SqList L: This is a parameter of type SqList, which presumably represents the sequence list that you want to traverse.
   void(Visit)(ElemType): This is a parameter of type function pointer. It's named Visit, and it takes a single argument of
   type ElemType. This function pointer is used to specify what operation should be performed on each element during the traversal.
 */
void ListTraverse(SqList L, void(Visit)(ElemType)) {
    int i;
    for (i = 0; i < L.length; i++)
        Visit(L.elem[i]);
    printf("\n");

}
