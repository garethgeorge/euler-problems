-- isCool 1:_:2:_:3:_:4:_:5:_:6:_:7:_:8:_:9:_:[] = True
-- isCool [1,_,2,_,3,_,4,_,5,_,6,_,7,_,8,_,9,_] = True
isCool [_,9,_,8,_,7,_,6,_,5,_,4,_,3,_,2,_,1] = True
isCool _ = False

listify 0 = []
listify n = n `rem` 10 : listify (n `div` 10)

theAnswer = [x | x <- [(10^(18 `div` 2))..(10^(18 `div` 2 + 1))], isCool $ listify (x * x)]

main = print $ theAnswer
