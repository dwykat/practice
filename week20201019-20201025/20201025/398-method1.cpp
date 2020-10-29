class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        bool is_first = true;
        int ret; // 返回值
        int idx = -1; // 索引
        int cnt = 1; // 等于target的个数

        for(auto val: nums){
            idx++;
            if(is_first){ // 先判断是否命中过
                if(val == target){
                    ret = idx;
                    is_first = false;
                }
                continue;
            }
            // 第二个及之后等于target的元素是否被选择的概率p=1/(cnt+1)
            if(val == target){
                if((rand()%(cnt+1) == cnt)){
                    ret = idx;
                }
                cnt++;
            }
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */