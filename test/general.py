from plot import plot
import pygame
from pygame.locals import *
import serial
import time



import pylab
import matplotlib
matplotlib.use("Agg")
import matplotlib.backends.backend_agg as agg
from matplotlib import style

style.use("ggplot")
green = (32,178,170)
lime = (0, 255, 0)
red = (200, 0 ,0)
black = (0,0,0)
white = (255,255,255)
bright_red = (255,0,0)
bright_green = (173,255,47)
light_blue = (135,206,235)
window_Width = 1200
window_Height = 900


def text_objects(text, font):
    textSurface = font.render(text, True, black)
    return textSurface, textSurface.get_rect()

def message_display(text, x, y, size):
    largeText = pygame.font.Font('freesansbold.ttf', size)
    TextSurf, TextRect = text_objects(text, largeText)
    TextRect.center = (x,y)
    window.blit(TextSurf, TextRect)

def display_general(color1, text):
    pygame.draw.rect(screen, color1,(200,70,600,100))
    message_display(text, 500, 110, 40)

    message_display('Team #: 1230', 200, 260, 25)
    message_display('Mission Time:', 200, 320, 25)
    message_display('Heatshield:', 200, 380, 25)
    message_display('Parachute:', 200, 500, 25)

    pygame.draw.rect(screen, lime,(475,775,250,50))
    pygame.draw.rect(screen, red,(250,775,100,50))
    message_display('Save and export', 600, 800, 25)
    message_display('Reset', 300, 800, 25)

    message_display('Tilt:', 600, 260, 25)
    message_display('Height:', 600, 320, 25)
    message_display('Voltage:', 600, 380, 25)
    message_display('Pressure:', 600, 440, 25)
    message_display('Temperature:', 600, 500, 25)
    message_display('Acceleration:', 600, 560, 25)


def button(x, y, height, width, color1, color2, text, text_size, position):
    click = pygame.mouse.get_pressed()
    mouse = pygame.mouse.get_pos()
    if (x+width > mouse[0] > x and (y*position)+height > mouse[1] > y*position):
        pygame.draw.rect(screen, color2,(x,y*position,width,height))

        if click[0] == 1:
            if position == 1:
               display_general(color1, text)

            else:
                pygame.draw.rect(screen, color1,(200,70,600,100))
                message_display(text, 500, 110, 40)

                fig = pylab.figure(figsize=[8, 6.5], # Inches
                                   dpi=100,        # 100 dots per inch, so the resulting buffer is 400x400 pixels
                                   )
                ax = fig.gca()
                ax.plot([1, 2, 4, 8,10])
                canvas = agg.FigureCanvasAgg(fig)
                canvas.draw()
                renderer = canvas.get_renderer()
                raw_data = renderer.tostring_rgb()
                surf = pygame.image.fromstring(raw_data, (800,650), "RGB")
                screen.blit(surf, (120,230))
                pygame.display.flip()

    else:
        pygame.draw.rect(screen, color1,(x,y*position,width,height))

    message_display(text, (x + width/2), (y*position + height/2), text_size)


def create():
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'General', 20, 1)
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'Height', 20, 2)
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'Voltage', 20, 3)
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'Pressure', 20, 4)
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'Temperature', 20, 5)
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'Acceleration', 20, 6)
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'Location', 20, 7)

    pygame.display.update()

def game_loop():

    pygame.display.set_caption('U sure CANSAT UCR')

    background_colour = light_blue

    screen.fill(background_colour)

    size = (400,400)
    x = 20
    y = 10
    port = '/dev/ttyACM0'

    myPlot = plot()
    crashed = False
    #arduinoData = serial.Serial(port, 9600)
    time = 0
    dataList = []
    timeList = []
    f = myPlot.fig.add_subplot(111)

    while not crashed:
        create()



     #   while not (arduinoData.readline()):
      #      pass

     #   dataArray = arduinoData.readline()
     #   data = float(dataArray)
     #   dataList.append(data)
     #   print data
     #   timeList.append(time)
     #   game.animate(x, y, size, screen, port, timeList, dataList, f)
     #   time = time+1

        for event in pygame.event.get():
    		if event.type == pygame.QUIT:
    			crashed = True

pygame.init()
window = pygame.display.set_mode((window_Width, window_Height), DOUBLEBUF)
screen = pygame.display.get_surface()

game_loop()
