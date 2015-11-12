import Data.Char

sumdigits :: [Char] -> Int
sumdigits xs = sum [ord x - ord '0' | x <- xs]

main = print $ sumdigits  $ show $ 2 ^ 1000
