(define (if-program condition if-true if-false)
  `(if ,condition ,if-true ,if-false))

(define (square n) (* n n))

(define (pow-expr base exp)
  (if (= 0 exp)
    1
    (if (= 1 exp)
      `(* ,base 1)
    (if (odd? exp)
      (list `* base (pow-expr base (- exp 1)))
      (list `square (pow-expr base (/ exp 2)))
      )
      )
    ))

(define-macro (repeat n expr)
  `(repeated-call ,n (lambda () ,expr)))

; Call zero-argument procedure f n times and return the final result.
(define (repeated-call n f)
  (if (= n 1)
      (f)
      (begin (f) (repeated-call (- n 1) f))))
