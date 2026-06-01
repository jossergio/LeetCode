impl Solution {
    pub fn minimum_cost(cost: Vec<i32>) -> i32 {
        let mut cost = cost; // Torna mutável
        cost.sort_by (| a, b | b.cmp (&a));
        let mut resposta = 0;
        for (i, v) in cost.into_iter ().enumerate () {
            if i % 3 != 2 { // É o terceiro da sequência
                resposta += v;
            }
        }
        resposta
    }
}
