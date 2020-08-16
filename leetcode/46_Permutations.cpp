class Solution {
public:
    int n;
    vector<vector<int>> all_permutations;
    void generate_all_permutations(int curr_index, vector<int> nums){
        if(curr_index == n){
            all_permutations.push_back(nums);
            return;
        }
        for(int i=curr_index; i<n; i++){
            // swap curr_index and ith position.
            int temp = nums[i];
            nums[i] = nums[curr_index];
            nums[curr_index] = temp;
            
            generate_all_permutations(curr_index + 1, nums);
            
            // swap back curr_index and ith position.
            temp = nums[i];
            nums[i] = nums[curr_index];
            nums[curr_index] = temp;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = (int)nums.size(); 
        generate_all_permutations(0, nums);
        return all_permutations;
    }
};
