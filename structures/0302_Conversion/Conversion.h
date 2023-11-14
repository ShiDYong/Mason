/********************************************************************************
* @author: mason shi
* @date: 2023/11/13 22:07
* @version: 1.0
* @description: 进制的转换
********************************************************************************/
#ifndef CONVERSION_H
#define CONVERSION_H

#include<stdio.h>
#include "SqStack.h"


void Conversion(int i);

/*
 *用于跟踪和验证括号是否匹配的接口
 */
int isParenthesisBalanced(char *expression);

#endif