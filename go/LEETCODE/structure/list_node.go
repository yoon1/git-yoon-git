package structure

type ListNode struct {
	Val  int
	Next *ListNode
}

func (l *ListNode) Traverse() []int {
	res := []int{}
	for node := l; node != nil; node = node.Next {
		res = append(res, node.Val)
	}
	return res
}

func MakeListNode(nums []int) *ListNode {
	if len(nums) == 0 {
		return nil
	}

	head := &ListNode{
		Val: nums[0],
	}
	p := head
	for i := 1; i < len(nums); i++ {
		node := ListNode{
			Val: nums[i],
		}
		p.Next = &node
		p = p.Next
	}
	return head
}

func CompareListNode(a *ListNode, b *ListNode) bool {
	for a != nil && b != nil {
		if a.Val != b.Val {
			return false
		}
		a = a.Next
		b = b.Next
	}
	return a == nil && b == nil
}
