/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;  /* border pixel of windows */
static const unsigned int snap      = 32; /* snap pixel */
static const int showbar            = 1;  /* 0 means no bar */
static const int topbar             = 0;  /* 0 means bottom bar */
static const int user_bh            = 0;  /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]     = { "fira mono medium:size=11:antialias=true" };
static const char col_black[]  = "#222222";
static const char col_grey[]   = "#d3d3d3";
static const char col_cyan[]   = "#528b8b";
static const char col_white[]  = "#c2c2b0";
static const char *colors[][3] = {
	              /* foreground background border  */
	[SchemeNorm] = { col_white, col_black, col_grey },
	[SchemeSel]  = { col_cyan,  col_black, col_cyan },
};

/* tagging */
static const char *tags[]    = { "·", "·", "·", "·", "·", "·", "·", "·" };
static const char *alttags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered   isfloating   monitor */
	{ "st",       NULL,       NULL,       0,            1,           0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;   /* number of clients in master area */
static const int resizehints = 0;   /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol  arrange function */
	{ "[T]",   tile },    /* first entry is default */
	{ "[B]",   bstack },
	{ "[M]",   monocle },
	{ "[F]",   NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* dmenu */
static char dmenumon[2]    = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenu[] = { "dmenu_run", "-m", dmenumon, NULL };

/* commands */
static const char *brightnessdown[] = { "xbacklight", "-dec", "10", NULL };
static const char *brightnessup[]   = { "xbacklight", "-inc", "10", NULL };
static const char *menu[]           = { "/home/steerpyke/.suckless/scripts/dmenu_menu.sh", NULL };
static const char *printscreen[]    = { "scrot", "$HOME/Pictures/screenshot.png", NULL };
static const char *terminal[]       = { "st", NULL };
static const char *volumedown[]     = { "amixer", "sset", "Master", "5%-", NULL };
static const char *volumetoggle[]   = { "amixer", "sset", "Master", "toggle", NULL };
static const char *volumeup[]       = { "amixer", "sset", "Master", "5%+", NULL };
static const char *web[]            = { "/home/steerpyke/.suckless/scripts/dmenu_web.sh", NULL };
static const char *windows[]        = { "/home/steerpyke/.suckless/scripts/dmenu_windows.sh", NULL };

static Key keys[] = {
	/* modifier                     key                       function        argument */
	{ MODKEY,                       XK_d,                     spawn,          {.v = dmenu } },
	{ 0,                            XF86XK_MonBrightnessDown, spawn,          {.v = brightnessdown } },
	{ 0,                            XF86XK_MonBrightnessUp,   spawn,          {.v = brightnessup } },
	{ MODKEY,                       XK_slash,                 spawn,          {.v = menu } },
	{ 0,                            XK_Print,                 spawn,          {.v = printscreen } },
	{ MODKEY,                       XK_Return,                spawn,          {.v = terminal } },
	{ 0,                            XF86XK_AudioLowerVolume,  spawn,          {.v = volumedown } },
	{ 0,                            XF86XK_AudioMute,         spawn,          {.v = volumetoggle } },
	{ 0,                            XF86XK_AudioRaiseVolume,  spawn,          {.v = volumeup } },
	{ MODKEY,                       XK_w,                     spawn,          {.v = web } },
	{ MODKEY,                       XK_a,                     spawn,          {.v = windows } },
	{ MODKEY|ShiftMask,             XK_b,                     togglebar,      {0} },
	{ MODKEY,                       XK_l,                     focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_h,                     focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_l,                     movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_h,                     movestack,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_k,                     incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,                     incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_k,                     setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_j,                     setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_Return,                zoom,           {0} },
	{ MODKEY,                       XK_Tab,                   view,           {0} },
	{ MODKEY|ShiftMask,             XK_x,                     killclient,     {0} },
	{ MODKEY,                       XK_t,                     setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_b,                     setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,                     setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_f,                     setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,                 setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,                 togglefloating, {0} },
	{ MODKEY,                       XK_0,                     view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                     tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,                 focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,                focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,                 tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                                     0)
	TAGKEYS(                        XK_2,                                     1)
	TAGKEYS(                        XK_3,                                     2)
	TAGKEYS(                        XK_4,                                     3)
	TAGKEYS(                        XK_5,                                     4)
	TAGKEYS(                        XK_6,                                     5)
	TAGKEYS(                        XK_7,                                     6)
	TAGKEYS(                        XK_8,                                     7)
	{ MODKEY|ControlMask|ShiftMask, XK_q,                     quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

