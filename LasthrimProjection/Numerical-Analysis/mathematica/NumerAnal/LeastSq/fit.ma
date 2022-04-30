(*^

::[paletteColors = 128; automaticGrouping; currentKernel; 
	fontset = title, inactive, noPageBreakBelow, noPageBreakInGroup, nohscroll, preserveAspect, groupLikeTitle, center, M7, bold, L1, e8,  24, "Times"; ;
	fontset = subtitle, inactive, noPageBreakBelow, noPageBreakInGroup, nohscroll, preserveAspect, groupLikeTitle, center, M7, bold, L1, e6,  18, "Times"; ;
	fontset = subsubtitle, inactive, noPageBreakBelow, noPageBreakInGroup, nohscroll, preserveAspect, groupLikeTitle, center, M7, italic, L1, e6,  14, "Times"; ;
	fontset = section, inactive, noPageBreakBelow, nohscroll, preserveAspect, groupLikeSection, grayBox, M22, bold, L1, a20,  18, "Times"; ;
	fontset = subsection, inactive, noPageBreakBelow, nohscroll, preserveAspect, groupLikeSection, blackBox, M19, bold, L1, a15,  14, "Times"; ;
	fontset = subsubsection, inactive, noPageBreakBelow, nohscroll, preserveAspect, groupLikeSection, whiteBox, M18, bold, L1, a12,  12, "Times"; ;
	fontset = text, inactive, nohscroll, noKeepOnOnePage, preserveAspect, M7, L1,  12;
	fontset = smalltext, inactive, nohscroll, noKeepOnOnePage, preserveAspect, M7, L1,  10, "Times"; ;
	fontset = input, noPageBreakInGroup, nowordwrap, preserveAspect, groupLikeInput, M42, N23, bold, L1,  12, "Courier"; ;
	fontset = output, output, inactive, noPageBreakInGroup, nowordwrap, preserveAspect, groupLikeOutput, M42, N23, L-5,  12, "Courier"; ;
	fontset = message, inactive, noPageBreakInGroup, nowordwrap, preserveAspect, groupLikeOutput, M42, N23, L1,  12, "Courier"; ;
	fontset = print, inactive, noPageBreakInGroup, nowordwrap, preserveAspect, groupLikeOutput, M42, N23, L1,  12, "Courier"; ;
	fontset = info, inactive, noPageBreakInGroup, nowordwrap, preserveAspect, groupLikeOutput, M42, N23, L1,  12, "Courier"; ;
	fontset = postscript, PostScript, formatAsPostScript, output, inactive, noPageBreakInGroup, nowordwrap, preserveAspect, groupLikeGraphics, M7, l34, w282, h287, L1,  12, "Courier"; ;
	fontset = name, inactive, noPageBreakInGroup, nohscroll, preserveAspect, M7, italic, B65535, L1,  10, "Times"; ;
	fontset = header, inactive, nohscroll, noKeepOnOnePage, preserveAspect, M7, italic, L1,  12, "Times"; ;
	fontset = Left Header, inactive, nohscroll, noKeepOnOnePage, preserveAspect, M7, italic, L1,  12, "Times"; ;
	fontset = footer, inactive, nohscroll, noKeepOnOnePage, preserveAspect, center, M7, italic, L1,  12, "Times"; ;
	fontset = Left Footer, inactive, nohscroll, noKeepOnOnePage, preserveAspect, center, M7, italic, L1,  12, "Times"; ;
	fontset = help, inactive, nohscroll, noKeepOnOnePage, preserveAspect, M7, L1,  12;
	fontset = clipboard, inactive, nohscroll, noKeepOnOnePage, preserveAspect, M7, L1,  12;
	fontset = completions, inactive, nohscroll, noKeepOnOnePage, preserveAspect, M7, L1,  12, "Courier"; ;
	fontset = special1, inactive, nohscroll, noKeepOnOnePage, preserveAspect, M7, L1,  12;
	fontset = special2, inactive, nohscroll, noKeepOnOnePage, preserveAspect, M7, L1,  12;
	fontset = special3, inactive, nohscroll, noKeepOnOnePage, preserveAspect, M7, L1,  12;
	fontset = special4, inactive, nohscroll, noKeepOnOnePage, preserveAspect, M7, L1,  12;
	fontset = special5, inactive, nohscroll, noKeepOnOnePage, preserveAspect, M7, L1,  12;
	next21StandardFontEncoding; ]
:[font = Left Header; inactive; preserveAspect; fontSize = 22; fontName = "Times"; ]
Least Square Fit:
:[font = Left Header; inactive; preserveAspect; ]
We use the Mathematica function Fit. 
;[s]
3:0,0;11,1;22,2;62,-1;
3:1,14,11,Times,0,16,0,0,0;1,14,11,Times,2,16,0,0,0;1,14,11,Times,0,16,0,0,0;
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Example 1. Linear polynomial:
;[s]
2:0,0;9,1;29,-1;
2:1,14,11,Times,1,16,0,0,0;1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Clear[XY,f];
XY={{1, 3.7}, {2, 4.1}, {2.5, 4.3}, {3, 5}};
f[x_]=Fit[XY, {1,x}, x]
:[font = input; preserveAspect; ]
Clear[dots, least];
dots = ListPlot[XY,PlotStyle->{PointSize[0.02]},
                DisplayFunction->Identity];
least= Plot[f[x],{x,1,3.2},
                DisplayFunction->Identity];
Show[least, dots, DisplayFunction->$DisplayFunction,
PlotLabel->txt,AxesLabel->{"x","y    "}]

:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Example 2. Least square method using polynomial:
;[s]
2:0,0;9,1;48,-1;
2:1,14,11,Times,1,16,0,0,0;1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Clear[XY,f];
XY={{0.24, 0.23}, {0.65, -0.26}, {0.95, -1.10},
{1.24, -0.45}, {1.73,0.27}, {2.01, 0.10}, {2.23, -0.19},
 {2.52, 0.24}, {2.77,0.56}, {2.99, 1.00}};
:[font = Left Header; inactive; preserveAspect; ]
Polynomial of degree 2:
;[s]
1:0,0;23,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
f[x_]=Fit[XY, {1,x,x^2}, x]
:[font = input; preserveAspect; ]
Clear[dots, least];
dots = ListPlot[XY,PlotStyle->{PointSize[0.02]},
                DisplayFunction->Identity];
least= Plot[f[x],{x,0,3.2},
                DisplayFunction->Identity];
Show[least, dots, DisplayFunction->$DisplayFunction,
PlotLabel->txt,AxesLabel->{"x","y    "}]

:[font = Left Header; inactive; preserveAspect; ]
Polynomial of degree 6:
;[s]
1:0,0;23,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Clear[f];
f[x_]=Fit[XY, {1,x,x^2, x^3, x^4, x^5,x^6}, x]
:[font = input; preserveAspect; ]
Clear[dots, least];
dots = ListPlot[XY,PlotStyle->{PointSize[0.02]},
                DisplayFunction->Identity];
least= Plot[f[x],{x,0.2,3.05},
                DisplayFunction->Identity];
Show[least, dots, DisplayFunction->$DisplayFunction,
PlotLabel->txt,AxesLabel->{"x","y    "}]

:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Example 3. Least square method using polynomial of degree 6,
which shows that the mathematica didn't do it correctly! We 
compare it with the orthogonal fit: notebooks "normeqn.ma" or
;[s]
4:0,0;9,1;82,2;93,3;184,-1;
4:1,14,11,Times,1,16,0,0,0;1,14,11,Times,0,16,0,0,0;1,14,11,Times,2,16,0,0,0;1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Clear[XY, n]; 
f[x_]:=1 + Sin[10 x]; 
pt[x_]:= 10+ (x-1)/14;  
n=15;
XY=N[Table[{pt[i], f[pt[i]]},  {i, 1,n}],10];
:[font = input; preserveAspect; ]
Clear[f];
f[x_]=Fit[XY, {1,x,x^2, x^3, x^4, x^5,x^6}, x] 
:[font = input; preserveAspect; ]
Clear[dots, least];
dots = ListPlot[XY,PlotStyle->{PointSize[0.02]}, 
                DisplayFunction->Identity];
least= Plot[f[x],{x,10,11},
                DisplayFunction->Identity];
Show[least, dots, DisplayFunction->$DisplayFunction,
PlotLabel->txt,AxesLabel->{"x","y    "}]
^*)