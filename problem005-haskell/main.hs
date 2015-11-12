gcd' :: (Integral a) => a -> a -> a
gcd' a 0 = a
gcd' a b = gcd b (a `mod` b)

lcm' :: (Integral a) => a -> a -> a
lcm' _ 0 =  0
lcm' 0 _ =  0
lcm' x y =  abs ((x `quot` (gcd' x y)) * y)

main = print $ foldr lcm' 1 [1..20]