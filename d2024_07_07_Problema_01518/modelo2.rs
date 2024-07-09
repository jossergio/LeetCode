impl Solution {
    pub fn num_water_bottles(num_bottles: i32, num_exchange: i32) -> i32 {
        let mut resposta: i32 = 0;
        let mut vazias: i32 = 0;
        let mut num_bottles: i32 = num_bottles; // Só para "sombrear"
        while (num_bottles > 0) {
            resposta += num_bottles;
            vazias += num_bottles;
            num_bottles = vazias / num_exchange;
            vazias %= num_exchange;
        }
        return resposta;
    }
}

