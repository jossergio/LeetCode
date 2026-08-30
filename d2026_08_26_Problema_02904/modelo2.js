/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var shortestBeautifulSubstring = function(s, k) {
    let resp = "";
    let i = 0;
    let cont = 0;
    for (let j = 0; j < s.length; j += 1) {
        if (s.charAt (j) === "1") {
            cont += 1;
        }
        while (cont === k) {
            let tmp = s.substring (i, j + 1);
            if (resp === "" || tmp.length < resp.length || (tmp.length === resp.length && tmp < resp)) {
                resp = tmp;
            }
            if (s.charAt (i) === "1") {
                cont -= 1;
            }
            i += 1;
       }
    }
    return resp;
};
