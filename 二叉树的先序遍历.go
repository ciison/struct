// 二叉树的先序遍历, 使用的是 递归来实现的
package main

import "fmt"

type btree struct {
	val   int
	left  *btree
	right *btree
}

// root 是二叉树的根节点
// visit 是对应的处理函数
func preOrderVisit(root *btree, visit func(val int)) {
	if root != nil {
		visit(root.val)
		preOrderVisit(root.left, visit)
		preOrderVisit(root.right, visit)
	}
}
func main() {
	// 使用先序遍历二叉树
	//
	//             1
	//       2             4
	//   3
	root := &btree{
		val: 1,
		left: &btree{
			val: 2,
			left: &btree{
				val: 3,
			},
		},
		right: &btree{
			val: 4,
		},
	}

	// 结果:  1 2 3 4
	preOrderVisit(root, func(val int) { fmt.Print(val, " ") })
}
