impl Solution {
    pub fn count_good_triplets(arr: Vec<i32>, a: i32, b: i32, c: i32) -> i32 {
        let t = arr.len ();
        let mut resposta = 0; // i32
        for i in 0..t {
            for j in (i + 1)..t {
                for k in (j + 1)..t {
                    if i32:: abs (arr [i] - arr [j]) <= a
                    && i32::abs (arr [j] - arr [k]) <= b
                    && i32::abs (arr [i] - arr [k]) <= c {
                        resposta += 1;
                    }
                }
            }
        }
        resposta
    }
}
