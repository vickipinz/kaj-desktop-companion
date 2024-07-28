// Mouse events
// http://ssp.shillest.net/ukadoc/manual/list_shiori_event.html#OnMouseClick

// Petting!
OnMouseMove
{
	if reference4 != "" //ignore
 	{
 		stroke++ //if you move the mouse over the right areas, the stroke count will go up.
 		if stroke >= 40 
		{
 			stroke = 0 // resetting the stroke count
			if reference4 == "Head" || reference4 == "Body"
 			{
				"\0\s[0]YAY I LOVE BEING PET!!!\e"
				"\0\s[0]AHH.....\e"
				"\0\s[0]WOW UR PETTING ME XD\e"
				"\0\s[0]IM BEING PET!!!\e"
 			}
 		}
	}
 	else
	{
		stroke = 0 // stop measuring if being stroked when hand removed
 	}
}

// Clicking!
OnMouseClick
{
	if reference5 == 0 // left click
	{
		if reference3 == 0 
		{
			if reference4 == "Mouth"
			{
				BitesYou
			}
			elseif reference4 == "Eye"
			{
				EyePoke
			}
			elseif reference4 == "Privates"
			{
				RudePoke
			}
			elseif reference4 == "Paw"
			{
				HighFive
			}
			else
			{
				RandomTalk
			}
		}
	}
}

// Double-clicking!
OnMouseDoubleClick
{
	if reference5 == 0 // left click
	{
		if reference4 == "Mouth"
		{
			BitesYou
		}
		elseif reference4 == "Eye"
		{
			EyePoke
		}
		elseif reference4 == "Privates"
		{
			RudePoke
		}
		elseif reference4 == "Paw"
		{
			HighFive
		}
		else // Open the Dog Menu
		{
			OpenSakuraMenu
		}
	}
}

// Spam clicking!!!
OnMouseMultipleClick
{
	if reference4 == "Mouth"
	{
		BitesYou
	}
	elseif reference4 == "Eye"
	{
		EyePoke
	}
	elseif reference4 == "Privates"
	{
		RudePoke
	}
	elseif reference4 == "Paw"
	{
		HighFive
	}
}

EyePoke
{
	"\_v[sfx/poke.wav]"
	--
	"\0\s[0]\_q"
	--
	"OW!!!"
	"DONT POKE MY EYE!!!"
	"OWIE!!!!!!"
	"OW MY EYE!!!"
	--
	"\e"
}

RudePoke
{
	"\_v[sfx/poke.wav]"
	--
	if pokey >= 5 { // kaj closes entirely
		"\0\s[1004]THATS IT IM OUTTA HERE!!!\w8\w8\w8\w4\-"
		"\0\s[1004]THATS IT IM OUTTA HERE!!!\w8\w8\w8\w4\-"
	}
	else
	{
		pokey++
		--
		"\0\s[0]\_q"
		--
		"WHAT IS WRONG WITH YOU???"
		"WHATS THE MATTER WITH YOU???"
		"KILL YOURSELF!!!"
		"ARE YOU OUT OF YOUR FUCKING MIND???"
		"CUT IT OUT!!!"
		"FUCK YOU!!!"
		--
		"\e"
	}
}

HighFive
{
	"\_v[sfx/slap.wav]"
	--
	"\0\s[0]\_q"
	--
	"HIGH FIVE!!!"
	"UP TOP!!!"
	--
	"\e"
}

BitesYou
{
	"\_v[sfx/bite.wav]"
	--
	"\0\s[0]\_q"
	--
	"*CHOMP*"
	"*BITES*"
	"*BITES YOU*"
	--
	"\e"
}
