/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    let th = haystack.length;
    let tn = needle.length;
    if (tn <= th) {
        for (let i = 0; i < th - tn + 1; i += 1) {
            if (needle === haystack.substr (i, tn)) {
                return i;
            }
        }
    }
    return -1; // Não achou
};
