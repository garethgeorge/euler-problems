divides n d = (n `div` d) : divides ((n - (n `div` d) * d) * 10) d

repeat' thing = repeat'' thing
    where repeat'' [] = repeat'' thing
          repeat'' (x:xs) = x : repeat'' xs

checkForRepeats' xs thing = check' (take ((length thing) * 3) (repeat' thing)) xs
    where check' [] [] = True
          check' [] _ = True
          check' _ [] = True
          check' (a:as) (b:bs) | a /= b = False
                               | otherwise = check' as bs

checkForRepeats xs n stop | n > stop = -1
                          | checkForRepeats' xs (take n xs) = n
                          | otherwise = checkForRepeats xs (n + 1) stop

repeats' xs = checkForRepeats xs 1 ((length xs) `div` 2)


repeats [x] = -1
repeats (x:xs) = if repeats' (x:xs) /= -1
                    then repeats' (x:xs)
                    else repeats xs

max' (n1, a) (n2, b) = if a > b then (n1, a) else (n2, b)

main = print $ foldr max' (-1, -1) $ (map (\n -> (n, (repeats $ take 1000 $ divides 1 n)))) [1..100]

-- main = print $ repeats $ take 100 $ divides 1 13
-- main = print $ repeats [1,2,1,2,1,2,1,2]
--main = print $ take 10000 $ divides 1 13

