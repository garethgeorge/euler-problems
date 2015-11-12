import Data.Numbers.Primes

prime_factors :: Int -> [Int]
prime_factors 1 = []
prime_factors n
  | factors == []  = [n]
  | otherwise = factors ++ prime_factors (n `div` (head factors))
  where factors = take 1 $ filter (\x -> (n `mod` x) == 0) [2 .. n-1]

main = do
    let bigAssNumber = 600851475143
    let biggest = maximum $ prime_factors bigAssNumber
    print biggest
