const ASSISTANT_NUM  = 65536;

function solution(str1, str2) {
    const JSimilarity = measureJSimilarity(makeStringToSet(str1), makeStringToSet(str2));
    return Math.floor(JSimilarity * ASSISTANT_NUM);
}

function makeStringToSet(str) {
    const set = [];
    str = str.toUpperCase();
    let pre = '';
    for(let cur of str) {
        const word = pre.concat(cur);
        if(/[A-Z][A-Z]/g.test(word)) {
            set.push(word);
        }
        pre = cur;
    }
    return set;
}

function measureJSimilarity(A, B) {
    const aLength = A.length;
    const bLength = B.length;
    
    if(aLength == 0 && bLength == 0) {
        return 1;
    }
    
    const interLength = A.reduce((len, word) => {
        const sameCheckIdx = B.indexOf(word);
        if(sameCheckIdx > -1) {
            B[sameCheckIdx] = "";
            return len + 1;
        }
        return len;
    }, 0);
    
    return interLength / (aLength + bLength - interLength);
}