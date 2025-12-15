impl Solution {
    pub fn get_descent_periods(prices: Vec<i32>) -> i64 {
        let n = prices.len ();
        let mut i = 0usize;
        let mut resposta = 0i64;
        while i < n {
            let mut cont = 1i64;
            let mut total = 1i64;
            let mut j = i + 1;
            while j < n && prices [j - 1] - prices [j] == 1 {
                cont += 1;
                total += cont;
                j += 1;
            }
            resposta += total;
            i = j;
        }
        resposta
    }
}
