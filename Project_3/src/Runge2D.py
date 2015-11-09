#!/usr/bin/env python
#
# Taylor Ellington
# 11/5/2015
#
# 
#
#



from pylab import *
from mpl_toolkits.mplot3d.axes3d import Axes3D

# load all the files output from the two Runge functions
a = loadtxt('avals.txt')
b = loadtxt('bvals.txt')
Runge = loadtxt('Runge.txt')
p6Uni = loadtxt('p6_uni.txt')
p24Uni = loadtxt('p24_uni.txt')
p6Cheb = loadtxt('p6_Cheb.txt')
p24Cheb = loadtxt('p24_Cheb.txt')

# calcuate the errors
p6Unierr = np.zeros((201,101), dtype=np.float64)
p24Unierr = np.zeros((201,101), dtype=np.float64)
p6Cheberr = np.zeros((201,101), dtype=np.float64)
p24Cheberr = np.zeros((201,101), dtype=np.float64)
for i in xrange(0, 201):
    for j in xrange(0,101):
        p6Unierr[i][j] = abs( Runge[i][j] - p6Uni[i][j])
        p24Unierr[i][j] = abs( Runge[i][j] - p24Uni[i][j])
        p6Cheberr[i][j] = abs( Runge[i][j] - p6Cheb[i][j])
        p24Cheberr[i][j] = abs( Runge[i][j] - p24Cheb[i][j])

X, Y = meshgrid(b, a)

# plot the values of the Runge function
fig = figure()
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(X, Y, Runge, rstride=1, cstride=1, linewidth=0, cmap=cm.jet)
ax.set_xlabel('x')
ax.set_ylabel('y')
title('$Runge(x,y)$')
savefig('Runge.png')

#plot p6 with Uniform nodes
fig = figure()
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(X, Y, p6Uni, rstride=1, cstride=1, linewidth=0, cmap=cm.jet)
ax.set_xlabel('x')
ax.set_ylabel('y')
title('$p_{6}Uniform$')
savefig('p6Uniform.png')

#plot p24 with uniform nodes
fig = figure()
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(X, Y, p24Uni, rstride=1, cstride=1, linewidth=0, cmap=cm.jet)
ax.set_xlabel('x')
ax.set_ylabel('y')
title('$p_{24}(x,y)$')
savefig('p24Uniform.png')

#Plot p6 with Chebyshev nodes
fig = figure()
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(X, Y, p6Cheb, rstride=1, cstride=1, linewidth=0, cmap=cm.jet)
ax.set_xlabel('x')
ax.set_ylabel('y')
title('$p_{6}Chebyshev$')
savefig('p6Chebyshev.png')

# plot p24 with Chebyshev nodes
fig = figure()
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(X, Y, p24Cheb, rstride=1, cstride=1, linewidth=0, cmap=cm.jet)
ax.set_xlabel('x')
ax.set_ylabel('y')
title('$p_{24}ChebyshevError$')
savefig('p24Chebyshev.png')

#plot the error of p6 with uniform nodes
fig = figure()
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(X, Y, p6Unierr, rstride=1, cstride=1, linewidth=0, cmap=cm.jet)
ax.set_xlabel('x')
ax.set_ylabel('y')
title('$|Runge - p_{6}Uniform|$')
savefig('p6UniformError.png')

#plot the error of p24 with uniform nodes
fig = figure()
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(X, Y, p24Unierr, rstride=1, cstride=1, linewidth=0, cmap=cm.jet)
ax.set_xlabel('x')
ax.set_ylabel('y')
title('$|Runge - p_{24}Uniform|$')
savefig('p24UniformError.png')

#plot the error of p6 with Chebyshev nodes
fig = figure()
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(X, Y, p6Cheberr, rstride=1, cstride=1, linewidth=0, cmap=cm.jet)
ax.set_xlabel('x')
ax.set_ylabel('y')
title('$|Runge - p_{6}Chebyshev|$')
savefig('p6ChebyshevError.png')

#plot the error of p24 with Chebyshev nodes
fig = figure()
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(X, Y, p24Cheberr, rstride=1, cstride=1, linewidth=0, cmap=cm.jet)
ax.set_xlabel('x')
ax.set_ylabel('y')
title('$|Runge - p_{24}Chebyshev|$')
savefig('p24ChebyshevError.png')