impl Solution {
    pub fn separate_digits(nums: Vec<i32>) -> Vec<i32> {
        fn digitos (mut a: i32) -> Vec<i32> {
            let mut tmp: Vec<i32> = Vec::new ();
            while a > 0 {
                tmp.push (a % 10);
                a /= 10;
            }
            tmp.reverse ();
            tmp
        };
        let mut resposta: Vec<i32> = Vec::new ();
        for v in nums {
            resposta.extend (digitos (v));
        }
        resposta
    }
}
