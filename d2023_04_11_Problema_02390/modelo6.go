func removeStars(s string) string {
    resposta := make ([]rune, len (s)) // slice de mesmo tamanho de s, com vazios
    var pos int // = 0
    for _, c := range s {
        if c == '*' {
            pos -= 1
        } else {
            resposta [pos] = c
            pos += 1
        }
    }
    return string (resposta [:pos])
}

