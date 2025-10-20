impl Solution {
    pub fn successful_pairs(spells: Vec<i32>, potions: Vec<i32>, success: i64) -> Vec<i32> {
        let mut resposta = vec![0; spells.len ()];
        let mut spellsIndex = spells.into_iter ().enumerate ().map (| (i, v) | (v as i64, i)).collect::<Vec<_>> ();
        spellsIndex.sort_by (| &a, &b | b.0.cmp (&a.0) ); // Pelo primeiro índice da tupla
        let mut potions: Vec<i64> = potions.into_iter ().map (| v | v as i64).collect ();
        potions.sort ();
        let t = potions.len (); // Será utilizado em vários momentos
        let mut indexPotions = 0;
        for (valor, indice) in spellsIndex {
            while indexPotions < t && potions [indexPotions] * valor < success {
                indexPotions += 1
            }
            resposta [indice] = (t - indexPotions) as i32;
        }
        resposta
    }
}
