factorial 0 = 1
factorial n = n * (factorial (n - 1))

sumdigits :: Integer -> Integer
sumdigits 0 = 0
sumdigits n = (n `rem` 10) + sumdigits (n `div` 10)


main = print $ sumdigits $ factorial 100
