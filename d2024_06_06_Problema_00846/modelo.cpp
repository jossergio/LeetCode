class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size () % groupSize != 0) // Nem tenta
            return false;
        sort (hand.begin (), hand.end ());
        const size_t t = hand.size ();
        size_t proximo = 0;
        while (proximo < t) {
            int anterior; // Será controlado no laço, abaixo
            for (int i = 0; i < groupSize; i += 1) { // Lembrar que sempre haverá suficiente, pelo teste no início
                if ((i == 0) || (hand [proximo] == anterior + 1)) {
                    anterior = hand [proximo++];
                    continue; // Para não haver else
                }
                // else
                if (hand [proximo] >= anterior + 2)
                    return false; // Não há como formar sequência
                size_t pegar = proximo + 1;
                while (pegar < t && hand [proximo] <= anterior) {
                    swap (hand [pegar], hand [proximo]);
                    pegar += 1;
                }
                if (pegar > t) // Pode ter saído igual
                    return false; // Só tinha iguais
                // else
                if (hand [proximo] == anterior + 1) {
                    anterior = hand [proximo++];
                    continue; // Para não ter else
                }
                return false; // Se passou pelos testes acima e falhou, não pode formar sequencia
            }
        }
        return true; // Passou em todos os testes
    }
};

