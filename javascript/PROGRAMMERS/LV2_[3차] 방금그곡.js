function solution(m, musicinfos) {
    var answer = {
        time: 0, 
        title: "",
        melody: "",
    };
    
    musicinfos.forEach((info) => {
        const cur = infoStrToObj(info);
        if (checkMelody(m, cur)) {
            answer = answer.time < cur.time ? cur : answer;
        }
    });

    return answer.title == '' ? '(None)' : answer.title;
}

function infoStrToObj(str) { 
    const arr = str.split(',');
    return ({
        time: timeStrToInt(arr[1]) - timeStrToInt(arr[0]),
        title: arr[2],
        melody: arr[3]
    });    
}

function timeStrToInt(time) {
    const t = parseInt(time.replace(':', ''));
    return (parseInt(t / 100) * 60) + (t %  100);
}

function checkMelody(my, real) {
    let realMelody = setMelodySeperator(real.melody)
                        .substring(0,real.time);
    realMelody = realMelody.repeat(Math.ceil(real.time / realMelody.length)); // repeat(3) => 123, => 123123123
    const myMelody = setMelodySeperator(my);
    
    return realMelody.indexOf(myMelody) > -1 ? true : false;
}

function setMelodySeperator(melody) {
    const regex = /([A-G]{1,1}[#]{0,1})/g;
    
    //'C# => c'
    // 'CC#' => 'Cc'
    return melody.match(regex)
                .map(x => x.length > 1 ? x[0].toLowerCase() : x)
                .join('');
}