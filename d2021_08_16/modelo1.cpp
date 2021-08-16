class NumArray {
private:
    vector<int> vetor;
public:
    NumArray(vector<int>& nums) {
        vetor = nums;
    }
    
    int sumRange(int left, int right) {
        int soma = 0;
        while (left <= right)
            soma += vetor [left++];
        return soma;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

