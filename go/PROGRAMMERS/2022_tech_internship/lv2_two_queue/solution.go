package lv2_two_queue

type QueueWrap struct {
	q   []int
	sum int64
}

func (qw *QueueWrap) Pop() int {
	if len(qw.q) <= 0 {
		panic("fail..")
	}

	res := (qw.q)[0]
	qw.q = (qw.q)[1:]

	qw.sum -= int64(res)

	return res
}

func (qw *QueueWrap) Push(v int) {
	qw.q = append(qw.q, v)
	qw.sum += int64(v)
}

func sum(arr []int) (val int64) {
	for _, v := range arr {
		val += int64(v)
	}
	return
}

func solution(queue1 []int, queue2 []int) int {
	max := (len(queue1) + len(queue2)) * 2
	a := QueueWrap{queue1, sum(queue1)}
	b := QueueWrap{queue2, sum(queue2)}

	count := 0
	for count <= max {
		if a.sum == b.sum {
			return count
		}
		if a.sum < b.sum {
			a.Push(b.Pop())
		} else {
			b.Push(a.Pop())
		}
		count++
	}

	return -1
}
