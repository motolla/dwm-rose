/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 0;        /* border pixel of windows */
static const unsigned int snap           = 32;       /* snap pixel */
static const unsigned int gappih         = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;       /* vert inner gap between windows */
static const unsigned int gappoh         = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps               = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int colorfultag    = 1;        /* 0 means use SchemeSel for selected tag */
static const int showbar                 = 1;        /* 0 means no bar */
static const int topbar                  = 1;        /* 0 means bottom bar */
static const int vertpad                 = 8;       /* vertical padding of bar */
static const int sidepad                 = 8;       /* horizontal padding of bar */
static const int horizpadbar             = 6;        /* horizontal padding for statusbar */
static const int vertpadbar              = 12;        /* vertical padding for statusbar */
static const char *fonts[]               = { "Iosevka Mayukai Sonata:Bold:size=12", "Symbols Nerd Font:Semibold:size=16" };

#include "colors/rose-pine.h"
static const char *colors[][3]  = {
  /*                     fg   bg   border */
  [SchemeNorm]       = { fg1, bg0, fg2 },
  [SchemeSel]        = { bg1, rose, rose },
  [SchemeTag]        = { bg0, bg1, bg0 },
  [SchemeTag1]       = { rose, bg0,  bg1 },
  [SchemeTag2]       = { red, bg0, bg1 },
  [SchemeTag3]       = { yellow, bg0, bg1 },
  [SchemeTag4]       = { bluu, bg0, bg1 },
  [SchemeTag5]       = { purple, bg0, bg1 },
  [SchemeTag6]       = { cyan, bg0, bg1 },
  [SchemeLayout]     = { rose, bg0, bg1 },
  [SchemeTitle]      = { fg0, bg0, bg1 },
  [SchemeTitle1]     = { rose, bg0, bg1 },
  [SchemeTitle2]     = { red, bg0, bg1 },
  [SchemeTitle3]     = { yellow, bg0, bg1 },
  [SchemeTitle4]     = { bluu, bg0, bg1 },
  [SchemeTitle5]     = { purple, bg0, bg1 },
  [SchemeTitle6]     = { cyan, bg0, bg1 },
};

static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3,
                                  SchemeTag4, SchemeTag5, SchemeTag6 };

static const int titleschemes[] = { SchemeTitle1, SchemeTitle2, SchemeTitle3,
                                    SchemeTitle4, SchemeTitle5, SchemeTitle6 };

/* tagging */
static const char *tags[] = { "󰅩", "󰈹", "󰘬", "󰓇", "󰠖", "󱍢"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       2,            0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ " ",      tile },    /* first entry is default */
	{ "󱂬 ",      NULL },    /* no layout function means floating behavior */
	{ " ",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#include "movestack.c"

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-c", "-l", "12", NULL };
static const char *termcmd[]  = { "st", NULL };

/* volume commands */
static const char *uvol[]   = { "pactl", "set-sink-volume", "0", "+5%",     NULL };
static const char *dvol[] = { "pactl", "set-sink-volume", "0", "-5%",     NULL };
static const char *mvol[] = { "pactl", "set-sink-mute", "0", "toggle", NULL };

/* brightness commands */
static const char *ubright[] = { "xbacklight", "-inc", "10",     NULL };
static const char *dbright[] = { "xbacklight", "-dec", "10",     NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */

  // Programs //
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,	                      XK_Return, spawn,          {.v = termcmd } },
  { MODKEY,                       XK_bracketleft, spawn,     SHCMD("~/bin/volcon") },
  { MODKEY,                       XK_Print,  spawn,          SHCMD("~/bin/scrot") },
  { ControlMask,                  XK_Print,  spawn,          SHCMD("~/bin/flamecrop") },
  // Programs: brightness //
	{ 0,                            0x1008FF02, spawn,         {.v = ubright } },
	{ 0,                            0x1008FF03, spawn,         {.v = dbright } },
  // Programs: audio //
	{ 0,                            0x1008FF13, spawn,         {.v = uvol } },
	{ 0,                            0x1008FF11, spawn,         {.v = dvol } },
	{ 0,                            0x1008FF12, spawn,         {.v = mvol } },

  // Visual //
  { MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
  { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
  { MODKEY|ShiftMask,             XK_n,      togglecolorfultag,   {0} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },


  // Visual: gaps //
  { MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } },
  { MODKEY|Mod4Mask,              XK_l,      incrgaps,       {.i = -1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } },
  { MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } },
  { MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
  { MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
  { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } },
  { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
  { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
  { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } },
  { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } },
  { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
  { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },

  // Misc //
  { MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,	                      XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  // Quit dwm //
  { MODKEY|ShiftMask,             XK_q,      quit,           {0} },


  // Workspaces //
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

