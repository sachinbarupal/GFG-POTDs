//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int k, vector<int> &hand) {
        // code here
        sort(hand.begin(),hand.end());
        map<int,int> mp;
        
        for(int i=0;i<N;++i) mp[hand[i]]++;
        
        while(true)
        {
            int num = mp.begin()->first, firstFreq = mp.begin()->second,cnt =0;

            while(cnt<k)
            {
                if(mp[num]<firstFreq) return false;
                
                mp[num]-=firstFreq;
                cnt++;
                if(mp[num]==0) mp.erase(num);
                num++;
            }
            if(mp.size()==0) break;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
