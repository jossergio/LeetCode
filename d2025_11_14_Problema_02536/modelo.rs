impl Solution {
    pub fn range_add_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = n as usize;
        let mut resposta = vec![vec![0; n]; n];
        for q in queries {
            for i in q [0]..=q [2] {
                for j in q [1]..=q [3] {
                    resposta [i as usize][j as usize] += 1;
                }
            }
        }
        resposta
    }
}
