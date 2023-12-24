package structure

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func IsSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}
	if p == nil || q == nil {
		return false
	}
	if p.Val != q.Val {
		return false
	}

	return IsSameTree(p.Left, q.Left) && IsSameTree(p.Right, q.Right)
}

const NULL = -1

func CreateTree(arr []int) *TreeNode {
	if len(arr) == 0 {
		return nil
	}

	root := &TreeNode{
		Val: arr[0],
	}

	queue := []*TreeNode{root}
	i := 1

	for i < len(arr) {
		node := queue[0]
		queue = queue[1:]

		if arr[i] != NULL {
			node.Left = &TreeNode{Val: arr[i]}
			queue = append(queue, node.Left)
		}
		i++

		if i < len(arr) && arr[i] != NULL {
			node.Right = &TreeNode{Val: arr[i]}
			queue = append(queue, node.Right)
		}
		i++
	}

	return root
}
