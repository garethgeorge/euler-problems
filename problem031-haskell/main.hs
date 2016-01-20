denominations = [1, 2, 5, 10, 20, 50, 100, 200]

-- build function nicely
waysCompiler :: (Int -> Int) -> Int -> (Int -> Int)
waysCompiler waysLast denom = newWays
    where newWays n | n >= denom = (waysLast n) + (newWays (n - denom))
                    | otherwise = waysLast n

-- variable name needs work
waysPerDenomination = ways1 : gen ways1 (tail denominations)
    where ways1 :: Int -> Int
          ways1 n = 1
          gen :: (Int -> Int) -> [Int] -> [(Int -> Int)]
          gen lastFunc [] = []
          gen lastFunc (x:xs) = newFunc : gen newFunc xs
                        where newFunc = waysCompiler lastFunc x 

ways = last waysPerDenomination

main = print $ ways 200