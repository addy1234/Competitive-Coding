int tree[500005];
string str;
int n;

void buildTree(int l, int r, int index){
    if(l == r){
        if(str[l] == '0')tree[index] = 1;
        else tree[index] = 0;
        return;
    }    
    int mid = (l+r)/2;
    buildTree(l, mid, 2*index);
    buildTree(mid+1, r, 2*index + 1);
    tree[index] = tree[2*index] + tree[2*index + 1];
    return;
}


int query(int l, int r, int ql ,int qr, int index){
    if(ql > r || qr < l){
        return 0;
    }
    
    if(l >= ql && r <= qr){
        return tree[index];
    }
    
    int mid = (l+r)/2;
    int left = query(l, mid, ql, qr, 2*index);
    int right = query(mid+1, r, ql, qr, 2*index+1);
    return left + right;
}

vector<int> Solution::solve(string A, vector<vector<int> > &B) {
    str = A;
    n = str.length();
    int left[n], right[n];
    
    // calculate for right.
    if(str[n-1] == '1'){
        right[n-1] = n-1;
    }else{
        right[n-1] = -1;
    }
    for(int i=n-2;i>=0;i--){
        if(str[i] == '1'){
            right[i] = i;
        }else{
            right[i] = right[i+1];
        }
    }
    
    // calculate for left.
    if(str[0] == '1'){
        left[0] = 0;
    }else{
        left[0] = -1;
    }
    for(int i=1;i<n;i++){
        if(str[i] == '1'){
            left[i] = i;
        }else{
            left[i] = left[i-1];
        }
    }
    
    buildTree(0, n-1, 1);
    
    vector<int> ans;
    int q = B.size();
    for(int i=0;i<q;i++){
        int l = B[i][0];
        int r = B[i][1];
        l--;
        r--;
        int rightl = right[l];
        int leftr  = left[r];
        //cout<<l<<" "<<r<<" "<<rightl<<" "<<leftr<<", ";
        if(leftr != -1 && rightl != -1 && leftr >= rightl){
            int v = query(0, n-1, rightl, leftr, 1);
            ans.push_back(v);
        }else{
            ans.push_back(0);
        }
    }
    return ans;
}
