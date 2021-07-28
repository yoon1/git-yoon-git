const NUM_MAX_LENGTH = 5;
const INDEX = {
    HEAD: 0,
    NUMBER: 1
}; 

function solution(files) {
    // 1. parsing
    const parsedFiles = files.map((file, id) => {
        const words = file.split(/(\d+)/);
        return {
            'head': words[INDEX.HEAD].toUpperCase(),
            'number': parseInt(words[INDEX.NUMBER].substring(0, NUM_MAX_LENGTH)),
            'id': id
        }
    });
    
    // 2. sort
    parsedFiles.sort(function(a, b) {
        if(a.head != b.head) return a.head < b.head ? -1 : 1;
        if(a.number != b.number) return a.number < b.number ? -1 : 1;
        return a < b;
    });
    return parsedFiles.map((parseFile) => (files[parseFile.id]));
    
}