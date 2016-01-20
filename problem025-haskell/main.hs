fibseq' :: Integer -> Integer -> [Integer]
fibseq' a b = (a + b) : fibseq' b (a + b)
fibseq = 1 : 1 : (fibseq' 1 1)

containsDigits :: Integer -> Integer -> Bool
containsDigits n a = a >= 10 ^ (n - 1)

main = do
    putStrLn $ "first 100 fib numbers: "
    print $ snd $ head $ dropWhile (\(n, i) -> not (containsDigits 1000 n)) (zip fibseq [1..])