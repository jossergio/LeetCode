impl Solution {
    fn ler (v: i32) -> (i32, i32) {
        ((v >> 6) & 15, v & 63) // H, M
    }
    fn contar_1 (v: i32) -> i32 {
        let mut v = v;
        let mut cont = 0;
        while v > 0 {
            if v & 1 == 1 {
                cont += 1;
            }
            v >>= 1;
        }
        cont
    }
    fn montar (h: i32, m: i32) -> String {
        if m < 10 {
            format! ("{}:0{}", h.to_string (), m.to_string ()) // Adiciona o 0
        } else {
            format! ("{}:{}", h.to_string (), m.to_string ())
        }
    }
    pub fn read_binary_watch(turned_on: i32) -> Vec<String> {
        let mut resposta: Vec<String> = Vec::new ();
        for i in 0..1024 { // 1024: limite de dez 1
            if Self::contar_1 (i) == turned_on {
                let (h, m) = Self::ler (i);
                if h < 12 && m < 60 {
                    resposta.push (Self::montar (h, m));
                }
            }
        }
        resposta
    }
}
