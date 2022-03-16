class Solution {
public:
/*
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int size=pushed.size();
        int ptr1=0,ptr2=0;
        stack<int>st;
        while(ptr1<size && ptr2<size)
        {
             st.push(pushed[ptr1]);
             ptr1++;
            while(!st.empty() && popped[ptr2]==st.top()) 
            {
                st.pop();
                ptr2++;
            }
        }
        return st.empty();
    }*/
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int ptr1=0,ptr2= 0;
		for (auto val : pushed)
		{
			pushed[ptr1++] = val;
			while (ptr1 > 0 && pushed[ptr1 - 1] == popped[ptr2])
			{
				ptr1--;
				ptr2++;
			}
		}
		return ptr1 == 0;
	}
};


		