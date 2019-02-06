
import sys
import numpy as np
from PIL import Image

name = 'bricks'

def clamp(x):
	return max(0, min(x, 255))

def hexer(rgb=(0, 0, 0)):
	return '0x{0:02x}{1:02x}{2:02x}'.format(clamp(rgb[0]), clamp(rgb[1]), clamp(rgb[2]))

im = Image.open(name + '.png')

data = im.getdata()

f = open(name + '.tori', 'w+')

resolution = im.size

i = 0

f.write('(')

for j in range(2):
	f.write(str(resolution[j]))
	if j == 0:
		f.write(',')

f.write(')\n')

k = 0

for pix in data:
	f.write(str(pix))
	f.write(' ')
	if i == resolution[0]:
		f.write('\n')
		i = 0
	i += 1
