import Data.Numbers.Primes

max' a b = if a > b then a else b

-- find the sums of the elements in the sequence
sequenceSums xs = primal' xs 0
    where primal' [] _ = []
          primal' (x:xs) sum = (x + sum) : (primal' xs (x + sum))

onlyPrimeSums xs = [(i, x) | (i, x) <- (zip [1..] xs), isPrime x]
biggestPrimeSum xs = last $ onlyPrimeSums xs

-- couldn't really think of a good function name / really tired right now.
thingy bound (x:xs) = if x > bound 
                        then (0, 0)
                        else if bps > bpss
                                then bps
                                else bpss
    where bps = biggestPrimeSum $ takeWhile (<=bound) (sequenceSums (x:xs))
          bpss = thingy bound xs

main = print $ thingy 1000000 primes
