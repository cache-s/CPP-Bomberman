-- map1.lua

-- 3 = bord de map
-- 2 = mur indestructible
-- 1 = mur destructible
-- 0 = sol

math.randomseed(os.time())

function generateMap(width, height)
   w = {}
   h = {}

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
      -- if res == nil then
      -- 	 res = w[1].." "
      -- else
      -- 	 for i = 1, width do
      -- 	    res = res..w[i].." "
      -- 	 end
      -- end
     --end
   print("Map1 ready")
   print(res)
   -- for b = 1, height do
   --    for k,v in pairs(h[b]) do print(k,v) end
--    end
end


generateMap(10,10)