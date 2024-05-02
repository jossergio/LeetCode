use std::collections::HashMap;
impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut pilha: Vec<char> = Vec::new ();
        let mapa: HashMap <char, char> = HashMap::from ([
            ('}', '{'),
            (']', '['),
            (')', '(')
        ]);
        for c in s.chars () {
            if c == '{' || c == '[' || c == '(' {
                pilha.push (c);
            } else { // Só podem ser os fechamentos
                if pilha.len () > 0 && pilha [pilha.len () - 1] == mapa [&c] {
                    pilha.pop ();
                } else {
                    return false
                };
            }
        }
        return pilha.len () == 0
    }
}

