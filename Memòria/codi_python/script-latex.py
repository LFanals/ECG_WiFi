import matplotlib.pyplot as plt
# use LaTeX fonts in the plot
plt.rc('text', usetex=True)
plt.rc('font', family='serif')
# get the figure
f = plt.figure()


inicial = 5000
interes = 0.15

x = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
y = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
for i in range(15):
    y[i]=inicial*pow((1+interes), x[i])


# set labels (LaTeX can be used)
plt.title(r'\textbf{Mutual Information Feature Selection}', fontsize=11)
plt.xlabel(r'\textbf{Best K features}', fontsize=11)
plt.ylabel(r'\textbf{AUC Score on split11 Dataset}', fontsize=11)

plt.plot(x,y, label='Exponential')
plt.legend(loc='upper left')
# plt.grid()
plt.show()

# save as PDF
f.savefig("fs_mi.pdf", bbox_inches='tight')
# -------------------------------------------------------------------------------------------------------------


