function solution(arr) {
    const reducer = (accumulator, currentValue) => accumulator + currentValue;
    return arr.reduce(reducer) / arr.length;
}