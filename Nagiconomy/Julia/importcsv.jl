using CSV
using DataFrames

df = CSV.read("/home/browni/LasthrimProjection/importedenergydata.csv", DataFrame)
print(df)
