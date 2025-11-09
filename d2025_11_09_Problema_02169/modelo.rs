impl Solution {
    pub fn count_operations(num1: i32, num2: i32) -> i32 {
        let mut num1 = num1; // Torna mutável
        let mut num2 = num2; // Idem
        let mut resposta = 0; // i32
        while num1 != 0 && num2 != 0 {
            if num1 > num2 {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            resposta += 1;
        }
        resposta
    }
}
