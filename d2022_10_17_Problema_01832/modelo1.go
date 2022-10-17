func checkIfPangram(sentence string) bool {
    mapa := make (map [rune] bool)
    total := 0 // Irá contar as letras únicas
    for _, c := range sentence {
        if _, existe := mapa [c]; !existe {
            mapa [c] = true
            total += 1
        }
    }
    return total == 26 // Letras no alfabeto inglês
}

