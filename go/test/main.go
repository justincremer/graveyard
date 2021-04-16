package main

import (
	"./utils"
	"fmt"
)

func main() {
	for i := 1; i <= 20; i++ {
		fmt.Println("Factorial", i, ":", fact(i))
	}
}
