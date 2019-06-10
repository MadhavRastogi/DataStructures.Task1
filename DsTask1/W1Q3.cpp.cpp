#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Utility function to print the queue
void Print(queue<int>& Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

// Function to reverse the queue
void reverseQueue(queue<int>& Queue)
{
    stack<int> Stack;
    while (!Queue.empty()) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
}

// Driver code
int main()
{
    queue<int> Queue;
    int a;
    char y='y';
    cout<<"enter elements of queue"<<endl;
    while(y=='y')
    {
        cin>>a;
        Queue.push(a);
        cout<<"Do you want to continue y/n"<<endl;
        cin>>y;
    }
    reverseQueue(Queue);
    Print(Queue);
}
