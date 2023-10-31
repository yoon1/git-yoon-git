export function curry(fn: Function): Function {
    return function curried() {
        // return sum += nums.reduce((acc, cur) => acc + cur, 0)
        return fn();
    };
};
