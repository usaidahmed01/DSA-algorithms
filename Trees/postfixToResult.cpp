#include <bits/stdc++.h>
using namespace std;

struct dstack
{
    int data;
    dstack *next;
};
dstack *top = nullptr;

void push(int value)
{ 
    dstack *userptr = (dstack *)malloc(sizeof(dstack));
    userptr->data = value;
    userptr->next = top;
    top = userptr;
    cout<<"Value has pushed."<<userptr->data<<endl;
}

int pop()
{
    if (top == nullptr)
    {
        return 0;
    }
    else
    {
        int value = top->data;
        dstack *temp = top;
        top = top->next;

        free(temp);

        cout<<"Value has popped. "<<endl;

        return value;
    }
}

int postExpResult(string exp){
    for (int i = 0; i < exp.length(); i++)
    {
        if(exp[i] != '+' && exp[i] != '-' &&  exp[i] != '*' && exp[i] != '/'){
            exp[i] -= 48;
            push(exp[i]);
        }else{
            int num2 = pop();
            int num1 = pop();
            if(exp[i] == '+'){
                int result = num1 + num2;
                push(result);
            }
            
            else if(exp[i] == '-'){
                int result = num1 - num2;
                push(result);
            }

            else if(exp[i] == '*'){
                int result = num1 * num2;
                cout<<result<<endl;
                push(result);
            }

        }
    }
    return pop();
    
}


main()
{
    cout<<"Enter Post Expression "<<endl;
    string exp;
    cin>>exp;

    cout<<"Result: "<< postExpResult(exp)<<endl;
}