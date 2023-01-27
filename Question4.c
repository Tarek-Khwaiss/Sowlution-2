#include "stdalign.h"
#include "stdio.h"
#include "math.h"
#define SIZE 20
#define COUNT 6

#define N 20
#define Size 10

// dynamic change of the data
typedef char element;

typedef struct
{
    element data[N];
    int top;
} stack;

int isEmptyStack(stack p)
{
    return (p.top == -1);
}
int isFullStack(stack p)
{
    return (p.top == N - 1);
}

stack CreateStack()
{
    stack p;
    p.top = -1;
    return p;
}

int Push(stack *p, element e)
{
    if (isFullStack(*p))
        return 0;
    p->data[++p->top] = e;
    return 1;
}

int Pop(stack *p)
{
    if (isEmptyStack(*p))
        return 0;
    p->top--;
    return 1;
}

int Top(stack p, element *e)
{
    if (isEmptyStack(p))
        return 0;
    *e = p.data[p.top];
    return 1;
}

// problem 4
int palandromBrackets(char brackets[Size])
{

    // using a stack to check for occurences
    stack s = CreateStack();
    element e;

    int remaingSize = Size;

    for (int i = 0; i < Size; i++)
    {

        // first check if we have a top for the stack
        if (Top(s, &e))
        {
            if ((e == '(' && brackets[i] == ')') || (e == '{' && brackets[i] == '}') || (e == '[' && brackets[i] == ']'))
            {
                // 2 brackets facing each other so we pop them
                Pop(&s);
                remaingSize -= 2;
            }
            // brackets that are facing each other are different
            else if ((e == '(' && (brackets[i] == ']' || brackets[i] == '}')) || (e == '{' && (brackets[i] == ']' || brackets[i] == ')')) || (e == '[' && (brackets[i] == '}' || brackets[i] == ')')))
            {
                return 0;
            }
            else
            {
                Push(&s, brackets[i]);
            }
            // here we don't have anything in the stack so we push the first element probably
        }
        else
        {
            Push(&s, brackets[i]);
        }
    }

    stack mirror = CreateStack();

    for (int i = 0; i < remaingSize / 2; i++)
    {
        Top(s, &e);
        Pop(&s);
        Push(&mirror, e);
    }

    // checking if the brackets are valid
    element e1, e2;
    for (int i = 0; i < remaingSize / 2; i++)
    {
        if (Top(s, &e1) && Top(mirror, &e2))
        {
            if ((e1 == '(' && e2 == ')') || (e1 == '[' && e2 == ']') || (e1 == '{' && e2 == '}'))
            {
                Pop(&s);
                Pop(&mirror);
            }
            // non matching
            else
            {
                return 0;
            }
        }

        // if the program passed all the checks
        return 1;
    }
}
