class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        
        tabela = {
            "a": ".-",
            "b": "-...",
            "c": "-.-.",
            "d": "-..",
            "e": ".",
            "f": "..-.",
            "g": "--.",
            "h": "....",
            "i": "..",
            "j": ".---",
            "k": "-.-",
            "l": ".-..",
            "m": "--",
            "n": "-.",
            "o": "---",
            "p": ".--.",
            "q": "--.-",
            "r": ".-.",
            "s": "...",
            "t": "-",
            "u": "..-",
            "v": "...-",
            "w": ".--",
            "x": "-..-",
            "y": "-.--",
            "z": "--.."
        }
        
        codificadosUnicos = set ()
        
        for palavra in words:
            tmp = ""
            for letra in palavra:
                tmp += tabela [letra]
            codificadosUnicos.add (tmp)
        
        
        return len (codificadosUnicos)
    
