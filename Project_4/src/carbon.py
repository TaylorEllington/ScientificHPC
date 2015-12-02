from matplotlib import *
from pylab import *
t_values = loadtxt("time.txt");
T_values = loadtxt("Temp.txt");
C2MM = loadtxt("C2mm.txt")
C4MM = loadtxt("C4mm.txt")
C2mm_800K = loadtxt("C2mm_800K.txt")
C2mm_900K = loadtxt("C2mm_900K.txt")
C2mm_1000K = loadtxt("C2mm_1000K.txt")
C2mm_1100K = loadtxt("C2mm_24hour.txt")
C2mm_1200K = loadtxt("C2mm_1200K.txt")
C4mm_800K = loadtxt("C4mm_800K.txt")
C4mm_900K = loadtxt("C4mm_900K.txt")
C4mm_1000K = loadtxt("C4mm_1000K.txt")
C4mm_1100K = loadtxt("C4mm_1100K.txt")
C4mm_1200K = loadtxt("C4mm_1200K.txt")

time_ticks =[]
x_ticks =[]
x_vals = linspace(0, 599, 7)
for x in xrange(0,7):
	x_ticks.append(round(x_vals[x]))
	time_ticks.append(round( t_values[round(x_vals[x])]/3600) )

temp_ticks = []
y_ticks = []
y_vals = linspace(0, 399, 5)
for x in xrange(0,5):
	y_ticks.append(round(y_vals[x], -1))
	temp_ticks.append(round(T_values[ y_vals[x] ], -1))

figure()
ax = subplot()
imshow(C2MM)
colorbar(orientation='horizontal')
xlabel("Time (Hours)")
ylabel("Temperature (Kelvin)")
gca().invert_yaxis()
ax.set_xticks(x_ticks)
ax.set_xticklabels(time_ticks)
ax.set_yticks(y_ticks)
ax.set_yticklabels(temp_ticks)
title("Carbon 2MM")
savefig("Carbon_Contour_2mm.png")

figure()
ax = gca()
imshow(C4MM)
colorbar(orientation='horizontal')
xlabel("Time (Hours)")
ylabel("Temperature (Kelvin)")
gca().invert_yaxis()
gca().set_xticks(x_ticks)
ax.set_xticklabels(time_ticks)
ax.set_yticks(y_ticks)
ax.set_yticklabels(temp_ticks)
title("Carbon 4MM")
savefig("Carbon_Contour_4mm.png")

figure()
plot(t_values, C2mm_800K,label="800K")
plot(t_values, C2mm_900K, label="900K")
plot(t_values, C2mm_1000K, label="1000K")
plot(t_values, C2mm_1100K, label="1100K")
plot(t_values, C2mm_1200K, label="1200K")
title("Carbon concentration at 2mm at a given temperature")
xlabel("Time")
ylabel("Carbon Concentration")
xticks( (1*3600, 6*3600, 12*3600, 24*3600, 36*3600, 48*3600), ('1 hr', '6 hr', '12 hr', '24 hr', '36 hr', '48 hr') )
axes = gca()
axes.set_ylim([0,0.025])
legend( loc=2, ncol=2, mode="expand", borderaxespad=0.3)
savefig("2mm_carbon_concetration_aggregate.png")

figure()
plot(t_values,C4mm_800K,label="800K")
plot(t_values, C4mm_900K, label="900K")
plot(t_values, C4mm_1000K, label="1000K")
plot(t_values, C4mm_1100K, label="1100K")
plot(t_values, C4mm_1200K, label="1200K")
title("Carbon concentration at 4mm at a given temperature")
xlabel("Time")
ylabel("Carbon Concentration")
xticks( (1*3600, 6*3600, 12*3600, 24*3600, 36*3600, 48*3600), ('1 hr', '6 hr', '12 hr', '24 hr', '36 hr', '48 hr') )
axes = gca()
axes.set_ylim([0,0.025])
legend( loc=2, ncol=2, mode="expand", borderaxespad=0.3)
savefig("4mm_carbon_concetration_aggregate.png")

