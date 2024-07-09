impl Solution {
    pub fn pass_the_pillow(n: i32, time: i32) -> i32 {
        let mut p: i32 = 1; // Posição do travesseiro
        let mut time: i32 = time; // Para "sombrear"
        while time > 0 {
            if p == 1 {
                p = if time >= n - 1 { n } else { time + 1 } ;
                time -= n - 1; // Não conta o 1o
            }
            if p == n { // Já testa no mesmo laço
                p = if time >= n - 1 { 1 } else { n - time };
                time -= n - 1;
            }
        }
        return p
    }
}

