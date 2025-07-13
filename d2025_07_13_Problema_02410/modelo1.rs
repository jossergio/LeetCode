impl Solution {
    pub fn match_players_and_trainers(players: Vec<i32>, trainers: Vec<i32>) -> i32 {
        let mut p = players.clone ();
        let mut t = trainers.clone ();
        p.sort ();
        t.sort ();
        let mut tp = p.len () as i32 - 1; // Vou precisar do 0 e do -1
        let mut tt = t.len () as i32 - 1; // Idem
        let mut resposta = 0; // i32
        while tp >= 0 && tt >= 0 {
            let mut c = 0;
            let mut tmp = t [tt as usize];
            while tmp > 1 {
                c += 1;
                tmp /= 10;
            }
            while tp >= 0 && p [tp as usize] > t [tt as usize] {
                tp -= 1;
            }
            if tp >= 0 {
                resposta += 1;
            }
            tp -= 1;
            tt -= 1;
        }
        resposta
    }
}
