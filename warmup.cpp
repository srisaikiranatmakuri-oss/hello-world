#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numIndex;  // stores value -> index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numIndex.find(complement) != numIndex.end()) {
            // found the solution
            return {numIndex[complement], i};
        }
        numIndex[nums[i]] = i;
    }
    return {};  // just in case (though problem says one solution exists)
}

int main() {
    // Example 1
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}