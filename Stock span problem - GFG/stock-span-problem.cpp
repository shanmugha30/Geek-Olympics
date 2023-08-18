//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> ans;
       stack<pair<int,int>> st;
       ans.push_back(1);
       
       for(int i=0; i < n ;i++){
           
           if(!st.empty()){
               while(!st.empty()){
                   if(st.top().first > price[i]){
                       ans.push_back(i-st.top().second);
                       break;
                   }
                   else{
                   st.pop();
                   }
                }
                if(st.empty()){
                    ans.push_back(i+1);
                }
            }
           st.push({price[i],i});
       }
       return ans;
    }
};




// } Driver Code Ends

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends