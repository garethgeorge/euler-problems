
numberToListRev' :: (Integral b) => b -> b -> [b]
numberToListRev' b 0 = []
numberToListRev' b n = (n `rem` b) : (numberToListRev' b (n `div` b))
