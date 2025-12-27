impl Solution {
    pub fn minimum_boxes(apple: Vec<i32>, capacity: Vec<i32>) -> i32 {
        let mut total_apple = apple.iter ().sum ();
        let mut capacity = capacity;
        capacity.sort_by (
            | a, b | b.cmp (&a)
        ); // sort_by
        let m = capacity.len ();
        let mut i = 0usize;
        let mut resposta = 0;
        while i < m && total_apple > 0 {
            resposta += 1;
            total_apple -= if capacity [i] <= total_apple {
                capacity [i]
            } else {
                total_apple
            }; // if
            i += 1;
        }
        resposta
    }
}
