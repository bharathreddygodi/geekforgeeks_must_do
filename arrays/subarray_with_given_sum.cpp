// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        int sum = 0;
        int front = 0;
        int back = 0;
        vector<int> ret;

        while (front < n)
        {
            if (sum < s)
            {
                if (back < n)
                {
                    sum += arr[back];
                    back++;
                }
                else
                {
                    break;
                }
            }
            else if (sum > s)
            {
                sum -= arr[front];
                front++;
            }
            else
            {
                ret.push_back(front + 1);
                ret.push_back(back);
                return ret;
            }
        }
        ret.push_back(-1);
        return ret;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends