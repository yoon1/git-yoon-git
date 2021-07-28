function solution(n, t, m, p) {
    var answer = '';
    // 0* 1 1* 0 1* 1 1 0 0
    // 1 => toString(2진법) => split('')
    let num = 0;
    
    // string length와 t의 갯수가 동일하면 return
    let order = 0;
    
    while(answer.length < t) {
        const arr = num.toString(n).toUpperCase().split('');

        for(let cur of arr) {
            ++order;
            if(order == p){
                answer += cur;
                if(answer.length === t) {
                    return answer;
                }
            }
            if(order == m) {
                order = 0;
            }
        };

        num += 1;
    }
    
    return answer;
}