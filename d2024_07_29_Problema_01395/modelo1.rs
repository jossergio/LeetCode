impl Solution {
    pub fn num_teams(rating: Vec<i32>) -> i32 {
        let mut resposta: i32 = 0;
        let t: usize = rating.len ();
        for i in (0..t) {
            for j in (i + 1..t) {
                if rating [j] < rating [i] {
                    for k in (j + 1..t) {
                        if rating [k] < rating [j] {
                            resposta += 1;
                        }
                    }
                } else {
                    for k in (j + 1..t) {
                        if rating [k] > rating [j] {
                            resposta += 1;
                        }
                    }
                }
            }
        }
    resposta
    }
}

