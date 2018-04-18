import numpy as np

import matplotlib.pyplot as plt


#cargar los datos para la grafica

datos=np.loadtxt('gravi.txt')


#para separar las columnas n, 

x1=datos[:,0]
x2=datos[:,1]
x3=datos[:,2]


plt.figure()
plt.plot(x2,x1,color='k')
plt.title("x Vs t")
plt.savefig('pos.png')
plt.plot(x3,x1,color='b', marker='D')
plt.title("v Vs t")
plt.savefig('vel.png')
plt.plot(x3,x2,color='r', marker='D')
plt.title("v Vs x")
plt.savefig('phase.png')

