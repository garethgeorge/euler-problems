routes = [[routes' x y | x <- [0..]] | y <- [0..]]
        where routes' 0 0 = 1
              routes' 0 y = routes !! (y - 1) !! 0
              routes' x 0 = routes !! 0 !! (x - 1)
              routes' x y = (routes !! (y - 1) !! x) + (routes !! y !! (x - 1))

printGrid [] = print "Done."
printGrid (x:xs) = do
    putStrLn $ show (x)
    printGrid xs
main = printGrid $ take 20 $ map (take 20) routes
-- answer: 137846528820 