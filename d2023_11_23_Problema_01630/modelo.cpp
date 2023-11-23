class Solution {
private:
    bool checar (const vector<int>& nums, int l, int r) {
        const int t = r - l + 1;
        if (t < 2)
            return true; // Nem sei se haverá pegadinha
        vector<int> tmp (t);
        copy (nums.begin () + l, nums.begin () + r + 1, tmp.begin ());
        sort (tmp.begin (), tmp.end ());
        const int fator = tmp [1] - tmp [0];
        for (int i = 1; i < t; i += 1)
            if ((tmp [i] - tmp [i - 1]) != fator)
                return false; // Não é PA
        return true; // Passou por tudo
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        const int t = l.size ();
        vector<bool> resposta (t);
        for (int i = 0; i < t; i += 1)
            resposta [i] = checar (nums, l [i], r [i]);
        return resposta;
    }
};

