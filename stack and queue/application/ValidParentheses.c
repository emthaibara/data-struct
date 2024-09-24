#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**
 * 括号匹配
 */
bool validParenthese(char* s){
    int length = strlen(s);
    int i = 0;
    char stack[length];
    int top = -1;
    while(i < length){
        char c = s[i++];
        //左括号压栈
        if(c == '(' || c == '[' || c == '{'){
            stack[++top] = c;
        //右括号出栈并比对
        }else if(c == ')'){
            //匹配失败或栈空
            if(top < 0 || stack[top--] != '(')return false;
        }else if(c == ']'){
            if(top < 0 || stack[top--] != '[')return false;
        }else if(c == '}'){
            if(top < 0 || stack[top--] != '{')return false;
        }
    }
    //匹配完之后栈空则为合法
    return top == -1;
}
int main(){
    printf("%d\n",validParenthese("(]"));
    printf("%d\n",validParenthese("()[]{}"));
    printf("%d\n",validParenthese("()"));
}