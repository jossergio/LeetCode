impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut valores = std::collections::HashMap::new ();
        let limite = nums.len () / 2;
        println! ("Limite: {limite}");
        for v in nums {
            if let Some (a) = valores.get_mut (&v) {
                *a += 1;
            } else {
                valores.insert (v, 1 as usize);
            }
            if valores [&v] > limite {
                return v;
            }
        }
        0 // Para ter algo aqui
    }
}

