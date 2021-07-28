function solution(msg) {
    var answer = [];
    const dict = new Map();
    let index = 1;
    
    // 0. dictionary 초기화
    for(; index <= 26; index++){
        dict.set(String.fromCharCode(65+(index-1)), index);
    }
    
    const len = msg.length;
    for(let i = 0, j = 0; i < len; i = j) {
        let w = '', c = '';
        
        // 1. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾음.
        for(j = i; j < len && dict.has(c = msg.substring(i,j+1)) ; j++);
        w = j < len ? c.slice(0, -1) : c;
        // w = (w === undefined || w === '') ? msg.substring(i) : w;
        
        // 2. w에 해당하는 사전의 색인 번호 출력
        answer.push(dict.get(w));
        
        // 3. 사전 추가
        dict.set(c, index++);
    }
        
    return answer;
}