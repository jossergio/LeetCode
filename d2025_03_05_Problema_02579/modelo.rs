impl Solution {
    pub fn colored_cells(n: i32) -> i64 {
        let mut n = n; // Torna mutável
        let mut resposta: i64 = 1; // Base
        let mut acum: i64 = 0;
        while n > 1 { // 1
            acum += 4;
            resposta += acum;
            n -= 1;
        }
        resposta
    }
}
