impl Solution {
    pub fn binary_gap(n: i32) -> i32 {
        (0..32).filter (| i | n & (1 << i) != 0)
            .fold ((0, Option::<i32>::None),
                | (maximo, anterior), atual |
                    (
                        if let Some (valor_anterior) = anterior { maximo.max (atual - valor_anterior)} else { 0 },
                        Some (atual)
                    )
            ).0
    }
}
