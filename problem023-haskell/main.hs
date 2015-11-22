import Data.Numbers.Primes
import Control.DeepSeq
import Data.List
import Data.Time

-- really fast proper divisers

unique' [] = []
unique' [a] = [a]
unique' (a:b:bs) = if a == b
                    then unique' (b:bs)
                    else a : unique' (b:bs)


properDivisors n = properDivisors' n (floor $ sqrt $ fromIntegral n)
    where  properDivisors' n 0 = []
           properDivisors' n 1 = [1]
           properDivisors' n a = if n `rem` a == 0
                                    then if a /= n `div` a
                                        then a : (n `div` a) : properDivisors' n (a - 1)
                                        else a : properDivisors' n (a - 1)
                                    else properDivisors' n (a - 1)

lPrimes' (x:xs) = x : lPrimes' [n | n <- xs, n `mod` x /= 0]
lPrimes = lPrimes' [2..]


properDivisorsSum n = sum $ properDivisors n

isAbundant n = (properDivisorsSum n) > n
abundantNumbers = filter isAbundant [1..]

abundantPairsLessThan n = takeWhile (<=n) (unique' $ sort $ bldr abundantSet abundantSet)
    where abundantSet = takeWhile (<=n) abundantNumbers
          bldr [] [] = []
          bldr [_] [] = []
          bldr (a:a':as) [] = bldr (a':as) (a':as)
          bldr (a:as) (b:bs) = a + b : (bldr (a:as) bs)

main = do
  start <- getCurrentTime
  print $ take 1000 lPrimes
  end <- getCurrentTime
  print $ take 1000 primes 
  end2 <- getCurrentTime

  print $ diffUTCTime end start
  print $ diffUTCTime end2 end

  let bound = 28123
  let sumsOfAbundants = sum $ abundantPairsLessThan bound
  let sumsOfIntegers = bound * (bound + 1) `div` 2
  print $ sumsOfIntegers - sumsOfAbundants
