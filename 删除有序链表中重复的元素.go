// 删除有序链表中重复的元素
// 比如: 1 -> 1 -> 2 -> 2 -> 3 === > 1 -> 2 -> 3

package main

import (
	"fmt"
)

type _sortList struct {
	val  int // 数据域
	next *_sortList
}

// 移除有序 list 中重复的数据
func removeDumpEle(head *_sortList) *_sortList {
	if head == nil {
		return nil
	}
	// 构造一个 新的 head
	newHead := &_sortList{}
	curr := newHead

	preVal := head.val
	tmp := &_sortList{val: preVal}
	curr.next = tmp
	curr = curr.next
	for h := head.next; h != nil; h = h.next {
		// 如果当前的数据域和上一个数据域不相等, 将数据域亦如新的head的尾部
		if h.val != preVal {
			// 重新赋值上一个节点的数据域
			preVal = h.val
			tmp := &_sortList{val: h.val}
			curr.next = tmp
			curr = curr.next
		}
	}
	// 返回新链表的头节点
	return newHead.next

}
func main() {
	head := &_sortList{val: 1, next: &_sortList{val: 1, next: &_sortList{val: 2, next: &_sortList{val: 2, next: &_sortList{val: 3}}}}}
	head = removeDumpEle(head)
	for h := head; h != nil; h = h.next {

		fmt.Print(h.val, " ")
	}
}
