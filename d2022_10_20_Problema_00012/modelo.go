func intToRoman(num int) string {
    var resposta string
    milhar := func () {
        valor := 0
        for num >= 1000 {
            valor += 1
            num -= 1000
        }
        switch valor {
            case 1: resposta += "M"
            case 2: resposta += "MM"
            case 3: resposta += "MMM"
            // vazio já é o padrão
        }
    }

    centena := func () {
        valor := 0
        for num >= 100 {
            valor += 1
            num -= 100
        }
        switch valor {
            case 1: resposta += "C"
            case 2: resposta += "CC"
            case 3: resposta += "CCC"
            case 4: resposta += "CD"
            case 5: resposta += "D"
            case 6: resposta += "DC"
            case 7: resposta += "DCC"
            case 8: resposta += "DCCC"
            case 9: resposta += "CM"
            // vazio já é o padrão
        }
    }

    dezena := func () {
        valor := 0
        for num >= 10 {
            valor += 1
            num -= 10
        }
        switch valor {
            case 1: resposta += "X"
            case 2: resposta += "XX"
            case 3: resposta += "XXX"
            case 4: resposta += "XL"
            case 5: resposta += "L"
            case 6: resposta += "LX"
            case 7: resposta += "LXX"
            case 8: resposta += "LXXX"
            case 9: resposta += "XC"
            // Vazio já é o padrão
        }
    }

    unidade := func () {
        valor := 0
        for num >= 1 {
            valor += 1
            num -= 1
        }
        switch valor {
            case 1: resposta += "I"
            case 2: resposta += "II"
            case 3: resposta += "III"
            case 4: resposta += "IV"
            case 5: resposta += "V"
            case 6: resposta += "VI"
            case 7: resposta += "VII"
            case 8: resposta += "VIII"
            case 9: resposta += "IX"
            // Vazio já é o padrão
        }
    }

    milhar ()
    centena ()
    dezena ()
    unidade ()
    return resposta
}

