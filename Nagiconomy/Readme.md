# About
Learning economy with computational and analysis tools 

# How to Use Julia
We are using Julia-1.7.3

You can learn how to install Julia and run a file here:
https://github.com/glanzkaiser/glanzshamzs/tree/main/Julia

## Example of importing csv file
Open Julia REPL (Install packages CSV and DataFrames)

```
include("importcsv.jl")
```
It will show a table of Asia's countries reliance on imported energy, sources: IEA(International Energy Agency); EIU(Economist Intelligence Unit)

## Example of Plotting from csv file

```
include("importcsv-statsplot.jl")
```

| Import CSV | Plot from CSV | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/nagiconomy-julia1.png" width="83%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/nagiconomy-julia2.png" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Nagiconomy/Julia/importcsv.jl">importcsv.jl</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Nagiconomy/Julia/importcsv-statsplot.jl">importcsv-statsplot.jl</a> | 


# Nagiconomy' Topics
Ingredients:
1. Julia-1.7.3
2. PlotlyJS

## 1. Countries Reserves and Debts' Data

| Central Bank' Reserves | Database | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/nagiconomy-julia3.png" width="83%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/nagiconomy-julia4.png" width="83%"> | 
| <a href="https://data.worldbank.org/indicator/FI.RES.TOTL.CD">Click here</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Nagiconomy/Julia/totalreserveswithgold_db.csv">CSV data</a> | 

| Central Bank' Reserves and Debts |
| ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/nagiconomy-julia6.png" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Nagiconomy/Julia/nagiconomy-totalreserves.jl">nagiconomy-totalreserves.jl</a> | 

### Nagi & Glanz' Opinion:

#### Glanz: 
How can a country pay a debt if the reserve is far below the debt? Is it to give foods to those that can be worthy for the country' asset? I do not think that all deserve to be fed by country if they create a chain effect that will lower the country' ability to improve its GDP, productivity, and innovations. Take care of the crimes in all areas, if it is lower then emerging to 0, then your debts will be gone. That's my opinion. There might be a lot of new Marie Curie, Einstein or Isaac Newton differing from sex gender, sexual orientation in your country that needs a safety that can only be given by developed country, they might want to walk alone find inspiration like how Da Vinci used to walk in forest with his assistant Dio. Is the country' leader not knowing this potential hidden all over the place?

#### Nagi: 
The debts are for paying the country ambition that differ, such as America needs a lot of ammunition and weapons to fund the war. To build infrastructure like China' Belt and Road Initiative that can ensure China's long-term income and position as the landlord of trade in Euro-Asia area.

## 2. Energy Economics

| Energy Data | Database | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/nagiconomy-julia7-1.png" width="83%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/nagiconomy-julia7-2.png" width="83%"> | 
| <a href="https://energy-charts.info/charts/energy/chart.htm?l=en&c=DE&chartColumnSorting=default&interval=month&year=-1">Click here</a> | <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Nagiconomy/Julia/csv/energy-charts_Public_net_electricity_generation_in_Germany_in_March_Excel.csv">CSV data</a> | 

| Public net electricity generation in Germany (Quarterly) | Public net electricity generation in Germany (2015-2022) | 
| ------------- | ------------- | 
| <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/nagiconomy-julia7.png" width="83%"> | <img src="https://github.com/glanzkaiser/glanzshamzs/blob/main/Julia/images/nagiconomy-julia7-3.png" width="83%"> | 
| <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Nagiconomy/Julia/nagiconomy-statsplot-energy.jl">nagiconomy-statsplot-energy.jl</a> |  <a href="https://github.com/glanzkaiser/glanzshamzs/blob/main/Nagiconomy/Julia/nagiconomy-statsplot-energytotal.jl">nagiconomy-statsplot-energytotal.jl</a> |

### Nagi & Glanz' Opinion:
#### Glanz: 
Wind energy has a great potential in Germany. I wonder for another country, what kind of energy they used ? Is it mostly the conventional oil or coal? or shifting to renewable? We can see the geographical correlation with the energy used. 

#### Nagi: 
The data can be analyze more if we have the price per watt hour for each energy, the cost to generate per watt hour, more transparency, how much the government takes from generating till selling to public. Sufficient energy fulfilled is the basic needs for better economy. Add a new correlation between type of energy mostly used and the country' GDP or any other significant economics indicator.

# Economic Problems
We are going to summarize economic problems and find the solution to eliminate poverty and inequality, with the tools of science, engineering, technology and other fields.

## 1. United Kingdom
### 2022/07
1. UK has the highest inﬂation in the G7
2. Britain is stuck in a 15 year low productivity rut. 
3. Its current account deﬁcit has ballooned, sterling has tumbled and debt interest costs are rising. 

## 2. United States
### 2022/07
1. 

## 3. Worldwide
### 2022/07
1. During the ﬁrst two years of the pandemic more than 80% of schooldays in Latin America and South Asia were disrupted by closures of some sort. Even today schools in some countries, such as the Philippines, remain shut to most pupils. The harm that school closures have done to children has vastly outweighed any beneﬁts they may have had for public health.  If children cannot read and understand a simple story, they will struggle to earn a good living. Nearly every problem that confronts humanity can be alleviated by good schooling. Better educated people are more likely to devise a cleaner energy source, a cure for malaria or a smarter town plan. Workers who can read and manipulate numbers are more productive. Bookish populations will ﬁnd it easier to adapt to climate change. They will also have fewer babies, and educate them better. If the damage the pandemic has done to education is not reversed, all these goals will be harder to reach.

## 4. China
### 2022/07
1. In 2018 ByteDance was forced to shutdown Neihan Duanzi, its joke-sharing app,which once had more than 200m users, after China’s media regulator claimed that its “off-colour” content had “triggered intense resentment among internet users”
#### Glanz & Nagi' Opinion
China is smart, they penetrate through culture or soft power, like France with their language and it is one of the most spoken language on this planet.

2. 

# Sources
https://juliadatascience.io

https://towardsdatascience.com/learning-gadfly-by-creating-beautiful-seaborn-plots-in-julia-755821156c86

The Economist

# Authors
Nagi, Glanz
