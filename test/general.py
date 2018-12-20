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
#!/usr/bin/python
#  -*- coding: latin-1 -*-

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
    pygame.draw.rect(screen, light_blue,(120,230,800,650))
    pygame.draw.rect(screen, color1,(410,70,380,80))
    message_display(text, 600, 110, 40)
    message_display('Team #: 1230', 197, 260, 25)
    message_display('Count of packets:', 224, 320, 25)
    message_display('Port:', 148, 380, 25)
    message_display('Board:', 160, 440, 25)
    message_display('Heatshield:', 189,500 , 25)
    pygame.draw.rect(screen, red,(280,490,35,35))
    pygame.draw.rect(screen, red,(280,550,35,35))
    message_display('deployed', 360, 507.5, 20)
    message_display('released', 361, 567.5, 20)
    message_display('Parachute:', 189, 620, 25)
    pygame.draw.rect(screen, red,(280,610,35,35))
    message_display('Launch:', 172, 680, 25)
    pygame.draw.rect(screen, red,(280,670,35,35))
    pygame.draw.rect(screen, lime,(475,775,250,50))
    pygame.draw.rect(screen, red,(250,775,100,50))
    message_display('Save and export', 600, 800, 25)
    message_display('Reset', 300, 800, 25)
    message_display('Mission Time:', 655, 320 , 25)
    message_display('Tilt:', 595, 380, 25)
    message_display('Altitude:', 621, 440, 25)
    message_display('Voltage:', 624, 500, 25)
    message_display('Pressure:', 635, 560, 25)
    message_display('Temperature:', 657, 620, 25)
    message_display('Acceleration:', 655, 680, 25)

def load_image(filename, transparent=False):
        try: image = pygame.image.load(filename)
        except pygame.error, message:
                raise SystemExit, message
        image = image.convert()
        size=[800, 650]
        image= pygame.transform.scale(image, size)
        if transparent:
                color = image.get_at((0,0))
                image.set_colorkey(color, RLEACCEL)
        return image
    
def display_radar(color1, text):
    pygame.draw.rect(screen, color1,(410,70,380,80))
    message_display(text, 600, 110, 40)
    background_image = load_image('radar.jpg')
    screen.blit(background_image, (120, 230))
    pygame.draw.circle(screen, red, (500,400), 5, 5)
    pygame.draw.circle(screen, red, (450,480), 5, 5)
    pygame.draw.circle(screen, red, (530,410), 5, 5)
    pygame.draw.circle(screen, red, (580,350), 5, 5)
    pygame.draw.circle(screen, red, (600,380), 5, 5)
    pygame.draw.circle(screen, red, (500,400), 5, 5)
    pygame.display.flip()
    message_display('2000m', 120, 885, 15)
    message_display('1000m', 320, 885, 15)
    message_display('0m', 520, 885, 15)
    message_display('1000m', 720, 885, 15)
    message_display('2000m', 920, 885, 15)
    message_display('2000m', 95, 230, 15)
    message_display('1000m',95, 392.5, 15)
    message_display('0m', 95, 555, 15)
    message_display('1000m', 95, 717.5, 15)
    
def button(x, y, height, width, color1, color2, text, text_size, position):
    click = pygame.mouse.get_pressed()
    mouse = pygame.mouse.get_pos()
    if (x+width > mouse[0] > x and (y*position)+height > mouse[1] > y*position):
        pygame.draw.rect(screen, color2,(x,y*position,width,height))

        if click[0] == 1:
            if position == 1:
               message_display('Team U-sure', 195 ,200 , 25)
               display_general(color1, text)

            elif position == 7:
               message_display('Team U-sure', 195 ,200 , 25)
               display_radar(color1, text)

            else:
                message_display('Team U-sure', 195 ,200 , 25)
                pygame.draw.rect(screen, color1,(410,70,380,80))
                message_display(text, 600, 110, 40)

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
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'Altitude', 20, 2)
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'Voltage', 20, 3)
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'Pressure', 20, 4)
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'Temperature', 20, 5)
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'Acceleration', 20, 6)
    button(window_Width/1.2, window_Height/8, 50, 130, green, bright_green, 'Location', 20, 7)
    pygame.display.update()

def game_loop():
    pygame.display.set_caption('U-sure CANSAT UCR')
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
