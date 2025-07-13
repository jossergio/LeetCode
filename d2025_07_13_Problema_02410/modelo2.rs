impl Solution {
    pub fn match_players_and_trainers(players: Vec<i32>, trainers: Vec<i32>) -> i32 {
        let mut p = players.clone ();
        let mut t = trainers.clone ();
        p.sort ();
        t.sort ();
        let mut tp = p.len (); // Atenção, abaixo, para o 0-begin
        let mut tt = t.len (); // Idem
        let mut resposta = 0; // i32
        while tp > 0 && tt > 0 {
            tt -= 1; // Como é 0-begin e o tipo é usize e preciso do zero...
            tp -= 1; // Idem
            loop { // Nunca pensei que fosse usar, mas o 0-begin pediu
                if tp >= 0 && p [tp] <= t [tt] {
                    resposta += 1;
                    break;
                }
                // else
                if tp == 0 {
                    break;
                }
                // else
                tp -= 1;
            }
        }
        resposta
    }
}
