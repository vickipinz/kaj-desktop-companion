OnTeachName	
{
	if reference0 == "TEACHNAME" //ignore this
	{
		"\0\s[0]WHAT SHLD I CALL U??\![open,inputbox,OnNameTeach,-1]\e"
	}
}

OnNameTeach
{
	username = reference0
	NameDone
}

NameDone
{
	if firstboot == 1
	{
		firstboot = 0
		
		"\0\s[0]HAI %(username)!!! ITS GREAT TO MEET YOU!!!\w5\n\nIM GOING TO ANNOY U NOW!!!\e"
	}
	else
	{
		"\0\s[0]HAI %(username)!! I LOVE U!!\e"
	}	
}
