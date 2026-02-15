// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
        let mut i = 1 as i64; // Pois o cálculo temporário pode estourar i32; Rust tem isso
		let mut j = n as i64; // Idem
        while i < j {
            let meio = (i + j) / 2;
            if self.isBadVersion (meio as i32) { // meio sempre está no limite de i32
                j = meio;
            } else {
                i = meio + 1;
            }
        }
        i as i32
    }
}
