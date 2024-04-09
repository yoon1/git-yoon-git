package main

import (
	"fmt"
	"testing"
)

func Test_sortColors(t *testing.T) {
	st := Constructor()
	fmt.Println(st.Next(100))
	fmt.Println(st.Next(80))
	fmt.Println(st.Next(60))
	fmt.Println(st.Next(70))
	fmt.Println(st.Next(60))
	fmt.Println(st.Next(75))
	fmt.Println(st.Next(85))
}
