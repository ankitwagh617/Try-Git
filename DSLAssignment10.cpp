#include <iostream>
#include <string.h>
using namespace std;
#define MAX 50
class Stack
{
    int data[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(char e)
    {
        if (!full())
        {
            top++;
            data[top] = e;
        }
        else
        {
            cout << "\nStack is Full\n";
        }
    }
    int full()
    {
        if (top == MAX - 1)
        {
            return 1;
        }
        return 0;
    }
    int pop()
    {
        if (!empty())
        {
            int x;
            x = data[top];
            data[top] = 0;
            top--;
            return x;
        }
        else
        {
            cout << "\nStack is Empty.\n";
            return 0;
        }
    }
    int empty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }
    int priority(char op)
    {
        int ans;
        if (op == '*' || op == '/')
        {
            ans = 2;
        }
        else if (op == '+' || op == '-')
        {
            ans = 1;
        }
        return ans;
    }
};
void convert(char inf[50], char postf[50])
{
    Stack st;
    char ch, expr;
    int i = 0, j = 0;
    while (inf[i] != '\0')
    {
        expr = inf[i];
        if (expr == '/' || expr == '*' || expr == '+' || expr == '-')
        {
            if (st.empty())
            {
                st.push(expr);
            }
            else
            {
                while (!st.empty())
                {
                    ch = st.pop();
                    if (st.priority(ch) >= st.priority(expr)) 
                    {
                        postf[j] = ch;
                        j++;
                    }
                    else
                    {
                        st.push(ch);
                        break;
                    }
                }
                st.push(expr);
            }
        }
        else
        {
            postf[j] = expr;
            j++;
        }
        i++;
    }
    while (!st.empty())
    {
        postf[j] = st.pop();
        j++;
    }
    postf[j] = '\0';
}
int main()
{
    char infix[50], postfix[50];
    cout << "Enter the Infix expression : ";
    cin.getline(infix, 28);
    convert(infix, postfix);
    cout << "Postfix= " << postfix;
    return 0;
}