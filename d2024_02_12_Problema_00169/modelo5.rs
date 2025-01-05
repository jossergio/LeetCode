impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut valores = std::collections::HashMap::new ();
        let limite = nums.len () / 2;
        println! ("Limite: {limite}");
        for v in nums {
            let a = valores.entry (v).or_insert (0 as usize);
            *a += 1;
            if *a > limite {
                return v;
            }
        }
        0 // Para ter algo aqui
    }
}

