import Data.Numbers.Primes

primes' = 1 : primes

-- everything that is not a prime.
composits :: [Int]
composits = composits' [2..] primes
    where composits' (n:ns) (p:ps) | n == p = composits' ns ps
                                   | otherwise = n : composits' ns (p:ps)
oddComposits :: [Int]
oddComposits = filter (\x -> x `rem` 2 == 1) composits

-- squares
squares :: [Int]
squares = map (\x -> x*x) [1..]

primeAndSquare :: Int -> [Int]
primeAndSquare n = filter (n==) [p + 2 * s | p <- (takeWhile (<=n) primes'), s <- (takeWhile (\a -> a * 2 <= n) squares)]

conjecture :: Int -> Bool
conjecture n = length (primeAndSquare n) > 0

firstThatViolates :: Int
firstThatViolates = head (filter (not . conjecture) oddComposits)

main = print $ firstThatViolates