class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty()) return res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, temp, res);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int start, vector<int>& temp, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(candidates[i] > target) break;
            if(i > start && candidates[i] == candidates[i - 1]) continue;
            temp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, temp, res);
            temp.pop_back();
        }
    }
};