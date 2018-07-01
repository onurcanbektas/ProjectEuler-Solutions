module Sim where
-- Add a constraint on the position of the Ant, i.e we shouln't have something like
-- (6,5)
import Data.Matrix
import Data.Random.Distribution.Uniform

type BMatrix = Matrix Bool

data Move = UP | DOWN | LEFT | RIGHT deriving (Show, Eq)

data Ant = Ant {position :: (Int, Int),
                isBagFull :: Bool,
                stepCount :: Int} deriving Show

data State = State {ant :: Ant,
                    grid :: BMatrix,
                    leftFood ::Int,
                    success :: Bool} deriving Show

--To main
gridZero :: BMatrix
gridZero = matrix 5 5 (\(i,j) -> False)
ant'' = Ant (5,5) True 1
stateZero = State ant'' gridZero 5 False
--

carryFood :: State -> State
carryFood x = x {ant = ant',grid = grid'} where
 ant' = (ant x) {isBagFull = True}
 grid' = setElem False (position . ant $ x ) (grid x)

leaveFood :: State -> State
leaveFood x = x {ant = ant', grid = grid'} where
 ant' = (ant x) {isBagFull = False}
 grid' = setElem True (position . ant $ x) (grid x)

checkMovability :: Ant -> Move -> Bool
checkMovability ant move
 | move == UP = if (snd . position $ ant) == 5
  then False
  else True
 | move == DOWN = if (snd . position $ ant) == 1
  then False
  else True
 | move == LEFT = if (fst . position $ ant) == 1
  then False
  else True
 | move == RIGHT = if (fst . position $ ant) == 5
  then False
  else True
 | otherwise = True

moveToDirection :: Ant -> Move -> Ant
moveToDirection ant move = ant' where
 ant' = ant {position = addTuples (position ant) (1,0)}

addTuples :: (Num a) => (a,a) -> (a,a) -> (a,a)
addTuples (x,y) (z,w) = (x+z, y+w)

checkSuccess :: State -> Bool
checkSuccess x = success x

