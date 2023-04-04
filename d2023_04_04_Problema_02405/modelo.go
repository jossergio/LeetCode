func partitionString(s string) int {
    mapa := make (map [rune] int)
    var contador int // = 0
    var recente int // = 0; divisão mais recente
    for i, c := range s {
        if v, existe := mapa [c]; existe {
            if v != -1 {
                if recente <= v {
                    contador += 1
                    recente = i
                }
            }
        }
        mapa [c] = i
    }
    contador += 1 // Sempre falta contar o último trecho
    return contador
}

