from plot import plot
import pygame
from pygame.locals import *
import serial

green = (0,200,0)
red = (250, 0 ,0)

pygame.init()

window = pygame.display.set_mode((600, 600), DOUBLEBUF)
screen = pygame.display.get_surface()

size = (400,400)
x = 20
y = 10
port = '/dev/ttyACM0'

game = plot()
crashed = False
#arduinoData = serial.Serial(port, 9600)
time = 0
dataList = []
timeList = []
f = game.fig.add_subplot(111)

while not crashed:

 #   while not (arduinoData.readline()):
  #      pass

 #   dataArray = arduinoData.readline()
 #   data = float(dataArray)
 #   dataList.append(data)
 #   print data
 #   timeList.append(time)
 #   game.animate(x, y, size, screen, port, timeList, dataList, f)
 #   time = time+1


    pygame.draw.rect(screen, green,(150,450,100,50))
    pygame.draw.rect(screen, red,(550,450,100,50))


    pygame.display.update()

    for event in pygame.event.get():
		if event.type == pygame.QUIT:
			crashed = True
