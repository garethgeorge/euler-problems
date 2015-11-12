toString :: Int -> String
toString a = show a

isPalendrome :: Int -> Bool
isPalendrome a = theCheck $ toString a
    where theCheck a = (reverse a) == a

cartProd xs ys = [(x,y) | x <- xs, y <- ys]

main = do
    let theRange = [100..999]
    let prod = cartProd theRange theRange
    let tuppleProduct a = (fst a) * (snd a)

    let products = map tuppleProduct prod 

    let palendromeProducts = filter isPalendrome products

    print $ maximum palendromeProducts
