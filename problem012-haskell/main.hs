import Data.Numbers.Primes

fitz :: Int -> Int -> Int
fitz n p | n `rem` p == 0 = 1 + fitz (n `div` p) p
         | otherwise = 0

factors' n = sum [1 | x <- [1..n], n `rem` x == 0]

pow n 1 = n
pow n p = n * pow n (p - 1)

factorsAndPowers n = primeFactorization' n primes
  where primeFactorization' 1 _ = []
        primeFactorization' n (p:ps) | l /= 0 = (p, l) : (primeFactorization' (n `div` (p ^ l)) ps)
                                     | otherwise = (primeFactorization' (n `div` (p ^ l)) ps)
          where l = fitz n p

rebuildFromFactors [] = 1
rebuildFromFactors ((n, p):fs) = n ^ p * rebuildFromFactors fs

factorCount [] = 1
factorCount ((n,p):fs) = (p + 1) * factorCount fs

factorCount' n = factorCount $ factorsAndPowers n

triangleNumbers = [x * (x + 1) | x <- [1..]]
triangleNumbersAndFactorCounts = [(x, factorCount' x) | x <- triangleNumbers]


main = print $ foldr (&&) True $ map (\n -> (factorCount' n) == (factors' n)) [10000..11000]
-- main = print $ factorCount' 76576500
-- main = print $ factorCount' 76576500
-- main = print $ head $ filter (\x -> snd(x) >= 500) triangleNumbersAndFactorCounts

