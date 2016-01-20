-- numbers that are the sum of the fifth powers of their digits

powersOfDigits p [] = 0
powersOfDigits p (x:xs) = (x ^ p) + (powersOfDigits p xs)

numberToListRev' :: (Integral b) => b -> b -> [b]
numberToListRev' b 0 = []
numberToListRev' b n = (n `rem` b) : (numberToListRev' b (n `div` b))

weLike p n = (powersOfDigits p list) == n
    where list = numberToListRev' 10 n

main = print $ sum $ [x | x <- [2..1000000], weLike 5 x]
