function solution(s) {
    const numbers = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'];
    const replaceAll = (str, searchStr, replaceStr) => (str.split(searchStr).join(replaceStr));
    numbers.forEach((cur, idx) => {
        s = replaceAll(s, cur, idx);
    });
    return Number(s);
}