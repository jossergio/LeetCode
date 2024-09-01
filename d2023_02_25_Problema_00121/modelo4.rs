impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut maximo: i32 = 0;
        let mut menor: i32 = prices [0];
        for v in prices {
            if v < menor {
                menor = v
            } else {
                maximo = core::cmp::max (maximo, v - menor);
            }
        }
        maximo
    }
}

