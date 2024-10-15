class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> aux;
        for (int n: nums) {
            aux.push (n);
        }
        long long resposta = 0;
        while (k > 0) {
            int tmp = aux.top ();
            aux.pop ();
            resposta += tmp;
            aux.push (ceil (tmp / 3.0));
            k -= 1;
        }
        return resposta;
    }
};

