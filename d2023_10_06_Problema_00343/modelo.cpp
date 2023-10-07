class Solution {
public:
    int integerBreak(int n) {
        unordered_map<int, int> memo;
        
        function<int (int)> buscar = [&] (int i) -> int {
            if (i <= 1)
                return memo [i] = 1;
            if (memo.count (i) == 0) {
                memo [i] = i - 1; // * 1
                for (int j = 2; j < i; j += 1) {
                    memo [i] = max (memo [i], (i - j) * j); // Optei por duas linhas, por melhor visualização
                    memo [i] = max (memo [i], (i - j) * buscar (j));
                }
            }
            return memo [i];
        }; // buscar
        
        return buscar (n);
    }
};

