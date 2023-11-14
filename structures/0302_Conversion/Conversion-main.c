/********************************************************************************
* @author: mason shi
* @date: 2023/11/13 22:12
* @version: 1.0
* @description: 
********************************************************************************/
#include "stdio.h"
#include "Conversion.h"

#define LEN 100

int main(int argc, char **argv) {
    int i = 342391;

    printf("将十进制数转换为八进制数...\n");

    Conversion(i);

    char expression[100];

    //从用户输入获取表达式
    printf("输入表达式： ");
    fgets(expression, LEN, stdin);

    //检查括号是否平衡
    if (isParenthesisBalanced(expression)) printf("括号是平衡的\n");
    else printf("括号不平衡\n");


    return 0;
}
