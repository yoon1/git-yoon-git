package main

type OrderedStream struct {
	arr []string
	p   int
}

func Constructor(n int) OrderedStream {
	var arr = make([]string, n)

	return OrderedStream{
		arr: arr,
		p:   0,
	}
}

func (this *OrderedStream) Insert(idKey int, value string) []string {
	this.arr[idKey-1] = value
	if this.arr[this.p] == "" {
		return []string{}
	}

	stream := []string{}
	for this.p < len(this.arr) && this.arr[this.p] != "" {
		stream = append(stream, this.arr[this.p])
		this.p++
	}

	return stream
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Insert(idKey,value);
 */
