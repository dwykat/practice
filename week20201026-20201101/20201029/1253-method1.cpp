class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size(); // 列个数
        vector<vector<int>> ans(2, vector<int>(n));

        int sum = 0;
        for(auto& elem: colsum)
            sum += elem;
        // upper+lower不等于sum,不可构造
        if(sum != upper+lower)
            return {};
        
        for(int i=0; i<n; i++){
            // 如果当前列和为2, 上下2行必为1
            if(colsum[i] == 2){
                if(upper>=1 && lower>=1){
                    ans[0][i] = 1;
                    ans[1][i] = 1;
                    upper--;
                    lower--;
                }else{
                    return {};
                }

            }else if(colsum[i] == 1){ // 优先取1多的行取1,防止后面1不够
                if(upper >= lower && upper > 0){
                    ans[0][i] = 1;
                    upper--;
                }else if(lower > upper && lower > 0){
                    ans[1][i] = 1;
                    lower--;
                }else{
                    return {};
                }
            }// colsum[i] == 0, 上下2行都为0,我们的初始化满足
        }
        return ans;

    }
};