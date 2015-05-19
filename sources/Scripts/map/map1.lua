-- map1.lua

-- 3 = bord de map
-- 2 = mur indestructible
-- 1 = mur destructible
-- 0 = sol

function generate (width, height)

w = {}
h = {}

	 for x = 0, width do
	     for y = 0, height do
	     	 if (x == 0 or y == 0) then
		    w[x + 1] = 0
		 else
		   if (x == 1 or y == 1) then
		      w[x + 1] = math.floor(rand()*2) --nb entre 0 et 1
		   else
			w[x + 1] = math.floor(rand()*3) --nb entre 0 et 2
		   end
		 end
	     end
	     h[y + 1] = w
	 end
	 print("Map1 ready")

end


local A1, A2 = 727595, 798405  -- 5^17=D20*A1+A2
local D20, D40 = 1048576, 1099511627776  -- 2^20, 2^40
local X1, X2 = 0, 1
function rand()
    local U = X2*A2
    local V = (X1*A2 + X2*A1) % D20
    V = (V*D20 + U) % D40
    X1 = math.floor(V/D20)
    X2 = V - X1*D20
    return V/D40
end