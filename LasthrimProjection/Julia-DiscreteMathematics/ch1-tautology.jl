# ⊻ = xor (exclusive or)
# ⊼ = nand (not and)
# ⊽ = nor (not or)
# Table is prettier in terminal/xterm than in Jupyter Notebook

using DataFrames, PrettyTables
df=DataFrame(p=repeat([true, false],inner=4), q=repeat([true, false],inner=2,outer=2), r=repeat([true, false],outer=4))

df[!,"~p"].=.!(df.p)
#df[!,"~q"].=.!(df.q)
#df[!,"~r"].=.!(df.r)
#df[!,"p ⩓ q"].=df.p.&&df.q
#df[!,"p ⩔ q"].=df.p.||df.q
#df[!,"p ⊻ q"] .=df.p .⊻ df.q
#df[!,"p ⊼ q"] .=df.p .⊼ df.q
#df[!,"p ⊽ q"] .=df.p .⊽ df.q
df[!,"~(p ⩓ ~p"].=.!(df.p.&&.!(df.p))
df[!,"p ⩔ ~p"].=df.p.||.!(df.p)
df[!,"p ⩔ q ⩔ r ⩔ ~(r ⩓ q)"].= (df.p.||df.q.||df.r) .|| .!(df.r .&& df.q)

pretty_table(df, nosubheader=true)
