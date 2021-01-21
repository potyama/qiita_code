#include <stdio.h>

char rpn(char pol_f[100]);

int c2i(char c);
char i2c(int i);

void push(char stack[100], int *sp, char c);
char pop(char stack[100], int *sp);


int main(void)
{
    char pol_f[100];
    char dmy;

    printf("Input Reverse Poland : ");
    scanf("%s%c", pol_f, &dmy);

    printf("Ans : %d\n", c2i(rpn(pol_f)));

    return 0;
}

char rpn(char pol_f[100])
{
    char stack[100];
    int sp = 0;
    int i;
    char first, second;

    for ( i = 0; pol_f[i] != '\0'; i++) {
        if ( '9' >= pol_f[i] && pol_f[i] >= '1' ) {
            push(stack,&sp,pol_f[i]);

        } else {
            if (pol_f[i] == '+') {
                second = pop(stack, &sp);
                first = pop(stack, &sp);
                push(stack, &sp, i2c(c2i(first) + c2i(second)));
            } else if  (pol_f[i] == '-') {
                second = pop(stack, &sp);
                first = pop(stack, &sp);
                push(stack, &sp, i2c(c2i(first) - c2i(second)));

            } else if  (pol_f[i] == '*') {
                second = pop(stack, &sp);
                first = pop(stack, &sp);
                push(stack, &sp, i2c(c2i(first) * c2i(second)));
            } else  if  (pol_f[i] == '/'){
                second = pop(stack, &sp);
                first = pop(stack, &sp);
                push(stack, &sp, i2c(c2i(first) / c2i(second)));

            }
        }
    }

    return pop(stack, &sp);
}

int c2i(char c){
    return c - '0';
}

char i2c(int i){
    return '0' + i;
}

void push(char stack[100], int *sp, char c){
    stack[(*sp)++] = c;
}

char pop(char stack[100], int *sp){
    return stack[--*sp];
}