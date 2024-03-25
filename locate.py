import cv2
import numpy as np
import sys
#print("Test")

#Read in image and convert it to grey
image = cv2.imread(sys.argv[1])
image_grey = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

#Read in Waldo
waldo_01 = cv2.imread('waldo01.png',0)
waldo_02 = cv2.imread('waldo02.png',0)
waldo_03 = cv2.imread('waldo03.png',0)
height_w1 = waldo_01.shape[0]
width_w1 = waldo_01.shape[1]
height_w2 = waldo_02.shape[0]
width_w2 = waldo_02.shape[1]
height_w3 = waldo_03.shape[0]
width_w3 = waldo_03.shape[1]

#Look for Waldo
find_w1 = cv2.matchTemplate(image_grey,waldo_01,cv2.TM_CCOEFF_NORMED)
find_w2 = cv2.matchTemplate(image_grey,waldo_02,cv2.TM_CCOEFF_NORMED)
find_w3 = cv2.matchTemplate(image_grey,waldo_03,cv2.TM_CCOEFF_NORMED)

threshold = 0.6

#If Waldo is found, finds where.
location_w1 = np.where(find_w1 >= threshold)

#create a list of places waldo01 was found using the image
w1locations = list(map(list,zip(*location_w1)))
#the number of places waldo01 found in the image
numw1locations = len(w1locations)

if len(w1locations) > 0:
    print(w1locations[0])

location_w2 = np.where(find_w2 >= threshold)

#create a list of places waldo01 was found using the image
w2locations = list(map(list,zip(*location_w2)))
#the number of places waldo01 found in the image
numw2locations = len(w2locations)

if len(w2locations) > 0:
    print(w2locations[0])

location_w3 = np.where(find_w3 >= threshold)

#create a list of places waldo01 was found using the image
w3locations = list(map(list,zip(*location_w3)))
#the number of places waldo01 found in the image
numw3locations = len(w3locations)

if len(w3locations) > 0:
    print(w3locations[0])
#print(find_w1)
#print(location_w1)

#find x - print(location[0] + (width / 2))
#find y - print(location[1] + (height / 2))
if numw1locations > 0 or numw2locations > 0 or numw3locations > 0:
    print("true")
