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
Least Square Fit using Orthogonal Polynomials
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
The following generates the least square fit using orthogonal 
polynomials.  Once BestFit[X, p] is run, where XY is the data 
and p is the degree of least fit, the output is : Orthogonal polynomials
P[n,x], and least square polynomial BestFit[x,p]. 
;[s]
1:0,0;250,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Off[General::spell1];
Clear[BestFit, BestPoly,XY0,p];
BestFit[XY0_,p0_] := 
Block[{XY},
  XY = XY0;
  p = p0;
m=Length[XY];
Clear[a,b,ips,P];
ips[f_,g_] := Sum[ f g /. x-> XY[[i,1]] ,{i,m}];
a[n_] := a[n] = ips[ x P[n-1,x] , P[n-1,x] ] / ips[ P[n-1,x] , P[n-1,x] ]; 
b[n_] := b[n] = ips[ x P[n-1,x] , P[n-2,x] ] / ips[ P[n-2,x] , P[n-2,x] ];
P[0,x_] = 1;
P[1,x_] = x - a[1];
P[n_,x_] := P[n,x] = (x-a[n]) P[n-1,x] - b[n] P[n-2,x];
For[i=1,i <= m,i++,
   xy[XY[[i,1]]] = XY[[i,2]] ];
BestPoly[x_,p] = 
        Sum[ (ips[ xy[x] , P[k,x] ] /
        ips[ P[k,x], P[k,x] ]) P[k,x]  ,{k,0,p} ]; ];
On[General::spell1];     
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Example 1. We use a polynomial of degree 6 to fit the following data:
;[s]
4:0,0;9,1;10,2;11,3;70,-1;
4:1,14,11,Times,1,16,0,0,0;1,14,11,Times,0,16,0,0,0;1,14,11,Times,0,16,0,0,0;1,13,10,Times,0,14,0,0,0;
:[font = input; preserveAspect; ]
Clear[XY];
XY={{0.24, 0.23}, {0.65, -0.26}, {0.95, -1.10},
{1.24, -0.45}, {1.73,0.27}, {2.01, 0.10}, {2.23, -0.19},
 {2.52, 0.24}, {2.77,0.56}, {2.99, 1.00}};  
:[font = input; preserveAspect; ]
BestFit[XY,6]    
:[font = input; preserveAspect; ]
For[j=0, j<=6, j++,
   Print["P",j,"(x)=" Simplify[P[j,x]]] ]  
:[font = input; preserveAspect; ]
Simplify[BestPoly[x,6]]  

:[font = input; preserveAspect; ]
Clear[nodes,fcn]
nodes=ListPlot[XY,PlotStyle->PointSize[.02],
              DisplayFunction->Identity]; 
fcn=Plot[ BestPoly[x,6],{x,0.2,3.2},
              DisplayFunction->Identity];
Show[nodes,fcn,DisplayFunction->$DisplayFunction]          
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Example 2. We use a polynomial of degree 6 to fit the following data:
;[s]
3:0,0;9,1;12,2;13,-1;
3:1,14,11,Times,1,16,0,0,0;1,14,11,Times,0,16,0,0,0;1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Clear[XY, n]; 
f[x_]:=1 + Sin[10 x]; 
pt[x_]:= 10+ (x-1)/14; 
n=15;
XY=N[Table[{pt[i], f[pt[i]]},  {i, 1,n}],10]; 
:[font = input; preserveAspect; ]
BestFit[XY,6]; 
 Simplify[BestPoly[x,6]]   
:[font = input; preserveAspect; ]
Clear[nodes,fcn]
nodes=ListPlot[XY,PlotStyle->PointSize[.02], 
              DisplayFunction->Identity];  
fcn=Plot[ BestPoly[x,6],{x,10,11},
              DisplayFunction->Identity];
Show[nodes,fcn,DisplayFunction->$DisplayFunction]          
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
One should compare the result with the result of solving normal
equation directly. See notebook "normeq.ma".
;[s]
1:0,0;109,-1;
1:1,14,11,Times,0,16,0,0,0;
^*)