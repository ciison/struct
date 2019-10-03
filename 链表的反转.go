// 链表的反转
// 例如: 1, 2, 3 => 3, 2, 1
package main

import "fmt"

//
type _reverseNode struct {
	val  int
	next *_reverseNode
}

func reverseNode(head *_reverseNode) *_reverseNode {
	// 借助一个新的head, 头节点完成链表的反转
	if head == nil {
		return nil
	}
	newHead := &_reverseNode{}
	for h := head; h != nil; {
		tmp := h
		h = h.next
		// 将当前节点的尾部指向 newHead.next 域,

		tmp.next = newHead.next
		// 将 newHead.next 域指向当前的节点
		newHead.next = tmp

	}
	return newHead.next
}

func main() {
	head := &_reverseNode{val: 1, next: &_reverseNode{val: 2, next: &_reverseNode{val: 3}}}
	fmt.Print("反转前:")
	for h := head; h != nil; h = h.next {
		fmt.Print(h.val, " ")
	}
	fmt.Println()

	head = reverseNode(head)
	fmt.Print("反转后:")
	for h := head; h != nil; h = h.next {
		fmt.Print(h.val, " ")
	}
	fmt.Println()
}
