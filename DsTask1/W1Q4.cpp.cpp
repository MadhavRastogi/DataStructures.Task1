#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function to check if given queue element
// can be sorted into another queue using a
// stack.
bool checkSorted(int n, queue<int>& q)
{
    stack<int> st;
    int expected = 1;
    int fnt;

    // while given Queue is not empty.
    while (!q.empty()) {
        fnt = q.front();
        q.pop();

        // if front element is the expected element
        if (fnt == expected)
            expected++;

        else {
            // if stack is empty, push the element
            if (st.empty()) {
                st.push(fnt);
            }

            // if top element is less than element which
            // need to be pushed, then return fasle.
            else if (!st.empty() && st.top() < fnt) {
                return false;
            }

            // else push into the stack.
            else
                st.push(fnt);
        }

        // while expected element are coming from
        // stack, pop them out.
        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }

    // if the final expected element value is equal
    // to initial Queue size and the stack is empty.
    if (expected - 1 == n && st.empty())
        return true;

    return false;
}

// Driven Program
int main()
{
    queue<int> q;
    int ele,i,n;
    cout<<"enter queue size"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"enter element"<<endl;
        cin>>ele;
        q.push(ele);
    }
    (checkSorted(n, q) ? (cout << "Yes") :
                         (cout << "No"));

    return 0;
}
