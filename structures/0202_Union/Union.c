/********************************************************************************
* @author: mason shi
* @date: 2023/10/4 15:37
* @version: 1.0
* @description: 
********************************************************************************/
#include "Union.h"

/**
 * A=AUB:计算La于Lb的并集并返回
 * @param La
 * @param Lb
 * 由于生成的并集会拼接在La上，所以La的入参为指针类型.
 * 思路：只要从线性表Lb中依次获取得每个数据元素，并依值在线性表La
 *      中进行查访，若不存在，则插入之。
 *
 */
void Union(SqList *La, SqList Lb) {
    int La_len, Lb_len;
    int i;
    ElemType e;
    //求顺序表的长度,借助之前获取长度方法
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);

    for (i = 0; i < Lb_len; i++) {
        //取Lb中的某个数据元素赋值给e
        GetElem(Lb, i, &e);
        //判断La中不存在和e相同的数据元素，则插入
        if (!LocalElem(*La, e, equal))//函数指针，力大无穷
            ListInsert(La, i, e);

    }


}

/**
 * 判断是否相等
 * @param e1
 * @param e2
 * @return 如果相等，则返回TRUE,否则，返回FALSE.
 */
Status equal(ElemType e1, ElemType e2) {
    return e1 == e2 ? TRUE : FALSE;
}