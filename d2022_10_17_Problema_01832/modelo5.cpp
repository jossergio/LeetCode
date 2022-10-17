func checkIfPangram(sentence string) bool {
    var mapa [26] bool // Todos zero
    total := 0 // Irá contar as letras únicas
    for _, c := range sentence {
        if !mapa [c - 'a'] {
            mapa [c - 'a'] = true
            total += 1
            if total == 26 { // Chegou ao total de possibilidades
                return true
            }
        }
    }
    return false // Por omissão, se chegou até aqui sem encontrar todos
}

