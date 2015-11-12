import Data.Numbers.Primes
import Control.DeepSeq
import Data.List

-- really fast proper divisers
properDivisors'' n' = properDivisors n' primes
    where   properDivisors :: Int -> [Int] -> [Int]
            properDivisors 1 (p:ps) = [1]
            properDivisors n (p:ps) | p >= n' = [1]
                                    | n `rem` p == 0 = properDivisors' n 1 (p:ps)
                                    | otherwise = properDivisors n ps
                where properDivisors' n n' (p:ps) | n `rem` p == 0 = (n' * p) : (properDivisors' (n `div` p) (n' * p) (p:ps))
                                                  | otherwise = properDivisors n ps

properDivisors' :: Int -> [Int]
properDivisors' n = [x | x <- [1..(sqrt $ fromIntegral n)], n `rem` x == 0]

properDivisorsSum :: Int -> [Int] -> Int
properDivisorsSum 1 (p:ps) = 1
properDivisorsSum n (p:ps) | n `rem` p == 0 = properDivisors' n 1 (p:ps)
                           | otherwise = properDivisorsSum n ps
    where properDivisors' n n' (p:ps) | n `rem` p == 0 = (n' * p) + (properDivisors' (n `div` p) (n' * p) (p:ps))
                                      | otherwise = properDivisorsSum n ps




isAbundant n = (properDivisorsSum n primes) > n
abundantNumbers = filter isAbundant [1..]

sumsOfAbundantPairsLessThan n = bldr abundantSet abundantSet
    where abundantSet = takeWhile (<=(ceiling $ n / 2)) abundantNumbers
          bldr [] [] = []
          bldr [_] [] = []
          bldr (a:a':as) [] = bldr (a':as) (as)
          bldr (a:as) (b:bs) = a + b : (bldr (a:as) bs)

main = do
    print $ sort $ properDivisors'' 24 
    print $ sort $ properDivisors' 24