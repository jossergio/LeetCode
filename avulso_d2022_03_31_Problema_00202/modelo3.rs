use std::collections::HashSet;
impl Solution {
    pub fn is_happy(n: i32) -> bool {
        if n == 0 {
            return false; // LeetCode
        }
        let mut n = n; // Sombreia
        let mut passagens: HashSet<i32> = HashSet::new ();
        passagens.insert (0);
        while n != 1 {
            let mut interno = n;
            n = 0; // Inicia o preparo para o próximo ciclo
            while interno != 0 {
                let v = interno % 10;
                n += v * v;
                interno /= 10;
            }
            if passagens.contains (&n) {
                return false; // Iria entrar em um laço e não chegaria a 1
            }
            // else
            passagens.insert (n);
        }
        true // Se conseguiu chegar a 1, encontrou
    }
}
