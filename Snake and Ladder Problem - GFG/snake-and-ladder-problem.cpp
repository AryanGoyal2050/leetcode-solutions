//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        
        map <int, int> snake;
        map <int, int> ladder;
        
        for(int i=0; i<N; i++)
        {
            if(arr[2*i] > arr[2*i+1])
            {
                //ladder
                ladder[arr[2*i]] = arr[2*i+1];
            }
            else
            {
                //snake
                snake[arr[2*i]] = arr[2*i+1];
            }
        }
        
        queue <pair <int, int>> q;  //<pos, moves>
        q.push({1, 0});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int mov = it.second;
            
            if(x == 30) return mov;
            
            for(int i=1; i<=6; i++)
            {
                int newx = x+i;
                if(newx > 30) continue;
                if(snake[newx]) q.push({snake[newx], mov+1});
                else if(ladder[newx]) q.push({ladder[newx], mov+1});
                else q.push({newx, mov+1});
            }
            
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends