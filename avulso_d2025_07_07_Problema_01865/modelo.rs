use std::collections::HashMap;
struct FindSumPairs {
    cont1: HashMap<i32, i32>,
    cont2: HashMap<i32, i32>,
    nums2: Vec<i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FindSumPairs {

    fn new(nums1: Vec<i32>, nums2: Vec<i32>) -> Self {
        let mut tmp1 = HashMap::new (); // Prefefi assim, no lugar de gerar tmp direto como estrutura, para facilitar abaixo
        let mut tmp2 = HashMap::new ();
        for v in nums1 {
            tmp1.entry (v).and_modify (|v| *v += 1).or_insert (1);
        }
        for &v in &nums2 {
            tmp2.entry (v).and_modify (|v| *v += 1).or_insert (1);
        }
        Self {cont1: tmp1, cont2: tmp2, nums2}
    }
    
    fn add(&mut self, index: i32, val: i32) {
        let mut tmp = self.nums2 [index as usize];
        self.cont2.entry (tmp).and_modify (|v| *v -= 1).or_insert (0); // Não insere, mas...
        self.nums2 [index as usize] += val;
        tmp = self.nums2 [index as usize];
        self.cont2.entry (tmp).and_modify (|v| *v += 1).or_insert (1); // Já aqui...
    }
    
    fn count(&self, tot: i32) -> i32 {
        let mut r = 0;
        for (i, v) in self.cont1.iter () {
            r += v * self.cont2.get (&(tot - i)).unwrap_or (&0);
        }
        r
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * let obj = FindSumPairs::new(nums1, nums2);
 * obj.add(index, val);
 * let ret_2: i32 = obj.count(tot);
 */
 