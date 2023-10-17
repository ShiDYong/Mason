/********************************************************************************
* @author: mason shi
* @date: 2023/10/17 21:43
* @version: 1.0
* @description: 
********************************************************************************/
#include "MergeList.h"

/*
 *非递减链表归并：C=A+B
 *
 */
void MergeList(LinkList *La, LinkList *Lb, LinkList *Lc) {
    LinkList pa, pb, pc;
    pa = (*La)->next;//注意pa是La的指向的下一个结点
    pb = (*Lb)->next;
    pc = *Lc = *La;//用La的头结点作为Lc的头结点
    //遍历La和Lb
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    //插入剩余段
    pc->next = pa ? pa : pb;//要注意这里的理解,pa为NULL，说明La的元素已经归并完来，不为NULL,则说明Lb已经归并完了
    //释放Lb的头结点所占内存
    free(*Lb);
    *La = NULL;
    *Lb = NULL;


}