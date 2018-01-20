import matplotlib
matplotlib.use("Agg")
import matplotlib.backends.backend_agg as agg
import pylab
import pygame
from pygame.locals import *
import matplotlib.animation as animation
from matplotlib import style
import serial

class plot:
	fig = pylab.figure(figsize=[4, 4], dpi=100)

	def animate(self, x, y, size, screen, port, timeList, dataList, f):

		f.plot(timeList,dataList)
		canvas = agg.FigureCanvasAgg(self.fig)
		canvas.draw()
		renderer = canvas.get_renderer()
		raw_data = renderer.tostring_rgb()
		surface = pygame.image.fromstring(raw_data, size, "RGB")
		screen.blit(surface, (x,y))
		pygame.display.flip()
		f.clear()
