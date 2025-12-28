impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        let b = grid [0].len () as i32 - 1; // Base; vamos utilizar o -1 como final
        let mut limite = b; // Base inicial
        let mut contagem = 0;
        for v in grid {
            while limite >= 0 && v [limite as usize] < 0 {
                limite -= 1;
            }
            contagem += b - limite;
        }
        contagem
    }
}
