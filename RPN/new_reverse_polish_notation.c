#include <stdio.h>

int rpn(char pol[]);
void push(int *sp, int stack[], int value);
int pop(int *sp, int stack[]);


int main(void)
{
    char pol[100];
    char dmy;

    printf("Input Reverse Poland : ");
    scanf("%s%c", pol, &dmy);

    printf("Ans : %d\n", rpn(pol));

    return 0;
}

int rpn(char pol[])
{
    int stack[100];
    int sp = 0;
    int i;
    int value = 0;
    int _1stValue;
    int _2ndValue;

    for ( i = 0; pol[i] != '\0'; i++) {
        if ( '1' <= pol[i] && pol[i] <= '9' ) {
            while(pol[i]!=','){
                value= (value * 10)+(pol[i]-'0');
                i++;
            }
            push(&sp,stack,value);
            value = 0;
        } else {
            if (pol[i] == '+') {
                _2ndValue = pop(&sp, stack);
                _1stValue = pop(&sp, stack);
                push(&sp, stack, _1stValue + _2ndValue);
            } else if  (pol[i] == '-') {
                _2ndValue = pop(&sp, stack);
                _1stValue = pop(&sp, stack);
                push(&sp, stack, _1stValue - _2ndValue);
            } else if  (pol[i] == '*') {
                _2ndValue = pop(&sp, stack);
                _1stValue = pop(&sp, stack);
                push(&sp, stack, _1stValue * _2ndValue);
            } else { // if  (pol[i] == '/')
                _2ndValue = pop(&sp, stack);
                _1stValue = pop(&sp, stack);
                push(&sp, stack, _1stValue / _2ndValue);
            }
        }
    }
    return pop(&sp, stack);
}

void push(int *sp, int stack[], int value){
    stack[(*sp)++] = value;
}

int pop(int *sp, int stack[]){
    return stack[--*sp];
}
