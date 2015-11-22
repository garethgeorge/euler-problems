import Data.List

toNumber xs = sum [x * (10 ^ y) | (x, y) <- (zip (reverse xs) [0,1..])]
main = do
    let p = permutations [0,1,2,3,4,5,6,7,8,9]
    let p' = map toNumber (sort p)
    print $ p' !! (1000000 - 1)