/**
 * @param {string} arriveAlice
 * @param {string} leaveAlice
 * @param {string} arriveBob
 * @param {string} leaveBob
 * @return {number}
 */
var countDaysTogether = function(arriveAlice, leaveAlice, arriveBob, leaveBob) {
    let diasMes = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    function diaDoAno (vetorDia) {
        let calculo = 0;
        for (let m = 0; m < parseInt (vetorDia [0]) - 1; m += 1) { // Contagem limite de 0-begin
            calculo += diasMes [m];
        }
        return calculo + parseInt (vetorDia [1]);
    }
    // Vou usar variáveis independentes para melhor visualização do código
    const ano = 365;
    const inicioAlice = diaDoAno (arriveAlice.split ("-")) - 1; // Ajusta para 0-begin
    const finalAlice = diaDoAno (leaveAlice.split ("-")); // Porém, o último torna-se limite no laço de fill
    const inicioBob = diaDoAno (arriveBob.split ("-")) - 1;
    const finalBob = diaDoAno (leaveBob.split ("-"));
    const visitaAlice = new Array (ano).fill (0).fill (1, inicioAlice, finalAlice);
    const visitaBob = new Array (ano).fill (0).fill (1, inicioBob, finalBob);
    // Não vi como utilizar uma função zip. Então, fiz iterativamente
    let contagem = 0;
    for (let i = 0; i < ano; i += 1) {
        if (visitaAlice [i] === 1 && visitaBob [i] === 1) {
            contagem += 1;
        }
    }
    return contagem;
};
