/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"fira mono medium:size=11:antialias=true"
};

static const char *colors[SchemeLast][2] = {
 				/*  fg         bg      */
	[SchemeNorm]          = { "#c2c2b0", "#222222" },
	[SchemeSel]           = { "#528b8b", "#222222" }, // SchemeSel fg also border color
	[SchemeSelHighlight]  = { "#528b8b", "#222222" },
	[SchemeNormHighlight] = { "#528b8b", "#222222" },
	[SchemeOut]           = { "#c2c2b0", "#222222" },
	[SchemeOutHighlight]  = { "#c2c2b0", "#222222" },
};

static const char *prompt              = NULL; /* -p  option; prompt to the left of input field */
static const unsigned int border_width = 1;    /* size of the window border */
static int topbar                      = 1;    /* -b  option; if 0, dmenu appears at bottom     */
static int fuzzy                       = 1;    /* -F  option; if 0, dmenu doesn't use fuzzy matching     */
static unsigned int dmw                = 400;  /* fixed width of the window */
static unsigned int lines              = 8;    /* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lineheight         = 25;    /* -h option; minimum height of a menu line */
static unsigned int min_lineheight     = 8;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
