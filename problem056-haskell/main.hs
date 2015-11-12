

-- considdering natural numbers of the form a^b where a, b < 100 what is the maximum digital sum?

import Data.Char

max' :: (Ord a) => a -> a -> a
max' a b | a > b = a
         | otherwise = b

sumDigits n = sum $ [ord n'' - ord '0' | n'' <- (show n)] 

maxDigSum a p 100 = 0
maxDigSum a p b = max' (sumDigits a) (maxDigSum p (a*p) (b+10))

main = do print $ maxDigSum 10 1 0
