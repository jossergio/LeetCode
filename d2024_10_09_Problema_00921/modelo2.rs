impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut fechados: i32 = 0;
        let mut abertos: i32 = 0;
        for c in s.chars () {
            if c == '(' {
                abertos += 1;
            } else {
                if abertos > 0 {
                    abertos -= 1;
                } else {
                    fechados += 1; 
                }
            }
        }
        abertos + fechados // O que sobrou precisa de um par
    }
}

