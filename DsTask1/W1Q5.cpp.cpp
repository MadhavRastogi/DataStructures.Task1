#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;

    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push item into s1
        s1.push(x);

        // Push everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};

// Driver code
int main()
{
    Queue q;
    int a,ele;
    char y='y';
    while(y=='y')
    {
      cout<<"1.Push,2.Pop"<<endl;
      cin>>a;
      switch(a)
      {
          case 1:cout<<"enter element"<<endl;
                 cin>>ele;
                 q.enQueue(ele);
                 break;
          case 2:cout <<q.deQueue()<<endl;
                 break;
          default:cout<<"Invalid"<<endl;
      }
      cout<<"do you want to continue"<<endl;
      cin>>y;
    }
    return 0;
}
