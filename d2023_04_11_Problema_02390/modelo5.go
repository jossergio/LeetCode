func removeStars(s string) string {
    var resposta string
    for _, c := range s {
        if c == '*' {
            resposta = resposta [:len (resposta) - 1]
        } else {
            resposta += string (c)
        }
    }
    return resposta
}

