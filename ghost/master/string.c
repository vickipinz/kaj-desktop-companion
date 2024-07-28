On_username
{
	username
}

On_homeurl // updates directory
{
	"http://kaj.unluckywind.net/etc/ukagaka/"
}

On_recommendrootbutton.caption
{
	"Ukagaka Sites"
}

On_sakura.recommendsites
{
	"Zarla's Ukagaka Walkthrough"
	--
	"%ASC(1)http://ashido.com/ukagaka/%ASC(2)"
	--
	
	"Ukagawa Webring (English)"
	--
	"%ASC(1)http://ukagakawebring.netlify.app/%ASC(2)"
	--
	
	"SSP"
	--
	"%ASC(1)http://ssp.shillest.net/%ASC(2)"
	--
	
	"Crow + SSP Reference (J)"
	--
	"%ASC(1)http://crow.aqrs.jp/reference/all/index.html%ASC(2)"
	--
	
	"Ghost Documentation (J)"
	--
	"%ASC(1)http://usada.sakura.vg/contents/specification.html%ASC(2)"
	--
	
	"Disc-2 (J)"
	--
	"%ASC(1)http://disc2.s56.xrea.com/%ASC(2)"
	
	"UKADOC Project Wiki (J)"
	--
	"%ASC(1)http://ssp.shillest.net/ukadoc/manual/index.html/%ASC(2)"
}

On_portalrootbutton.caption
{
	"Kaj's Links"
}
 
On_sakura.portalsites
{
	"Kaj Desktop Companion"
	--
	"%ASC(1)http://kaj.unluckywind.net/widget%ASC(2)"
	--
	
	"Kaj Strife"
	--
	"%ASC(1)http://kaj.unluckywind.net/%ASC(2)"
	--
	
	"Twitter"
	--
	"%ASC(1)http://kaj.unluckywind.net/twitter%ASC(2)"
	--
}

On_updatebutton.caption
{
	"Check for Updates (v0.2.1)"
}

//---- 소멸 지시 버튼 표시 교체 -------------------------------------------------------
On_vanishbutton.visible
{
 	if deleteshitai == "ON"
 	{
		"1"
	}
	else
	{
		"0"
	}
}

//---- 딳벍뭷궻뫜궻긕?긚긣뼹롦벦 -------------------------------------------------------
On_otherghostname
{
	ghostexlist = ""
	_i = 0
	while _i >= 0 {
		_ghostname = NAMETOVALUE("reference%_i")
		if _ghostname != "" {
			if _i > 0; ghostexlist += ","
			ghostexlist += _ghostname[0]
			_i++
		}
		else; _i = -1
	}
	ghostexcount = ARRAYSIZE(ghostexlist)
}

//---- SHIORI 듫쁀륃뺪 ------------------------------------------------------------------
On_version
{
	GETSETTING(AYAINFO_VERSION)
}

On_craftman
{
	"umeici"
}

On_craftmanw
{
	"?럖"
}

On_name
{
	"AYA"
}

//---- Owned SSTP 뾭 uniqueid 롦벦 ------------------------------------------------------
On_uniqueid
{
	uniqueid = reference0
}

//---- hwnd 롦벦 ------------------------------------------------------------------------
On_hwnd
{
	sakurahwnd    = reference0[0]
	kerohwnd      = reference0[1]
	sakurablnhwnd = reference1[0]
	keroblnhwnd   = reference1[1]
}

