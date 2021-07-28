function solution(numbers) {
    // var answer = [];
    const set = new Set();
    const len = numbers.length;
    for(let p = 0; p < len; p++) 
        for(let q = p+1; q < len; q++) 
            set.add(numbers[p] + numbers[q]);
    
    return [...set].sort((a,b)=> (a-b));
}