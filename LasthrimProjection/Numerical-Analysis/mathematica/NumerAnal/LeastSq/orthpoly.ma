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
Legendre Orthogonal Polynomials and Least 
Square Approximation
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
The following generatea sequence of orthogonal polynomials with 
respect to the inner product induced by  dx on [-1,1]: 
;[s]
1:0,0;120,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Clear[ips,P,a,b];
ips[f_,g_] := Integrate[f g, {x,-1,1}];
a[n_] := ips[ x P[n-1,x] , P[n-1,x] ] / ips[ P[n-1,x], P[n-1,x] ]; 
b[n_] := ips[ x P[n-1,x] , P[n-2,x] ] / ips[ P[n-2,x], P[n-2,x] ];
P[0,x_] = 1; 
P[1,x_] = x - a[1];
P[n_,x_] := P[n,x] = (x-a[n]) P[n-1,x] - b[n] P[n-2,x]   ;
:[font = input; preserveAspect; ]
For[j=0, j<=5, j++,
   Print["P",j,"(x)=" Simplify[P[j,x]]] ]    
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Mathematica has built Legendre polynomials in its package: 
;[s]
2:0,0;11,1;150,-1;
2:1,14,11,Times,2,16,0,0,0;1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
For[j=0, j<=5, j++,
   Print["P",j,"(x)=",  LegendreP[j,x]] ]    
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Here is  the least square approximation to a function f :
;[s]
1:0,0;57,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
BestPoly[f_,p_] := Simplify[
        Sum[ (ips[ f[x] , P[k,x] ] /
        ips[ P[k,x], P[k,x] ]) P[k,x]  ,{k,0,p} ] ]     
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Example 1.  f(x) = e^x; least square polynomial of degree 2:
;[s]
2:0,0;9,1;60,-1;
2:1,14,11,Times,1,16,0,0,0;1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Clear[f,g];
f[x_] = Exp[x];
g[x_]=BestPoly[f,2] //N  
:[font = input; preserveAspect; ]
Clear[func,approx];
func=Plot[f[x],{x,-1,1}, DisplayFunction->Identity]; 
approx=Plot[g[x],{x,-1,1}, DisplayFunction->Identity];
Show[func,approx,DisplayFunction->$DisplayFunction]           
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Example 2.  f(x) = cos(4x); least square polynomial of degree 4:
;[s]
2:0,0;9,1;65,-1;
2:1,14,11,Times,1,16,0,0,0;1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Clear[f,g];
f[x_] = Cos[4 x]; 
g[x_]=BestPoly[f,4] //N 
:[font = input; preserveAspect; ]
Clear[func,approx];
func=Plot[f[x],{x,-1,1}, DisplayFunction->Identity];
approx=Plot[g[x],{x,-1,1}, DisplayFunction->Identity];
Show[func,approx,DisplayFunction->$DisplayFunction]            
^*)