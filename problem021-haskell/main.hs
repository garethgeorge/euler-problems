import Data.Numbers.Primes

sum_all_factors_primes 0 _ = 1
sum_all_factors_primes n (p:ps) | p * p > n = 1
                                | n `rem` p == 0 = sum_all_factors_primes_co (n `div` p) (p:ps) (p*p)
                                | otherwise = sum_all_factors_primes n ps
sum_all_factors_primes_co n (p:ps) j | n `rem` p == 0 = sum_all_factors_primes_co (n `div` p) (p:ps) (j * p)
                                     | otherwise = (sum_all_factors_primes n ps) * (j - 1) `div` (p - 1)

sum_all_factors n = sum [x | x <- (takeWhile )]

sum_all_factors n = sum [x | x <- [1..(n-1)], n `rem` x == 0]


main = do
    print $ (sum_all_factors_primes 123 primes)
    print $ sum_all_factors 123