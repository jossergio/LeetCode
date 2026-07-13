/**
 * @param {number[][]} intervals
 * @return {number}
 */
var removeCoveredIntervals = function(intervals) {
    let t = intervals.length;
    let resposta = intervals.length;
    for (let i = 0; i < t; i += 1) {
        for (let j = 0; j < t; j += 1) {
            if (i != j && intervals [i][0] >= intervals [j][0] && intervals [i][1] <= intervals [j][1]) {
                resposta -= 1;
                break; // Não gosto disso, mas será útil aqui
            }
        }
    }
    return resposta;
};
