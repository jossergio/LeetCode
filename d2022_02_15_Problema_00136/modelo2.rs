use std::collections::HashSet;
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut tabela: HashSet<i32> = HashSet::new ();
        for v in nums {
            if !tabela.remove (&v) { // Ou tem ou não tem
                tabela.insert (v);
            }
        }
        return {match tabela.iter ().next () { // Só fica um
            Some (&v) => v,
            None => 0, // Só para ter algo
            } 
        }
    }
}

