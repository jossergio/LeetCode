impl Solution {
    pub fn num_of_unplaced_fruits(fruits: Vec<i32>, baskets: Vec<i32>) -> i32 {
        let t = fruits.len (); // Tanto faz
        let mut usados = vec! [false; t];
        let mut resposta = 0; // i32
        for f in fruits {
            let mut j: usize = 0;
            while j < t && (usados [j] || baskets [j] < f) {
                j += 1;
            }
            if j == t {
                resposta += 1;
            } else {
                usados [j] = true;
            }
        }
        resposta
    }
}
