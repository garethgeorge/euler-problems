fibs = 0 : 1 : map fib [2..]
    where fib n = (fibs !! (n - 1)) + (fibs !! (n - 2))  

main = print $ sum $ filter myEven $ takeWhile (myLimit) (fibs)
    where myEven x = (x `rem` 2) == 0
          myLimit x = x < 4000000
