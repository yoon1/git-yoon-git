function solution(left, right) {
    let answer = 0;
    for(let num = left; num <= right; num++) {        
        answer += countDivisor(num) % 2 == 0 ? num : -num;
    }
    return answer;
}

const countDivisor = (num) => {
    let i = num;
    let count = 0;
    while(i-- >= 0) {
        count += (num % i == 0) ? 1 : 0;
    }
    return count;
}