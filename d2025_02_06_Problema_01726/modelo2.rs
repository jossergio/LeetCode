impl Solution {
    fn fat (n: i32) -> i128 {
        let mut r = 1 as i128;
        let mut n = n; // Torna mutável
        while n > 1 {
            r *= n as i128;
            n -= 1;
        }
        r
    }
    pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
        let mut d: std::collections::HashMap<i32, i32> = std::collections::HashMap::new ();
        for (i, v1) in nums.iter ().enumerate () {
            for v2 in nums [i + 1..].iter () {
                let tmp = v1 * v2;
                let v = d.entry (tmp).or_insert (0);
                *v += 1;
            }
        }
        let mut resposta = 0 as i128;
        for v in d.values () {
            if *v > 1 {
                resposta += (Self::fat (*v) / Self::fat (*v - 2)) * 4;
            }
        }
        resposta as i32
    }
}
