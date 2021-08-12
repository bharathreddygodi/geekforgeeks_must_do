// { Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.

    void rearrange(long long *arr, int n) 
    { 
        int max = n-1;
        int min = 0;
        int c = arr[max]+1;
        if (n < 2)
        {
            return;
        }
        // formula if (d = a+ b*c) then d/c is b and d%c is a
        // c = a[max] + 1
        // Even = (a[i] + (a[max]%c)*c)
        // ODD = (a[i] + (a[min]%c)*c)
    	// Now start swapping
    	for (int i = 0; i < n; i++)
    	{
    	    if ((i % 2) == 1)   // Odd
    	    {
        	    arr[i] = arr[i] + (arr[min]%c)*c;
        	    min++;
    	    }
    	    else    // even
    	    {
                arr[i] = arr[i] + (arr[max]%c)*c;
                max--;
    	    }
    	}
    	for(int i = 0; i < n; i++)
    	{
    	    arr[i] /= c;
    	}
    }
};

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends