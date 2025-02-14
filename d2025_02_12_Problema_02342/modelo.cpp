class Solution {
    private:
        int soma_digitos (int n) {
            int r = 0;
            while (n > 0) {
                r += n % 10;
                n /= 10;
            }
            return r;
        }
    public:
        int maximumSum(vector<int>& nums) {
            map<int, vector<int>> tabela;
            int maximo = -1; // Padrão
            for (int n: nums) {
                int tmp = soma_digitos (n);
                tabela [tmp].push_back (n);
                push_heap (tabela [tmp].begin (), tabela [tmp].end ());
                if (tabela [tmp].size () > 1) {
                    if (tabela [tmp].size () == 2) maximo = max (maximo, tabela [tmp][0] + tabela [tmp][1]);
                    else maximo = max (maximo, tabela [tmp][0] + max (tabela [tmp][1], tabela [tmp][2]));
                }
            }
            return maximo;
        }
    };
    