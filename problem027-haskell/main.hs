import Data.Numbers.Primes
f :: Int -> Int -> Int -> Int
f a b n = n * n + a * n + b

primeyness :: (Int -> Int) -> Int
primeyness fn = length $ takeWhile isPrime (map fn [0..])

max' a b = if a > b then a else b

main = print $ foldr max' (0, 0) [(primeyness (f a b), a * b) | a <- [-1000..1000], b <- [-1000..1000]]
