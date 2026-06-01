impl Solution {
    pub fn minimum_cost(cost: Vec<i32>) -> i32 {
        let mut cost = cost; // Torna mutável
        cost.sort_by (| a, b | b.cmp (&a));
        cost
            .into_iter ()
            .enumerate ()
            .fold (0, | acum, (i, v) |
                acum + if i % 3 != 2 { v } else { 0 } // Dispensa o terceiro da sequência
            )
    }
}
