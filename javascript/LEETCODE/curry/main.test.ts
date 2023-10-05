import {curry} from './main';

test.each([
    ['test case 0', function sum(a:number, b:number) {return a + b;}, [1, 2], 3], // test case 0
    ['test case 1', function sum(a:number, b:number, c:number) { return a + b + c; }, [1, 2, 3], 6], // test case 1
    ['test case 2', function sum(a:number, b:number, c:number) { return a + b + c; }, [1, 2, 3], 6], // test case 2
    ['test case 3', function sum(a:number, b:number, c:number) { return a + b + c; }, [1, 2, 3], 6], // test case 3
    ['test case 4', function life() { return 42; }, [], 42], // test case 4
])('%s', (testName, fn, args, expected) => {
    const csum = curry(fn);
    const result = csum(...args)
    expect(result).toBe(expected);
});

test('test case 0', () => {
    const fn = function sum(a:number, b:number) {return a + b;}
    const csum = curry(fn);
    const result = csum(1)(2)
    expect(result).toBe(3);
});

test('test case 1', () => {
    const fn = function sum(a:number, b:number, c:number) { return a + b + c; }
    const csum = curry(fn);
    expect(csum(1)(2)(3)).toBe(6);
});

test('test case 2', () => {
    const fn = function sum(a:number, b:number, c:number) { return a + b + c; }
    const csum = curry(fn);
    expect(csum(1,2)(3)).toBe(6);
});

test('test case 3', () => {
    const fn = function sum(a:number, b:number, c:number) { return a + b + c; }
    const csum = curry(fn);
    expect(csum()()(1,2,3)).toBe(6);
});

test('test case 4', () => {
    const fn = function life() { return 42; }
    const csum = curry(fn);
    expect(csum()).toBe(42);
});

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */