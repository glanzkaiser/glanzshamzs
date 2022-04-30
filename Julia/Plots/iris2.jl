# Using the DataFrames Package
using DataFrames
   
# Using the CSV package
using CSV
   
# Reading the CSV file
Iris = dataset("datasets", "iris");
  
# Using Plots Package 
using Plots 
  
# Plot Histogram
Plots.histogram(Iris[:SepalLength], 
                bins = 50, xlabel = "SepalLength", 
                            labels = "Length in cm")
