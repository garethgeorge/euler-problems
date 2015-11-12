-- must be two infinite lists.

cp as bs = [(as !! i, bs !! (n - i)) | n <- [0..], i <- [0..n]]

d :: Integer -> Integer
d n = sum [a | a <- [1..(n-1)], n `rem` a == 0]
d' = map d [1..]

areAmicable :: (Int, Int) -> Bool
areAmicable (a,b) = (d' !! a) == b && (d' !! b) == a

amicablePairs = filter areAmicable (cp [1..] [1..])
main = print $ take 3 amicablePairs
--main = print $ take 10 amicablePairs
