package utils

func fact(x int) (fx int) {
	if x <= 1 {
		return 1
	}

	return x * fact(x-1)
}
