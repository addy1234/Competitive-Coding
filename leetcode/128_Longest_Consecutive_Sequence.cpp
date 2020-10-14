class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, pair<int,int>> mp;
        int n = (int)nums.size();
        
        for(int i=0;i<n;i++){
            mp[nums[i]] = {1, -1};
        }
        
        int maxlen = 0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]].second == -1){
                // cal function.
                int left = -1, right = -1;
                //left side.
                mp[nums[i]].second = 1;
                int j = nums[i] - 1;
                while(mp.find(j) != mp.end()){
                    mp[j].second = 1;
                    j--;
                }
                left = j + 1;
                // right side.
                j = nums[i];
                while(mp.find(j) != mp.end()){
                    mp[j].second = 1;
                    j++;
                }
                right = j - 1;
                maxlen = max(maxlen, right - left + 1);
            }
        }
        return maxlen;
    }
};