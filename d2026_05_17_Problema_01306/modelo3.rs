impl Solution {
    fn buscar (a: &Vec<i32>, i: i32, p: &mut Vec<bool>) -> bool {
        // Condições de saída
        if a [i as usize] == 0 { return true; }
        if p [i as usize] { return false; }
        p [i as usize] = true;
        let resposta = // Por conta do controle de passagens, preciso armazenar em uma variável
            (i - a [i as usize] >= 0 && Self::buscar (a, i - a [i as usize], p)) ||
            (i + a [i as usize] < a.len () as i32 && Self::buscar (a, i + a [i as usize], p));
        p [i as usize] = false;
        resposta
    }
    pub fn can_reach(arr: Vec<i32>, start: i32) -> bool {
        // Para gerenciamento dos deslocamentos com cálculos negativos, irei mwnter start como i32
        let mut passou = vec![false; arr.len ()];
        Self::buscar (&arr, start, &mut passou)
    }
}
