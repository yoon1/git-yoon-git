package main

/**
 * This is the declaration of customFunction API.
 * @param  x    int
 * @param  x    int
 * @return 	    Returns f(x, y) for any given positive integers x and y.
 *			    Note that f(x, y) is increasing with respect to both x and y.
 *              i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1) -- 증가 곡선.
 */

func findSolution(customFunction func(int, int) int, z int) [][]int {
	var res [][]int
	for x := 1; x <= 1000; x++ {
		for y := 1; y <= 1000; y++ {
			v := customFunction(x, y)
			if v == z {
				s := []int{x, y}
				res = append(res, s)
			} else if v > z {
				break
			}
		}
	}

	return res
}
