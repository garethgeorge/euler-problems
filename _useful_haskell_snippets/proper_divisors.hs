import Data.Numbers.Primes

-- really fast proper divisers
properDivisors 1 (p:ps) = []
properDivisors n (p:ps) | n `rem` p == 0 = properDivisors' n 1 (p:ps)
                        | otherwise = properDivisors n ps
    where properDivisors' n n' (p:ps) | n `rem` p == 0 = (n' * p) : (properDivisors' (n `div` p) (n' * p) (p:ps))
                                      | otherwise = properDivisors n ps



main = print $ properDivisors 20 primes