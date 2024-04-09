package main

type StockSpanner struct {
	stk []int
}

func Constructor() StockSpanner {
	return StockSpanner{
		stk: []int{},
	}
}

func (this *StockSpanner) Next(price int) int {
	this.stk = append(this.stk, price)

	var cnt = 0
	var l = len(this.stk)
	for cnt < l && this.stk[l-cnt-1] <= price {
		cnt++
	}

	return cnt
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */
