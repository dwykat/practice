class Solution {
public:
    bool is_less_or_equal(string s1, string s2){
        if(s1+s2 <= s2+s1)
            return true;
        return false;
    }

    void sort_str(vector<string>& s, int left, int right){
        if(left < right){
            int low = left, high = right;
            string pivot = s[low];
            while(low < high){
                while(is_less_or_equal(pivot, s[high]) && low < high)
                    high--;
                s[low] = s[high];
                while(is_less_or_equal(s[low], pivot) && low < high)
                    low++;
                s[high] = s[low];
            }
            s[low] = pivot;
            sort_str(s, left, low-1);
            sort_str(s, low+1, right);
        }
    }

    string minNumber(vector<int>& nums) {
        // 数字基本上按字符串升序排序
        // 特殊情况就是字符串有重合的时候
        // 如: 3和35, 3和30前者 3<35, 后者3>30
        // x+y > y+x => x > y
        vector<string> nums_str;
        for(auto num: nums){
            nums_str.push_back(to_string(num));
        }

        // 排序
        sort_str(nums_str, 0, nums_str.size()-1);
        string ret = "";
        for(auto num_str: nums_str){
            ret += num_str;
        }
        return ret;
    }
};