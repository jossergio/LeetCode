use std::collections::HashMap;
impl Solution {
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
        let mut contagem: HashMap<i32, i32> = HashMap::new ();
        for n in nums {
            contagem.entry (n).and_modify (| v | *v += 1).or_insert (1);
        }
        let mut valores = contagem.values ().collect::<Vec<_>> ();
        valores.sort_by (| a, b | b.cmp (a));
        let maximo = valores [0]; // Para facilitar o visual e a compreensão
        maximo * Vec::from (valores).into_iter ().filter (| &a | a == maximo).collect::<Vec<_>> ().len () as i32
    }
}
