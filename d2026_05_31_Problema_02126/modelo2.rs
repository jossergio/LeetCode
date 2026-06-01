impl Solution {
    pub fn asteroids_destroyed(mass: i32, asteroids: Vec<i32>) -> bool {
        let mut asteroids = asteroids;
        let mut massa = mass as i64;
        asteroids.sort ();
        for v in asteroids.into_iter ().map (| a | a as i64) {
            if massa >= v {
                massa += v; // Destrói e acumula na massa
            } else {
                return false; // Não consegue destruir a partir daqu
            }
        }
        true // Passou e destruiu todos
    }
}
