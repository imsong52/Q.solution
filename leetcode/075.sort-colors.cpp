/*
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors
 *
 * Medium (37.01%)
 * Total Accepted:    144545
 * Total Submissions: 390559
 * Testcase Example:  '[0]'
 *
 * 
 * Given an array with n objects colored red, white or blue, sort them so that
 * objects of the same color are adjacent, with the colors in the order red,
 * white and blue.
 * 
 * 
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * 
 * 
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 * 
 * 
 * click to show follow up.
 * 
 * 
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with an one-pass algorithm using only constant space?
 * 
 * 
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = -1, j = n-1, k = 0;

        while (k <= j) {
            switch(nums[k]) {
                case 0: ++i; swap(nums[i], nums[k]); ++k; break;
                case 1: ++k; break;
                case 2: swap(nums[j], nums[k]); --j; break;
            }
        }
    }
};
