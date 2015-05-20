-- map1.lua

-- 3 = bord de map
-- 2 = mur indestructible
-- 1 = mur destructible
-- 0 = sol


function generateMap(width, height)

w = {}
h = {}

	 for x = 1, width do
	     for y = 1, height do
	     	 if (x == 1 or y == 1 or (x == width) or (y == height)) then
		    w[y] = 3
		 else
		   if (x == 2 or y == 2 or (x == width - 1) or (y == height - 1)) then
		      w[y] = math.floor(rand()*2) --nb entre 0 et 1
		   else
			w[y] = math.floor(rand()*3) --nb entre 0 et 2
		   end
		 end
	     print("x = "..x.." y = "..y.." val = "..w[y])
	     end
	     print("\n")
	     h[x] = w
	 end
	 print("Map1 ready")
	 print("   "..#h)
	 for b, n in pairs(h) do
	     print("b = "..b)
	     for k, v in pairs(h[b]) do print(k, v) end
	     print("\n")
	 end
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

generateMap(10,10)
