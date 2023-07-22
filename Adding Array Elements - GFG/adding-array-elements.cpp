//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        
        int cnt=0,flag=0;
        priority_queue<int> pq;
        for(int i=0; i < n; i++){
            pq.push(-arr[i]);
        }
        
        while(!pq.empty()){
            if(abs(pq.top()) >= k){
                flag=1;
                break;
            }
            cnt++;
            int first=abs(pq.top()); pq.pop();
            if(pq.empty()){
                break;
            }
            int second=abs(pq.top()); pq.pop();
            pq.push(-(first+second));
        }
        
        if(flag){
            return cnt;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends