class Solution:
    def removeStars(self, s: str) -> str:
        resposta = [" "] * len (s) # Monta uma lsita de brancos de mesmo tamanho de s
        pos = 0 # Posição onde cada elemento irá
        for c in s:
            if c == '*':
                pos -= 1
            else:
                resposta [pos] = c
                pos += 1
        return "".join (resposta [:pos]) # Tira os brancos ou lixo do final
    
