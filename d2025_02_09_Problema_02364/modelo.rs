impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let mut tabela = std::collections::HashMap::new ();
        let tamanho = ((nums.len () * (nums.len () - 1)) as i64) / 2; // Para o resultado
        for (i, v) in nums.into_iter ().enumerate () {
            let mut tmp = tabela.entry (v - (i as i32)).or_insert (0 as i64);
            *tmp += 1;
        }
        tamanho - tabela.into_iter ().filter_map (|a| if a.1 > 1 { Some (((a.1 * (a.1 - 1)) / 2) as i64) } else { None }).sum::<i64> ()
    }
}
