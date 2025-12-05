impl Solution {
    pub fn count_partitions(nums: Vec<i32>) -> i32 {
        let  mut direita: i32 = nums.iter ().sum ();
        let mut esquerda = 0;
        let t = nums.len ();
        let mut cont = 0;
        for i in 0..(t - 1) {
            esquerda += nums [i];
            direita -= nums [i];
            if i32::abs (esquerda - direita) % 2 == 0 {
                cont += 1;
            }
        }
        cont
    }
}
