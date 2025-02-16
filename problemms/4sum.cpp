class Solution {
public:
    void solve(vector<int> &nums,vector<vector<int>> &ans,int target){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        for(i;i<n-3;i++){
            int j=i+1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(j;j<n-2;j++){
                if( j>1 && nums[j]==nums[j-1] ){
                continue;
            }
            int sum1=nums[i]+nums[j];
            int k=j+1;
            int l=n-1;
            while(k<l){
                int sum2=nums[k]+nums[l];
                if(sum1+sum2==target){
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                }
                else if(sum1+sum2>target){
                    l--;
                }
                else{
                    k++;
                }
                while(l>k && nums[k]==nums[k+1]) k++;
                while(l>k && nums[l]==nums[l-1]) l--;

            }
        }
    }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        solve(nums,ans,target);
        return ans;
    }

};