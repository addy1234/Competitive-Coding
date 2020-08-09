#define lli long long int
vector<pair<int, int>> arr[100005];
int num[100005];
vector<lli> ans;

void dfs1(int node, int par){
    num[node] = 0;
    for(auto i : arr[node]){
        if(i.second != par){
            num[node] += dfs1(i.second, node);
        }
    }
    num[node]++;
    return num[node];
}

void dfs2(int node, int par){
    for(auto i : arr[node]){
        if(i.second != par){
            ans.push_back(num[i.second] * i.first);
            dfs(i.second, node);
        }
    }
    return;
}

int Solution::solve(int n, vector<vector<int> > &b, int c) {
    for(int i=0;i<n;i++){
        arr[b[i][0]].push_back({b[i][2], b[i][1]});
        arr[b[i][1]].push_back({b[i][2], b[i][0]});
    }

    dfs1(1, -1);
    dfs2(1, -1);
    sort(ans.begin(), ans.end());
    lli fin_ans = 0, cnt = 0;
    for(int i=ans.size()-1;i>=0;i--){
        if(cnt < c){
            continue;
            cnt++;
        }
        else{
            fin_ans += ans[i];   
        }
    }
    return (int)ans;
}
