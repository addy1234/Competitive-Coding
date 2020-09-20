class Solution {
public:
    string removeOuterParentheses(string S) {
        int count=0,start=0;
        int n = S.length();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            if(S[i] == '(')count++;
            else count--;
            if(count == 0){
                v.push_back(make_pair(start,i));
                start = i + 1;
            }
        }
        string ans="";
        for(auto i : v){
            int x = i.first;
            int y = i.second;
            for(int j=x+1;j<=y-1;j++){
                ans+=S[j];
            }
        }
        return ans;
    }
};