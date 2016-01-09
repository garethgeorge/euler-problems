sequence' = map (\x -> x ^ x) [1..]

sumCountFromSeq n seq = sum $ take n $ seq
takeLastNDigits n = (`rem`(10 ^ n))

main = print $ takeLastNDigits 10 $ sumCountFromSeq 1000 sequence'
