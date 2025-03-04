impl Solution {
    pub fn check_powers_of_three(n: i32) -> bool {
        let mut multiplos: Vec<i32> = vec![1]; // Já põe o primeiro
        for _ in 1..=16 { // Dica da plataforma; a potência máxima que será utilizada
            multiplos.push (*multiplos.last ().unwrap_or (&1) * 3);
        }
        multiplos.reverse ();
        let mut n = n; // Torna mutável
        for v in multiplos {
            if v <= n {
                n -= v;
                if n == 0 {
                    return true;
                }
            }
        }
        false
    }
}
