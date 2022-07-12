using PlotlyJS

percent_lost= ["17–54%", "1–5.4%", "0.2%", "0.1-0.3%"]
trace = scatter3d(
    x=["1346-01-01", "1918-02-10", "1981-03-20","2019-02-20"],
    y=["Black Death", "Spanish Flu", "HIV/AIDS","COVID-19"],
    z=[200000000, 100000000, 36300000,26000000],
    marker_color=["red", "green", "blue", "orange"], #or the hexcode for each color
    name="Death toll",
    text= ["Global population lost: $perc"  for perc in percent_lost],
   
)
# years, y is for pandemics, and z is for Death toll
layout = Layout(width=600, height=600, font_size=10,
    scene=attr(
        xaxis=attr(type="date"),
        yaxis=attr(type="category"),
        zaxis=attr(type="number"),
        xaxis_title ="year",
        yaxis_title="pandemics",
        zaxis_title="death toll",
	tittle_text="Source: Wikipedia",
	
        camera_eye=attr(x=1.85, y=1.85, z=1.25),
        annotations=[
        attr(
            showarrow=false,
            x="1346-01-01",
            y="Black Death",
            z=230000000,
            text="GPL: 17–54%",
            yshift=-7, #Shifts the position of the  annotation and arrow up (positive) or down (negative) by 7 pixels.
            font_size=10,
            ),
        attr(showarrow=false,
            x="1918-02-10",
            y="Spanish Flu",
            #z=4,
            xshift=40, #Shifts the position of the  annotation and arrow to the right (positive) or left (negative) by 40 pixels.
            yshift=70,
            text="GPL: 1–5.4%",
            font_size=10,    
            ),
        attr(showarrow=false,
            x="1981-03-20",
            y="HIV/AIDS",
            #z=4,
            yshift=25,
            xshift=40,
            text="GPL: 0.2%",
            font_size=10,    
            ),
        attr(showarrow=false,
            x="2019-02-20",
            y="COVID-19",
            #z=5,
                yshift=35,
            text="GPL: 0.1-0.3%",
            font_size=10,
        )]
    ),
)

plot(trace, layout)
# to plot in browser
# pl=Plot(trace, layout)