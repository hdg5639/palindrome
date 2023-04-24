#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE_STACK 100

typedef char element;
typedef struct {
    element stack[MAX_SIZE_STACK];
    int top;
} StackType;

void init(StackType* s) {
    s->top = -1;
}

char is_empty(StackType* s) {
    return s->top == -1;
}

char is_full(StackType* s) {
    return s->top == MAX_SIZE_STACK - 1;
}

void push(StackType* s, element item) {
    if (is_full(s))
        exit(1);
    s->stack[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_empty(s))
        exit(1);
    return s->stack[(s->top)--];
}

element peek(StackType* s) {
    if (is_empty(s))
        exit(1);
    return s->stack[s->top];
}

char checking(char* exp) {
    int i = 0;
    StackType s;
    init(&s);
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) {
            push(&s, toupper(exp[i]));
        }
    }
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) {
            if (toupper(exp[i]) != peek(&s)) {
                return 0;
            }
            pop(&s);
        }
    }
    return 1;
}

int main() {
    char tmp;
    for (;;) {
        char palindrome[MAX_SIZE_STACK];
        printf("문자열을 입력하시오: ");
        scanf_s(" %[^\n]", palindrome, MAX_SIZE_STACK);
        char result = checking(palindrome);
        if (result == 1) {
            printf("회문입니다.\n");
        }
        else {
            printf("회문이 아닙니다.\n");
        }
        printf("\n계속 입력하시겠습니까?(Y/N): ");
        scanf_s(" %c", &tmp, 1);
        if (tmp == 'N')
            break;
        printf("\n");
    }

    return 0;
}