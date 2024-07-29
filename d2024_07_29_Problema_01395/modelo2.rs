impl Solution {
    pub fn num_teams(rating: Vec<i32>) -> i32 {
        let mut resposta: i32 = 0;
        let t: usize = rating.len ();
        for i in (0..t) {
            for j in (i + 1..t) {
                for k in (j + 1..t) {
                    if (rating [k] < rating [j] && rating [j] < rating [i])
                        || (rating [i] < rating [j] && rating [j] < rating [k]) {
                        resposta += 1;
                    }
                }
            }
        }
        resposta
    }
}

