//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        
       long long int cntPairs=0,sum=0;
       unordered_map<int,vector<int>> mp;
       
       for(int i=0; i < arr.size(); i++){
           sum+=arr[i];
           
           if(sum == 0){
               cntPairs++;
           }
           if(mp.find(sum) != mp.end()){
               vector<int> vc=mp[sum];
               for(auto it:vc){
                   cntPairs++;
               }
           }
           mp[sum].push_back(i);
       }
       
       return cntPairs;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends