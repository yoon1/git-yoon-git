const MAX = 0, MIN = 1, UNKNOWN = 0;

function solution(lottos, win_nums) {
    const set_win_nums = new Set(win_nums);
    const score = new Map([ // [갯수, 등수]
        [6, 1],
        [5, 2],
        [4, 3],
        [3, 4],
        [2, 5],
        [1, 6],
        [0, 6]
    ]);
    
    const answer = lottos.reduce((result, lotto) => {
        if(lotto == UNKNOWN) {
            result[MAX]++;
        }
        if(set_win_nums.has(lotto)) {
            result[MAX]++;
            result[MIN]++;
        }
        return result;
    }, [0, 0]);
    
    return [score.get(answer[MAX]), score.get(answer[MIN])];
    
}