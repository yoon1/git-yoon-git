function solution(absolutes, signs) {
    let answer = 0;
    for(let idx = 0; idx < absolutes.length; idx++) {
        answer +=  absolutes[idx] * (signs[idx] ? 1 : -1);
    }
    
    return answer;
}