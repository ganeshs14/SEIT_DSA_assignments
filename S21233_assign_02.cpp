#include <iostream>
#include <ctype.h>

using namespace std;

typedef struct node
{
    char data;
    struct node *next;
} node;
class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }
    int isempty()
    {
        if (top == NULL)
            return 1;
        return 0;
    }
    void push(char x)
    {
        node *p;
        p = new node();
        p->data = x;
        p->next = top;
        top = p;
    }
    char pop()
    {
        node *p;
        char x;
        p = top;
        x = p->data;
        top = top->next;
        delete (p);
        return x;
    }
    char topdata()
    {
        return top->data;
    }
};
void infix_postfix(char infix[20], char postfix[20]);
void reverse(char a[20], char b[20]);
void infix_prefix(char infix[20], char prefix[20]);
int evaluate(int op1, int op2, char op);
void evaluate_postfix(char postfix[20]);
int precedence(char x);
void evaluate_prefix(char prefix[20]);
void dash()
{
    for (int i; i < 50; i++)
    {
        printf("-");
    }
}
int main()
{
    char infix[20], token, postfix[20], prefix[20];
    int ch, result;

    do
    {
        dash();
        cout << "\n\t<--Apk's of STACK-->" << endl;
        dash();
        cout << "\n1.Infix to Postfix Expansion";
        cout << "\n2.Infix to Prefix Expansion";
        cout << "\n3.Evaluate Postfix";
        cout << "\n4.Evaluate Prefix";
        cout << "\n5.Exit";
        cout << "\nEnter your choice(1,2,3,4,5)-->";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter Infix Expression : ";
            cin >> infix;
            infix_postfix(infix, postfix);
            cout << "\nPostfix : " << postfix;
            cout << "\n";
            break;
        case 2:
            cout << "\nEnter Infix Expression : ";
            cin >> infix;
            infix_prefix(infix, prefix);
            cout << "\nPrefix Expression : " << prefix;
            cout << "\n";
            break;
        case 3:
            evaluate_postfix(postfix);
            break;
        case 4:
            evaluate_prefix(prefix);
            break;
        }
    } while (ch != 5);
    cout << "\tExit";
}

void infix_postfix(char infix[20], char postfix[20])
{
    stack s;
    int i, j = 0;
    char token, x;
    for (i = 0; infix[i] != '\0'; i++)
    {
        token = infix[i];
        if (isalnum(token))
        {
            postfix[j] = token;
            j++;
        }
        else
        {
            if (token == '(')
                s.push(token);
            else if (token == ')')
            {
                while ((x = s.pop()) != '(')
                {
                    postfix[j] = x;
                    j++;
                }
            }
            else
            {
                while (s.isempty() != 1 && precedence(token) <= precedence(s.topdata()))
                {
                    postfix[j] = s.pop();
                    j++;
                }
                s.push(token);
            }
        }
    }
    while (s.isempty() != 1)
    {
        postfix[j] = s.pop();
        j++;
    }
    postfix[j] = '\0';
}
void reverse(char a[20], char b[20])
{
    int i, j = 0;
    for (i = 0; a[i] != '\0'; i++)
    {
    }
    i--;
    for (j = 0; i >= 0; j++, i--)
    {
        if (a[i] == '(')
            b[j] = ')';
        else if (a[i] == ')')
            b[j] = '(';
        else
            b[j] = a[i];
    }
    b[j] = '\0';
}
void infix_prefix(char infix[20], char prefix[20])
{
    char prefix1[20], infix1[20];
    reverse(infix, infix1);
    infix_postfix(infix1, prefix1);
    reverse(prefix1, prefix);
}
int precedence(char x)
{
    if (x == '(')
        return 0;
    else if (x == '^')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 3;
    else
        return -1;
}

int evaluate(int op1, int op2, char op)
{
    if (op == '+')
        return op1 + op2;
    else if (op == '-')
        return op1 - op2;
    else if (op == '*')
        return op1 * op2;
    else if (op == '/')
        return op1 / op2;
    else if (op == '%')
        return op1 % op2;
    else
        return -1;
}

void evaluate_postfix(char postfix[20])
{
    stack s;
    int i, op1, op2, result;
    char token;
    int x;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        token = postfix[i];
        if (isalnum(token))
        {
            cout << "Enter the value :" << token;
            cout << " = ";
            cin >> x;
            s.push(char(x));
        }
        else
        {
            op2 = s.pop();
            op1 = s.pop();
            result = evaluate(op1, op2, token);
            s.push(char(result));
        }
    }
    result = s.pop();
    cout << "result :" << result;
    cout << "\n";
}
void evaluate_prefix(char prefix[20])
{
    stack s;
    int i, op1, op2, result;
    char token;
    int x;
    for (i = 0; prefix[i] != '\0'; i++)
    {
    }

    i--;

    for (; i >= 0; i--)
    {
        token = prefix[i];

        if (isalnum(token))
        {
            cout << "Enter the value :" << token;
            cout << " = ";
            cin >> x;
            s.push(char(x));
        }
        else
        {
            op1 = s.pop();
            op2 = s.pop();
            result = evaluate(op1, op2, token);
            s.push(char(result));
        }
    }
    result = s.pop();
    cout << "result :" << result;
    cout << "\n";
}

//S21233_GANESH SHELAR..