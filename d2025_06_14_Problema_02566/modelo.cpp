class Solution {
public:
    int minMaxDifference(int num) {
        stack<int> p;
        int tmp = num;
        while (tmp != 0) {
            p.push (tmp % 10);
            tmp /= 10;
        }
        int maior = 0;
        while (!p.empty () && p.top () == 9) {
            maior = maior * 10 + 9;
            p.pop();
        }
        int subst = 0; // Define
        if (!p.empty ()) {
            subst = p.top ();
            p.pop ();
            maior = maior * 10 + 9;
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
        subst = p.top (); // Reaproveita
        p.pop ();
        while (!p.empty ()) {
            menor *= 10;
            tmp = p.top (); // Reaproveita
            p.pop ();
            if (tmp != subst) menor += tmp;
        }
        return maior - menor;
    }
};
