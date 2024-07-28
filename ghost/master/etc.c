OnFileDrop2
{
	_filepath = SPLITPATH(reference0)
	_filename = _filepath[2]
	_fileext = TOLOWER(_filepath[3])
	case _fileext
	{
		when ".jpg", ".jpeg", ".bmp", ".png"
		{
			Wallpaperfile = reference0
			
			"\0\s[0]WOW!!! AN IMAGE!!! %(_filename)%(_fileext)...\w8\n\n[half]CAN I... MAKE THIS YOUR WALLPAPER?\n\n[half]/
			\![*]\q[Centered,SetWallpaper_0]\n/
			\![*]\q[Tiled,SetWallpaper_1]\n/
			\![*]\q[Stretched,SetWallpaper_2]\n\n[half]/
			\![*]\q[No thanks,SetWallpaper_Cancel]\e"
		}
		when ".mid", ".wav", ".mp3", ".wma", ".au", ".flac"
		{
			"\0\s[0]IS DIS MUSIC?? I <3 MUSIC!!! I don't have my iPod though...\w8\n\nhere, u can have ur %(_filename)%(_fileext) back.\e"
		}
		others
		{
			"\0\s[0]COOL FILE!!! IDK WHAT TO DO WITH THIS...\w8\n\n %(_filename)%(_fileext), it's called...\e"
		}
	}
}

Select.SetWallpaper_0
{
	"\![set,wallpaper,%(Wallpaperfile),center]\0\s[0]RIGHT THERE IN TEH MIDDLE!!!\e"
}
Select.SetWallpaper_1
{
	"\![set,wallpaper,%(Wallpaperfile),tile]\0\s[0]TILED AWAY!!!\e"
}
Select.SetWallpaper_2
{
	"\![set,wallpaper,%(Wallpaperfile),stretch]\0\s[0]HEHEHE... ALL STRECHED OUT....\e"
}
Select.SetWallpaper_Cancel
{
	"\![set,wallpaper,%(Wallpaperfile),center]\0\s[1003]GET FUCKED!!! I MADE IT UR WALLPAPER ANYWAY!!!\e"
	"\![set,wallpaper,%(Wallpaperfile),stretch]\0\s[1003]GET FUCKED!!! I MADE IT UR WALLPAPER ANYWAY!!!\e"
	"\![set,wallpaper,%(Wallpaperfile),tile]\0\s[1003]GET FUCKED!!! I MADE IT UR WALLPAPER ANYWAY!!!\e"
}
 
OnInstallBegin
{
	"\0\s[0]I'M INSTALLING SOMETHING FOR YOU...\n\n\e"
}
 
OnInstallComplete
 {
	"\0" 
 	--
	if reference0 == "shell" 
 	{	
		"\s[0]SHELL INSTALLED: %(reference1)\e"
 	}
	elseif reference0 == "ghost"
 	{
		"\s[0]GHOST INSTALLED: %(reference1)\e"
 	}
	elseif reference0 == "balloon"
 	{
		"\s[0]BALLOON INSTALLED: %(reference1)\e"
 	}
	elseif reference0 == "plugin"
 	{
		"\s[0]PLUGIN INSTALLED: %(reference1)\e"
 	}
	elseif reference0 == "calendar skin"
	{
		"\s[0]CALENDAR SKIN INSTALLED: %(reference1)"
	}
	elseif reference0 == "headline"
	{
		"\0\s[0]HEADLINE INSTALLED: %(reference1)\e"
	}
	elseif reference0 == "rss"
	{
		"\0\s[0]RSS FEED INSTALLED: %(reference1)\e"
	}
	else 
	{
		"\s[0]I INSTALLED SOMETHING CALLED %(reference1)"
	}
}

OnInstallFailure
{
	"\0\s[0]THE INSTALLATION FAILED!!! ;-;\n\n[half]\w5"
	--
	if reference0 == "unsupported"
	{
		"THIS FILE IS UNSUPPORTED!!!\e"
	}	
	elseif reference0 == "extraction"
	{
		"I COULDN'T EXTRACT THE FILE!!!\e"
	}
}
 
OnInstallRefuse
{
	"\0\s[0]I CAN'T INSTALL THIS... \w4IT SEEMS TO BE FOR %(reference0)!!!\e"
	
	//reference0 in this function refers to the ghost this file is associated with, probably the name of the ghost listed in its install.txt file. You would see this if you dropped a shell made for a different ghost on your current ghost, for example. They can't install a shell for themselves they can't use, right? Anyway, replace this with what you wish, you can use the reference0 envelope or not if you want.
}


// Uninstallation

OnVanishSelecting
{
	"\0\s[0]YOU'RE UNINSTALLING ME??? YOU CAN'T GET RID OF ME!!! BUT IF U GO FORWARD, YOU MIGHT LOSE DATA!!!\e"
}

OnVanishSelected
{
	"\0\s[0]GOODBYE!!! I'LL NEVER FORGET U!!!!!!!\w9\w9\e"
}

OnVanishCancel
{
	"\0\s[0]YAAAAAAAAY WE CAN KEEP HAVING FUN 2GETHER :D\e"
}

OnVanishButtonHold
{
	"\0\s[0]NYEH!!!\e"
}
 
OnVanished
{
	
}

// Network Update
 
OnUpdateBegin
{
	"\0\s[0]\_qYAY UPDATE TIME!!!\w8\w8\e"
}
 
OnUpdateReady
{
	reference0++
	
    "\0\s[0]\_qFOUND %(reference0) NEW FILES!\e"
}

OnUpdateComplete
{
	if reference0 == "none"
 	{
 		"\0\s[0]\_qTHERE ARE NO NEW FILES!!!\e"
	}
 	else
	{
		"\0\s[0]\_qUPDATE COMPLETE!!!\w8\w8\n\n[half]RELOADING...\w8\w8\![reload,ghost]\e"
 	}
}
 
OnUpdateFailure
{
	_file = SPLITPATH(reference1)[2] + SPLITPATH(reference1)[3] // Gets the name and extension of the offending file
	
	if reference0 == "timeout"
 	{
 		"\0\s[0]OH NOES!!! THE CONNECTION TIMED OUT...\e"
	}
 	elseif reference0 == "md5 miss"
	{
		"\0\s[0]THE MD5 HASH OF %(_file) DOESN'T MATCH!!! WTF!!!\e"
 	}
	else 
 	{
 		"\0\s[0]THE UPDATE COULDN'T BE COMPLETED.\n\nERROR: '%(reference0)'\e"
	}
}

OnUpdate.OnDownloadBegin
{
 	"\0\_q\s[0]DOWNLOADING... \e"
}

OnUpdate.OnMD5CompareBegin
{
	"\0\_q\s[0]CHECKING MD5... \e"
}

OnUpdate.OnMD5CompareComplete
{
	"\0\_q\s[0]MD5 GOOD! \e"
}

OnUpdate.OnMD5CompareFailure
{
	"\0\_q\s[0]MD5 MISMATCHED! \w8\e"
}

// Ghost Creation and Updating
 
OnUpdatedataCreating
{
	"\0\_q\s[0]IM MAKING updates2.dau...\e"
}

OnUpdatedataCreated
{
	"\0\_q\s[0]updates2.dau MADE!!!\e"
}

OnNarCreating
{
	"\0\_q\s[0]IM MAKING THE .nar...\e"
}
 
OnNarCreated
{
	"\0\_q\s[0]%(reference0) MADE!!!\e"
}

OnShellScaling
{
	if reference0 >= 101 
	{
		"\0\s[0]YAY IM %(reference0)% MORE ANNOYING!!!\e"
	}
	elseif reference0 == 100 
	{
		"\0\s[0]IM A NORMAL SIZED DOG!\e"
	}
	elseif reference0 <= 99
	{
		"\0\s[0]WOW!!! IM %(reference0)% TINIER!!!\e"
	}
}