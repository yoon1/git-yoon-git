package main

import (
	"fmt"
	"runtime"
	"sync"
	"testing"
	"time"
)

func memConsumed() uint64 {
	runtime.GC()
	var s runtime.MemStats
	runtime.ReadMemStats(&s)
	return s.Sys
}

func bigIntSlice(size int) []int {
	a := []int{}
	for i := size; i > 0; i-- {
		a = append(a, i)
	}
	return a
}

func Test_solution1(t *testing.T) {
	// 100만개 -> 35s
	// 50만개 -> 9s
	// 25만개 -> 2.5s
	// 12.5만개 -> 0.5s
	a := bigIntSlice(500000)
	tcs := []struct {
		Numbers []int
		Answer  []int
	}{
		//{[]int{2, 3, 3, 5}, []int{3, 5, 5, -1}},
		//{[]int{9, 1, 5, 3, 6, 2}, []int{-1, 5, 6, 6, -1, -1}},
		{a, []int{}},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			start := time.Now()
			solution_1(tc.Numbers)
			//assert.Equal(t, tc.Answer, res)
			fmt.Printf("실행시간: %s\n", time.Since(start))
		})
	}
}

func Test_near(t *testing.T) {
	const length = 500000
	a := bigIntSlice(length)
	sc := make([]int, length)

	t.Run("1개", func(t *testing.T) {
		start := time.Now()
		near_2(&sc[0], 0, a, length)
		fmt.Printf("실행시간: %s\n", time.Since(start))
		// n^2
		// 736.5us
	})

	t.Run("use waitgroup", func(t *testing.T) {
		runtime.GOMAXPROCS(runtime.NumCPU())
		//반복횟수: 500, 실행시간: 26.868917ms
		//반복횟수: 1000, 실행시간: 47.052375ms
		//반복횟수: 10000, 실행시간: 480.38425ms
		//반복횟수: 100000, 실행시간: 4.494670542s
		//반복횟수: 200000, 실행시간: 9.058486667s
		//반복횟수: 300000, 실행시간: 13.606970666s (거의 균일하게 시간이 늘어나긴 하는듯? -- goroutine 생성 갯수가 제한이 있는 것 같음.)
		// -> 100만개면 약 40-50초 걸리는 것으로 예상
		// 왜그런걸까? 한번에 다 만들 수 없는건가 ??
		// 결과적으로 goroutine을 사용한 게 더 빠르긴 함
		recNum := []int{500, 1000, 10000, 100000, 200000, 300000}
		maxGorutine := 0
		for _, rn := range recNum {
			start := time.Now()
			beforeMem := memConsumed()
			wg := sync.WaitGroup{}
			for i := 0; i < rn/10; i++ {
				wg.Add(10)

				for j := 0; j < 10; j++ {
					go func(ci int) {
						defer wg.Done()
						near_2(&sc[0], 0, a, length)
					}(i)
				}
				curGoroutine := runtime.NumGoroutine()
				if maxGorutine < curGoroutine {
					maxGorutine = curGoroutine
				}
			}
			wg.Wait()
			afterMem := memConsumed()
			fmt.Printf("실행중인 gorutine의 최대 갯수 %d, ", maxGorutine)
			fmt.Printf("소비된 메모리 양 %.3fkb, ", float64(afterMem-beforeMem)/float64(rn)/1000)
			fmt.Printf("반복횟수: %d, 실행시간: %s\n", rn, time.Since(start))
		}
	})

	t.Run("nouse waitgroup", func(t *testing.T) {
		//반복횟수: 500, 실행시간: 189.116791ms
		//반복횟수: 1000, 실행시간: 380.317167ms
		//반복횟수: 10000, 실행시간: 3.777512792s
		//반복횟수: 100000, 실행시간: 37.759945166s
		// ... 너무 오래 걸려서 그만둠(암튼 정비례)
		recNum := []int{500, 1000, 10000, 100000, 200000, 300000}
		for _, rn := range recNum {
			start := time.Now()
			for i := 0; i < rn; i++ {
				near_2(&sc[0], 0, a, length)
			}
			fmt.Printf("반복횟수: %d, 실행시간: %s\n", rn, time.Since(start))
		}
	})
}
