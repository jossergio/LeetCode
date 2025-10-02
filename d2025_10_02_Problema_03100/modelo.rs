impl Solution {
    pub fn max_bottles_drunk(num_bottles: i32, num_exchange: i32) -> i32 {
        let mut num_bottles = num_bottles; // Torna mutável
        let mut num_exchange = num_exchange; // Idem
        let mut vazias = 0;
        let mut resposta: i32 = 0;
        while num_bottles > 0 {
            resposta += num_bottles;
            vazias += num_bottles;
            num_bottles = 0; // Esvazia tudo
            while vazias >= num_exchange {
                vazias -= num_exchange;
                num_exchange += 1;
                num_bottles += 1;
            }
        }
        resposta
    }
}
