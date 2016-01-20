import Data.Numbers.Primes
import Data.List

inRange a b = takeWhile b . dropWhile (not . a)

fourDigitPrimes = inRange (>1000) (<10000) primes

digitsToList 0 = []
digitsToList n = (n `rem` 10) : digitsToList (n `div` 10)

allTheSame xs = and $ map (== head xs) (tail xs)

numbersArePermutations :: [Int] -> Bool
numbersArePermutations = (allTheSame . (map (sort . digitsToList)))

checkForSetsThatWork = working
    where possibilities = [[a, b, 2 * b - a] | a <- fourDigitPrimes, b <- fourDigitPrimes, a < b, isPrime (2 * b - a)]
          working = [list | list <- possibilities, numbersArePermutations list]

concatListsAsString =  concat . map show

main = print $ (map concatListsAsString) $ checkForSetsThatWork 