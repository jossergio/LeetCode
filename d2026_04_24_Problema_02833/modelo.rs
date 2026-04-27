impl Solution {
    pub fn furthest_distance_from_origin(moves: String) -> i32 {
        let mut tmp = vec![0; 3]; // Um para cada tipo
        for c in moves.chars () {
            if c == 'L' {
                tmp [0] += 1;
            } else if c == 'R' {
                tmp [1] += 1;
            } else { // Só pode ser _
                tmp [2] += 1;
            }
        }
        i32::max (
            tmp [0] + tmp [2] - tmp [1],
            tmp [1] + tmp [2] - tmp [0]
        )
    }
}
