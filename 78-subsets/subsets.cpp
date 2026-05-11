class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        // Stores all subsets
        vector<vector<int>> result;

        // Current subset
        vector<int> path;

        // Recursive function
        function<void(int)> backtrack = [&](int index) {

            // Base case
            if(index == nums.size()) {
                result.push_back(path);
                return;
            }

            // INCLUDE current element
            path.push_back(nums[index]);

            // Explore
            backtrack(index + 1);

            // Undo choice
            path.pop_back();

            // EXCLUDE current element
            backtrack(index + 1);
        };

        // Start recursion
        backtrack(0);

        return result;
    }
};