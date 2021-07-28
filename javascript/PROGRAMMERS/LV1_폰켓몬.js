function solution(nums) {
    const species = new Set(nums).size;
    const select = nums.length / 2;
    
    return species > select ? select : species;
}