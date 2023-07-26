class Solution {
private:
    double tempoNecessario (const vector<int>& dist, int velocidade) {
        double tempo = 0;
        for (int i = 0; i < dist.size () - 1; i += 1) // Irá, até, o penúltimo
            tempo += ceil ((double) dist [i] / (double) velocidade);
        tempo += ((double) dist.back ()) / (double) velocidade; // O último tem que arredondar para cima
        return tempo;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int esquerda = 0;
        int direita = 1e7; // O máximo que o problema cita que será
        int menorVelocidade = -1;
        while (esquerda <= direita) {
            int meio = (esquerda + direita) / 2;
            if (tempoNecessario (dist, meio) <= hour) {
                menorVelocidade = meio;
                direita = meio - 1;
            } else
                esquerda = meio + 1;
        }
        return menorVelocidade;
    }
};

