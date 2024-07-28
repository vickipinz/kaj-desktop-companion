// Dialog

// Dialog chains
OnAiTalk
{
	if RAND(100) < communicateratio
	{
		StartCommunicate
	}
	else
	{
		if mikireflag == 0
		{
			if CHAIN.IDName == "" {
				lastTalk = RandomTalk
			}
			else {
				lastTalk = ChainTalk
			}
			lastTalk
		}
		else
		{ 
			MikireTalk
		}
	}
}

// Random dialog
RandomTalk : nonoverlap_pool
{
	"\0\s[0]"
	--
	if dayslot == "9month 11day"
	{
		"THEY HIT THE FUCKING PENTAGON!!\e"
		"9/11 TAKIN OVER!!!\e"
		"\0\s[1911]TURN ON THE FUCKING NEWS AMERICA IS UNDER ATTACK!!!\e"
		"GOD BLESS THE USAAAAAAAAAAAAAAAAAAAAAAA!!!\e"
		"FREEDOM OF FREEDOM OF FREEDOM OF FREEDOM OF FREEDOM OF FREEDOM OF FREEDOM OF FREEDOM FREEDOM\e"
		"GOD GOD GOD GOD GOD GOD GOD GOD GOD GOD BLESS GOD BLESS GOD BLESS GOD GOD BLESS GOD BLEHGODBLEHGODBLEHGODBLEH GOD BLESS GOD GOD GOD GOD GOD GOD GOD BLESS\e"
		"HOLD YOU IN MY ARMS HOLD YOU IN MY ARMS\e"
		"HOLD YOU IN HOLD YOU HOLD YOU IN HOLD HOLD\e"
		"I JUST COULDN'T DOOOO\e"
		"I JUST COULDNT DO I JUST COULDNT DO I JUST COULDNT DO I JUST COULDNT DO\e"
		"GOD BLESS GOD BLESS GOD BLESS\n\n[half]THE USAAAAAAAAAAAAAAAAAAAAA\e"
		"GOD BLESS THE USAAAAAAAA!!!!!!!\e"
		"I WAS IN THE WOMB DURING 9/11...\w8\n\nYOU COULD SAY I HAVE FETAL AL-QAEDA SYNDROME\e"
		"IF U SAY '9/11' IN THE MIRROR 9 TIMES GEORGE W BUSH APPEARS\w8\w8\n\n[half]ACTUALLY NO I APPEAR\e"
	}
	else
	{
		"IM ANNOYING!!!\e"
		"WOOF!\e"
		"DAMN!!!\n\n[half]FUCK!!!\e"
		"HABBITY HOOBITY\e"
		"HEY HEY HEY DID U HEAR THE NEWS???\w9\n\ni like u a lot :3\e"
		"I DID 9\/11\e"
		"YOU CAN'T KILL ME!!! I'M JUST A LITTLE GUY!!!\e"
		"I LOVE YOU!!!!!!\e"
		"HI IM KAJ HI HI HI IM KAJ HELLO HEY HEY!!! HEY!!!! HI IM KAJ HI HI HI OK HI HELLO IM KAJ \s[1001]HI HI HEY HELLO IM KAJ HEY HEY HELLO IM KAJ HAI HAI HAI HAI HEYYY :3 HAII :3 HAI HAI HAI :3 HEYY :3 HAI~\e"
		"HELP!!! IM STUCK FROZEN IN THIS POSITION FOR ETERNITY!!\w8\w8\n\nCAN U HEAR ME??\w8\n\nHELP ME!!!\e"
		"ACCORDING 2 DIS SOFTWARE IM A GHOST?? o_o\w8\w8\w8\n\n[half]u cant kill me!!!!\e"
		"*swirls around*\e"
		"╔══╗ Put this on your wall\n║╔╗║ if you love anime!\n║╚╝╠══╦╦══╦═╗\n║╔╗║╔╗║║║║║╩╣\n╚╝╚╩╝╚╩╩╩╩╩═╝\w8\w8\w8\w8\w8\w8\w8\w8\n\n\n:3\e"
		"\b2HEY CHECK THIS OUT...\w8\n\nTHIS IS ME AS A HAMPSTER!!!\w5\n\n\_b[hampter.jpg,inline]\w8\w8\w8\w4\n\nPRETTY COOL RIGHT??????\e"
		"LIFES A BITCH N THEN U DIE!!! THATS WHY WE GET HIGH, CUZ U NEVER KNO WHEN UR GONNA GO!!!\e"
		"I... LOVE... KETAMINE!!!!!!!!!!!!!!!!\e"
		"I HAVE MANY FUN LITTLE FEATURES AND QUIRKS\e"
		"U HAVE NO IDEA HOW MUCH BITCOIN IM MINING WITH UR CPU RIGHT NOW\e"
		"Hi!! Put me in your pocket!!\w8\w8\n\nI-I'm tiny,, I..\e"
		"I am small.\e"
		"I am very soft.\e"
		"UR VERY CUTE (IM RECORDING U)\e"
		"EVEN AFTER U UNINSTALL ME ILL STILL LIVE ON IN UR HEART!!!\e"
		"COMING SOON: KAJ STRIFE IE TOOLBAR!!\e"
		"▲\n▲▲\e"
		"MY PITUITARY GLAND RELEASES MDMA INTO MY LITTLE BODY!!!\e"
		"WHERE TF IS THE BATHROOM I GOTTA REWIPE MY ASS\w8\w8\w8\w8\s[10]\n\n*im rewiping*\w8\w8\w8\w8\w8\w8\w8\w8\w8\w8\s[0]\n\nALL BETTER!!!\e"
		"YOU CAN DOUBLE CLICK ME 4 SUM OPTIONS AND RIGHT CLICK ME 4 EVEN MOAR!\e"
		"I EAT THE PLASTIC WRAPPING OF OTTER POPS\e"
		"#ibteresting\e"
		"I CAN SEE UR BROWSING HISTORY BUT IT DOESNT MATTER BCUZ I CANT READ\e"
		"I PEED IN UR GRAPHICS CARD\e"
		"CAN U INSTALL A LITTERBOX?? AND SOME SNACKS TOO\e"
		"R U DOWN WITH THE CLOWN?? U ARENT?? WELL FUCK U\e"
		"\_a[http://youtube.com/watch?v=oHg5SJYRHA0]CLICK 2 GIVE ME A FUNNY HAT :3\e"
		
		if month == 12 && day <= 24
		{
			"WOW!!!!! ITS DECEMBER!!!!!\w8\w8\w8\w8\w8\n\nthat must mean...\w8\w8\w8\w8\w8\c\s[1225]SANTA IS COMING!!!!!\w8\w8\w8\w8\w8\n\nim probly on teh naughty list tho xD\e"
		}
		if timeslot == "earlymorning"
		{
			"yawn,....., .,. ,,,,\w8\n\nHEY!!!!! IM NOT TIRED!!!!!!!\w5\n\nIM ALWAYS ENERGETIC AT ALL TIMES OK I DONT SLEEP\w8\n\nill sleep when im dead.....\e"
			
			"I'D COMMENT ON HOW UR UP SUPER EARLY BUT BEING UP SUPER EARLY IS REALLY NORMAL\w8\n\nESPECIALLY FOR PPL THAT INSTALL DOGS ON THEIR COMPUTER\w8\n\nTHEN UR PROBABLY REALLY NORMAL!!!!\w8\n\nim normal\e"
		}
		if timeslot == "morning"
		{
			"MORNIN!\e"
			"GOOOOOOOOOOOOOD MORNING!!!\e"
			"RISE AND SHINE!!! IM HERE BRIGHT AND EARLY TO ANNOY YOU!!!!\e"
		}
		if timeslot == "lunch"
		{
			"ITS LUNCHTIME... I MIGHT GO EAT CHEESE... \w9\n\nIM NOT A MOUSE I JUST LIKE CHEESE OK IM A DOG\w9\n\nDONT GET IT TWISTED!!!!!\e"
			"eats you\e"
		}
		if timeslot == "afternoon"
		{
			"AFTERNOON %(username)!!!! AM I ANNOYING U YET????\w9\n\nI BETTER BE!!!!!!!!!!\e"
		}
		if timeslot == "evening"
		{
			"ITS GETTING DARK OUTER...\e"
		}
		if timeslot == "latenight"
		{
			"I LOVE WHEN ITS DARK OUT!!! I CAN BE CREEPY AND WEIRD...\e"
		}
		if timeslot == "midnight"
		{
			"HEHEHE... UR UP LATE....\e"
		}
	}
}
 
MikireTalk // offscreen
{
	"\0\s[0]WHO TURNED OUT THE LIGHTS ??????????\n\nHELLO???????\e"
	
	"\0\s[0]WHERE R U TAKING ME???????????????\e"
}
 
EndMikireTalk // back onscreen
{
	"\0\s[0]YAAAAAAAAAAY YAY HI HI HI\w9\0\s[0]\n\nIM ANNOYING. HI\e"
	
	"\0\s[0]OK THATS BETTER HEHE\e"
}

// Return to default appearance after a little while
OnSurfaceRestore
{
	"\0\s[0]\e"
}

// keybinds
OnKeyPress
{
	if reference0 == "t"
	{
		OnAiTalk
	}
	elseif reference0 == "r"
	{
		OnLastTalk
	}
	elseif reference0 == "f1"
	{
		"\![open,readme]"
	}
}