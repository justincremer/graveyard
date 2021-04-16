package main

import (
	"container/heap"
	"fmt"
	"time"

	"xiubox.io/heap/pq"
	"xiubox.io/heap/reg"
)

func testReg() {
	h := &reg.IntHeap{2, 1, 5, 4, 7, 6}
	heap.Init(h)
	heap.Push(h, 3)
	fmt.Printf("minimum: %d\n", (*h)[0])
	for h.Len() > 0 {
		time.Sleep(time.Millisecond * 200)
		fmt.Printf("%d ", heap.Pop(h))
	}
}

func testPq() {
	items := map[string]int{
		"banana": 3, "apple": 2, "pear": 4,
	}

	queue := make(pq.PriorityQueue, len(items))
	i := 0

	for value, priority := range items {
		queue[i] = &pq.Item{
			Value:    value,
			Priority: priority,
			Index:    i,
		}
		i++
	}
	heap.Init(&queue)

	item := &pq.Item{
		Value:    "orange",
		Priority: 1,
	}
	heap.Push(&queue, item)
	queue.Update(item, item.Value, 5)

	item = &pq.Item{
		Value:    "cherry",
		Priority: 1,
	}
	heap.Push(&queue, item)

	for len(queue) > 0 {
		item := heap.Pop(&queue).(*pq.Item)
		fmt.Printf("%.2d:%s ", item.Priority, item.Value)
	}
}

func main() {
	testReg()
	time.Sleep(time.Second)
	fmt.Print("\033[H\033[2J")
	testPq()
}
