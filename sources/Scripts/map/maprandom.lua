-- map1.lua

-- 3 = bord de map
-- 2 = mur indestructible
-- 1 = mur destructible
-- 0 = sol

math.randomseed(os.time())

function serializeMap(width, height)
   w = {}

   for x = 1, width do
      for y = 1, height do
	    if (x == 2 or y == 2 or (x == width - 1) or (y == height - 1)) then
	       w[y] = math.floor(math.random()*2) --nb entre 0 et 1
	    else
	       w[y] = math.floor(math.random()*3) --nb entre 0 et 2
	    end
	 if (x == 1 or y == 1 or (x == width) or (y == height)) then
	    w[y] = 3
	 end
	 if res == nil then
	    res = w[y]
	 else
            res = res..w[y]
         end
      end

   end
   --print(res)
   return(res)
end
