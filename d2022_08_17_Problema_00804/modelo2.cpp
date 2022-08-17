class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        map<char, string> tabela = {
            {'a', ".-"},
            {'b', "-..."},
            {'c', "-.-."},
            {'d', "-.."},
            {'e', "."},
            {'f', "..-."},
            {'g', "--."},
            {'h', "...."},
            {'i', ".."},
            {'j', ".---"},
            {'k', "-.-"},
            {'l', ".-.."},
            {'m', "--"},
            {'n', "-."},
            {'o', "---"},
            {'p', ".--."},
            {'q', "--.-"},
            {'r', ".-."},
            {'s', "..."},
            {'t', "-"},
            {'u', "..-"},
            {'v', "...-"},
            {'w', ".--"},
            {'x', "-..-"},
            {'y', "-.--"},
            {'z', "--.."}
        };
        
        set<string> codificadosUnicos;
        
        for (string palavra: words) {
            string tmp = "";
            for (char c: palavra)
                tmp += tabela [c];
            codificadosUnicos.insert (tmp);
        }
        
        return codificadosUnicos.size ();
    }
};

