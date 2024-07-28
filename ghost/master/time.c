// Time functions and variables

timeslot // time of day
{
	if hour >= 5 && hour <= 8 { "earlymorning" }
	elseif hour >= 9 && hour <= 11 { "morning" }
	elseif hour >= 12 && hour <= 16 { "afternoon" }
	elseif hour >= 17 && hour <= 20 { "evening"	}
	elseif hour >= 21 && hour <= 24 { "latenight" }
	else { "midnight" }
}

dayslot { "%(month)month %(day)day" } // weird date format

happybirthday
{
	if wishedhbd == 0
	{
		wishedhbd = 1
		"\0\s[0]IT'S %(bornmonthprint) %(borndayprint)!\w8\w8\w8\nWAIT...\w4 ZOMG!!!\w8\w8\c\s[1331]HAPPY BIRTHDAY %(username)!!!\w8\w8\nI HOPE ITS A SPECIAL ONE!!!\w8\w8\n\n[half]IM SO PROUD OF U FOR MAKING IT THIS FAR :D\w8\w8\n\n[half]UR RLY RLY SPECIAL AND I LOVE U!!!!!!\x"
	}
}

HourCheck
{
if passmin >= 59
	{
		passmin = 0
		passhour = passhour + 1
	}
}

OnMinuteChange
{
	HourCheck // checks to see if an hour has passed
	--
	// if it suddenly becomes the users' birthday
	if dayslot == userbirthday && wishedhbd == 0
	{
		"%(happybirthday)"
	}
	elseif minute == 0
	{
 		if hour == 12 
		{
 			"\0\s[0]DING DONG, DING DONG....\w8\n\nDING DONG DING DONG!!!!!!\w7\w7\c THATS RIGHT U DING DONG!!! ITS NOON!!!\e"		
			"\0\s[0]ITS HIGH NOON........ \w8\0\s[1001]\n\nTHIS TOWN AINT BIG ENUF 4 TEH 2 OF US!!!!!!!\e"
			"\0\s[0]ITS NOON!!!!!!!!!!!!!!! ROFL\e"
			"\0\s[0]AYO FUCK 12!!!\e"
		}
 		elseif hour == 0 
		{
			if month == 1 && day == 1 {
				"\0\s[1331]HAPPY NEW YEAR!!!!!!\w8\w8\w8\w8\n\n[half]WOW, TEH FIRST THING U SAW THIS YEAR WAS ME??\w8\w8\w8\w8\n\n[half]I HOPE THAT MEANS ITS A GUD YEAR :3\e"
			}
 			"\0\s[0]HEY!!! IT'S MIDNIGHT!!! THAT MEANS...... ITS A NEW DAY!!!!!! HOLY FUCK!!!!!!\e"
			"\0\s[0]THE COCK STRIKES TWELVE...\w8\n\n[half]SORRY. TYPO\e"
			"\0\s[0]THE CLOCK STRIKES TWELVE...\w8\n\n[half]OR ZERO IF UR WEIRD\e"
			"\0\s[0]AYO FUCK 12!!!\e"
		}
		else
		{
			"\0\s[0]HEY!!! IT'S %(hour12) O'CLOCK!!!\e"
			"\0\s[0]DING DONG ITS %(hour12)!!\e"
		}
	}
	elseif hour == 7 && minute == 45 
	{
		"\0\s[0]ITS 745 IN THE MORNING YEAH!!!!!!!!!!\e"
	}
	elseif hour == 4 || hour == 16
	{
		if minute == 20
		{
			"\0\s[1420]420 BLAZE IT!!!\e"
			
			"\0\s[1420]SMOKE WEED BE TRANSGENDER!!!\e"
			
			"\0\s[1420]ITS WEED O'CLOCK!!! FUCK!!!\e"
		}
	}
	
	// offscreen detection
	elseif mikireflag == 1
 	{
 		MikireTalk
	}
 }

OnSecondChange
{
	if passsec == 59
 	{
	 	passsec = 0
 		passmin = passmin + 1
	}
 	else
 	{
	 	passsec = passsec + 1
	}
	if mikireflag == 0 && reference1 == 1 // when moved off-screen
	{
		MikireTalk
	}
	if mikireflag == 1 && reference1 == 0 // when moved back on-screen
	{
		EndMikireTalk
	}
	mikireflag = reference1 // reference1 is if the ghost is offscreen or not
	if reference2 == 1
	{
 		// when two characters overlap (unused)
	}
}