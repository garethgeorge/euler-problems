import Data.List.Split
import Data.Char
import Data.List

abcVal xs = sum [ord x - ord 'A' + 1| x <- xs]
scores xss = [i * (abcVal xs) | (xs, i) <- (zip (sort xss) [1..])]

main = do
    fdata <- readFile "names.txt"
    let names = splitOn "," fdata
    print $ sum $ scores names