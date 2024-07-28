// "Dog Menu" (double-click body to open)

OpenSakuraMenu
{
	"\0\s[0]DOG MENU!!!\n\n[half]\_q"
	--
	MenuRun
}

MenuRun
{	
	if lastTalk != ""
	{
		"\![*]\q[CAN U REPEAT THAT?,OnLastTalk]\n"
	}
	--
 	"\![*]\q[ANNOY ME!,OnAiTalk]"
	"\![*]\q[SAY SOMETHING!,OnAiTalk]"
	--
	"\n\n[half]\![*]\q[CONFIGURATION!,configmenu]\n"
	--
	"\![*]\q[SSP SETTINGS!,sspconfig]\n"
	--
	"\![*]\q[EMPTY RECYCLE BIN!,ChoiceGarbagecan]\n\n[half]"
	--
	
 	"\![*]\q[NEVERMIND!,CANCEL]"
}

OnLastTalk 
{
	"%(lastTalk)\e"
}

Select.BACKTOMENU
{
	OpenSakuraMenu
}

Select.configmenu
{
	TalkConfig
}

TalkConfig
{
	"\0\_q"
	--
	"\f[bold,1]NAME:\f[bold,0] %(username) (\q[change,TEACHNAME])\n"
	--
	"\f[bold,1]BDAY:\f[bold,0] %(birthdayprint) (\q[change,TEACHBDAY])\n"
	--
	"\f[bold,1]HOW OFTEN I ANNOY U:\f[bold,0] %(talktime) (\q[change,talkinter])\n\n[half]"
	--
	"\q[BACK 2 DOG MENU,BACKTOMENU]\e"
}

Select.TEACHBDAY
{	
	"\0\s[0]WUT MONTH WERE U BORN??\![open,inputbox,OnUserBornMonth,-1]\e"
}

OnUserBornMonth
{
	_tempmonth = TOSTR(reference0) //this stores what the user put in as a variable called _tempmonth
	_tempmonth = TOLOWER(_tempmonth) //changes it to lowercase
	
	//this is attaching the right value to the input from the user
	if _tempmonth == "january" || _tempmonth == "1" {bornmonth = 1; bornmonthprint = "JANUARY"}
	elseif _tempmonth == "february" || _tempmonth == "2" {bornmonth = 2; bornmonthprint = "FEBRUARY"}
	elseif _tempmonth == "march" || _tempmonth == "3" {bornmonth = 3; bornmonthprint = "MARCH"}
	elseif _tempmonth == "april" || _tempmonth == "4" {bornmonth = 4; bornmonthprint = "APRIL"}
	elseif _tempmonth == "may" || _tempmonth == "5" {bornmonth = 5; bornmonthprint = "MAY"}
	elseif _tempmonth == "june" || _tempmonth == "6" {bornmonth = 6; bornmonthprint = "JUNE"}
	elseif _tempmonth == "july" || _tempmonth == "7" {bornmonth = 7; bornmonthprint = "JULY"}
	elseif _tempmonth == "august" || _tempmonth == "8" {bornmonth = 8; bornmonthprint = "AUGUST"}
	elseif _tempmonth == "september" || _tempmonth == "9" {bornmonth = 9; bornmonthprint = "SEPTEMBER"}
	elseif _tempmonth == "october" || _tempmonth == "10" {bornmonth = 10; bornmonthprint = "OCTOBER"}
	elseif _tempmonth == "november" || _tempmonth == "11" {bornmonth = 11; bornmonthprint = "NOVEMBER"}
	elseif _tempmonth == "december" || _tempmonth == "12" {bornmonth = 12; bornmonthprint = "DECEMBER"}
	
	else
	{
		"\0\s[0]UM IDK WUT MONTH THAT IS. TRY AGAIN??"
		--
		"\![open,inputbox,OnUserBornMonth,-1]\![set,balloontimeout,-1]\e"
	}
	--
	"\0\s[0]%(bornmonthprint)... \w8WUT DAY???"
	--
	"\![open,inputbox,OnUserBornDay,-1]\![set,balloontimeout,-1]\e"
}

Printday
{
	if bornday == 1 || bornday == 21 || bornday == 31
	{	"%(bornday)ST"	}
	elseif bornday == 2 || bornday == 22
	{	"%(bornday)ND"	}
	elseif bornday == 3 || bornday == 23
	{	"%(bornday)RD"	}
	else
	{	"%(bornday)TH"	}
}

OnUserBornDay
{
	_tempday = reference0 //storing the input in _tempday
	_tempday = TOLOWER(_tempday) //changes it to lowercase
	_tempday = REPLACE(_tempday,"st","") //if the user types something like 2nd, 3rd, etc, this will make it just the number. It'll just add the suffix back later on the one that actually shows.
	_tempday = REPLACE(_tempday,"nd","")
	_tempday = REPLACE(_tempday,"rd","")
	_tempday = REPLACE(_tempday,"th","")
	_tempday = TOINT(_tempday) //Converts it to an integer
	
	if ((bornmonth == 1 || bornmonth == 3 || bornmonth == 5 || bornmonth == 7 || bornmonth == 8 || bornmonth == 10 || bornmonth == 12) && _tempday >= 1 && _tempday <= 31) || (bornmonth == 2 && _tempday >= 1 && _tempday <= 29) || ((bornmonth == 4 || bornmonth == 6 || bornmonth == 9 || bornmonth == 11) && _tempday >= 1 && _tempday <= 30) //This ugly function checks if the day falls into a valid range. If it does, we set some variables and continue down.
	{
		bornday = _tempday
		borndayprint = Printday
		userbirthday = "%(bornmonth)month %(bornday)day"
		birthdayprint = "%(bornmonthprint) %(borndayprint)"
		
		"%(birthchecked)"
	}
	else
	{
		"\0\s[0]UHHH WUT. COME AGAIN??"
		--
		"\![open,inputbox,OnUserBornDay,-1]\e"
	}	
}

birthchecked
{
	if userbirthday == dayslot
	{
		wishedhbd = 1
		if userbirthday == "3month 31day"
		{
			"\0\s[0]HOLY SHIT ITS UR BIRTHDAY???\w8\n\n[half]*AND* MINE TOO???\w8\n\n[half]\s[1331]HAPPY BIRTHDAY TO US!!!\x"
		}
		else
		{
			"\0\s[0]HOLY SHIT ITS UR BIRTHDAY???\w6\n\n[half]\s[1331]HAPPY BIRTHDAY %(username)!!!!!!!\w6\n\n[half]<3<3<3<3<3\x"
			"\0\s[0]ITS UR BDAY??? ZOMG!!!\w6\n\n[half]\s[1331]HAPPY BDAY %(username)!!!!!\w8\n\n[half]<3<3<3<3<3<3<3\x"
		}
	}
	elseif userbirthday == "12month 25day"
	{
		"\0\s[0]OMG R U JESUS CHRIST??? THATS SO COOL!!!\w8\n\n[half]HAHA OK YEAH U HAVE PROBABLY HEARD THAT ONE BEFORE MY BAD. LOL\e"
	}
	elseif userbirthday == "3month 31day"
	{
		"\0\s[0]WE HAVE THE SAME BIRTHDAY!!!\n\n[half]WOW!!!\e"
	}
	else 
	{
		"\0\s[0]SO U WERE BORN ON %(bornmonthprint) %(borndayprint)... ILL REMEMBER THAT!!!\e"
	}
}

Select.talkinter
{
	"\0\s[0]HOW OFTEN SHOULD I ANNOY YOU???? CURRENTLY I ANNOY U %(talktime)/
	\0\n\n[half]/
	\![*]\q[EVERY 30 SECONDS,TALKMAX]\n/
	\![*]\q[EVERY 60 SECONDS,TALKHIGH]\n/
	\![*]\q[EVERY 3 MINUTES,TALKNORMAL]\n/
	\![*]\q[EVERY 5 MINUTES,TALKPOOR]\n/
	\![*]\q[SHUT UP!!!,TALKNONE]\n\n[half]/
	\![*]\q[KEEP IT THE SAME!!!,TalksTill]\e"
}

Select.TalksTill
{
	"\0\s[0]OK ILL KEEP ANNOYING U AT THE SAME RATE :3\e"
}

Select.TALKMAX
{
	talktime = "EVRY 30 SECS"
	aitalkinterval = 30
	
	"\0\s[0]U WANT ME TO ANNOY U EVERY 30 SECONDS??? THATS SO KIND OF U\w8\n\nur prolly gonna lern all my jokes pretty quickly tho.....\e"
}

Select.TALKHIGH
{
	talktime = "EVRY 60 SECS"
	aitalkinterval = 60
	
	"\0\s[0]OK I WILL ANNOY U EVERY 60 SECONDS!!!!\e"
}

Select.TALKNORMAL
{
	talktime = "EVRY 3 MINS"
	aitalkinterval = 180
	
	"\0\s[0]OK I WILL ANNOY U EVERY 3 MINUTES\e"
}

Select.TALKPOOR
{
	talktime = "EVRY 5 MINS"
	aitalkinterval = 300
	
	"\0\s[0]EVERY 5 MINUTES IT IS\e"
}

Select.TALKNONE
{
	talktime = "NEVER..."
	aitalkinterval = 0
	
	"\0\s[0]aww... ok ill stop... :(\e"
}

Select.TEACHNAME
{
	OnTeachName	
}

Select.CANCEL
{
	"\0\s[0]OK THATS FINE I GUESS\e"
}

Select.sspconfig
{
	"\![open,configurationdialog]\e"
}

Select.ChoiceGarbagecan
{
	_gomicheck = FUNCTIONEX("gomi.dll", "-n")
	
	if _gomicheck == 0
	{
		"\0\s[0]I WENT 2 LOOK IN UR RECYCLE BIN BUT NOTHING WUZ THERE!!!\w8\w8\w8\n\n\s[1002]NOW IM HUNGRY SO ILL EAT THIS TRASH IVE BEEN HOLDING ONTO INSTEAD!!!\e"
		"\0\s[0]THERES NO TRASH FOR ME TO TAKE OUT!!! IM SAD NOW... U GOT ME EXCITED...\e"
	}
	elseif _gomicheck >= 1
	{
		"\0\s[1002]UR LETTING ME EAT UR TRASH??? I LOVE YOU!!!\w8\w8\n\n*nomnomnomnomnom*\![raise,OnGarbagecanEmpty]\w8\n\n\s[0]OK I ATE ALL UR TRASH!!!\e"
		
		"\0\s[1002]OK ILL TAKE OUT THE TRASH!!!\w8\w8\n\n\s[10]......................\![raise,OnGarbagecanEmpty]\w8\n\n\s[0]UR TRASH IS GONE!! NOW U CAN THROW AWAY MOAR TRASH!!!! *burp*\e"
		
		"\0\s[1002]WATCH AS UR TRASH DISAPPEARS BEFORE UR VERY EYES...\w8\w8\![raise,OnGarbagecanEmpty]\w8\n\n\s[0]GONE. IDK WHERE IT WENT\e"
	}
}

OnGarbagecanEmpty
{
	_gomi = FUNCTIONEX("gomi.dll", "-f")
}
