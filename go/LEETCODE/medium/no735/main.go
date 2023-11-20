package main

import "math"

func asteroidCollision(asteroids []int) []int {
	for len(asteroids) >= 2 {
		var t = asteroids[len(asteroids)-2:]
		asteroids = asteroids[:len(asteroids)-2]
		info := crash(t[0], t[1])
		if info.isSameDir {
			asteroids = append(asteroids, t...)
			break
		}

		if !info.isSamePower {
			asteroids = append(asteroids, info.survived)
		}
	}

	return asteroids
}

type crashInfo struct {
	isSameDir   bool
	isSamePower bool
	survived    int
}

func crash(a, b int) crashInfo {
	if a*b > 0 {
		return crashInfo{true, false, 0}
	}

	var (
		aa = math.Abs(float64(a))
		ab = math.Abs(float64(b))
	)

	if aa == ab {
		return crashInfo{false, true, a}
	}

	if aa < ab {
		return crashInfo{false, false, b}
	}

	return crashInfo{false, false, a}
}
