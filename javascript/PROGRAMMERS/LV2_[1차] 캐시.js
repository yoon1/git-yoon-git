function solution(cacheSize, cities) {
    let answer = 0;
    let cache = [];
    
    if (cacheSize == 0) {
        return cities.length * 5;
    }
    
    const reducer = (acc, city) => {
        const vCity = city.toLowerCase();
        let hit = false;
        const curCacheSize = cache.length;
        const hitIdx = cache.indexOf(vCity);
        
        if(hitIdx != -1) {
            cache.splice(hitIdx, 1);
            hit = true;
        } else {
            if(cacheSize <= curCacheSize) {
                cache.shift();
            }
        }
        cache.push(vCity);
        
        return acc += hit ? 1 : 5;
    };
    
    answer = cities.reduce(reducer, 0);
    
    return answer;
}