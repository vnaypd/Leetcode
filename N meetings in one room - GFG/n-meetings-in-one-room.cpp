//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] < v2[1];
    }

    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
    
        vector<vector<int>> meetings;
        
        for(int i=0; i<n; i++){
            vector<int> temp;
            temp.push_back(start[i]);
            temp.push_back(end[i]);
            meetings.push_back(temp);
        }
        
        sort(meetings.begin(), meetings.end(), sortcol);
        int count = 0;
        int ending = meetings[0][1];
        count++;
        
        for(int i=1; i<n; i++){
            if(meetings[i][0] > ending){
                count++;
                ending = meetings[i][1];
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends