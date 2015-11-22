import Data.List

unique' [] = []
unique' [a] = [a]
unique' (a:b:bs) = if a == b
                    then unique' (b:bs)
                    else a : unique' (b:bs)

main = do
    let numbers = [a ^ b | a <- [2..100], b <- [2..100]]
    print $ length $ unique' $ sort $ numbers
