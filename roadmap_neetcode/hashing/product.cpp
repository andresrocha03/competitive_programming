// Problem: we have an array nums of integers. We need to output another array in which
// the i-th element is the product of all elements of nums, except the nums[i]
// Solution: compute the prefix and suffix product, then it is enough for i-th element to compute
// i-1-th prefix product times i+1-th sufix product.

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> prefix_product;
            vector<int> suffix_product;
            vector<int> output;
            int product = 1;


            for (int i=0; i<nums.size(); i++) {
                product *= nums[i];
                prefix_product.push_back(product);
            }
            
            product = 1;
            for (int i=nums.size()-1; i>=0; i--) {
                product *= nums[i];
                suffix_product.push_back(product);
            }

            reverse(suffix_product.begin(),suffix_product.end());

            for (int i=0; i<nums.size(); i++ ) {
                int p1, p2;
            
                p1 = (i-1 >=0) ? prefix_product[i-1] : 1; 
                p2 = (i + 1 < nums.size()) ? suffix_product[i+1] : 1; 
                
                output.push_back(p1*p2);     
            }

            return output;
        }
};