-- aggressiveAI.lua

--NEWMAP
    -- FLOOR = 0,
    -- BRKWALL = 1,
    -- UBRKWALL = 2,
    -- MAPWALL = 3,
    -- BONUS = 4,
    -- PPL = 5
    -- DANGER = 6

-- UP = 104,
-- DOWN = 105,
-- LEFT = 106,
-- RIGHT = 107,


function move(sMap, width, height, selfx, selfy)
   
   local map = {}
   local chara
   local pos

   pos = (width * selfy) + selfx + 1

   for i = 1, string.len(sMap) do
      chara = string.sub(sMap, i, i)
      map[i] = tonumber(chara)
   end

   if (map[pos] == 6) then --Survie de l'IA
      if (map[pos + width] == 0 or (map[pos + width] == 4)) then
	 return(104)
      elseif (map[pos + 1] == 0 or (map[pos + 1] == 4)) then
	 return(106)	 --go right
      elseif (map[pos - 1] == 0 or (map[pos - 1] == 4)) then
	 return(107)	 --go left
      elseif (map[pos - width] == 0 or (map[pos - width] == 4)) then
	 return(105)	 -- go bot
      end
      ret = math.floor((math.random()* 4) + 104)
      return (ret)
   end -- Survie

   if ((map[pos + width] ~= 0 and map[pos + width] ~= 4) and (map[pos - width] ~= 0 and map[pos - width] ~= 4) and (map[pos + 1] ~= 0 and map[pos + 1] ~= 4) and (map[pos - 1] ~= 0 and map[pos - 1] ~= 4)) then
      return (404) --on bouge pas!
   end

   --posage de bombe
   if (map[pos + (width)]) then 
      if (map[pos + width] == 5) then
	 return(101) --on bombe
      end
   end
      if (map[pos + (2 * width)]) then 
      if (map[pos + width] < 3 and (map[pos + (2 * width)] == 5)) then
	 return(101) --on bombe
      end
   end
   if (map[pos + (3 * width)]) then 
      if (map[pos + width] < 3 and map[pos + (2 * width)] < 3 and (map[pos + (3 * width)] == 5)) then
	 return(101) --on bombe 
      end
   end

   if (map[pos - (width)]) then 
      if (map[pos - width] == 5) then
	 return(101) --on bombe
      end
   end
   if (map[pos - (2 * width)]) then 
      if (map[pos - width] < 3 and (map[pos - (2 * width)] == 5)) then
	 return(101) --on bombe
      end
   end

   if (map[pos - (3 * width)]) then 
      if (map[pos - width] < 3 and map[pos - (2 * width)] < 3 and (map[pos - (3 * width)] == 5)) then
	 return(101) --on bombe
      end
   end
   
   if (map[pos + 1]) then 
      if (map[pos + 1] == 5) then
	 return(101) --on bombe
      end
   end
   if (map[pos + 2]) then 
      if (map[pos + 1] < 3 and (map[pos + (2 * 1)] == 5)) then
	 return(101) --on bombe
      end
   end
   if (map[pos + 3]) then 
      if (map[pos + 1] < 3 and map[pos + (2 * 1)] < 3 and (map[pos + (3 * 1)] == 5)) then
	 return(101) --on bombe 
      end
   end
   
   if (map[pos - 1]) then 
      if (map[pos - 1] == 5) then
	 return(101) --on bombe
      end
   end   
   if (map[pos - 2]) then 
      if (map[pos - 1] < 3 and (map[pos - (2 * 1)] == 5)) then
	 return(101) --on bombe
      end
   end
   if (map[pos - 3]) then 
      if (map[pos - 1] < 3 and map[pos - (2 * 1)] < 3 and (map[pos - (3 * 1)] == 5)) then
	 return(101) --on bombe
      end
   end
   --fin posage de bombe
   
   --recolte de bonus
   if (map[pos + (width)]) then 
      if (map[pos + width] == 5) then
	 return(105) --on recolte
      end
   end
   if (map[pos + (2 * width)]) then 
      if (map[pos + width] < 1 and (map[pos + (2 * width)] == 4)) then
	 return(105)--on recolte
      end
   end
   if (map[pos + (3 * width)]) then 
      if (map[pos + width] < 1 and map[pos + (2 * width)] < 1 and (map[pos + (3 * width)] == 4)) then
	 return(105)--on recolte 
      end
   end
   
   if (map[pos - (width)]) then 
      if (map[pos - width] == 4) then
	 return(104)--on recolte
      end
   end
   if (map[pos - (2 * width)]) then 
      if (map[pos - width] < 1 and (map[pos - (2 * width)] == 4)) then
	 return(104)--on recolte
      end
   end
   if (map[pos - (3 * width)]) then 
      if (map[pos - width] < 1 and map[pos - (2 * width)] < 1 and (map[pos - (3 * width)] == 4)) then
	 return(104)--on recolte
      end
   end
   if (map[pos + 1]) then 
      if (map[pos + 1] == 4) then
	 return(106)--on recolte
      end
   end
   if (map[pos + 2]) then 
      if (map[pos + 1] < 1 and (map[pos + (2 * 1)] == 4)) then
	 return(106)--on recolte
      end
   end
   if (map[pos + 3]) then 
      if (map[pos + 1] < 1 and map[pos + (2 * 1)] < 1 and (map[pos + (3 * 1)] == 4)) then
	 return(106)--on recolte 
      end
   end
    
   if (map[pos - 1]) then 
      if (map[pos - 1] == 4) then
	 return(107)--on recolte
      end
   end
   if (map[pos - 2]) then 
      if (map[pos - 1] < 1 and (map[pos - (2 * 1)] == 4)) then
	 return(107)--on recolte
      end
   end

   if (map[pos - 2]) then 
      if (map[pos - 1] < 1 and map[pos - (2 * 1)] < 1 and (map[pos - (3 * 1)] == 4)) then
	 return(107)--on recolte
      end
   end
   
   --fin recolte bonus
   
   -- movement
   
   delta = 0
   distance = 0
   closestDistance = 0
   closest = -1
   
   for i = 0, (width * height) do
      if (map[i] == 5 and i ~= pos) then
   	 delta = math.abs(pos - i)
   	 distance = ((delta / width) - 2 + (delta % width) )
   	 if (closest == -1 or distance < closestDistance) then
   	    closestDistance = distance
   	    closest = i
   	 end
      end
   end

   if (pos - closest > 0) then -- au dessus ou a gauche
      if (pos - closest) then
	 if (pos - closest < width) then
	    if (map[pos - 1] == 0) then
	       return(107)
	    end
	 end
	 if (map[pos - 1]) then
	    if (map[pos - 1] == 1) then
	       return(101) --on bombe le mur!
	    end
	 end
	 if (map[pos - 1]) then
	    if (map[pos - 1] == 2) then
	       if (map[pos - width] == 0) then
		  return(105)-- go top pour contourner
	       end
	    end
	    if (map[pos - width] ) then
	       if (map[pos - width] == 1) then
		  return(101) --on bombe le mur pour contourner l'obstacle indestructible
	       end
	    end
	    if (map[pos + width] ) then
	       if (map[pos + width] == 0) then
		  return(104)-- go bot pour contourner
	       end
	    end
	    if (map[pos + width] ) then
	       if (map[pos + width] == 1) then
		  return(101) --on bombe le mur pour contourner l'obstacle indestructible
	       end
	    end
	 end --end gauche
      else -- au dessus!
	 if (map[pos - width] == 0) then
	    return(105)-- go top
	 end
	 if (map[pos - width] == 1) then
	    return(101) --on bombe le mur!
	 end
	 if (map[pos - width] == 2) then
	    if (map[pos - 1] == 0) then
               return(107)-- go left pour contourner
            end
            if (map[pos - 1] == 1) then
               return(101) --on bombe le mur pour contourner l'obstacle indestructible
            end
            if (map[pos + 1] == 0) then
               return(106)-- go right pour contourner
            end
            if (map[pos + 1] == 1) then
               return(101) --on bombe le mur pour contourner l'obstacle indestructible
            end
	 end
      end -- end au dessus
   else -- en dessous ou a droite!
      if (closest - pos < width) then -- a droite!
	 if (map[pos + 1] == 0) then
	    return(106)--go right
	 end
	 if (map[pos + 1] == 1) then
	    return(101) --on bombe le mur!
	 end
	 if (map[pos + 1] == 2) then
	    if (map[pos - width] == 0) then
	       return(105)-- go top pour contourner
	    end
	    if (map[pos - width] == 1) then
	       return(101) --on bombe le mur pour contourner l'obstacle indestructible
	    end
	    if (map[pos + width] == 0) then
	       return(104)-- go bot pour contourner
	    end
	    if (map[pos + width] == 1) then
	       return(101) --on bombe le mur pour contourner l'obstacle indestructible
	    end
	 end --end gauche
      else -- en dessous!
	 if (map[pos + width] == 0) then
	    return(104)-- go bot
	 end
	 if (map[pos + width] == 1) then
	    return(101) --on bombe le mur!
	 end
	 if (map[pos + width] == 2) then
	    if (map[pos - 1] == 0) then
               return(107)-- go left pour contourner
            end
            if (map[pos - 1] == 1) then
               return(101) --on bombe le mur pour contourner l'obstacle indestructible
            end
            if (map[pos + 1] == 0) then
               return(106)-- go right pour contourner
            end
            if (map[pos + 1] == 1) then
               return(101) --on bombe le mur pour contourner l'obstacle indestructible
            end
	 end
      end -- end au dessus
   end --end dessous ou droite
   
   --fin mouvement

   return(101)

   --deltapos / largeur - 2 + deltapos % largeur;
end
