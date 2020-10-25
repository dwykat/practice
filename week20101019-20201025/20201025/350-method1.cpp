class Solution {
public:

    void sort(vector<int>& vec, int left, int right){
        if(left < right){
            int pivot = vec[left];
            int low=left, high=right;
            while(low < high){
                while(vec[high]>=pivot && low<high){
                    high--;
                }
                vec[low] = vec[high];
                while(vec[low]<=pivot && low<high){
                    low++;
                }
                vec[high] = vec[low];
            }
            vec[low] = pivot;
            sort(vec, left, low-1);
            sort(vec, low+1, right);
        }

    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if(nums1.empty() || nums2.empty())
            return ret;
        
        int length1 = nums1.size();
        int length2 = nums2.size();

        sort(nums1, 0, length1-1);
        sort(nums2, 0, length2-1);
        
        if(nums1[length1-1]<nums2[0] || nums1[0]>nums2[length2-1])
            return ret;
        int i=0, j=0;
        while(i<length1 && j<length2){
            if(nums1[i] == nums2[j]){
                // 相等则交集+1
                ret.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i] < nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        return ret;
    }
};
