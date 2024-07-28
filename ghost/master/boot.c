// Boot, closing, shell/ghost switching

OnFirstBoot // If no profile folder is found
{
	// Reset all variables
 	lastTalk       = ""
	passhour       = 0
	passmin        = 0 
	passsec        = 0
 	username       = "FRIEND" // Placeholder name if somehow skipped
	stroke         = 0	// Sets being-pet state to zero
 	teachusername  = 0	// Related to it learning your name
	mikireflag     = 0	// Determines behavior at certain points
 	aitalkinterval = 180 // Default talk rate
	talktime       = "EVRY 3 MINS"
	birthdayprint  = "???" 
	deleteshitai   = "ON" // toggle for uninstallation. normally would be changed in the dog menu (unused)
	nowshell       = "chibi" // Default shell
	firstboot      = 1 // This marks that this is the first time you've run the ghost. It's so it won't reroute to general name changing dialogue when the user inputs their name.
	
	if reference0 == 0 
 	{
		"\0\s[0]HI!!! IM KAJ!!! IM A LITTLE DOGGY THAT LIVES ON UR DESKTOP!!!\w8\w4"
		--
		"\n\n[half]THATS RIGHT!!! IM HERE 2 ANNOY U!!!!!!!!\w8\w4"
		--
		"\n\n[half]U CAN DOUBLE CLICK ME 2 OPEN TEH DOG MENU OR RITE CLICK ME 2 OPEN TEH MAIN MENU!!!\w8\w4"
		--
		"\n\n[half]PRESS F1 WHILE IM ACTIVE IF U RLY NEED HELP!!!\w8\w8"
		--
		"\n\n[half]WE'RE GOING 2 HAVE SO MUCH FUN 2GETHER!!! OR AT LEAST I'LL BE HAVING FUN >:3\w8\w8\e"
 	}
}

OnBoot // Regular boot
{
	lastTalk = ""
	passhour = 0
	passmin = 0
	passsec = 0
	wishedhbd = 0
	pokey = 0
	
	"\0\s[0]"
	--
	if dayslot == userbirthday
	{
		"%(happybirthday)"
	}
	elseif RAND(100) < 7
	{
		"\0\s[0]HEY HEY HEY!!! ITS UR LUCKY DAY!!!\w8\w8\n\nHOW?? I JUST KNOW :)\e"
	}
 	else
 	{
		if timeslot == "earlymorning"
		{
			"\0\s[0]BARK BARK BARK BARK!!! IM WAKING EVERYONE UP!!!"
		}
		elseif timeslot == "morning"
		{
			"\0\s[0]ANOTHER DAY ANOTHER DOG!!!\e"
			"\0\s[0]GOOD MORNING %(username)!!! LETS HAVE AN ANNOYING ONE 2DAY!!!\e"
		}
		elseif timeslot == "afternoon"
		{
			"\0\s[0]GOOD MORNING!! I MEAN AFTERNOON!! SRY I JUST WOKE UP xD\e"
			"\0\s[0]HEWWO!!\n\nI JUST GOT DONE EATING CHEESE :3\n\nBUT IM NOT A MOUSE, IM A BUNNYDOG!! DONT GET IT TWISTED!!!\e"
		}
		elseif timeslot == "evening"
		{
 		"\0\s[0]EVENING, %(username)!"
		"\0\s[0]HAI %(username)! HOW WAS UR DAY?"
		}
		elseif timeslot == "latenight"
		{
 		"\0\s[0]TEEHEE ITS GETTING LATE... good 2 see u :D"
		"\0\s[0]EVENING, %username)!"
		}
		else // midnight
		{
		"\0\s[0]JUST CUZ ITS THE MIDDLE OF THE NIGHT DOESNT MEAN I CANT BE ANNOYING!!!"
		}
	}
}

OnClose
{
	if passmin >= 5 || passhour > 0
	{
		"\0\s[0]CYA L8R!!\w8\e"
		"\0\s[0]BYE-BYE!!!!\w8\e"
		"\0\s[0]GOODBYE I LOVE U\w8\e"
	}
 	else
 	{
		"\0\s[0]G-GONE SO SOON?\w8\e"
 	}
 	--
	"\-\e"
}

OnWindowStateMinimize
{
	"\0\s[0]AHH UR SQUEEZING ME INTO THE TASKBAR NUUUU\e"
	"\0\s[0]OK ILL B TINY I GUESS...\e"
	"\0\s[0]YAY I GET TO BE IN THE TRAY!!!\e"
}

OnWindowStateRestore
{
	"\0\s[0]YAY IM BIG AGAIN\e"
	"\0\s[0]HI AGAIN\e"
	"\0\s[0]RAAAAAWWWRRRR!!!!!\e"
	"\0\s[0]IM ANNOYING!!!"
}
 
OnGhostChanging // before ghost changing
{
	if reference0 == "Kaj Strife" // change to same ghost (reloading)
	{
		"\0\s[0]OK IM RELOADING!!!\w8\e"
		"\0\s[0]EATS MYSELF\w8\e"
	}
 	else // change to diff ghost
	{
		"\0\s[0]OK HAVE FUN WITH %(reference0)!!!\w8\e"
		"\0\s[0]im sure %(reference0) isnt as annoying as ME!!\w8\e"
		"\0\s[0]SAY HI TO %(reference0) 4 ME!!!\w8\e"
	}
}

OnGhostChanged // after ghost switching
{
	pokey = 0
	"\0\s[0]" 
	--
	if reference0 == "Kaj Strife" // after reloading
	{
		"\0\s[0]I FEEL REFRESHED!!\e"
		"\0\s[0]YAY THX 4 RELOADING ME!!!\e"
		"\0\s[0]IM RAWRING TO GO!!!\e"
	}
	else // from diff ghost
	{
		"\0\s[0]I JUST KILLED %(reference0) WITH THE BIGGEST GUN IN THE WORLD\e"
		"\0\s[0]SO LONG, %(reference0), HELLO, ME!!!!!!!!/e"
		
		"\0\s[0]HI IM KAJ!!!\e"
		"\0\s[0]DAMN!!!\e"
		"\0\s[0]IM ANNOYING!!!\e"
	}
}

OnShellChanging // before shell switching
{
	"\0\s[0]MY METAMORPHISIS BEGINS...\e"
}
 
OnShellChanged // after shell switching
{
 	if reference0 == "Kaj (four legged)"
 	{
 		nowshell = "bastard"
		
 		"\0\s[0]GRRR IM A LITTLE BASTARD NOW!!!\e"
		"\0\s[0]NYEHEHEHE I CAN RUN FASTER NOW\e"
 	}
	elseif reference0 == "Kaj (chibi)"
	{
		nowshell = "chibi"
		
		"\0\s[0]DAMN!!! FUCK!!!\e"
		"\0\s[0]IM ANNOYING!!!\e"
	}
 	else 
 	{
		"\0\s[0]YAY NOW IM %(reference[0])!!\e"
	}
}
