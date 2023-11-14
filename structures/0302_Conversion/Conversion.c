/********************************************************************************
* @author: mason shi
* @date: 2023/11/13 22:11
* @version: 1.0
* @description: 进值转换的实现:将指定的非负数十进制整数，转换为八进制后输出
********************************************************************************/
#include "Conversion.h"

void Conversion(int i) {
    SqStack S;
    SElemType e;
    InitStack(&S);

    //八进制数前面加0
    printf("十进制数 %d 转换为八进制数后： 0", i);
    while (i != 0) {
        Push(&S, i % 8); //进栈从低位到高位
        i = i / 8;
    }
    while (StackEmpty(S) == FALSE) {
        Pop(&S, &e); //出栈时从高位到低位
        printf("%d", e);
    }
    printf("\n");


}

/*
 * 判断是否匹配的括号对
 */
static int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')') return 1;
    else if (character1 == '[' && character2 == ']') return 1;
    else if (character1 == '{' && character2 == '}') return 1;
    else return 0;

}

/*
 *用于跟踪和验证括号是否匹配的接口
 * 首先检查是否平衡
 */
int isParenthesisBalanced(char *expression) {
    SqStack S;
    SElemType e;
    InitStack(&S);
    int i;
    for (i = 0; expression[i] != '\0'; i++) {
        //如果是左括号，入栈
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
            Push(&S, expression[i]);
            //如果是右括号，检查栈顶的左括号是否匹配
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {

            if (StackEmpty(S) || !isMatchingPair(*(Pop(&S, &e)), expression[i]))
                return 0; //如果栈为空或者括号不匹配，返回不平衡
        }


    }

    //如果栈不为空，说明有未匹配的左括号，返回不平衡
    return StackEmpty(S);

}

