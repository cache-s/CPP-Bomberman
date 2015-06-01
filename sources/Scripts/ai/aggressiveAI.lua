-- aggressiveAI.lua

--TODO : 1) Si sur une case 4 (DangerZone) ou 6(Bomb) : GTFO
--	 2) Si aligné à un joueur : On le bombe! (verifier si on peut se casser ;D)
--	 3) Si un bonus dans le coin : On va marcher dessus.
--	 4) Si un path est clear vers un joueur : on y va. Sinon, on se rapproche du mur cassable entre nous et on le bombe.

--HOWTO GTFO : On check les 4 cases autour de nous. Si l'une est safe, on y va. Sinon, on regarde que la case du haut est ateignable. Si oui, on recommence la verif, si non, on va a gauche, puis droite, puis bas.

function act (map, width, height, selfx, selfy)
pos = selfx * selfy + selfx


	 print("Aggressive AI ready")

end
