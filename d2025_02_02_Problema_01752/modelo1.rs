impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let t = nums.len ();
        let mut continuidade: bool = nums [t - 1] <= nums [0]; // Faz o 1o teste nos extremos
        for i in 1..t {
            if nums [i] < nums [i - 1] { // Possível ponto base de deslocamento
                if !continuidade { // Já seria o segundo
                    return false;
                } else {
                    continuidade = false;
                }
            }
        }
        true // Passou pelos testes
    }
}
