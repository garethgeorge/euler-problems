import Data.Numbers.Primes
import Data.List

-- this can concat some pretty bloody big numbers
concatNumbers a b = floor $ a * 10 ^ (ceiling (logBase 10 b)) + b

-- any pair concatinated in any direction is still prime.
-- this about n ^ 2 - n run time.
isAnAwesomeSet [] = True
isAnAwesomeSet (a:as) = (stillAwesome as) && (isAnAwesomeSet as)
    where stillAwesome [] = True
          stillAwesome (b:bs) = if (isPrime $ concatNumbers a b) && (isPrime $ concatNumbers b a)
                                    then stillAwesome bs
                                    else False

dot as bs = [(as !! i, bs !! (n - i)) | n <- [0..], i <- [0..n]]


flatten4 (a, (b, (c, d))) = (a, b, c, d)
dot4 as bs cs ds = map flatten4 $ dot as (dot bs (dot cs ds))

flatten5 (a, (b, (c, (d, e)))) = (a, b, c, d, e)
dot5 as bs cs ds es = map flatten5 $ dot as (dot bs (dot cs (dot ds es)))
sss  s ss sss sss sss sss sss sss sss sss ss sss sss ssssß

sum5 (a, b, c, d, e) = a + b + c + d + e

main = print $ map sum5 (dot5 [1..] [1..] [1..] [1..] [1..])