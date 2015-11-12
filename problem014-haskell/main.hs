max' (a,a1) (b, b1) = if a1 > b1
    then (a,a1)
    else (b,b1)

memoized_collatz = (map collatz [0 ..] !!)
   where collatz 1 = 1 
         collatz n = if x' > 1000000
                then 1 + (collatz x')
                else 1 + (memoized_collatz x')
            where x' = if even n then n `div` 2 else 3 * n + 1


main = print $ take 10 memoized_collatz
--main = print $ take 100 memoized_collatz
--main = print $ foldr max' (0, 0) (map (\x -> (x, memoized_collatz x)) [1..1000])