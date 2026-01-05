use std::collections::HashSet;
impl Solution {
    pub fn repeated_n_times(nums: Vec<i32>) -> i32 {
        let mut tabela: HashSet<i32> = HashSet::new ();
        for v in nums {
            if tabela.get (&v) != None { //Basta já ter um
                return v;
            }
            // else
            tabela.insert (v);
        }
        0 // Não chega aqui
    }
}
