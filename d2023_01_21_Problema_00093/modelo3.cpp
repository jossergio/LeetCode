class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        set<string> respostas;
        function<bool (string)> correto = [] (string t) -> bool {
            return (t.size () == 1) || (t [0] != '0' && stoi (t) <= 255);
        };
        for (int p1 = 1; p1 <= 3 && p1 <= s.size (); p1 += 1) {
            string base1 = s.substr (0, p1);
            if (!correto (base1))
                break; // Já nem tenta mais
            for (int p2 = 1; p2 <= 3 && (p1 + p2) <= s.size (); p2 += 1) {
                string base2 = s.substr (p1, p2);
                if (!correto (base2))
                    break;
                for (int p3 = 1; p3 <= 3 && (p1 + p2 + p3) < s.size (); p3 += 1) {
                    string base3 = s.substr (p1 + p2, p3);
                    if (!correto (base3) || p1 + p2 + p3 >= s.size ())
                        break;
                    string base4 = s.substr (p1 + p2 + p3); // Até o final
                    if ((s.size () - (p1 + p2 + p3)) <= 3 && correto (base4))
                        respostas.insert (s.substr (0, p1) + "." + s.substr (p1, p2) + "." + s.substr (p1 + p2, p3) + "." + s.substr (p1 + p2 + p3));
                }
            }
        }
        return vector (respostas.begin (), respostas.end ());
    }
};

