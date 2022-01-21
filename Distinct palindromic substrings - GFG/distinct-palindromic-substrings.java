// { Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*; 
class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0){
            String str = read.readLine().trim(); 
            Solution obj = new Solution();
            int ans = obj.palindromeSubStrs(str);
            System.out.println(ans);
        }
    }
}// } Driver Code Ends


//User function Template for Java

class Solution 
{ 
    int palindromeSubStrs(String str) { 
        // code here 
             int n=str.length();
             int count=0;
       boolean[][] isPalindrom=new boolean[n][n];
       HashSet<String> hs=new HashSet<>();
       for(int gap=0;gap<n;gap++){
           for(int si=0,ei=gap;ei<n;ei++,si++){
               if(gap==0)
               isPalindrom[si][ei]=true;
               else if(gap==1)
               isPalindrom[si][ei]=str.charAt(si)!=str.charAt(ei)?false:true;
               else
               isPalindrom[si][ei]=str.charAt(si)!=str.charAt(ei)?false:isPalindrom[si+1][ei-1];
               
               if(isPalindrom[si][ei]==true){
                   if(hs.contains(str.substring(si,ei+1))==false){
                       hs.add(str.substring(si,ei+1));
                       count++;
                   }
               }
           }
       }
       return count;
    }
} 