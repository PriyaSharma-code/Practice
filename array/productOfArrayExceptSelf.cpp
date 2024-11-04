//238. Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    vector<int> left_products(n, 1);
    vector<int> right_products(n, 1);
    vector<int> result(n);

    // Fill left_products
    for (int i = 1; i < n; ++i) {
        left_products[i] = left_products[i - 1] * nums[i - 1];
    }

    // Fill right_products
    for (int i = n - 2; i >= 0; --i) {
        right_products[i] = right_products[i + 1] * nums[i + 1];
    }

    // Calculate result
    for (int i = 0; i < n; ++i) {
        result[i] = left_products[i] * right_products[i];
    }

    return result;
    }
};