function solution(relation) {
    const answer = new Set();
    const colSize = relation[0].length;
    const arr = Array.from({length: colSize}, (v, i) => i);
    
    // 1. 멱집합 
    const candidateKeys = getPowerSet(arr);
    for(const candidateKey of candidateKeys) {
        if(candidateKey.length == 0) continue;
        // 2-1. 최소성
        if(!checkMinimalKey(candidateKey, answer)) continue; 

        // 2-2. 유일성
        if (!checkUniqueKey(relation, candidateKey)) continue;
        
        answer.add(JSON.stringify(candidateKey));
    }

    return answer.size;
}

function getPowerSet(arr) {
    const powerSet = arr.reduce(
                        (subsets, value) => subsets.concat(
                            subsets.map(set => [value, ...set].sort(function (a, b) {
                                return a - b;
                            }))
                        )
                        , [[]]
                    );
    
    return powerSet.sort(function(a, b) {
              return a.length - b.length;
           });
}

function checkMinimalKey(candidateKey, everKeys) {
    const powerSet = getPowerSet(candidateKey);
    let flag = true;
    for(const subset of powerSet) {
        if(everKeys.has(JSON.stringify(subset))) {
            flag = false;
        }
    }
    return flag;
}

function checkUniqueKey(relation, candidateKey) {
    const set = new Set();
    for(const row of relation) {
        const cols = candidateKey.reduce((val, cur) => {
            return val += row[parseInt(cur)];
        }, "");
        
        if(set.has(cols)) {
            return false;
        }
        
        set.add(cols);
    }

    return true;
}