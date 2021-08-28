(defun fib (n)
  "Returns the nth Fibonacci number"
  (if (< n 2)
	  n
	  (+ (fib (- n 1))
		 (fib (- n 2)))))

(defun many (n)
  (values n (* n 2) (* n 3)))

