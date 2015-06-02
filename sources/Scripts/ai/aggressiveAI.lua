-- aggressiveAI.lua

--TODO (cpp) : avant de serialiser la map : on définit les zones de danger en priorité)

--TODO : 1) Si sur une case 4 (DangerZone) ou 6(Bomb) : GTFO
--	 2) Si aligné à un joueur : On le bombe! (verifier si on peut se casser ;D)
--	 3) Si un bonus dans le coin : On va marcher dessus.
--	 4) Si un path est clear vers un joueur : on y va. Sinon, on se rapproche du mur cassable entre nous et on le bombe.

--HOWTO GTFO : On check les 4 cases autour de nous. Si l'une est safe, on y va. Sinon, on regarde que la case du haut est ateignable. Si oui, on recommence la verif, si non, on va a droite, puis gauche, puis bas.

--MAP : 
    -- FLOOR = 0,
    -- BRKWALL = 1,
    -- UBRKWALL = 2,
    -- MAPWALL = 3,
    -- Bonus : 10-19
    -- Gens : 20-29
    -- DANGER : 30

function act (map, width, height, selfx, selfy)
   pos = selfx * selfy + selfx

   if (map[pos] > 29) then --Survie de l'IA
      if (map[pos + width] == 0 or (map[pos + width] > 9 and map[pos + width] < 20)) then
	 --go up
      elseif (map[pos + 1] == 0 or (map[pos + 1] > 9 and map[pos + 1] < 20)) then
	 --go right
      elseif (map[pos - 1] == 0 or (map[pos - 1] > 9 and map[pos - 1] < 20)) then
	 --go left
      elseif (map[pos - width] == 0 or (map[pos - width] > 9 and map[pos - width] < 20)) then
	 -- go bot
      end
   end -- Survie
   
--posage de bombe
   if (map[pos + width] > 19 and map[pos + width] < 30) then
      --on bombe
   end
   if (map[pos + width] < 3 and (map[pos + (2 * width)] > 19 and map[pos + (2 * width)] < 30)) then
      --on bombe
   end
   if (map[pos + width] < 3 and map[pos + (2 * width)] < 3 and (map[pos + (3 * width)] > 19 and map[pos + (3 * width)] < 30)) then
      --on bombe 
   end

   if (map[pos - width] > 19 and map[pos - width] < 30) then
      --on bombe
   end
   if (map[pos - width] < 3 and (map[pos - (2 * width)] > 19 and map[pos - (2 * width)] < 30)) then
      --on bombe
   end
   if (map[pos - width] < 3 and map[pos - (2 * width)] < 3 and (map[pos - (3 * width)] > 19 and map[pos - (3 * width)] < 30)) then
      --on bombe
   end

   if (map[pos + 1] > 19 and map[pos + 1] < 30) then
      --on bombe
   end
   if (map[pos + 1] < 3 and (map[pos + (2 * 1)] > 19 and map[pos + (2 * 1)] < 30)) then
      --on bombe
   end
   if (map[pos + 1] < 3 and map[pos + (2 * 1)] < 3 and (map[pos + (3 * 1)] > 19 and map[pos + (3 * 1)] < 30)) then
      --on bombe 
   end

   if (map[pos - 1] > 19 and map[pos - 1] < 30) then
      --on bombe
   end
   if (map[pos - 1] < 3 and (map[pos - (2 * 1)] > 19 and map[pos - (2 * 1)] < 30)) then
      --on bombe
   end
   if (map[pos - 1] < 3 and map[pos - (2 * 1)] < 3 and (map[pos - (3 * 1)] > 19 and map[pos - (3 * 1)] < 30)) then
      --on bombe
   end
--fin posage de bombe

--recolte de bonus
   if (map[pos + width] > 9 and map[pos + width] < 20) then
      --on recolte
   end
   if (map[pos + width] < 3 and (map[pos + (2 * width)] > 9 and map[pos + (2 * width)] < 20)) then
      --on recolte
   end
   if (map[pos + width] < 3 and map[pos + (2 * width)] < 3 and (map[pos + (3 * width)] > 9 and map[pos + (3 * width)] < 20)) then
      --on recolte 
   end

   if (map[pos - width] > 9 and map[pos - width] < 20) then
      --on recolte
   end
   if (map[pos - width] < 3 and (map[pos - (2 * width)] > 9 and map[pos - (2 * width)] < 20)) then
      --on recolte
   end
   if (map[pos - width] < 3 and map[pos - (2 * width)] < 3 and (map[pos - (3 * width)] > 9 and map[pos - (3 * width)] < 20)) then
      --on recolte
   end

   if (map[pos + 1] > 9 and map[pos + 1] < 20) then
      --on recolte
   end
   if (map[pos + 1] < 3 and (map[pos + (2 * 1)] > 9 and map[pos + (2 * 1)] < 20)) then
      --on recolte
   end
   if (map[pos + 1] < 3 and map[pos + (2 * 1)] < 3 and (map[pos + (3 * 1)] > 9 and map[pos + (3 * 1)] < 20)) then
      --on recolte 
   end

   if (map[pos - 1] > 9 and map[pos - 1] < 20) then
      --on recolte
   end
   if (map[pos - 1] < 3 and (map[pos - (2 * 1)] > 9 and map[pos - (2 * 1)] < 20)) then
      --on recolte
   end
   if (map[pos - 1] < 3 and map[pos - (2 * 1)] < 3 and (map[pos - (3 * 1)] > 9 and map[pos - (3 * 1)] < 20)) then
      --on recolte
   end

--fin recolte bonus

-- movement

delta = 0
distance = 0
closestDistance = 0
closest = -1

   for i = 0, (width * height) do
      if (map[i] > 19 and map[i] < 30) then
	 delta = math.abs(pos - i)
	 distance = ((delta / width) - 2 + (delta % width) )
	 if (closest = -1 or distance < closestDistance) then
	    closestDistance = distance
	    closest = i
	 end
      end
   end
   
   if (pos - closest > 0) then -- au dessus ou a gauche
      if (pos - closest < width) then -- a gauche!
	 if (map[pos - 1] == 0) then
	    --go left
	 end
	 if (map[pos - 1] == 1) then
	    --on bombe le mur!
	 end
	 if (map[pos - 1] == 2) then
	    if (map[pos - width] == 0) then
	       -- go top pour contourner
	    end
	    if (map[pos - width] == 1) then
	       --on bombe le mur pour contourner l'obstacle indestructible
	    end
	    if (map[pos + width] == 0) then
	       -- go bot pour contourner
	    end
	    if (map[pos + width] == 1) then
	       --on bombe le mur pour contourner l'obstacle indestructible
	    end
	 end --end gauche
      else -- au dessus!
	 if (map[pos - width] == 0) then
	    -- go top
	 end
	 if (map[pos - width] == 1) then
	    --on bombe le mur!
	 end
	 if (map[pos - width] == 2) then
	    if (map[pos - 1] == 0) then
               -- go left pour contourner
            end
            if (map[pos - 1] == 1) then
               --on bombe le mur pour contourner l'obstacle indestructible
            end
            if (map[pos + 1] == 0) then
               -- go right pour contourner
            end
            if (map[pos + 1] == 1) then
               --on bombe le mur pour contourner l'obstacle indestructible
            end
	 end
      end -- end au dessus

   else -- en dessous ou a droite!

      if (closest - pos < width) then -- a droite!
	 if (map[pos + 1] == 0) then
	    --go right
	 end
	 if (map[pos + 1] == 1) then
	    --on bombe le mur!
	 end
	 if (map[pos + 1] == 2) then
	    if (map[pos - width] == 0) then
	       -- go top pour contourner
	    end
	    if (map[pos - width] == 1) then
	       --on bombe le mur pour contourner l'obstacle indestructible
	    end
	    if (map[pos + width] == 0) then
	       -- go bot pour contourner
	    end
	    if (map[pos + width] == 1) then
	       --on bombe le mur pour contourner l'obstacle indestructible
	    end
	 end --end gauche
      else -- en dessous!
	 if (map[pos + width] == 0) then
	    -- go bot
	 end
	 if (map[pos + width] == 1) then
	    --on bombe le mur!
	 end
	 if (map[pos + width] == 2) then
	    if (map[pos - 1] == 0) then
               -- go left pour contourner
            end
            if (map[pos - 1] == 1) then
               --on bombe le mur pour contourner l'obstacle indestructible
            end
            if (map[pos + 1] == 0) then
               -- go right pour contourner
            end
            if (map[pos + 1] == 1) then
               --on bombe le mur pour contourner l'obstacle indestructible
            end
	 end
      end -- end au dessus
      

   end --end dessous ou droite

--fin mouvement

	 print("Aggressive AI ready")

--deltapos / largeur - 2 + deltapos % largeur;

end
