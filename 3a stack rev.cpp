/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
using namespace std;



void reversestack(stack<int> &st)
{
    //base case - when the stack gets empty we return.
    if(st.empty()==true)
    {
        return;
    }
    
    //at every recursive call we store the top elemtn in a variable seperately.
    int a = st.top();
    st.pop();
  
    //recursicely call until stack gets empty.
    reversestack(st);
    
    //onece its empty when we are returning we will put back the element storedd in the variable and hence the stack would be reversed.
    st.push(a);
}


//print the stack
void printStack(stack<int> &st)
{
     while(st.size()!=0)
    {
        cout << st.top();
        st.pop();
    }
}

 
int main()
{
    int n;
    cin >> n;

    //storing elements in a stack.
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        st.push(a);
    }
   
    printStack(st);//before reversing
    reversestack(st);
    printStack(st);//after reversing
   
}

