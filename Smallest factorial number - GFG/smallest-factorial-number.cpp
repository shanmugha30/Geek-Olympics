//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int cntZero(int a){
            int i=1,cnt=0;
            while(a >= pow(5,i)){
                cnt+=(a/pow(5,i));
                i++;
            }
            return cnt;
        }
        
        int findNum(int n)
        {
          int low=0,high=n*5,ans=-1;
          int mid=(low+high)/2;
          
          while(low <= high){
              int zeros=cntZero(mid);
              if(zeros < n){
                  low=mid+1;
              }
              else{
                  ans=mid;
                  high=mid-1;
              }
              mid=(low+high)/2;
          }
          return ans;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends