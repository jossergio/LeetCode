class Solution {
private:
    string get_unidades (int n, vector<string>& unidades) {
        if (n < 20) { // Nunca vem zero
            return unidades [n - 1]; // 0-begin
        }
        // else
        string retorno;
        if (n >= 100) {
            retorno.append (unidades [(n / 100) - 1] + " Hundred"); // 0-begin
            int resto = n % 100;
            if (resto > 0) retorno.append (" " + get_unidades (resto, unidades));
        } else { // Ficou entre 20 e 99
            retorno.append (unidades [((n / 10) - 1) + 18]); // 0-begin; mais unidade de dez em 0-begin, também
            int resto = n % 10;
            if (resto > 0) retorno.append (" " + get_unidades (resto, unidades));
        }
        return retorno;
   }
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero"; // Não tenho como processar isso
        }
        vector<string> etapa {"", " Thousand", " Million", " Billion"}; // Já puz o espeço
        vector<string> unidades {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
                                "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        int i_etapa = 0;
        string resposta;
        while (num > 0) {
            int resto = num % 1000;
            num /= 1000;
            if (resto > 0) resposta = get_unidades (resto, unidades) + etapa [i_etapa] + (resposta.size () > 0 ? " " + resposta : resposta);
            i_etapa += 1;
        }
        return resposta;
    }
};

