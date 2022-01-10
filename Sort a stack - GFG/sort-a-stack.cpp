// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insertTheStack(stack<int>&s,int val)
{
    if(s.size()==0 or val>s.top())
    {
        s.push(val);
        return ;
    }
    int value=s.top();
    s.pop();
    insertTheStack(s,val);
    s.push(value);
}

void sortTheStack(stack<int> &s)
{
    if(s.size()==1)
     return ;
     
     int val=s.top();
     s.pop();
     sortTheStack(s);
     insertTheStack(s,val);
}

void SortedStack :: sort(){
    sortTheStack(s);
}

/*
void SortedStack :: sort()
{
    vector<int>ans;
    while(!s.empty())
    {
        int temp=s.top();
        s.pop();
        ans.push_back(temp);
    }
    
    for (int i=0; i<ans.size()-1; i++) {
  for (int j=0; j<ans.size()-1-i; j++)
    if (ans[j+1] < ans[j]) {  
       swap(ans[j+1],ans[j]);
  }
}
     for(int i=0;i<ans.size();i++)
      s.push(ans[i]);
}
*/