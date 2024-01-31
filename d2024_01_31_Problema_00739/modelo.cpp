class Solution {
int buscar (vector<int>& t, vector<int>& m, int v, int i) {
    if (m [i] == -1)
        return -1;
    // else
    if (t [m [i]] > v)
        return m [i];
    // else
    return buscar (t, m, v, m [i]);
}
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int t = temperatures.size ();
        vector<int> maiores (t, -1); // -1 = não tem maiores; o último é a certeza e irá ajustar durante o código
        for (int i = t -2; i >= 0; i -= 1) { // Começa do penúltimo
            if (temperatures [i] < temperatures [i + 1]) {
                maiores [i] = i + 1; // O próximo maior
            } else { // É maior ou igual e irá buscar o maior
                maiores [i] = buscar (temperatures, maiores, temperatures [i], i + 1); // Começa a busca pelo seguinte
            }
        }
        vector<int> resposta (t, 0);
        for (int i = 0; i < t; i += 1) {
            resposta [i] = maiores [i] == -1 ? 0 : maiores [i] - i;
        }
        return resposta;
    }
};

