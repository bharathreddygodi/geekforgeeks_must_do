// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string ret;
        string word;
        int size = (int)S.length();
        int i = size - 1;

        while(i >= 0)
        {
            if(S[i] == '.')
            {
                ret+=word;
                ret += ".";
                word = "";
            }
            else
            {
                word = (S[i]) + word;
            }
            i--;
        }
        ret = ret + word + S[size];
        return ret;
    }
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends