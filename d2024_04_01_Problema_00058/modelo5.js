/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let tmp = s.trim (); // Retira possíveis brancos desnecessários
    return tmp.length - tmp.lastIndexOf (" ") - 1;
};
