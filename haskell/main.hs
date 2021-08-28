import Data.List

fac :: Int -> Int
fac n = product [1 .. n]

main :: IO ()
main = print $ fac 10
