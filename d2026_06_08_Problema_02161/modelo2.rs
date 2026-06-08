impl Solution {
    pub fn pivot_array(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
        let mut resposta: Vec<i32> = nums
            .iter ()
            .copied () // Pois não podemos utilizar into_iter nessa questão, pois há outras etapas
            .filter (| a | *a < pivot)
            .collect ();
        resposta.extend (nums
            .iter ()
            .copied () // Idem
            .filter (| a | *a == pivot)
        );
        resposta.extend (nums
            .iter ()
            .copied () // Idem
            .filter (| a | *a > pivot)
        );
        resposta
    }
}
