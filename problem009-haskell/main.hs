import Control.Monad
import Data.Fixed

createList = map nicerTupple $ filter myFilter [(a, third c a, c) | c <- [1..], a <- [1..c]]
    where third c a = sqrt (c * c - a * a)
          myFilter (a, b, c) = b /= 0 && (mod' b 1) == 0
          nicerTupple (a, b, c) = (floor a, floor b, floor c)

condition (a, b, c) = a + b + c == 1000
product' (a, b, c) = a * b * c

main = print $ product' $ head $ filter condition (createList)