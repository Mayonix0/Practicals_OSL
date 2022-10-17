#include <stdio.h>
#include <string.h>

char stack[20];
int top = -1;

void push(char);
char pop();

int main()
{
    char str[20], ch;
    int i, len;

    printf("Enter any string: ");
    scanf("%s", str);

    len = strlen(str);

    for(i = 0; i < len; i++)
        push(str[i]);
    
    printf("The reversed string is: ");
    for(i = 0; i < len; i++)
    {
        ch = pop();
        printf("%c", ch);
    }
}

void push(char c)
{
    top++;
    stack[top] = c;
}
//Disease
char pop()
{
    char c;
    c = stack[top];
    top--;
    return c;
}