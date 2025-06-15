class Solution {
public:
    int maxDiff(int num) {
        stack<int> p;
        int tmp = num;
        while (tmp != 0) {
            p.push (tmp % 10);
            tmp /= 10;
        }
        int maior = 0;
        int subst = 0; // Define
        while (!p.empty ()) {
            tmp = p.top (); // Reaproveita
            p.pop ();
            maior = maior * 10 + 9;
            if (tmp != 9) {
                subst = tmp;
                break;
            }
        }
        while (!p.empty ()) {
            maior *= 10;
            tmp = p.top (); // Reaproveita
            p.pop ();
            if (tmp == subst)
                maior += 9;
            else
                maior += tmp;
        }
        while (num > 0) {
            p.push (num % 10);
            num /= 10;
        }
        int menor = 0;
        int asubst = p.top () == 1 ? 0 : 1; // Valor pelo qual será substituído; caso seja o segundo, será 0
        while (!p.empty ()) {
            tmp = p.top (); // Reaproveita
            p.pop ();
            if (tmp == 0) { // Não pode ser esse
                menor *= 10;
                continue;
            }
            menor = menor * 10 + 1;
            if (tmp != 1) {
                subst = tmp; // Reaproveita
                if (asubst == 0) menor -= 1; // Retira o que foi posto indevidamente
                break;
            }
        }
        while (!p.empty ()) {
            menor *= 10;
            tmp = p.top (); // Reaproveita
            p.pop ();
            if (tmp == subst)
                menor += asubst;
            else
                menor += tmp;
        }
        return maior - menor;
    }
};
