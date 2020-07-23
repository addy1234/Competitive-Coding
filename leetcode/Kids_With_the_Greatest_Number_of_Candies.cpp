class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int x) {
        int n = (int)v.size();
        vector<bool> ans;
        for(int i=0;i<n;i++){
            int p = v[i] + x;
            bool flag = 0;
            for(int j=0;j<n;j++){
                if(j == i)continue;
                else{
                    if(v[j] > p){
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag)ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};
