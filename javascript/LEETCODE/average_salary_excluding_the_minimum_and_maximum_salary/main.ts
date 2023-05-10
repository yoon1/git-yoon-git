export function average(salary: number[]): number {
    const v = salary.reduce(
        (acc, cur) => {
            return [
                Math.min(cur, acc[0]),
                Math.max(cur, acc[1]),
                acc[2] + cur,
            ]
        }, [Infinity, -Infinity, 0]
    );

    return (v[2] - (v[0]+v[1])) / (salary.length - 2)
};