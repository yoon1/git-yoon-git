package main

func averageWaitingTime(customers [][]int) float64 {
	var waitingTime = 0
	var end = 0
	for _, customer := range customers {
		end = max(end, customer[0]) + customer[1]
		waitingTime += end - customer[0]
	}

	return float64(waitingTime) / float64(len(customers))
}
