/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 14;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const char *fonts[]          = { "monospace:size=6" };
static const char dmenufont[]       = "monospace:size=6";
static const char col_gray1[]       = "#2E3440";
static const char col_gray2[]       = "#3B4252";
static const char col_gray3[]       = "#D8DEE9";
static const char col_gray4[]       = "#ECEFF4";
static const char col_cyan[]        = "#434C5E";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

static const char *const autostart[] = {
	"sh","-c","xrandr --output HDMI2 --right-of HDMI1",NULL,
    "tcsh","-c","picom --config $HOME/.config/picom/picom.conf &;feh --bg-fill --randomize $HOME/dwm/wallpaper &",NULL,
    "tcsh","-c","conda run spyder &",NULL,
    "tcsh","-c","firefox &;zotero &;thunderbird &;texstudio &;zoom &;thorium-browser &;obsidian &; spotify &; mlab -d &", NULL,
    "sh","-c","$HOME/whatsapp.AppImage &", NULL,
	"bash","-c","/usr/share/PowerFolder/PowerFolder-Client.sh &", NULL,
    "bash","-c","$HOME/dwm/status.sh &", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const char ptagf[] = "[%s %s]";	/* format of a tag label */
static const char etagf[] = "[%s]";	/* format of an empty tag */
static const int lcaselbl = 0;		/* 1 means make tag label lowercase */	

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Thorium-browser",NULL,NULL,1<<1,False,0},
	{ "firefox",    NULL, NULL ,       1 << 4,       False,           0},
	{ "obsidian",  NULL,       NULL,       1 << 3,       False,        0 },
	{ "Zotero",  NULL,       NULL,       1 << 2,       False,   0 },
    	{NULL,NULL,"FirstSpirit",1<<6,False,0},
	{ "de-dal33t-Start",  NULL,       NULL,       1 << 7,      False,      0 },
	{ "whatsapp-desktop-linux",  NULL,       NULL,       1 << 8,    False,      0 },
	/*#######################################################################*/
	{ "Spyder","Spyder",  NULL,       1 << 0,       True,           0},
	{ NULL,    NULL, "Figure" ,       1 << 0,       True,           0},
	{ "Spyder", "Spyder",    "Spyder",         1 << 0,       False,           1},
	{ "TeXstudio",  NULL,       NULL,       1 << 1,       False,      1 },
	{ "Spotify",  NULL,       NULL,       1 << 5,   False,      1 },
	{ "zoom",  NULL,       NULL,       1 << 2,       False,       1 },
	{ "thunderbird",  NULL,       NULL,       1 << 3,       False,        1   },
	{ NULL,  NULL,     "MATLAB",       1 << 4,       False,          1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "/home/kdebre/.local/bin/dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "/home/kdebre/.local/bin/st", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,			XK_e,		spawn,	SHCMD("thunar")},
	{ MODKEY,			XK_o,		spawn,	SHCMD("spectacle -r")},
	{ MODKEY,			0xff52,		spawn,	SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%")},
	{ MODKEY,			0xff54,		spawn,	SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%")},
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,		             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       0xff51,  focusmon,       {.i = -1 } },
	{ MODKEY,                       0xff53, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             0xff51,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             0xff53, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_plus,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_plus,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask, XK_r,      spawn,          SHCMD("systemctl reboot")},
	{ MODKEY|ShiftMask, XK_s,      spawn,          SHCMD("systemctl poweroff")},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

