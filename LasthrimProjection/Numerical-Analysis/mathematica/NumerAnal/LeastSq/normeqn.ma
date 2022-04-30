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
Least Square Problem with Normal Eqn: 
:[font = Left Header; inactive; preserveAspect; ]
 We consider the least square problem: Find the solution of
 AX=b in the least square sense;  the normal equation is 
             A*A x = A*b. 
If we  consider the least square fit of the data  {(Xi, Yi), i =1, ..., N}
 by a polynomial of degree n:
             P(x) = a0 + a1 x + a2 x^2 + ... +  an x^n,
then AX= b is given by P(Xi)  = Yi,  i=1,...,N,  so that  A = ( a_ij)  where 
a_ij = Xi^j , X=(a0,a1,a2, ... ,an)^T, and b = (Y1, Y2, ..., YN)^T.
;[s]
2:0,0;145,1;451,-1;
2:1,14,11,Times,0,16,0,0,0;1,13,10,Times,0,14,0,0,0;
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Let us consider the following example:
;[s]
1:0,0;38,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Clear[XY, n]; 
f[x_]:=1 + Sin[10 x]; 
pt[x_]:= 10+ (x-1)/14; 
n=15;
XY=N[Table[{pt[i], f[pt[i]]},  {i, 1,n}],10];
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
A and b are given by:
;[s]
1:0,0;21,-1;
1:1,13,10,Times,0,14,0,0,0;
:[font = input; preserveAspect; ]
A = Table[{1, XY[[i,1]], XY[[i,1]]^2,XY[[i,1]]^3,
  XY[[i,1]]^4,XY[[i,1]]^5,XY[[i,1]]^6},{i, 1,n}];
b = Table[ XY[[i,2]], {i,1,n}];
MatrixForm[A];  
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
The corresponding normal equation is  :
;[s]
1:0,0;39,-1;
1:1,13,10,Times,0,14,0,0,0;
:[font = input; preserveAspect; ]
ATA = Transpose[A].A ;
ATb = Transpose[A].b ; 
 MatrixForm[ATA]; 
 MatrixForm[ATb]; 
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Mehtod 1: Let us solve the normal equation by Gauss elimination ,
we need to open the notebook "gauss.ma" first:
;[s]
3:0,0;9,1;64,2;112,-1;
3:1,14,11,Times,1,16,0,0,0;1,14,11,Times,0,16,0,0,0;1,13,10,Times,0,14,0,0,0;
:[font = input; preserveAspect; ]
Clear[LU];
LU=GaussLU[ATA];
a1=N[GaussSol[LU,ATb], digit]  
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Here is the least square polynomial from this solution:
;[s]
1:0,0;55,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
least1[x_] =a1[[1]] + a1[[2]]x + a1[[3]]x^2 + a1[[4]]x^3 +
          a1[[5]]x^4 + a1[[6]] x^5 + a1[[7]] x^6 
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Here is the graph of the data and the polynomial:  
;[s]
1:0,0;51,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Clear[nodes,gp1]
nodes=ListPlot[XY,PlotStyle->PointSize[.02],
DisplayFunction->Identity]; 
gp1=Plot[least1[x],{x, 10, 11},DisplayFunction->Identity];
Show[nodes, gp1,DisplayFunction->$DisplayFunction]          
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Mehtod 2: Let us solve the normal equation by using the Gram-Schmidt 
factorization A=GS. T first, and then solve T X = B with  B=GS* b  using
the back-substitution. We use the notebooks "gram-sh.ma"  and "backsub.ma". 
;[s]
2:0,0;10,1;219,-1;
2:1,14,11,Times,1,16,0,0,0;1,13,10,Times,0,14,0,0,0;
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Here we run the Gram-Schmidt, compute B, and solve t X =B by
substitution:  
;[s]
1:0,0;76,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Clear[GS,B]
GS=GramSchmidt[A];
B= Transpose[GS] . b; 
a2 = BackSub[t,B] 
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Here is the least square polynomial from this solution:
;[s]
1:0,0;55,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
least2[x_] = a2[[1]] + a2[[2]]x + a2[[3]]x^2 + a2[[4]]x^3 +
          a2[[5]]x^4 + a2[[6]]x^5 + a2[[7]]x^6
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Here is the graph of the data and the polynomial:  
;[s]
1:0,0;51,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
Clear[gp2]
gp2=Plot[least2[x],{x, 10, 11},DisplayFunction->Identity];
Show[nodes, gp2,DisplayFunction->$DisplayFunction]          
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Comparision: Evidently, the second one is much better.  We can also see this by computing the lest squre error: 
;[s]
2:0,0;13,1;112,-1;
2:1,14,11,Times,1,16,0,0,0;1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
error1=Sum[ (least1[pt[i]] - f[pt[i]])^2, {i, 1,15}]//N  
:[font = input; preserveAspect; ]
error2=Sum[ (least2[pt[i]] - f[pt[i]])^2, {i, 1,15}]//N  
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
In fact, both a1 and a2 are solutions of normal equation. But their
difference is as much as 10^8 !! Let us print them down again.
;[s]
1:0,0;130,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
a1
:[font = input; preserveAspect; ]
a2
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Here is their difference, where the norm is the || .||_2 norm defined in
the "gram-sh.ma": 
;[s]
1:0,0;92,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
norm[a1-a2]
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
The reason for this difference is that ATA is  ill-conditioned. Hence,
the system is unstabled. The solution by Gaussian elimination will
have a large error. Here is the condition number 
;[s]
1:0,0;188,-1;
1:1,14,11,Times,0,16,0,0,0;
:[font = input; preserveAspect; ]
eigens = Eigenvalues[ATA];
Cond[ATA] = Max[Abs[eigens]] /Min[Abs[eigens]]
:[font = header; inactive; preserveAspect; fontSize = 14; fontName = "Times"; ]
Compare with the Mathematica build-in command "Fit":  
The mathematica solution of the Example 2 is bad !! 
;[s]
6:0,0;17,1;28,2;53,3;59,4;70,5;108,-1;
6:1,14,11,Times,1,16,0,0,0;1,14,11,Times,3,16,0,0,0;1,14,11,Times,1,16,0,0,0;1,14,11,Times,0,16,0,0,0;1,14,11,Times,2,16,0,0,0;1,14,11,Times,0,16,0,0,0;
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