use std::collections::HashSet;
impl Solution {
    pub fn longest_balanced(nums: Vec<i32>) -> i32 {
        let mut impares: HashSet<i32> = HashSet::new ();
        let mut pares: HashSet<i32> = HashSet::new ();
        let t = nums.len ();
        let mut maximo = 0; // Será interpretado como usize, pelo compilador
        for i in 0..t {
            impares.clear ();
            pares.clear ();
            for j in i..t {
                if nums [j] % 2 == 0 { // É par
                    pares.insert (nums [j]);
                } else { // Só pode ser ímpar
                    impares.insert (nums [j]);
                }
                if pares.len () == impares.len () {
                    maximo = maximo.max (j - i + 1);
                }
            }
        }
        maximo as i32
    }
}
