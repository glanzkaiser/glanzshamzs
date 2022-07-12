using PlotlyJS, CSV, DataFrames, HTTP

df = CSV.read("/home/browni/LasthrimProjection/totalreserveswithgold_db.csv", DataFrame)

# Initialize figure with subplots
fig = make_subplots(
    rows=2, cols=2,
    column_widths=[0.6, 0.4],
    row_heights=[0.4, 0.6],
    specs=[
        Spec(kind="geo", rowspan=2) Spec(kind="xy")
        missing Spec(kind= "scene")
    ]
)


# TODO: Plot not staying in it's sub plot spot
# Add scattergeo globe map of Central Bank locations
add_trace!(
    fig,
    scattergeo(
        lat=df[!, "Latitude"],
        lon=df[!, "Longitude"],
        mode="markers",
        hoverinfo="text",
        showlegend=false,
        marker=attr(color="crimson", size=4, opacity=0.8),
        projection_type="orthographic",
        landcolor="white",
        oceancolor="MidnightBlue",
        showocean=true,
        lakecolor="LightBlue"
    ),
    row=1, col=1
)

# Add locations bar chart

add_trace!(
    fig,
    bar(df, x=:Country, y=:Debts, name="Total debts"),
    row=1, col=2
)
add_trace!(
    fig,
    bar(df, x=:Country, y=:Reserves, name="Total reserves (includes gold, current USD)"),	
    row=1, col=2
)

# Set theme, margin, and annotation in layout
relayout!(
    fig,
    geo=attr(projection_type="orthographic",
    landcolor="white",
    oceancolor="MidnightBlue",
    showocean=true,
    lakecolor="LightBlue"),
    xaxis2_tickangle=45,
    template=templates.plotly_dark,
    margin=attr(r=10, t=25, b=40, l=60),
    annotations=[
        attr(
            text="Source: World Bank, Wikipedia",
            showarrow=false,
            xref="paper",
            yref="paper",
            x=0,
            y=0)
    ]
)

fig