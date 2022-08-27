class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int max1=INT_MIN;
        for(int i=0;i<m;i++){
            vector<int> val(n);          
            for(int j=i;j<m;j++){             
                for(int k1=0;k1<n;k1++){
				      		val[k1]+=matrix[k1][j];        
                }
                set<int>st;    
                st.insert(0);
                int ans=0;
                for(int k1=0;k1<n;k1++){
                    ans+=val[k1];
                    auto it = st.lower_bound(ans-k);           
                    if(it!=st.end()){
                        max1=max(max1,ans-*it);          
                    }
                    st.insert(ans);        
                }
            }
        }
        return max1;
    }
};