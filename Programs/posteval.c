/* evaluation of postfix expression
considering a single digit values
isdigit : It returns: Non-zero (true)
if the character is 0–9
0 (false) otherwise
push(ch-'0') :
ascii -> 0 - 48 , 1-49,2-50...9-57
eg : push('5'-'0') --> 53-48 =5
will get same value as int */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 15
int stack[MAX];
int top = -1;
void push(int item)
{
    if (top >= MAX - 1)
         printf("\nStack Overflow.");
     else
        stack[++top] = item;
}
int pop()
{
    if (top < 0)
        {
 printf("Stack Underflow."); exit(1);
        }
    else
        return stack[top--];
}
int evaluatePostfix(char* postfix) {
    int i, op1, op2, result;
    char ch;
    for (i = 0; postfix[i] != '\0'; i++)
        {
        ch = postfix[i];
        if (isdigit(ch))
             push(ch - '0');
         else {
   op2 = pop(); op1 = pop();
   switch (ch) {
   case '+': result = op1 + op2; break;
   case '-': result = op1 - op2; break;
   case '*': result = op1 * op2; break;
   case '/': result = op1 / op2; break;
    default:
        printf("Invalid operator encountered.");
                    exit(1);
            }
            push(result);
        }
    }
    return pop();
}
int main() {
    char postfix[MAX];
    int result;
    printf("Enter Postfix Expression: ");
    scanf("%[^\n]s",postfix);
    result = evaluatePostfix(postfix);
printf("The result of the Postfix expression is:%d\n", result);
    return 0;
}
// 36+24-*7+
//(((3+6)*(2-4))+7)