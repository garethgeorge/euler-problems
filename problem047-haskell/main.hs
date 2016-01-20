import Data.Numbers.Primes

myPrimeFactors n = primeFactors' n primes
    where primeFactors' 0 _ = []
          primeFactors' 1 _ = []
          primeFactors' n (p:ps) | n `rem` p == 0 = p : primeFactors' (n `div` p) (p:ps)
                                 | otherwise = primeFactors' n ps

unique [] = []
unique [a] = [a]
unique (a:b:as) | a == b = unique (b:as)
                | otherwise = a : unique (b:as)

primeFactorizations = map (unique . myPrimeFactors) [1..]
primeFactorizationCounts = map length primeFactorizations

findNConseqMatches n func = lookHere
    where lookHere (a:as) = if func a
                                then if lookAhead 1 as
                                        then a : take (n - 1) as
                                        else lookHere as
                                else lookHere as
          lookAhead count (a:as) = if count == n
                                       then True
                                       else if func a
                                                then lookAhead (count + 1) as
                                                else False

main = print $ (findNConseqMatches 4 (\(a, b) -> b == 4)) (zip [1..] primeFactorizationCounts)