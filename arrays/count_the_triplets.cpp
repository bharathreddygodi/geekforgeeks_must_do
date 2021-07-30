// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	int countTriplet(int arr[], int n)
	{
	    int sum = 0;
	    int count = 0;
	    sort(arr, arr + n);
        // Use two pointer method for the index i on i-1 to 0
        for(int i = 0; i < n; i++)
        {
    	   int j = i+1;
    	   int k = j+1;
            for(j; j < n; j++)
            {
                for (k; k < n; k++){
                    sum = (arr[i] + arr[j]);
                  if (arr[k] == sum)count++;
                  else if(arr[k] > sum)break;
                }
            }
        }
        return count;
	}
};

/**** Alternate code using while loop *****/
/**
	int countTriplet(int arr[], int n)
	{
	   sort(arr, arr + n);
	   int j, k, c = 0;
	   for (int i = 0; i < n; i++)
	   {
	       j = i+1;
	       k = j+1;
	       while(k<n)
	       {
	           //printf("i %d j %d k %d\n", arr[i], arr[j], arr[k]);
	           if ((arr[j]+ arr[i]) == arr[k])
	           {
	               c++;
	               j++;
	           }
	           else if((arr[j]+ arr[i]) < arr[k])
	           {
	               j++;
	               k--;
	           }
	           k++;
	       }
	   }
	   return c;
	}
 **/


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends